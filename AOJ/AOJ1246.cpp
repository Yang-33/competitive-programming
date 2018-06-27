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

/* -----  2018/06/30  Problem: AOJ 1246 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/1246  ----- */
/* ------問題------

ホテルの予約があり、2部屋ある。
予定[si,ti]で、コストwiを得ることができる。
選択を最適にすると最大どれだけのコストを得ることができるか。

-----問題ここまで----- */
/* -----解説等-----

絵を書くと重み付き区間スケジューリング的なものを重複2で行いたいことが分かる。
蟻本を読んでいると最小費用流でこれを見たことがあるので、再現すれば良い。
蟻本は辺集合の端点を含まないが、これを今回の問題に適用すると[s,t]は、[s-1,t]に張ることに対応する。

ICPC練習なのに写経してないやつがいてキレました。(許した)

----解説ここまで---- */

typedef long long PD_Type;
const PD_Type PD_INF = 1 << 30;

struct Primal_Dual {
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

		FOR(k, 0, V) {
			FOR(i, 0, V) {
				FOR(j, 0, (int)graph[i].size()) {
					edge &e = graph[i][j];
					if (e.cap == 0)continue;
					potential[e.to] = min(potential[e.to], potential[i] + e.cost);
				}
			}
		}


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

	int N;
	while (cin >> N, N) {
		VI L(N), R(N), W(N);
		FOR(i, 0, N) {
			cin >> L[i] >> R[i] >> W[i];
		}
		Primal_Dual F(400);
		FOR(i, 0, N) {
			F.add_edge(L[i] - 1, R[i], 1, -W[i]);
		}
		FOR(i, 0, 365) {
			F.add_edge(i, i + 1, 10, 0);
		}
		LL ans = -F.min_cost_flow(0, 365, 2);
		cout << ans << endl;
	}

	return 0;
}
