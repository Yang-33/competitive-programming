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

/* -----  2019/01/06  Problem: EDU_DP X / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

順序関係が必要なものについて、意味わからんやつは比較関数を考えると良い
>> 極大目指してswapしていくときの比較関数が実は全順序なので順序が決められてDPできるというパターンは典型
そうだねとなった

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	using tp = tuple<LL, LL, LL, LL>;
	vector<tp>a(N);
	FOR(i, 0, N) {
		LL w, s, v; cin >> w >> s >> v;
		a[i] = tp(w + s, w, s, v);
	}
	SORT(a);
	VVL dp(N + 1, VL(20004, 0));
	FOR(i, 0, N) {
		LL w, s, v;
		tie(ignore, w, s, v) = a[i];
		FOR(ww, 0, 20004) {
			if (ww <= s && ww + w < 20004)
				dp[i + 1][ww + w] = max(dp[i + 1][ww + w], dp[i][ww] + v);
			dp[i + 1][ww] = max(dp[i + 1][ww], dp[i][ww]);
		}
	}
	FOR(i, 0, 20004) {
		ans = max(ans, dp[N][i]);
	}
	cout << ans << "\n";

	return 0;
}
