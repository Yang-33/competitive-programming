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

/* -----  2019/04/04  Problem: ABC 044 C / Link: http://abc044.contest.atcoder.jp/tasks/abc044_c  ----- */

LL dp[51][51][2503];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, A; cin >> N >> A;
	vector<LL> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	// A*kにしたい
	dp[0][0][0] = 1;
	FOR(i, 0, N) {
		FORR(k, N - 1, 0 - 1) {
			FOR(p, 0, 2500 - a[i] + 1) {
				dp[i + 1][k + 1][p + a[i]] += dp[i][k][p];
				dp[i + 1][k][p] += dp[i][k][p];
			}
		}
	}
	LL ans = 0LL;
	FOR(i, 1, N + 1) {
		ans += dp[N][i][i*A];
	}
	DD(de(ans))
		cout << ans << "\n";

	return 0;
}
