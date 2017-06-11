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

/* -----  2017/06/11  Problem: yukicoder027 / Link: http://yukicoder.me/problems/no/27  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

全探索&DP。
dp[ 現在作りたい板の長さ ]:= この長さの板を作るために必要な板の最小枚数
として遷移させたい。
元手になる板の大きさが小さく、3枚しかないのでこの組み合わせについて全探索をする。
3枚の大きさがそれぞれ確定したらその三枚でdpをして、dp[v[0]]+dp[v[1]]+dp[v[2]]+dp[v[3]]
の候補のうちの最小値を答えにすればよい。

----解説ここまで---- */

ll v[4];
ll dp[35];
ll ans = LINF;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	FOR(i, 0, 4)cin >> v[i];
	ll n = 0;
	FOR(i, 0, 4)n = max(n, v[i]);
	FOR(a, 1, n + 1) {
		FOR(b, 1, n + 1) {
			FOR(c, 1, n + 1) {
				//値の割り振りが確定している
				FOR(i, 0, 35)dp[i] = LINF;
				dp[0] = 0;
				FOR(i, a, n + 1)dp[i] = min(dp[i], dp[i - a]+1);
				FOR(i, b, n + 1)dp[i] = min(dp[i], dp[i - b]+1);
				FOR(i, c, n + 1)dp[i] = min(dp[i], dp[i - c]+1);
				ll ret = 0;
				FOR(i, 0, 4)ret += dp[v[i]];
				ans = min(ans, ret);

			}
		}
	}

	cout << ans << endl;

	return 0;
}
