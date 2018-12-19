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

/* -----  2018/12/19  Problem: codefestival2014_team_relay F / Link: __CONTEST_URL__  ----- */
/* ------問題------

頂点数および辺数がともに n であるような連結な無向グラフは、ループをちょうど 1 つだけ含むことが知られています。
このようなグラフが与えられるので、グラフに含まれるループの長さを求めて下さい。

-----問題ここまで----- */
/* -----解説等-----

トポロジカルソート的なノリで閉路に色を塗ればよいが、面倒なので貼った。

----解説ここまで---- */


struct UnionFind {
	vector<int> data;
	UnionFind(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

struct Tree {
	UnionFind uf;
	vector<vector<int>> g;
	vector<int> used, ord, low, comp;

	Tree(int v) : uf(v), g(v), used(v, 0), comp(v), ord(v), low(v) {}

	void add_edge(int x, int y) {
		g[x].push_back(y);
		g[y].push_back(x);
	}

	void dfs(int idx, int& k, int par = -1) {
		used[idx] = true;
		ord[idx] = k++;
		low[idx] = ord[idx];

		for (auto &to : g[idx]) {
			if (!used[to]) {
				dfs(to, k, idx);
				low[idx] = min(low[idx], low[to]);
				if (ord[idx] >= low[to]) uf.unionSet(idx, to);
			}
			else if (to != par) {
				low[idx] = min(low[idx], ord[to]);
			}
		}
	}

	int loop(int root = 0) {
		int kk = 0;
		dfs(root, kk);

		int ptr = 0;
		vector<int> color(g.size());
		for (int i = 0; i < (int)g.size(); i++) {
			if (i == uf.root(i)) color[i] = ptr++;
		}
		return ptr;
	}
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	Tree tree(N);
	FOR(i, 0, N) {
		int a, b; cin >> a >> b; a--, b--;
		tree.add_edge(a, b);
	}
	int sz = tree.loop();
	cout << N - sz + 1 << endl;

	return 0;
}