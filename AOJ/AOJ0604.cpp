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

/* -----  2017/05/24  Problem:  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

ll M, N;
ll dp[2010][2010][2];
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	string s1, s2;
	cin >> M >> N;
	cin >> s1 >> s2;

	FOR(i, 0, 2010)FOR(j, 0, 2010) {
		dp[i][j][0] = 0;
		dp[i][j][1] = -LINF;
	}
	ans = -1;
	dp[0][0][0] = 0;

	FOR(i, 0, M + 1) {
		FOR(j, 0, N + 1) {
			if (s1[i] == 'I') {
				dp[i + 1][j][1] = max(dp[i + 1][j][1], dp[i][j][0] + 1);
			}
			else if(s1[i]=='O') {
				dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][1] + 1);

			}
			if (s2[j] == 'I') {
				dp[i][j + 1][1] = max(dp[i][j + 1][1], dp[i][j][0] + 1);
			}
			else if(s2[j]=='O'){
				dp[i][j + 1][0] = max(dp[i][j + 1][0], dp[i][j][1] + 1);

			}


		}
	}
	FOR(i, 0, M + 1) {
		FOR(j, 0, N + 1) {
			ans = max(ans, dp[i][j][1]);
		}
	}
	if (ans == -1)ans = 0;
	cout << ans << endl;

	return 0;
}
