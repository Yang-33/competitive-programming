#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
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

/* -----  2018/04/11  Problem: yukicoder 044  / Link: http://yukicoder.me/problems/no/044  ----- */
/* ------問題------

あなたは、Nマスのすごろくをしている。
毎ターン「１」または「２」前に進むことができる。
あなたは最初「０」のマスのスタートにいる。

ちょうどNマスに行く方法は何パターンありますか？


-----問題ここまで----- */
/* -----解説等-----

状態の遷移がとてもわかり易い。
あるマスへの到達は、1,2歩前からのみ。
dp(i):=iにたどり着くまでの組み合わせ で解ける。
提出したときにFibonacci numberであることに気がついた。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VL dp(N + 1, 0);
	dp[0] = dp[1] = 1;
	FOR(i, 2, N + 1) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	ans = dp[N];
	cout << ans << "\n";

	return 0;
}
