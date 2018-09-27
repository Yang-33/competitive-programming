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

/* -----  2018/09/27  Problem: yukicoder 286  / Link: http://yukicoder.me/problems/no/286  ----- */
/* ------問題------

N 個の商品がそれぞれ定価Mi円で売られているお店がある。

このお店で商品を購入する時、「今まで買った商品の"定価"の金額を合計して1000で割った余り（Mod 1000）の料金分」を購入ごとに値引きしてくれるという。
ただし、購入する商品が値引き後0円未満になる場合は、0円で購入する。

あなたは、同じものを買わずにN個の商品を全て購入したいと思っている。

このときN個の商品をすべて購入するときに、最小の購入金額の合計はいくらか計算してください。
商品を購入する順番は自由であるが、同時には購入できず1つずつしか購入できない。

-----問題ここまで----- */
/* -----解説等-----

bitdpを書くだけ。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;  cin >> N;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	VI dp(1 << N, INF);
	dp[0] = 0;
	FOR(state, 0, 1 << N) {
		int sums = 0;
		FOR(i, 0, N) {
			if (state & 1 << i) {
				sums += a[i];
			}
		}
		FOR(i, 0, N) {
			if (state & 1 << i)continue;
			int adds = max(0, a[i] - sums % 1000);
			dp[state|1<<i] = min(dp[state|1<<i], dp[state] + adds);
		}
	}
	ans = dp[(1 << N) - 1];
	cout << ans << "\n";

	return 0;
}
