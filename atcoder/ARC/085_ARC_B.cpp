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

/* -----  2018/02/27  Problem: 085_arc_b / Link: https://abc078.contest.atcoder.jp/tasks/arc085_b?lang=en  ----- */
/* ------問題------

N 枚のカードからなる山札があります。カードにはそれぞれ数が書かれており， 上から i 枚目には ai が書かれています。
この山札を使い，X さんと Y さんが 2 人でゲームをします。 X, Y さんは最初，Z,W が書かれたカードを持っています。 そして X さんから交互に以下を行います。
山札から何枚かカードを引く。そして今持っているカードを捨て，最後に引いたカードを代わりに持つ。ただし，必ず 1 枚は引かなくてはならない。
山札がなくなるとゲームは終了で，2 人の持っているカードに書かれた数の差の絶対値がこのゲームのスコアになります。
X さんはスコアを最大化するように，Y さんはスコアを最小化するようにゲームをプレイした時， スコアはいくつになるでしょうか？

-----問題ここまで----- */
/* -----解説等-----

なんかO(1)があったのを覚えているのですが、これはプログラミングコンテストで、
ゲームの末尾から再帰してO(N^3) -> 部分構造から O(N^2)

----解説ここまで---- */

LL N,Z,W;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>Z>>W;
	VL a(N+1);
	a[0] = W;
	FOR(i, 0, N) {
		cin >> a[i+1];
	}
	VVL dp(N + 1, VL(2));
	FORR(i, N, 0 - 1) {
		if (i == N) {
			dp[N][0] = LINF;
			dp[N][1] = -LINF;
		}
		else {
			dp[i][0] = abs(a[i] - a[N]);
			dp[i][1] = abs(a[i] - a[N]);
		}
		FOR(j, i + 1, N + 1) {
			dp[i][0] = max(dp[i][0], dp[j][1]);
			dp[i][1] = min(dp[i][1], dp[j][0]);
		}
	}
	ans = dp[0][0];
	cout << ans << "\n";

	return 0;
}
