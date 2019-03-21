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
const int INF = 1e9;                          const LL LINF = 1e18;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2019/03/21  Problem: ABC 061 D / Link: http://abc061.contest.atcoder.jp/tasks/abc061_d  ----- */

struct Edge {
	int to; LL cost;
	Edge(int t, LL c = 0) : to(t), cost(c)
	{}
	bool operator>(const Edge& rhs) const {
		return cost > rhs.cost;
	}
	bool operator<(const Edge& rhs) const {
		return cost < rhs.cost;
	}

};
using Graph = vector< vector<Edge> >;

bool BellmanFord(const Graph& G, vector<LL>& d, int s) {
	const int V = G.size();
	for (int i = 0; i < V; ++i)
		d[i] = LINF;
	d[s] = 0;

	for (int lp = 0; lp <= V; ++lp) {
		for (int i = 0; i < V; ++i) {
			for (const auto& e : G[i]) {
				if (d[i] != LINF && d[e.to] > d[i] + e.cost) {
					d[e.to] = d[i] + e.cost;
					if (lp == V && e.to == V - 1)return true;
				}
			}
		}
	}
	return false;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	Graph G(N);
	FOR(i, 0, M) {
		LL a, b, c; cin >> a >> b >> c;
		a--, b--;
		G[a].push_back(Edge(b, -c));
	}
	VL dist(N);
	bool find_loop = BellmanFord(G, dist, 0);
	if (find_loop) {
		cout << "inf" << endl;
	}
	else {
		cout << -dist.back() << endl;
	}

	return 0;
}
