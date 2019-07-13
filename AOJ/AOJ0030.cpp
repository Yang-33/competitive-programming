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

/* -----  2019/07/13  Problem: AOJ 0030 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0030  ----- */

int dp[11][11][201];
int main() {

	// dp(N,k,s):=総数
	dp[0][0][0] = 1;
	FOR(n, 0, 10) {
		FOR(k, 0, 10) {
			FOR(s, 0, 101) {
				dp[n + 1][k][s] += dp[n][k][s];
				dp[n + 1][k + 1][s + n] += dp[n][k][s];
			}
		}
	}
	int n, s;
	while (cin >> n >> s, n) {
		LL ans = dp[10][n][s];
		cout << (ans) << "\n";
	}

	return 0;
}
