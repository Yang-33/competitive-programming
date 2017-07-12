#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int i = s;i < e;i++)
#define debug(x) cout << #x << ": " << x << endl

const int INF = 1e9;
const ll LINF = 1e16;
/* -----  2017/07/12  Problem: AOJ 2828 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2828  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

先に続いて。
負辺ではると負コストが答えになってしまうので、
先に体積分を加算しておいてこれがどれだけ打ち消すことができ逆にどれを打ち消せないか、とみれば
負の辺でもうれしい気持ちになる。

----解説ここまで---- */

struct Primal_Dual
{
	const int INF = 1 << 30;
	typedef pair< int, int > pii;

	struct edge
	{
		int to, cap, cost, rev;
		edge() {}
		edge(int to, int cap, int cost, int rev) :to(to), cap(cap), cost(cost), rev(rev) {}

	};
	vector< vector< edge > > graph;
	vector< int > potential, min_cost, prevv, preve;

	Primal_Dual(int V) : graph(V) {}

	void add_edge(int from, int to, int cap, int cost)
	{
		graph[from].push_back(edge(to, cap, cost, (int)graph[to].size()));
		graph[to].push_back(edge(from, 0, -cost, (int)graph[from].size() - 1));
	}

	int min_cost_flow(int s, int t, int f)
	{
		int V = graph.size(), ret = 0;
		priority_queue< pii, vector< pii >, greater< pii > > que;
		potential.assign(V, 0);
		preve.assign(V, -1);
		prevv.assign(V, -1);

		while (f > 0) {
			min_cost.assign(V, INF);
			que.push(pii(0, s));
			min_cost[s] = 0;

			while (!que.empty()) {
				pii p = que.top();
				que.pop();
				if (min_cost[p.second] < p.first) continue;
				for (int i = 0; i < graph[p.second].size(); i++) {
					edge &e = graph[p.second][i];
					int nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];
					if (e.cap > 0 && min_cost[e.to] > nextCost) {
						min_cost[e.to] = nextCost;
						prevv[e.to] = p.second, preve[e.to] = i;
						que.push(pii(min_cost[e.to], e.to));
					}
				}
			}
			if (min_cost[t] == INF) return -1;
			for (int v = 0; v < V; v++) potential[v] += min_cost[v];
			int addflow = f;
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
};// Primal_Dual mnf(仕様頂点数), mnf.add_edge(a,b,cap,cost), mnf.min_cost_flow(s,t,f)
// miuns...->先に辺の全費用を求め、sum+mctとすればよい。

int N;

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	while (cin >> N, N) {
		Primal_Dual mnf(N * 2 + 2);
		vector<int> X(N);
		vector<int> Y(N);
		vector<int> Z(N);
		for (int i = 0; i < N; i++) {
			cin >> X[i] >> Y[i] >> Z[i];
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				vector<int> hen1(3);
				vector<int> hen2(3);
				hen1[0] = X[i]; hen1[1] = Y[i]; hen1[2] = Z[i];
				hen2[0] = X[j]; hen2[1] = Y[j]; hen2[2] = Z[j];
				sort(hen1.begin(), hen1.end());
				sort(hen2.begin(), hen2.end());

				bool f = false;
				for (int k = 0; k < 3; k++) {
					if (hen1[k] >= hen2[k]) { f = true; break; }
				}

				if (!f) {
					mnf.add_edge(i, N + j, 1, -X[i] * Y[i] * Z[i]);//変更点！！
				}
			}
		}
		int s = N * 2, t = 2 * N + 1;
		FOR(i, 0, N)mnf.add_edge(s, i, 1, 0);
		FOR(i, 0, N)mnf.add_edge(i + N, t, 1, 0);
		FOR(i, 0, N)mnf.add_edge(i, t, 1, 0);
		ll ans = 0;
		FOR(i, 0, N)ans += X[i] * Y[i] * Z[i];
		cout << ans+mnf.min_cost_flow(s, t, N) << endl;
	}
}