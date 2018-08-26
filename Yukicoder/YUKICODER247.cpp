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
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/08/26  Problem: yukicoder 247  / Link: http://yukicoder.me/problems/no/247  ----- */
/* ------問題------

関数f(x1,x2,…,xN)=∑i=1Naixi=a1x1+a2x2+⋯+aNxN とする。
この時f(x1,x2,…,xN)=Cの制約下での ∑i=1Nxiの最小値を求めてください。
ただし、xiは非負の整数変数であり、ai,Cは自然数の定数であるとする。
この時、非負の整数解がなければ−1を出力してください。

-----問題ここまで----- */
/* -----解説等-----

基本的なDP
dp[i]:=iをつくるのに必要なXの個数として、個数制限なしのDPをすればよい。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int C, N; cin >> C >> N;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	VL dp(C + 1, LINF);
	dp[0] = 0;
	FOR(i, 0, N) {
		FOR(c, 0, C-a[i]+1) {
			dp[c + a[i]] = min(dp[c + a[i]], dp[c] + 1);
		}

	}
	LL ans = dp[C];
	if (ans == LINF)ans = -1;
	cout << ans << "\n";

	return 0;
}
