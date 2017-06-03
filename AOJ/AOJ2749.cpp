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

/* -----  2017/06/03  Problem: JAG Domestic 2016 & NU contest 9 e / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2749  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

ll N, M;
int s[16];
int d[110];
int sets[1<<16];
int dp[110][1 << 16];
int ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (1) {
		scanf("%d%d", &N, &M);
//		cin >> N >> M;
		if (M == 0 && N == 0)break;
		FOR(i, 0, 105)FOR(j, 0, 1 << 15)dp[i][j] = INF;
		FOR(i, 0, N)scanf("%d", s + i);// cin >> s[i];
		FOR(i, 0, M)scanf("%d", d + i);// cin >> d[i];
		sort(d, d + M);
		ans = INF;

		FOR(i, 0, 1 << N) {
			int cost = 0;
			FOR(j, 0, N) {
				if ((i >> j) & 1) {
					cost += s[j];
				}
			}
			sets[i] = cost;
		}

		dp[0][0] = 0;
		FOR(m, 0, M) {
			FOR(s, 0, 1 << N) {
				dp[m + 1][s] = min(dp[m + 1][s], dp[m][s] + abs(sets[s] - d[m]));
				FOR(i, 0, N) {
					if (((s >> i) & 1) == 0)
						dp[m][s | 1 << i] = min(dp[m][s | 1 << i], dp[m][s]);
				}
			}
		}

		FOR(i, 0, 1 << N) {
			ans = min(ans, dp[M][i]);
		}
		printf("%d\n", ans);
//		cout << ans << endl;
	}
	return 0;
}
