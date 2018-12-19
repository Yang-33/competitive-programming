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

/* -----  2018/12/19  Problem: codefestival2014_team_relay G / Link: __CONTEST_URL__  ----- */
/* ------問題------

haruki さんは朝に弱いことで有名です。haruki さんの家には目覚まし時計が n 個あり、i 番目の目覚まし時計の音量は ai です。
haruki さんは鳴っている目覚まし時計の音量の合計が m 以上にならない限り、目を覚ますことはありません。しかしながら、必要以上に目覚まし時計をセットすると、うるさくて近所迷惑になってしまいます。
そこで、合計の音量が m 以上でかつ最小となるように目覚まし時計を選んだとき、その合計の音量を求めてください。

-----問題ここまで----- */
/* -----解説等-----

値の制約が小さいのでbool dpをする。dp(i):=合計でiとなるような選択が存在するか?
dp(M)以上が存在するかを見れば良い。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	VVL dp(N + 1, VL(50004, 0));
	dp[0][0] = 1;
	// bitsetでもOK
	FOR(i, 0, N) {
		FOR(p, 0, 50004 - a[i]) {
			dp[i + 1][p] |= dp[i][p];
			dp[i + 1][p + a[i]] |= dp[i][p];
		}
	}
	LL ans = 0;
	FOR(p, M, 50004) {
		if (dp[N][p]) {
			ans = p;
			break;
		}
	}
	if (!ans)ans = -1;
	cout << ans << endl;

	return 0;
}