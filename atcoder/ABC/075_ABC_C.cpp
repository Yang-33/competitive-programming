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

/* -----  2019/03/16  Problem: ABC 075 C / Link: http://abc075.contest.atcoder.jp/tasks/abc075_c  ----- */
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
struct Lowlink {
	UnionFind uf;
	vector<int> low, ord, used, parent;
	int root, k;
	Lowlink(int V, int Root) :uf(V), low(V), ord(V), used(V), parent(V), root(Root), k(0) {}

	void lowlink(int v, int p, int &k, vector<vector<int>>& G) {
		used[v] = true; //visited
		low[v] = ord[v] = k; k++;
		for (int i = 0; i < (int)G[v].size(); i++) {
			int u = G[v][i];
			if (used[u] == 0) {
				parent[u] = v;
				lowlink(u, v, k, G);
				low[v] = min(low[v], low[u]);
				if (ord[v] >= low[u])uf.unionSet(v, u);
			}
			else if (u != p) {
				low[v] = min(low[v], ord[u]);
			}
		}
	}
};
struct Artivcal_points : Lowlink {
	vector<pair<int, int> > edges;
	Artivcal_points(int V, int Root) :Lowlink(V, Root) {}

	void get_bridge(vector<int>& points, vector<pair<int, int> >& bridges, vector<vector<int> >& G) {
		Lowlink::lowlink(root, -1, k, G);
		{
			for (int v = 0; v < (int)G.size(); v++) {
				for (int i = 0; i < (int)G[v].size(); i++) {
					int u = G[v][i];
					if (ord[v] < low[u]) {
						if (u > v)
							bridges.push_back(pair<int, int>(v, u));
						else bridges.push_back(pair<int, int>(u, v));
					}
				}
			}
			sort(bridges.begin(), bridges.end());
			bridges.erase(unique(bridges.begin(), bridges.end()), bridges.end());
		}
	}
};


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	VI p;
	vector<PII> br;
	VVI G(N);
	FOR(i, 0, M) {
		int a, b; cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	Artivcal_points a(N, 0);
	a.get_bridge(p, br, G);

	LL ans = SZ(br);


	cout << (ans) << "\n";

	return 0;
}
