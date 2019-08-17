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

/* -----  2019/08/17  Problem: AOJ 0232 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0232  ----- */


int main() {
	int R, Y, Z;
	while (cin >> R >> Y >> Z, R) {
		vector<int> roulette(R);
		for (int i = 0; i < R; ++i) {
			cin >> roulette[i];
		}
		vector<PII>masu(Y + 1, PII(0, 0)); {
			FOR(i, 0, Z) {
				int n, e, a; cin >> n >> e >> a;
				masu[n] = { e,a }; // type, value
			}
		}
		vector<vector<double>>dp(Y + 1, vector<double>(Y * 100 + 1, 0));
		dp[0][0] = 1;
		FOR(i, 0, Y) {
			FOR(mo, 0, Y * 100) {
				FOR(r, 0, R) {
					int nx_i = i + roulette[r];
					int nx_mo = mo;
					if (masu[i].first == 1) { // step
						nx_i += masu[i].second;
					}
					else if (masu[i].first == 2) { // earn
						nx_mo += masu[i].second;
					}
					else if (masu[i].first == 3) { // pay
						nx_mo -= masu[i].second;
					}
					nx_mo = max(nx_mo, 0);
					nx_i = min(nx_i, Y);
					dp[nx_i][nx_mo] += dp[i][mo] * (1.0 / R);
				}
			}
		}
		double ans = 0;
		FOR(y, 0, 100 * Y + 1) {
			ans += dp[Y][y] * y;
		}
		cout << (int)ans << "\n";

	}


	return 0;
}
