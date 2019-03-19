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

/* -----  2019/03/19  Problem: ABC 070 D / Link: http://abc070.contest.atcoder.jp/tasks/abc070_d  ----- */

struct LCAT {
	int N;
	int it;
	int Root;
	vector<vector<PII>>table;
	vector<int>id;
	vector<vector<pair<int, LL>>>G;
	vector<LL>distarray;
	LCAT(int N) :N(N), it(0), Root(0), table(18, vector<PII>(2 * N)), id(N), G(N), distarray(N) {}
	void add_edge(int a, int b, LL c = 1) {
		G[a].emplace_back(b, c);
		G[b].emplace_back(a, c);
	}
	void build(int root) {
		Root = root;
		dfs(root, -1, 0, 0);
		int m = (N << 1) - 1;
		int h = 31 - __builtin_clz(m);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j + (1 << i) < m; j++) {
				table[i + 1][j] = min(table[i][j], table[i][j + (1 << i)]);
			}
		}
	}
	void dfs(int v, int p, int d, LL distd) {
		id[v] = it;
		distarray[v] = distd;
		table[0][it++] = { d, v };
		for (auto to : G[v]) {
			if (to.first == p)continue;
			dfs(to.first, v, d + 1, distd + to.second);
			table[0][it++] = { d, v };
		}
	}
	int lca(int u, int v) {
		u = id[u], v = id[v];
		if (u > v) swap(u, v);
		int b = 31 - __builtin_clz(v + 1 - u);
		return min(table[b][u], table[b][v + 1 - (1 << b)]).second;
	}
	LL dist(int u, int v) {
		return distarray[u] + distarray[v] - 2 * distarray[lca(u, v)];
	}
};
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	LCAT tree(N);
	FOR(i, 0, N - 1) {
		LL a, b, c; cin >> a >> b >> c;
		a--, b--;
		tree.add_edge(a, b, c);
	}
	LL Q, K; cin >> Q >> K;
	K--;
	tree.build(K);
	FOR(_, 0, Q) {
		LL a, b; cin >> a >> b;
		a--, b--;
		cout << tree.distarray[a] + tree.distarray[b] << endl;
	}

	return 0;
}
