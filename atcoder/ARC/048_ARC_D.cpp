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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/11/06  Problem: ARC 048 D / Link: http://arc048.contest.atcoder.jp/tasks/arc048_d  ----- */
/* ------問題------

AtCoder市には 1 から N までの番号のついた N 個の町があり、それらは N−1 本の双方向に通行可能な距離 1 の道路によって結ばれています。 どの町からどの町へも、いくつかの道を経由してたどり着くことが出来ます。
AtCoder市には高橋君が Q 人おり、i 人目の高橋君は町 si から町 ti に行きたいです。
AtCoder市のいくつかの町にはたこ焼き屋があります。高橋君たちはみな、2 秒間に距離 1 進む速度で歩きますが、たこ焼き屋のある町でたこ焼きを食べたあとは歩く速度が 1 秒間に距離 1 進む速度になります。 また高橋君たちはみな小食なので、たこ焼きを複数回食べることはしません。もちろん、たこ焼き屋のある町をたこ焼きを食べずに通過することは可能です。 また、たこ焼きを食べずに町 ti に到着してもかまいません。
AtCoder市の町の接続関係が与えられるので、 Q 人の高橋君すべてに対し、最適に行動したときの町 si から町 tiへの移動に費やされる時間の最小値を求めてください。 高橋君たちはみなたこ焼きのプロなので、たこ焼きを食べるのにかかる時間は無視できるものとします。

-----問題ここまで----- */
/* -----解説等-----

[HL分解での解法]
木上のクエリでの変数分離テクが出てきてかなり良かった。
問題はs-tパスでのxを経由して行く問題と見れる。ただし、x->yみたいな経路があって、xにアクセスするとxからたこ焼きyへの最小値が格納されているとする。
すると、問はdist(s,t) + dist(s,x) + 3*dist(x,y)と変形できる。これを最小化すれば良い。
ここで、dist(s,x)以外はクエリ前O(1)で解ける。
よってdist(s,x)のみを考える。これは |dist(root,s) - dist(root,x)|と書き換える事ができる。(木のテク集参照)
よって、3*dist(x,y)±dist(root,x)を{x|[s:t]}で最小化する問題になり、これはHL分解して列の最小値を求める問題に帰着される。
LCAごとに±を場合分けして、解けば良い。

[ダブリング解]
木のpathの最小、最大値はダブリングでできる。これはsparseTableと対して変わらない。

----解説ここまで---- */

struct HLD {
	int n, pos;
	vector<vector<int>> G;
	vector<int> vid, head, sub, hvy, par, dep, inv, type, ps, pt;
	HLD(int nn) :
		n(nn), pos(0), G(n),
		vid(n, -1), head(n), sub(n, 1), hvy(n, -1),
		par(n), dep(n), inv(n), type(n), ps(n), pt(n) {}

	void add_edge(int u, int v) {
		G[u].push_back(v);
		G[v].push_back(u);
	}
	void build(int root = 0) {
		int c = 0;
		dfs(root);
		bfs(root, c++);
	}
	void dfs(int rt) {
		using T = pair<int, int>;
		stack<T> st;
		par[rt] = -1;
		dep[rt] = 0;
		st.emplace(rt, 0);
		while (!st.empty()) {
			int v = st.top().first;
			int &i = st.top().second;
			if (i < (int)G[v].size()) {
				int u = G[v][i++];
				if (u == par[v]) continue;
				par[u] = v;
				dep[u] = dep[v] + 1;
				st.emplace(u, 0);
			}
			else {
				st.pop();
				for (int j = 0; j < (int)G[v].size(); j++) {
					int &u = G[v][j];
					if (u == par[v]) swap(u, G[v].back());
					if (u == par[v]) continue;
					sub[v] += sub[u];
					if (sub[u] > sub[G[v].front()]) swap(u, G[v].front());
				}
			}
		}
	}

