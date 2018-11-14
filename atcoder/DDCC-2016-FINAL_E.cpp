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

/* -----  2018/11/14  Problem: DDCC-2016-FINAL_E / Link: https://beta.atcoder.jp/contests/ddcc2016-final/tasks/ddcc_2016_final_e ----- */
/* ------問題------

N 頂点の根付き木が与えられます。 各頂点には 1, 2, …, N と番号がついており、頂点 1 はこの根付き木の根です。 i(1≦i≦N−1) 番目の辺は頂点 Ai と頂点 Bi をつなぐ、長さ Ci の無向辺です。
Q 個のクエリが与えられるので、順番に処理してください。 クエリには 2 種類あり、入力形式とクエリの内容は以下のとおりです。
1 v k x： 頂点 v を根とする部分木において、k 代目の頂点と k+1 代目の頂点をつなぐ辺それぞれについて、辺の長さに x を加算せよ。ここで、頂点 v は 1 代目の頂点と定義され、n 代目の頂点の直接の子であるような頂点は n+1 代目の頂点と定義される。
2 u v： 頂点 u から頂点 v への最短経路長を求めよ。

-----問題ここまで----- */
/* -----解説等-----

二次元クエリに帰着可能
座標圧縮した2Dsegtreeを用いれば、いつもの(preorder,depth)を操作することになる。
線分を縦に追加、(in[v])のall xの和がほしいので、これを実装すればよい。

----解説ここまで---- */

struct LCAT {
	int N;
	int it;
	vector<vector<PII>>table;
	vector<int>id;
	vector<vector<int>>G;
	LCAT(int N) :N(N), it(0), table(18, vector<PII>(2 * N)), id(N), G(N) {}
	void add_edge(int a, int b) {
		G[a].push_back(b);
		G[b].push_back(a);
	}
	void build(int root) {
		dfs(root, -1, 0);
		int m = (N << 1) - 1;
		int h = 31 - __builtin_clz(m);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j + (1 << i) < m; j++) {
				table[i + 1][j] = min(table[i][j], table[i][j + (1 << i)]);
			}
		}
	}
	void dfs(int v, int p, int d) {
		id[v] = it;
		table[0][it++] = { d, v };
		for (auto to : G[v]) {
			if (to == p)continue;
			dfs(to, v, d + 1);
			table[0][it++] = { d, v };
		}
	}
	int lca(int u, int v) {
		u = id[u], v = id[v];
		if (u > v) swap(u, v);
		int b = 31 - __builtin_clz(v + 1 - u);
		return min(table[b][u], table[b][v + 1 - (1 << b)]).second;
	}
};
PII et[100005];
void calc(const vector<vector<PLL>>&G, int root = 0) {
	int k = 0;
	stack<PII> s;
	s.push(PII(root, -1));
	while (!s.empty()) {
		PII q = s.top(); s.pop();
		int x = q.first, p = q.second;
		if (x < 0 || !x&&p>0) {
			et[-x].second = k;
			continue;
		}
		s.push(PII(-x, -p));
		et[x].first = k++;
		for (auto it : G[x]) {
			int y = it.first;
			if (y == p) continue;
			s.push(PII(y, x));
		}
	}
}
void dfs(int v, int p, int dep, LL val, const vector<vector<PLL>>&G, VI&depth, VL&sum) {
	depth[v] = dep;
	sum[v] = val;
	for (PLL nx : G[v]) {
		if (nx.first != p) {
			dfs(nx.first, v, dep + 1, val + nx.second, G, depth, sum);
		}
	}
}

// 1*H のupdate,1*Wのqueryを発行可能な2DSegmentTree
// init: Yを入れる
// update(a,b,low,val): y=[a,b),x=lowをvalでupdateする。
// get(k,h): y=k,x=[0,h]を回収する
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	vector<vector<PLL>>G(N);
	LCAT tree(N);
	FOR(i, 0, N - 1) {
		int a, b, c; cin >> a >> b >> c;
		a--, b--;
		G[a].push_back(PLL(b, c));
		G[b].push_back(PLL(a, c));
		tree.add_edge(a, b);
	}
	tree.build(0);
	calc(G, 0);
	VI depth(N, 0);
	VL sum(N, 0);
	dfs(0, -1, 0, 0, G, depth, sum);

	SegmentTree2D<LL> seg(N); // ref:lib/datastructure/segmenttree2DNarrowRectangle
	FOR(i, 0, N) {
		seg.set(et[i].first, depth[i]);
	}
	seg.build();
	int Q; cin >> Q;
	FOR(_, 0, Q) {
		int t; cin >> t;
		if (t == 1) { // add
			int v, k, x; cin >> v >> k >> x;
			v--;
			seg.update(et[v].first, et[v].second, depth[v] + k, x);
		}
		else { //query
			int u, v; cin >> u >> v;
			u--, v--;
			LL Uroot = seg.get(et[u].first, depth[u]) + sum[u];
			LL Vroot = seg.get(et[v].first, depth[v]) + sum[v];
			int lca = tree.lca(u, v);
			LL LCAroot = seg.get(et[lca].first, depth[lca]) + sum[lca];
			LL ans = Uroot + Vroot - 2 * LCAroot;
			cout << ans << "\n";

		}
	}
	return 0;
}
