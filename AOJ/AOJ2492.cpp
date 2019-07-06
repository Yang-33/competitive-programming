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

/* -----  2019/07/07  Problem: AOJ 2492 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2492  ----- */

VL Dijkstra(vector<vector<PLL>>& G, int s) {
	VL dist(SZ(G), LINF);
	dist[s] = 0;
	priority_queue<PLL, vector<PLL>, greater<PLL>> que;
	que.push(PLL(0LL, s));

	while (!que.empty()) {
		PLL p = que.top(); que.pop();
		int v; long long d;
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
	LL N; cin >> N;
	cin.ignore();
	vector<string> s(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, s[i]);
		s[i].pop_back();
	}
	vector<vector<PLL>>G(N + 1); {
		map<string, int>labelpos;
		FOR(i, 0, N) {
			if (s[i].find("goto") == string::npos) {
				labelpos[s[i]] = i;
			}
		}
		FOR(i, 0, N) {
			// if goto, cost 1 to next, cost 0 that label
			// else cost 0
			if (s[i].find("goto") == string::npos) { // not goto
				G[i].push_back(PLL(i + 1, 0));
			}
			else {
				G[i].push_back(PLL(i + 1, 1));
				string label = s[i].substr(5);
				G[i].push_back(PLL(labelpos[label],0));
			}
		}
	}
	auto res = Dijkstra(G, 0);
	LL ans = res.back();
	cout << (ans) << "\n";

	return 0;
}
