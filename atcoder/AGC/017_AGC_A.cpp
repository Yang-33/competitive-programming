#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/07/09  Problem: AGC 017 A / Link: http://agc017.contest.atcoder.jp/tasks/agc017_a  ----- */
/* ------問題------

いくつかのビスケットの入った袋が N 個あります．i 番目の袋には Ai 個のビスケットが入っています．

高木君は，このうちいくつかの袋を選んで，選んだ袋に入っているビスケットをすべて食べるということを行います．
このとき，袋を一つも選ばなかったり，すべての袋を選んだりしてもかまいません．

高木君は，食べるビスケットの枚数を 2 で割ると余りが P に等しくなるようにしたいです．
このような袋の選び方は何通りあるか求めてください．

-----問題ここまで----- */
/* -----解説等-----

剰余でわけたDPをする。渡す方。

----解説ここまで---- */

ll N;
int P;
int a[51];
ll dp[60][2];
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> P;
	FOR(i, 0, N) {
		cin >> a[i];
	}
	dp[0][0] = 1;
	FOR(i, 0, N) {
		FOR(j, 0, 2) {
			dp[i + 1][((j + a[i]) % 2)] += dp[i][j];
			dp[i + 1][j] += dp[i][j];
		}
	}
	ans = dp[N][P];
	cout << ans << endl;

	return 0;
}
