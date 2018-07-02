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

/* -----  2018/07/02  Problem: AOJ 2581 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2581  ----- */
/* ------問題------

長さnの順列p = (p1 p2 … pn)が与えられる。i番目の要素とj番目の要素を入れ替える操作には(pi+pj)×|i−j|のコストを要する。このとき、上記の入れ替え操作のみを用いてpを完全順列にするために必要な最小のコストを求めよ。
ただし、順列qが完全順列であるとは、1≤i≤nについて、qi≠iが成り立つことを言う。たとえば、(5 3 1 2 4)は完全順列であるが、(3 2 5 4 1)は4番目の数が4なので完全順列ではない。

-----問題ここまで----- */
/* -----解説等-----

割当問題に見える。
コストは分割することができて、端から移動させたときに最適な場所があったとして
ここまでの中継地点を任意の場所に取れる。
したがって式のpjは外すことができ、コストはpi*(i-to)になる。

----解説ここまで---- */

/* 最小費用流 非負 */
typedef long long PD_Type;
const PD_Type PD_INF = 1 << 30;

struct Primal_Dual{
	typedef pair< PD_Type, int > pii;

	struct edge{
		int to, rev;
		PD_Type	cap, cost;
		edge() {}
		edge(int to, PD_Type cap, PD_Type cost, int rev) :to(to), cap(cap), cost(cost), rev(rev) {}

	};
	vector< vector< edge > > graph;
	vector< int > prevv, preve;
	vector< PD_Type > potential, min_cost;
	Primal_Dual(int V) : graph(V) {}

	void add_edge(int from, int to, PD_Type cap, PD_Type cost){
		graph[from].push_back(edge(to, cap, cost, (int)graph[to].size()));
		graph[to].push_back(edge(from, 0, -cost, (int)graph[from].size() - 1));
	}

	PD_Type min_cost_flow(int s, int t, int f){
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


	int N; cin >> N;
	VI p(N);
	FOR(i, 0, N) {
		cin >> p[i];
	}
	Primal_Dual MCF(2 * N + 2);
	int S = 2 * N; int T = S + 1;

	FOR(i, 0, N) {
		MCF.add_edge(S, i, 1, 0);
		MCF.add_edge(i + N, T, 1, 0);
	}
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			if (p[i] != j + 1) {
				MCF.add_edge(i, N + j, 1, p[i] * abs(i - j));
			}
		}
	}


	cout << MCF.min_cost_flow(S, T, N) << endl;


	return 0;
}
