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
const ll MOD = 100000;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 1, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, 0, 0, 0, 1, -1, 1, -1 };

/* -----  2017/06/28  Problem:  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

ll W, H;
int  dp[105][105][2];
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	while (1) {
		cin >> W >> H;
		if (W == 0 && H == 0)break;
		ans = 0;//mod
		FOR(i, 0, 105)FOR(j, 0, 105)dp[i][j][0] = dp[i][j][1] = 0;

		FOR(i, 1, 101) {
			dp[i][1][0] = dp[1][i][0] = dp[i][1][1] = dp[1][i][1] = 1;
		}
		FOR(i, 2, H + 1) {
			FOR(j, 2, W + 1) {
				dp[i][j][0] = (dp[i][j - 1][0] + dp[i - 2][j][1]) % MOD;
				dp[i][j][1] = (dp[i - 1][j][1] + dp[i][j - 2][0]) % MOD;

			}
		}
		ans= (dp[H][W - 1][0] + dp[H - 1][W][1]) % MOD;

		cout << ans<< endl;


	}
	return 0;
}
