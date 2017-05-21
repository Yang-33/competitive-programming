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

/* -----  2017/05/21  Problem:  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

dp[ 見た長さi ][ Aの長さ ][ Bの長さ ][ 一つ前のものはAかBか ] := この状態での最小値
としてdpしたいが、計算量がＯ(N^3)となり多すぎる。
A,BはどちらもN/2の長さにしたいことを考えれば、片方の長さの情報はいらないことになる。
したがってdp[ 見た長さi ][ Aの長さ ][ 一つ前のものはAかBか ] := この状態での最小値
とすることでＯ(N^2)でぎりぎり間に合う。
ＡＯＪ特有のメモリの少なさから目盛りを節約するテクを使った。

----解説ここまで---- */

ll N;
ll a[10010];
ll ans = 0LL;
ll dp[2][5050][2];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 1, N) {
		cin >> a[i];
	}

	
	FOR(j, 0, 2)FOR(i, 0, 5050)FOR(k, 0, 2)dp[j][i][k] = LINF;
	dp[0][0][0] = 0;
	FOR(i, 0, N) {
		FOR(j, 0, min(i, N / 2) + 1) {
			dp[(i + 1) & 1][j + 1][0] = min(dp[i & 1][j][0], dp[i & 1][j][1] + a[i]);
			dp[(i + 1) & 1][j][1] = min(dp[i & 1][j][0]+a[i], dp[i & 1][j][1] );
			dp[i & 1][j][0] = dp[i & 1][j][1] = LINF;
		}
	}
	ans = min(dp[N & 1][N/2][0], dp[N & 1][N/2][1]);
	cout << ans << endl;

	return 0;
}
