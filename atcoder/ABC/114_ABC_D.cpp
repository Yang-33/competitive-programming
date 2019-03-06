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

/* -----  2019/02/27  Problem: ABC 114 D / Link: http://abc114.contest.atcoder.jp/tasks/abc114_d  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	map<int, int>Prime;
	FOR(i, 1, N + 1) {
		LL x = i;
		FOR(d, 2, i + 1) {
			while (x%d == 0) {
				Prime[d]++;
				x /= d;
			}
		}
	}
	map<LL, LL>dp;
	dp[1] = 1;
	for (auto it : Prime) {
		map<LL, LL>nx = dp;
		for (auto odp : dp) {
			FOR(k, 1, it.second + 1) {
				if (odp.first*(k + 1) <= 75)
					nx[odp.first*(k + 1)] += odp.second;
			}
		}
		nx.swap(dp);
	}
	LL ans = dp[75];
	cout << ans << "\n";

	//{ // 厳しくなければこれは書きたくないね
	//VI pidx;
	//for (auto it : Prime) {
	//	pidx.push_back(it.first);
	//}
	// 
	//	FOR(i, 0, SZ(pidx)) {
	//		FOR(j, i + 1, SZ(pidx)) {
	//			FOR(k, 0, SZ(pidx)) { //  5 5 3
	//				if (k == i || k == j)continue;
	//				if (Prime[pidx[i]] >= 4 && Prime[pidx[j]] >= 4 && Prime[pidx[k]] >= 2) {
	//					ans++;
	//				}
	//			}
	//			// 25 3
	//			if (Prime[pidx[i]] >= 24 && Prime[pidx[j]] >= 2) {
	//				ans++;
	//			}
	//			if (Prime[pidx[i]] >= 2 && Prime[pidx[j]] >= 24) {
	//				ans++;
	//			}
	//			// 15 5
	//			if (Prime[pidx[i]] >= 14 && Prime[pidx[j]] >= 4) {
	//				ans++;
	//			}
	//			if (Prime[pidx[i]] >= 4 && Prime[pidx[j]] >= 14) {
	//				ans++;
	//			}

	//		}
	//		// 75
	//		if (Prime[pidx[i]] >= 74)ans++;
	//	}
	//}
	return 0;
}
