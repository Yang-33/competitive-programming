#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) >= (e); (i)--)
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

int N, T, S;
int a[3010], b[3010];
#define MAX 5000
int dp[MAX];
int ans = -1;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> T >> S;
	FOR(i, 0, N) {
		cin >> a[i] >> b[i];
	}

	FOR(i, 0, MAX)dp[i] = 0;

	FOR(i, 0, N) {
		for (int t = T; t - b[i] >= 0; t--) {
			if (t <= S || t >= S + b[i])
				dp[t] = max(dp[t], dp[t - b[i]] + a[i]);
		}
	}


	//S?
	ans = 0;
	FOR(t, 0, T + 1) {
		ans = max(ans, dp[t]);
	}

	cout << ans << endl;

	return 0;
}
