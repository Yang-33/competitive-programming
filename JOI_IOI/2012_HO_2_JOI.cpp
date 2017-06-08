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

/* -----  2017/05/01  Problem: JOI本戦 2012 2 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0604  ----- */
/* ------問題------

O,Iで構成された車両群が二つある。これを頭から順に出して、IOIO...となるようにしたときにこの最大の長さはいくつになるか。

-----問題ここまで----- */
/* -----解説等-----

作れない先頭の部分は廃棄してもよい。

列車の取り出す順番をｄｐにもちこんで、列車の格納の条件からその部分解がそのまま答えになる。
dp[ 列車１をどこまでとりだしたか ][ 列車２をどこまで取り出したか ][ 現在作成中の列車の最後尾がI/O ] := 長さ
として条件に気をつけながら回す。
最後に部分解の最大値をとればよい。

----解説ここまで---- */

ll M, N;
string s, t;
int dp[2010][2010][2];
int ans = 0;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> M >> N;
	cin >> s >> t;
	FOR(i, 0, 2010)FOR(j, 0, 2010) {
		dp[i][j][0] = -INF;
		dp[i][j][1] = 0;
	}

	// 0:前回がI  1:前回が0
	FOR(i, 0, M + 1) {
		FOR(j, 0, N + 1) {//同時にやる
			if (s[i] == 'I') {
				dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][1] + 1);
			}
			else if (s[i] == 'O') {
				dp[i + 1][j][1] = max(dp[i + 1][j][1], dp[i][j][0] + 1);
			}
			if (t[j] == 'I') {
				dp[i][j + 1][0] = max(dp[i][j + 1][0], dp[i][j][1] + 1);
			}
			else if (t[j] == 'O') {
				dp[i][j + 1][1] = max(dp[i][j + 1][1], dp[i][j][0] + 1);
			}
		}
	}

	FOR(i, 0, M + 1) {
		FOR(j, 0, N + 1) {
			ans = max(ans, dp[i][j][0]);
		}
	}

	cout << ans << endl;

	return 0;
}
