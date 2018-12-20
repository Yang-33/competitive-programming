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

/* -----  2018/12/21  Problem: codefestival2015_team_relay G / Link: __CONTEST_URL__  ----- */
/* ------問題------

N 種類の主菜と M 種類の副菜から料理を選んでコースを作ります。 主菜は 1 種類しか選ぶことができませんが、副菜は何種類でも選ぶことができます。 また、副菜は 1 つも選ばなくても構いません。 主菜・副菜ともにコースに入れられるのは 1 種類につき 1 つまでです。
i 番目の主菜は値段が Ai で、お客さんの評価が Bi です。
i 番目の副菜は値段が Ci で、お客さんの評価が Di です。
コース全体の値段と評価は、主菜と副菜の合計で決まります。 コースの値段を L 以下にする時、コースの評価は最大でいくつになるか求めてください。

-----問題ここまで----- */
/* -----解説等-----

副菜についてdpして、最後にどの主菜が良いのか全部試す。
dp[i]:=値段がiとなるときの満足度の最大値、として適当にdpした後、
dp[i]:=値段がi以下の満足度の最大値、となるように下から値を持ち上げる。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	LL N, M, L;
	cin >> N >> M >> L;
	VL a(N), b(N);
	FOR(i, 0, N) {
		cin >> a[i] >> b[i];
	}
	VL c(M), d(M);
	FOR(i, 0, M) {
		cin >> c[i] >> d[i];
	}
	VL dp(L + 1, 0);
	FOR(i, 0, M) {
		FORR(x, L - c[i], 0 - 1) {
			dp[x + c[i]] = max(dp[x + c[i]], dp[x] + d[i]);
		}
	}
	FOR(x, 0, L) {
		dp[x + 1] = max(dp[x + 1], dp[x]);
	}
	LL ans = 0;
	FOR(i, 0, N) {
		if (L - a[i] >= 0) {
			ans = max(ans, dp[L - a[i]] + b[i]);
		}
	}
	cout << ans << endl;

	return 0;
}