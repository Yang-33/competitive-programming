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

/* -----  2019/07/14  Problem: HUPC2019day1 A / Link: __CONTEST_URL__  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VI v(4); {
		FOR(i, 0, 4) {
			cin >> v[i];
		}
	}
	VI w(4); {
		FOR(i, 0, 4) {
			cin >> w[i];
		}
	}
	VL dp(1000, LINF);
	dp[0] = 0;
	FOR(i, 0, 4) {
		FOR(ww, 0, 1000 - w[i]) {
			dp[ww + w[i]] = min(dp[ww + w[i]], dp[ww] + v[i]);
		}
	}
	LL ans = LINF;
	FOR(i, N, 1000) {
		ans = min(ans, dp[i]);
	}
	cout << (ans) << "\n";

	return 0;
}
