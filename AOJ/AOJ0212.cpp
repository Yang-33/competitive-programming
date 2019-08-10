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

/* -----  2019/08/04  Problem: AOJ 0212 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0212  ----- */

VVL Dijkstra(const vector<vector<PLL>>& G, int s, int C) {
	VVL dist(SZ(G), VL(C + 1, LINF));
	using tp = tuple<LL, LL, LL>;
	priority_queue<tp, vector<tp>, greater<tp>> que;
	dist[s][0] = 0;
	que.push(tp(0LL, s, 0));

	while (!que.empty()) {
		LL d, v, c;
		tie(d, v, c) = que.top(); que.pop();
		if (d > dist[v][c]) continue;

		FOR(i, 0, (int)G[v].size()) {
			int nv = G[v][i].first;
			if (c != C)
				if (dist[nv][c + 1] > dist[v][c] + G[v][i].second / 2) {
					dist[nv][c + 1] = dist[v][c] + G[v][i].second / 2;
					que.push(tp(dist[nv][c + 1], nv, c + 1));
				}
			if (dist[nv][c] > dist[v][c] + G[v][i].second) {
				dist[nv][c] = dist[v][c] + G[v][i].second;
				que.push(tp(dist[nv][c], nv, c));
			}
		}
	}
	return dist;
}


int main() {
	int C, N, M, S, D;
	while (cin >> C >> N >> M >> S >> D, C) {
		S--, D--;
		vector<vector<PLL>>G(N);
		FOR(i, 0, M) {
			int a, b, c;
			cin >> a >> b >> c; a--, b--;
			G[a].push_back(PLL(b, c));
			G[b].push_back(PLL(a, c));
		}
		VVL dist = Dijkstra(G, S, C);
		LL ans = LINF;
		FOR(i, 0, C + 1) {
			ans = min(ans, dist[D][i]);
		}
		cout << ans << "\n";
	}

	return 0;
}
