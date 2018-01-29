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

/* -----  2018/01/29  Problem: ARC 090 A / Link: http://arc090.contest.atcoder.jp/tasks/arc090_a  ----- */
/* ------問題------

2×N のマス目があります。上から i 行目、左から j 列目 (1≤i≤2, 1≤j≤N) のマスをマス (i,j) と表すことにします。
あなたははじめ、左上のマス (1,1) にいます。 あなたは、右方向または下方向への移動を繰り返し、右下のマス (2,N) に移動しようとしています。
マス (i,j) には Ai,j 個のアメが置かれています。 あなたは移動中に通ったマスに置いてあるアメをすべて回収します。 左上および右下のマスにもアメが置かれており、あなたはこれらのマスに置かれているアメも回収します。
移動方法をうまく選んだとき、最大で何個のアメを回収できるでしょうか。

-----問題ここまで----- */
/* -----解説等-----

全探索O(N(累積和), N^2) or DP O(N)

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;

	VVL a(2, VL(N));
	VVL dp(2, VL(N + 1, 0));
	FOR(i, 0, 2) {
		FOR(j, 0, N) {
			cin >> a[i][j];
		}
	}


	FOR(i, 0, N) {
		dp[0][i + 1] = max(dp[0][i + 1], dp[0][i] + a[0][i]);
		dp[1][i] = max(dp[1][i], dp[0][i] + a[0][i]);
		dp[1][i + 1] = max(dp[1][i + 1], dp[1][i] + a[1][i]);
	}
	ans = dp[1][N];
	cout << ans << "\n";

	return 0;
}
