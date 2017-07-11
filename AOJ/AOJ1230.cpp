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

/* -----  2017/07/11  Problem: AOJ 1230  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1230  ----- */
/* ------問題------

S個の石が置いてあり、最後の一つをとると負けになる。
n S M_1 M_2  ...  M_2nが与えられる。
M_(奇数)が自分のチームである。このとき必勝なら1,必敗なら0を出力せよ。

-----問題ここまで----- */
/* -----解説等-----

0:負け確定,1:勝ち確定として、末尾の状態から確定させ、次プレイヤーを負けにする手をもつ人を1にしていけばよい。
dp=memo[i][j]:=[ i番目の人が ][ 残りの石がjこの状態で ]:=勝てうるか
として末尾からのメモ化で解く。
ゲーム木探索慣れてきた。

----解説ここまで---- */

ll N;

ll ans = 0LL;
int S;
int m[21];
int dp[21][1<<13+1];

bool dfs(int p, int s) {
	int &res = dp[p][s];
	if (res != -1)return res;
	if (s <= 1)return res=0;
	res = 0;
	FOR(i, 1, m[p] + 1) {
		if (dfs((p + 1) % (2 * N), s - i) == 0)res = 1;
	}
	return res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	while(1) {
		cin >> N;
		if (N == 0)break;
		cin >> S;
		FOR(i, 0, 2 * N)cin >> m[i];
		FOR(i, 0, 2 * N)FOR(j, 0, 1 << 13 + 1)dp[i][j] = -1;
		ans = dfs(0, S);
		cout << ans << endl;
	}
	return 0;
}
