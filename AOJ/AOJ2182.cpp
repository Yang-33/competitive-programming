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

/* -----  2019/06/01  Problem: AOJ 2182 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2182  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s;
	while (cin >> s, s != "0") {
		int N = SZ(s);
		VVL dp(N + 1, VL(11, 0));
		FOR(i, 0, N) {
			int a = s[i] - '0';
			FOR(j, 0, 11) {
				dp[i + 1][(j * 10 + a) % 11] += dp[i][j];
			}
			if (a)dp[i + 1][a]++;
		}
		LL ans = 0LL;
		FOR(i, 0, N + 1) {
			ans += dp[i][0];
		}
		cout << (ans) << "\n";
	}

	return 0;
}
