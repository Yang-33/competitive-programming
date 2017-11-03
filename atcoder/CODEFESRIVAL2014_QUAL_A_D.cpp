#include "bits/stdc++.h"
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
#define debug(base) cerr << #base << ": " << base << endl
const int INF = 1e9;                          const LL LINF = 1e18;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/11/01  Problem: ketadp3 / Link: http://code-festival-2014-quala.contest.atcoder.jp/tasks/code_festival_qualA_d  ----- */
/* ------問題------

高橋君の電卓は壊れてしまっています。 K 種類より多くの種類の数字を打つと、電卓が壊れてしまいます。
整数 A が与えられます。高橋君は、この整数を入力したいです。
ですが、普通にその整数を打とうとすると、電卓が壊れてしまうことがあるため、 電卓が壊れない範囲で、出来るだけ整数 A との差の大きさが小さい整数を入力します。
この時、高橋君が入力する整数と、整数 A の差の大きさがいくつになるかを出力しなさい。
制約：でかい

-----問題ここまで----- */
/* -----解説等-----

dp[i番目を見ている][subset(0-9)][up or dowm]:= (up/down)における最適な値
として上からDPをする。
再帰では上手に書けなかったので桁DPではうまく選択するのが大事なんだなと思った
あと、leading zero を書いている人がいて、今回は関係なかったけど気を付けたい。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL a; cin >> a;
	int K; cin >> K;
	string A = to_string(a);

	LL dp[21][1 << 10][2];
	FOR(i, 0, 21)FOR(j, 0, 1 << 10) {
		dp[i][j][0] = -LINF;
		dp[i][j][1] = LINF;
	}

	int N = SZ(A);
	LL base = 0;
	dp[0][0][0] = 0;
	FOR(i, 0, N) {
		base = base * 10 + (A[i] - '0');
		FOR(sub, 0, 1 << 10) {
			FOR(du, 0, 2) {
				int pc = 0;
				FOR(num, 0, 10)if (sub&(1 << num))pc++;

				FOR(num, 0, 10) {//遷移
					if (pc == K && ((sub&(1 << num)) == 0))continue;
					LL nx = dp[i][sub][du] * 10 + (LL)num;
					if (nx < base)dp[i + 1][sub | (1 << num)][0] = max(dp[i + 1][sub | (1 << num)][0], nx);
					else		  dp[i + 1][sub | (1 << num)][1] = min(dp[i + 1][sub | (1 << num)][1], nx);
				}

			}
		}
	}
	ans = LINF;
	FOR(i, 0, N + 1) {
		FOR(sub, 0, 1 << 10) {
			FOR(du, 0, 2) {
				ans = min(ans, abs(dp[i][sub][du] - a));
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
