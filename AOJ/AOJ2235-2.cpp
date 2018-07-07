#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/07/07  Problem: AOJ 2235-2 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2235-2  ----- */
/* ------問題------

n 匹のうさぎがいて, 0 番からn － 1 番の番号がついた小屋に1 匹ずつ住んでいる.
あるとき, 秘密の組織によって地下通路の建設工事が行われる, という情報がうさぎたちのもとへ入った. 地下通路を使えば, うさぎたちは他のうさぎたちの小屋へ遊びに行けるようになって嬉しい.
通路は両方向に進むことができ, また通路同士は交わらない. 諸事情により, 一度建設された通路が破壊されてしまうこともある. 通路の建設や破壊の工事は1 本ずつ行われ, 各工事中はうさぎは自分の小屋に留まっているものとする.
うさぎたちは, 工事のいくつかの段階において, あるうさぎとあるうさぎが遊べるかどうかを事前に知りたい. うさぎたちは仲良しなので, 遊びに行くときに他のうさぎの小屋を自由に通ることができる. プログラミングが好きなうさぎたちは, 昔似たような問題を解いたので簡単だろうと思って挑戦し出したが, なかなか効率の良いプログラムが書けない. うさぎの代わりにこの問題を解け.

-----問題ここまで----- */
/* -----解説等-----

クエリ分しかイベントが来ない。タイムイベントをセグ木のindexとして、pop可能なufを持って、区間で連結を維持する。
その後、木上のdfsをする

----解説ここまで---- */

struct PersistentUnionFind {
	using T = pair<int, int>;
	int n;
	vector<int> r, p;
	stack<T> st;
	PersistentUnionFind() {}
	PersistentUnionFind(int sz) :n(sz), r(sz, 1), p(sz, 0) { iota(p.begin(), p.end(), 0); }
	int find(int x) {
		return x == p[x] ? p[x] : find(p[x]);
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	void unite(int x, int y) {
		x = find(x); y = find(y);
		st.emplace(-1, -1);
		if (x == y) return;
		if (r[x] < r[y]) swap(x, y);
		r[x] += r[y];
		p[y] = x;
		st.top() = T(x, y);
	}
	void undo(int t = 1) {
		for (int i = 0; i < t; i++) {
			int x, y;
			tie(x, y) = st.top(); st.pop();
			if (x < 0) continue;
			r[x] -= r[y];
			p[y] = y;
		}
	}
};

struct DynamicConnectivity { // insert&erase -> build -> exec
	using edge = pair<int, int>;
	using range = edge;

	int n, q;
	PersistentUnionFind puf;
	vector<vector<edge> > edges;
	vector<pair<range, edge> > prc;
	map<edge, int> cnt, app;

	DynamicConnectivity() {}
	DynamicConnectivity(int n, int q_) :n(n), q(1), puf(n) {
		while (q < q_) q <<= 1;
		edges.resize(q * 2 - 1);
	}

	void insert(int t, int u, int v) {
		edge e = minmax(u, v);
		if (cnt[e]++ == 0) app[e] = t;
	}

	void erase(int t, int u, int v) {
		edge e = minmax(u, v);
		if (--cnt[e] == 0) prc.emplace_back(range(app[e], t), e);
	}

	void add(int a, int b, const edge &e, int k, int l, int r) {
		if (r <= a || b <= l) return;
		if (a <= l&&r <= b) {
			edges[k].emplace_back(e);
			return;
		}
		int m = (l + r) >> 1;
		add(a, b, e, k * 2 + 1, l, m);
		add(a, b, e, k * 2 + 2, m, r);
	}

	void add(range &r, const edge &e) {
		add(r.first, r.second, e, 0, 0, q);
	}

	void build() {
		for (auto &e : cnt) {
			if (!e.second) continue;
			prc.emplace_back(range(app[e.first], q), e.first);
		}
		for (auto &s : prc)
			add(s.first, s.second);
	}

	void exec(const function<void(int)> &f, int k = 0) {
		for (auto &e : edges[k])
			puf.unite(e.first, e.second);

		if (k < q - 1) {
			exec(f, k * 2 + 1);
			exec(f, k * 2 + 2);
		}
		else {
			int x = k - (q - 1);
			f(x);
		}

		puf.undo(edges[k].size());
	}
};
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, K; cin >> N >> K;
	DynamicConnectivity dyc(N, K);
	VI type(K), a(K), b(K);
	FOR(i, 0, K) {
		cin >> type[i] >> a[i] >> b[i];
		if (type[i] == 1) {
			dyc.insert(i, a[i], b[i]);
		}
		else if (type[i] == 2) {
			dyc.erase(i, a[i], b[i]);
		}
	}

	dyc.build();
	auto f = [&](int x) {
		if (x < 0 || x >= K)return;
		if (type[x] == 3) {
			cout << (dyc.puf.same(a[x], b[x]) ? "YES" : "NO") << endl;
		}
	};
	dyc.exec(f);



	return 0;
}
