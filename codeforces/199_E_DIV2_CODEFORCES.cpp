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

/* -----  2018/11/20  Problem: 199_e_div2_codeforces / Link: https://codeforces.com/contest/342/problem/E  ----- */
/* ------問題------

N頂点の木がある。0以外の頂点は青色になっている。0は赤。
以下のクエリを処理せよ
1. 頂点vをblueからredにする
2. 頂点vにもっとも近いredの頂点との距離を求める。

-----問題ここまで----- */
/* -----解説等-----

重心分解では同心円状に伝播できる。(わりと特殊な用途らしい)
高さはlogNなので頂点まで登る、をしても良い

----解説ここまで---- */

struct CentroidDecomposition {
	int N;
	vector<vector<int>> E, child;
	vector<int> sz, vis, P;
	int root;
	void init(int n) {
		N = n;
		E.clear(); E.resize(N);
		sz.clear(); sz.resize(n);
		vis.clear(); vis.resize(n);
		P.clear(); P.resize(n);
		child.clear(); child.resize(n);
	}
	void add_edge(int a, int b) {
		E[a].push_back(b); E[b].push_back(a);
	}

	void szdfs(int v, int pa = -1) {
		sz[v] = 1;
		for (auto &w : E[v]) {
			if (vis[w] || w == pa)continue;
			szdfs(w, v);
			sz[v] += sz[w];
		}
	}
	int cendfs(int v, int pa, int tot) {
		for (auto &w : E[v]) {
			if (vis[w] or w == pa) continue;
			if (2 * sz[w] > tot)
				return cendfs(w, v, tot);
		}
		return v;
	}
	int makeCD(int v, int par = -1) {
		szdfs(v);
		v = cendfs(v, -1, sz[v]);
		P[v] = par;
		vis[v] = true;
		for (auto &w : E[v]) {
			if (!vis[w])
				makeCD(w, v);
		}
		return v;
	}
	void build() {
		root = makeCD(0);
		FOR(i, 0, N) {
			if (0 <= P[i])
				child[P[i]].push_back(i);
		}
	}
};

struct LCAT {
	int N;
	int it;
	vector<vector<PII>>table;
	vector<int>id;
	vector<vector<int>>G;
	vector<int>dist;
	LCAT(int N) :N(N), it(0), table(18, vector<PII>(2 * N)), id(N), G(N), dist(N, 0) {}
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
		if (p == -1) { dist[v] = 0; }
		else { dist[v] = dist[p] + 1; }
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
	int distance(int u, int v) {
		return dist[u] + dist[v] - 2 * dist[lca(u, v)];
	}
};

int read() { int in; scanf("%d",&in); return in; }
int main() {
	int N = read(), Q = read();
	static CentroidDecomposition tree; tree.init(N);
	static LCAT lcatree(N);
	FOR(i, 0, N - 1) {
		int a = read() - 1, b = read() - 1;
		tree.add_edge(a, b);
		lcatree.add_edge(a, b);
	}
	tree.build();
	lcatree.build(0);
	VI dist(N, INF);
	auto update = [&dist](int v) {
		int u = v;
		while (u >= 0) {
			dist[u] = min(dist[u], 0 + lcatree.distance(u, v));
			u = tree.P[u];
		}
	};
	auto query = [&dist](int v) {
		int ret = INF;
		int u = v;
		while (u >= 0) {
			ret = min(ret, dist[u] + lcatree.distance(u, v));
			u = tree.P[u];
		}
		return ret;
	};
	update(0);
	FOR(_, 0, Q) {
		int t = read(), v = read() - 1;
		if (t == 1) {
			update(v);
		}
		else {
			printf("%d\n", query(v));
		}
	}

	return 0;
}
