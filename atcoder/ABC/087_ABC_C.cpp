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

/* -----  2019/03/11  Problem: ABC 087 C / Link: http://abc087.contest.atcoder.jp/tasks/abc087_c  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	VVL a(2, VL(N));
	FOR(i, 0, 2) {
		FOR(j, 0, N) {
			cin >> a[i][j];
		}
	}
	VVL dp(2, VL(N + 1, 0));

	FOR(j, 0, N) {
		dp[0][j] += a[0][j];
		dp[0][j + 1] = max(dp[0][j + 1], dp[0][j]);
		dp[1][j] = max(dp[1][j], dp[0][j]);

		dp[1][j] += a[1][j];
		dp[1][j + 1] = max(dp[1][j + 1], dp[1][j]);
	}
	LL ans = dp[1][N - 1];

	cout << (ans) << "\n";

	return 0;
}