	void bfs(int r, int c) {
		using T = tuple<int, int, int>;
		stack<T> st;
		st.emplace(r, r, 0);
		while (!st.empty()) {
			int v, h;
			tie(v, h, ignore) = st.top();
			int &i = get<2>(st.top());
			if (!i) {
				type[v] = c;
				ps[v] = vid[v] = pos++;
				inv[vid[v]] = v;
				head[v] = h;
				hvy[v] = (G[v].empty() ? -1 : G[v][0]);
				if (hvy[v] == par[v]) hvy[v] = -1;
			}
			if (i < (int)G[v].size()) {
				int u = G[v][i++];
				if (u == par[v]) continue;
				st.emplace(u, (hvy[v] == u ? h : u), 0);
			}
			else {
				st.pop();
				pt[v] = pos;
			}
		}
	}
	// [l, r] 
	void for_each_vertex(int u, int v, const function<void(int, int)>& f) {
		while (1) {
			if (vid[u] > vid[v])swap(u, v);
			f(max(vid[head[v]], vid[u]), vid[v]);
			if (head[u] != head[v]) v = par[head[v]];
			else break;
		}
	}

	int lca(int u, int v) {
		while (1) {
			if (vid[u] > vid[v])swap(u, v);
			if (head[u] == head[v])return u;
			v = par[head[v]];
		}
	}
	int distance(int u, int v) {
		return dep[u] + dep[v] - 2 * dep[lca(u, v)];
	}
};


template< typename MeetSemilattice>
struct SparseTable {
	using T = typename MeetSemilattice::t;
	vector<vector<T>> st;

	SparseTable() {}

	SparseTable(const vector<T> &v) {
		int b = 0;
		while ((1 << b) <= v.size()) ++b;
		st.assign(b, vector<T>(1 << b));
		for (int i = 0; i < v.size(); i++) {
			st[0][i] = v[i];
		}
		for (int i = 1; i < b; i++) {
			for (int j = 0; j + (1 << i) <= (1 << b); j++) {
				st[i][j] = MeetSemilattice::op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
			}
		}
	}
	inline T query(int l, int r) {
		int b = 32 - __builtin_clz(r - l) - 1;
		return (MeetSemilattice::op(st[b][l], st[b][r - (1 << b)]));
	}
};

struct M {
	using t = LL;
	static t op(const t&l, const t&r) { return min(l, r); }
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, Q; cin >> N >> Q;
	HLD hlG(N);
	FOR(i, 0, N - 1) {
		int a, b; cin >> a >> b;
		a--, b--;
		hlG.add_edge(a, b);
	}
	hlG.build();

	string s; cin >> s;
	VL takoDist(N, INF);
	{
		queue<int>q;
		FOR(i, 0, N) {
			if (s[i] == '1') {
				q.push(i);
				takoDist[i] = 0;
			}
		}
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (int nx : hlG.G[v]) {
				if (takoDist[nx] > takoDist[v] + 1) {
					takoDist[nx] = takoDist[v] + 1;
					q.push(nx);
				}
			}
		}
	}

	VL up(N), down(N);
	{
		FOR(i, 0, N) {
			int rp = hlG.vid[i];
			up[rp] = - hlG.dep[i] + 3 * takoDist[i];
			down[rp] = hlG.dep[i] + 3 * takoDist[i];
		}
	}

	SparseTable<M> upminus(up);
	SparseTable<M> downplus(down);

	FOR(i, 0, Q) {
		int ss, tt; cin >> ss >> tt;
		ss--, tt--;
		int lca = hlG.lca(ss, tt);

		LL sToLca = LINF;
		hlG.for_each_vertex(ss, lca, [&](int l, int r) {
			sToLca = min(sToLca, upminus.query(l, r + 1));
		});

		LL lcaToT = LINF;
		hlG.for_each_vertex(lca, tt, [&](int l, int r) {
			lcaToT = min(lcaToT, downplus.query(l, r + 1));
		});

		LL stPath = hlG.distance(ss, tt);
		LL D1 = stPath * 2;
		LL D2 = stPath + hlG.dep[ss] + sToLca;
		LL D3 = stPath + hlG.dep[ss] + -2 * hlG.dep[lca] + lcaToT;
		LL ans = min({ D1,D2,D3 });
		cout << ans << "\n";
	}

	return 0;
}
