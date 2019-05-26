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

/* -----  2019/05/26  Problem: AOJ 2608 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2608  ----- */


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

	LL N, M, S, T; cin >> N >> M >> S >> T;
	vector<vector<PLL>>G(N);
	FOR(i, 0, M) {
		int a, b; cin >> a >> b;
		a--, b--;
		G[a].push_back(PLL(b, 1));
		G[b].push_back(PLL(a, 1));
	}
	S--, T--;
	VL Sdist = Dijkstra(G, S);
	VL Tdist = Dijkstra(G, T);
	map<LL, LL>Tsum;
	FOR(i, 0, N) {
		Tsum[Tdist[i]]++;
	}
	LL D = Sdist[T];
	LL ans = 0LL;
	FOR(i, 0, N) {
		ans += Tsum[D - 2 - Sdist[i]];
	}
	cout << (ans) << "\n";

	return 0;
}
