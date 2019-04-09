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

/* -----  2019/04/09  Problem: ABC 021 C / Link: http://abc021.contest.atcoder.jp/tasks/abc021_c  ----- */

pair<VL, VL> Dijkstra(vector<vector<PLL>>& G, int s) {
	int NN = (int)G.size();
	VL dist(NN, LINF);
	VL path(NN, 0);

	path[s] = 1;

	typedef pair<PLL, int> TP;
	priority_queue<TP, vector<TP>, greater<TP>> que;
	que.push(TP(PLL(0LL, s), s));

	while (!que.empty()) {
		TP p = que.top(); que.pop();
		int v, from;  long long d;
		d = p.first.first, v = p.first.second, from = p.second;
		if (d > dist[v]) continue;
		if (d == dist[v]) {
			path[v] += path[from];
			path[v] %= MOD;
			continue;
		}
		else {
			path[v] = path[from];
			dist[v] = d;
		}
		FOR(i, 0, (int)G[v].size()) {
			int nv = G[v][i].first;
			if (dist[nv] >= dist[v] + G[v][i].second) {
				que.push(TP(PLL(dist[v] + G[v][i].second, nv), v));
			}
		}
	}
	return pair<VL, VL>(dist, path);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	int S, T; cin >> S >> T;
	S--, T--;
	int M; cin >> M;
	vector<vector<PLL>>G(N);
	FOR(i, 0, M) {
		int a, b; cin >> a >> b;
		a--, b--;
		G[a].push_back(PLL(b, 1));
		G[b].push_back(PLL(a, 1));
	}
	auto it = Dijkstra(G, S);
	LL ans = it.second[T];

	cout << ans << "\n";

	return 0;
}
