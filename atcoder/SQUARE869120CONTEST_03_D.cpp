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

/* -----  2019/07/09  Problem: SQUARE869120CONTEST_03 D / Link: https://atcoder.jp/contests/s8pc-3/  ----- */

typedef long long PD_Type;
const PD_Type PD_INF = 1 << 30;

struct Primal_Dual
{
	typedef pair< PD_Type, int > pii;

	struct edge {
		int to, rev;
		PD_Type	cap, cost;
		edge() {}
		edge(int to, PD_Type cap, PD_Type cost, int rev) :to(to), cap(cap), cost(cost), rev(rev) {}

	};
	vector< vector< edge > > graph;
	vector< int > prevv, preve;
	vector< PD_Type > potential, min_cost;
	Primal_Dual(int V) : graph(V) {}

	void add_edge(int from, int to, PD_Type cap, PD_Type cost) {
		graph[from].push_back(edge(to, cap, cost, (int)graph[to].size()));
		graph[to].push_back(edge(from, 0, -cost, (int)graph[from].size() - 1));
	}

	PD_Type min_cost_flow(int s, int t, int f) {
		int V = graph.size();
		PD_Type ret = 0;
		priority_queue< pii, vector< pii >, greater< pii > > que;
		potential.assign(V, 0);
		preve.assign(V, -1);
		prevv.assign(V, -1);

		while (f > 0) {
			min_cost.assign(V, PD_INF);
			que.push(pii(0, s));
			min_cost[s] = 0;

			while (!que.empty()) {
				pii p = que.top();
				que.pop();
				if (min_cost[p.second] < p.first) continue;
				for (int i = 0; i < (int)graph[p.second].size(); i++) {
					edge &e = graph[p.second][i];
					PD_Type nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];
					if (e.cap > 0 && min_cost[e.to] > nextCost) {
						min_cost[e.to] = nextCost;
						prevv[e.to] = p.second, preve[e.to] = i;
						que.push(pii(min_cost[e.to], e.to));
					}
				}
			}
			if (min_cost[t] == PD_INF) return -1;
			for (int v = 0; v < V; v++) potential[v] += min_cost[v];
			PD_Type addflow = f;
			for (int v = t; v != s; v = prevv[v]) {
				addflow = min(addflow, graph[prevv[v]][preve[v]].cap);
			}
			f -= addflow;
			ret += addflow * potential[t];
			for (int v = t; v != s; v = prevv[v]) {
				edge &e = graph[prevv[v]][preve[v]];
				e.cap -= addflow;
				graph[v][e.rev].cap += addflow;
			}
		}
		return ret;
	}
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int H, W; cin >> H >> W;
	vector<vector<LL>> a(H, vector<LL>(W));
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> a[i][j];
		}
	}
	auto V = [&](int i, int j, bool OUT) {
		return 2 * (W*i + j) + OUT;
	};
	Primal_Dual F(2 * H*W);
	const LL ff = 1e5;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			F.add_edge(V(i, j, 0), V(i, j, 1), 1, ff - a[i][j]);
			F.add_edge(V(i, j, 0), V(i, j, 1), 1, ff);
		}
	}
	FOR(i, 0, H - 1) {
		FOR(j, 0, W) {
			F.add_edge(V(i, j, 1), V(i + 1, j, 0), 2, 0);
		}
	}
	FOR(i, 0, H) {
		FOR(j, 0, W - 1) {
			F.add_edge(V(i, j, 1), V(i, j + 1, 0), 2, 0);
		}
	}


	LL ans = -(F.min_cost_flow(V(0, 0, 0), V(H - 1, W - 1, 1), 2) - 2*ff * (H + W - 1));


	cout << (ans) << "\n";

	return 0;
}
