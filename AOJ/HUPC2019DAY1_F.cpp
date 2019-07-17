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

/* -----  2019/07/14  Problem: HUPC2019day1 F / Link: __CONTEST_URL__  ----- */

int main() {
	auto msb = [](int N) {
		return N ? 31 - __builtin_clz(N) : -INF;
	};
	LL N, K, M; cin >> N >> K >> M;
	VVL dp(2 * N + 1, VL(1 << K, 0));
	dp[0][0] = 1;
	FOR(i, 0, 2 * N) {
		FOR(state, 0, 1 << K) {
			if (state == (1 << K) - 1)continue; // k+1以上の差ができてしまう
			if ((state & 1 << (K - 1)) == 0) { // みぎ
				int nstate = (state << 1) | 1;
				dp[i + 1][nstate] += dp[i][state];
				dp[i + 1][nstate] %= M;
			}
			if (state) { // したにおく
				int nstate = (state - (1 << msb(state))) << 1;
				dp[i + 1][nstate] += dp[i][state];
				dp[i + 1][nstate] %= M;
			}
		}
	}
	LL ans = dp[2 * N][0];
	if (N == K)ans++; // よこに[1...N][N+1...2N]のやつ
	ans %= M;
	cout << ans << endl;


	return 0;
}
