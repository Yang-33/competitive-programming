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

/* -----  2018/08/24  Problem: yukicoder 235  / Link: http://yukicoder.me/problems/no/235  ----- */
/* ------問題------

ちゃろー、センパイ。
最新のVRを使ったゲーム「yukicoder王国の野望」をついに買いましたよ！
夏休みに、めぐる、yukicoder王国を何回か旅行する計画を立てているんですけど、今のうちにダンジョンにこもって旅費を稼ぐつもりなんです。
いくら稼げば良いのか、センパイ、計算してください！
yukicoder王国には N 個の街と N−1 個の道路があるんですね。
k 個目の道路は街 Ak と街 Bk を結ぶ道路で、全ての街は道路をいくつか通って行き来できるようになっています。
めぐるの旅行はある街 X からある街 Y に道路で移動するんですけど、街 X,Y も含めて、訪れる全ての街で一泊して観光するつもりなんですね。
今は街 k で泊まる場合の宿泊費は Sk なんですけど、この夏休みはyuki王様のパレードが予定されていて、宿泊費が変わっていくんですよね…。
街 k にはインフレ係数 Ck ってのが設定されているんですね。
王様が街 X から街 Y まで規模 Z のパレードを行ったら、その後はずーっと、街 X,Y も含めて、そのパレードの時に通った街の宿泊費が値上がりするんです。
それも、その街のインフレ係数と Z を掛けた分だけ値上がりするんで、きついんですよね…。
現在から夏休みが終わるまでの、めぐるの旅行の予定とパレードの予定は合計で Q 個あるんですよね。
めぐる、時系列順に予定 1, 予定 2, …, 予定 Q とすると、それぞれの予定は以下のどちらかの形式でメモをしているんです！
0 X Y Z：街 X から街 Y まで、規模 Z の国王のパレードが開催されます
1 X Y：めぐるが街 X から街 Y まで旅行する予定です！
そういえば、yuki国王のパレードってとっても華やかで楽しいんですよ。
今度一緒に見に行きませんか？
う…、そうですよね…。

-----問題ここまで----- */
/* -----解説等-----

列でできるならできることから、HLD+segtree
Cのパートで悩むが、遅延セグ木は一回push&fixしていることから、違う係数和Zが乗ることはない。

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
		G[u].push_back(v); G[v].push_back(u);
	}
	void build(int root = 0) {
		int c = 0; dfs(root); bfs(root, c++);
	}

	void dfs(int rt) {
		using T = pair<int, int>; stack<T> st; par[rt] = -1; dep[rt] = 0;	st.emplace(rt, 0);
		while (!st.empty()) {
			int v = st.top().first; int &i = st.top().second;
			if (i < (int)G[v].size()) {
				int u = G[v][i++];	if (u == par[v]) continue;	par[u] = v;	dep[u] = dep[v] + 1; st.emplace(u, 0);
			}
			else {
				st.pop();
				for (int j = 0; j < (int)G[v].size(); j++) {
					int &u = G[v][j]; if (u == par[v]) swap(u, G[v].back()); if (u == par[v]) continue; sub[v] += sub[u];
					if (sub[u] > sub[G[v].front()]) swap(u, G[v].front());
				}
			}
		}
	}

	void bfs(int r, int c) {
		using T = tuple<int, int, int>;
		stack<T> st; st.emplace(r, r, 0);
		while (!st.empty()) {
			int v, h; tie(v, h, ignore) = st.top(); int &i = get<2>(st.top());
			if (!i) {
				type[v] = c; ps[v] = vid[v] = pos++;
				inv[vid[v]] = v; head[v] = h; hvy[v] = (G[v].empty() ? -1 : G[v][0]);
				if (hvy[v] == par[v]) hvy[v] = -1;
			}
			if (i < (int)G[v].size()) { int u = G[v][i++];	if (u == par[v]) continue;	st.emplace(u, (hvy[v] == u ? h : u), 0); }
			else { st.pop(); pt[v] = pos; }
		}
	}

	void for_each_vertex(int u, int v, const function<void(int, int)>& f) {
		while (1) {
			if (vid[u] > vid[v])swap(u, v);	f(max(vid[head[v]], vid[u]), vid[v]);
			if (head[u] != head[v]) v = par[head[v]]; else break;
		}
	}

	void for_each_edge(int u, int v, const function<void(int, int)>&f) {
		while (1) {
			if (vid[u] > vid[v])swap(u, v);	if (head[u] != head[v]) { f(vid[head[v]], vid[v]); v = par[head[v]]; }
			else { if (u != v)f(vid[u] + 1, vid[v]);	break; }
		}
	}
	int lca(int u, int v) { while (1) { if (vid[u] > vid[v])swap(u, v);	if (head[u] == head[v])return u; v = par[head[v]]; } }

	int distance(int u, int v) { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }
};
struct Node {
	Node() :sum(0), cc(0) {} // e
	Node(long long x) :sum(x), cc(x) {}
	LL sum, cc;
};
struct Lazy {
	Lazy() :set(0), lazyval(0) {} // lazy e
	bool set;
	long long lazyval;
};

long long out_range = 0;

typedef long long ll;
struct LazySegTreeP {

	long long N;
	vector<Node> dat;
	vector<Lazy> lazy;

	inline Node merge(Node& a, Node& b) {
		Node node;
		(node.sum += (a.sum + b.sum) % MOD) %= MOD;
		(node.cc = (a.cc + b.cc) % MOD) %= MOD;
		return node;
	}

	void lazy_push(ll k, ll queryL, ll queryR) {
		if (lazy[k].set == 0)return;
		(dat[k].sum += (dat[k].cc*lazy[k].lazyval) % MOD) %= MOD;
		if (k < N - 1) {
			lazy_set(2 * k + 1, lazy[k].lazyval);
			lazy_set(2 * k + 2, lazy[k].lazyval);
		}
		lazy[k].lazyval = 0;
		lazy[k].set = 0;
	}

	inline void lazy_set(ll k, ll val) {
		lazy[k].set = 1;
		(lazy[k].lazyval += val % MOD) %= MOD;
	}

	inline void fix(ll k) {
		dat[k] = merge(dat[k * 2 + 1], dat[k * 2 + 2]);
	}

	inline void kth_direct_update(ll id, ll s, ll c) {
		id += N - 1;
		dat[id].sum = s; dat[id].cc = c;
	}
	void build() { for (int i = N - 2; i >= 0; i--) dat[i] = merge(dat[2 * i + 1], dat[2 * i + 2]); }

	LazySegTreeP(int _N) {
		N = 1;
		while (N < _N)N *= 2;
		dat = vector<Node>(N * 2 - 1);
		lazy = vector<Lazy>(N * 2 - 1);
	}

	~LazySegTreeP() { vector<Node>().swap(dat); vector<Lazy>().swap(lazy); }

	inline void lazy_update(ll queryL, ll queryR, ll val, ll k = 0, ll nodeL = 0, ll nodeR = -1) {
		if (nodeR == -1)nodeR = N;
		lazy_push(k, nodeL, nodeR);

		if (nodeR <= queryL || queryR <= nodeL) { return; }
		if (queryL <= nodeL && nodeR <= queryR) {
			lazy_set(k, val);
			lazy_push(k, nodeL, nodeR);
			return;
		}
		ll nodeM = (nodeL + nodeR) / 2;
		lazy_update(queryL, queryR, val, k * 2 + 1, nodeL, nodeM);
		lazy_update(queryL, queryR, val, k * 2 + 2, nodeM, nodeR);

		fix(k);
		return;
	}

	Node query(ll queryL, ll queryR, ll k, ll nodeL, ll nodeR) {

		lazy_push(k, nodeL, nodeR);

		if (nodeR <= queryL || queryR <= nodeL) { return Node(out_range); }
		if (queryL <= nodeL && nodeR <= queryR) { return dat[k]; }

		ll nodeM = (nodeL + nodeR) / 2;
		Node vl = query(queryL, queryR, k * 2 + 1, nodeL, nodeM);
		Node vr = query(queryL, queryR, k * 2 + 2, nodeM, nodeR);
		return merge(vr, vl);
	}
	inline Node query(int a, int b) {
		return query(a, b, 0, 0, N);
	}
};


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; scanf("%d", &N);
	VI s(N); FOR(i, 0, N)scanf("%d", &s[i]);
	VI c(N); FOR(i, 0, N)scanf("%d", &c[i]);
	HLD hld(N);
	FOR(i, 0, N - 1) {
		int a, b; scanf("%d%d", &a, &b);
		hld.add_edge(a - 1, b - 1);
	}
	hld.build();
	LazySegTreeP seg(N);
	// seg info ↓
	FOR(i, 0, N) {
		seg.kth_direct_update(hld.vid[i], s[i], c[i]);
	}
	seg.build();

	int Q; scanf("%d", &Q);
	FOR(_, 0, Q) {
		int b, x, y; scanf("%d%d%d", &b, &x, &y);
		x--, y--;
		if (!b) {
			int z; scanf("%d", &z);
			hld.for_each_vertex(x, y, [&](int l, int r) {
				seg.lazy_update(l, r + 1, z);
			});
		}
		else {
			LL ans = 0;
			hld.for_each_vertex(x, y, [&](int l, int r) {
				ans += seg.query(l, r + 1).sum%MOD;
				ans %= MOD;
			});
			cout << ans << "\n";
		}
	}

	return 0;
}
