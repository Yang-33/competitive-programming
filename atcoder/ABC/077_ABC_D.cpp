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

/* -----  2019/03/16  Problem: ABC 077 D / Link: http://abc077.contest.atcoder.jp/tasks/abc077_d  ----- */




int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL K; cin >> K;
	VL dist(K, LINF);
	priority_queue<PLL, vector<PLL>, greater<PLL>>pq;
	FOR(i, 1, 10) {
		dist[i%K] = min(dist[i%K], (LL)i);
		pq.push(PLL(dist[i%K], i%K));
	}
	while (!pq.empty()) {
		auto n = pq.top(); pq.pop();
		if (dist[n.second] < n.first)continue;
		FOR(i, 0, 10) {
			LL nxn = (10 * n.second + i) % K;
			LL nxw = n.first + i;
			if (dist[nxn] > nxw) {
				dist[nxn] = nxw;
				pq.push(PLL(nxw, nxn));
			}
		}
	}


	LL ans = dist[0];
	cout << ans << endl;

	return 0;
}