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

/* -----  2017/06/16  Problem: AOJ 2199  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2199&lang=jp ----- */
/* ------問題------

みて

-----問題ここまで----- */
/* -----解説等-----

dp[ 現在みている符号 ][ その符号のY(i-1)の値 ]:= ここまでの二乗和の最小値
としてDPする。
Y(i)=Y(i-1)+C[k]だがこれが[0,255]の外のときには値を修正する。

----解説ここまで---- */

ll N, M;
int c[20];
int x[20010];
ll dp[20010][260];
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0)break;
		FOR(i, 0, M)cin >> c[i];
		FOR(i, 0, N)cin >> x[i];


		//dp[i番目の列,N][0-255]:=最小和
		FOR(i, 0, 20010)FOR(j, 0, 260)dp[i][j] = LINF;
		dp[0][128] = 0;

		FOR(i, 0, N) {
			FOR(j, 0, 256) {
				FOR(k, 0, M) {
					if (dp[i][j] == LINF)continue;
					int af = j + c[k];
					if (af > 255)af = 255;
					else if (af < 0)af = 0;
					dp[i + 1][af] = min(dp[i + 1][af], dp[i][j] + (ll)(x[i] - af)*(x[i] - af));
					/*if (dp[i][j] == 0) {
						cout << "0: j: " << j << " af: " << af << " dp[i+i][af]: " << dp[i + 1][af] << endl;
					}*/
				}
			}
		}

		ans = LINF;
		FOR(i, 0, 256) {
			ans = min(ans, dp[N][i]);
		}
		cout << ans << endl;
	}
	return 0;
}
