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

/* -----  2019/07/14  Problem: AOJ 0070 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0070  ----- */

int main() {
	VVL dp(1 << 10, VL(500, 0));
	dp[0][0] = 1;
	FOR(state, 0, 1 << 10) {
		FOR(sum, 0, 400) {
			if (!dp[state][sum])continue;
			int c = __builtin_popcount(state);
			c++;
			FOR(i, 0, 10) {
				if (state & 1 << i)continue;
				dp[state | (1 << i)][sum + c * i] += dp[state][sum];
			}
		}
	}

	int N, S;
	while (cin >> N >> S) {
		LL ans = 0;
		FOR(state, 0, 1 << 10) {
			int c = __builtin_popcount(state);
			if (c != N)continue;
			if (S < 500)ans += dp[state][S];
		}
		cout << ans << "\n";
	}
	return 0;
}