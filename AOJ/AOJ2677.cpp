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

/* -----  2019/04/29  Problem: AOJ 2677 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2677  ----- */

struct LCAT {
	int N;
	int it;
	vector<vector<PII>>table;
	vector<int>id;
	vector<vector<pair<int, LL>>>G;
	vector<LL>distarray;
	LCAT(int N) :N(N), it(0), table(18, vector<PII>(2 * N)), id(N), G(N), distarray(N) {}
	void add_edge(int a, int b, LL c = 1) {
		G[a].emplace_back(b, c);
		G[b].emplace_back(a, c);
	}
	void build(int root) {
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
	VVI G(N);
	LCAT tree(N);
	FOR(i, 1, N) {
		int p; cin >> p;
		p--;
		G[i].push_back(p);
		G[p].push_back(i);
		tree.add_edge(i, p);
	}
	FOR(i, 0, N) {
		SORT(G[i]);
	}
	tree.build(0);
	VI a;
	queue<int>q;
	VI used(N);
	q.push(0);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		if (used[v])continue;
		used[v] = 1; a.push_back(v);
		for (auto nx : G[v]) {
			q.push(nx);
		}
	}

	LL ans = 0LL;
	FOR(i, 0, N-1) {
		int s = a[i];
		int t = a[i + 1];
		ans += tree.dist(s, t);
	}

	cout << (ans) << "\n";

	return 0;
}
