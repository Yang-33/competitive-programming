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

/* -----  2019/04/09  Problem: ABC 022 C / Link: http://abc022.contest.atcoder.jp/tasks/abc022_c  ----- */


VL Dijkstra(vector<vector<PLL>>& G, int s) {
	VL dist(SZ(G), LINF);
	dist[s] = 0;
	priority_queue<PLL, vector<PLL>, greater<PLL>> que;
	que.push(PLL(0LL, s));

	while (!que.empty()) {
		PLL p = que.top(); que.pop();
		int v; /* 頂点*/ long long d; /* 頂点vまでの距離 */
		tie(d, v) = p;

		if (d > dist[v]) continue;

		FOR(i, 0, (int)G[v].size()) {
			int nv = G[v][i].first;
			if (dist[nv] > dist[v] + G[v][i].second) {
				dist[nv] = dist[v] + G[v][i].second;
				que.push(PLL(dist[nv], nv));
			}
		}
	}
	return dist;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	vector<vector<PLL>>G(N);
	vector<vector<PLL>>G2(N);
	for (int i = 0; i < M; ++i) {
		int a, b, c; cin >> a >> b >> c;
		a--, b--;
		if (!a || !b) {
			G2[a].push_back(PLL(b, c));
			G2[b].push_back(PLL(a, c));
		}
		else {
			G[a].push_back(PLL(b, c));
			G[b].push_back(PLL(a, c));

		}
	}
	LL ans = LINF;
	for (auto s : G2[0]) {
		VL dist = Dijkstra(G, s.first);
		for (auto t : G2[0]) {
			if (s == t)continue;
			DD(de(s.first, t.first, dist[t.first], s.second, t.second));
			ans = min(ans, s.second + dist[t.first] + t.second);
		}
	}
	if (ans == LINF)ans = -1;
	cout << ans << "\n";

	return 0;
}
