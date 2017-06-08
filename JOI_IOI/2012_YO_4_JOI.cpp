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

/* -----  2017/05/01  Problem: JOI予選 2012 4  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0579  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

dp[ この日にちが終了したとき ][ 着ていた服 ] := この日終了時点でのうれしさの最大値
としてDPすればよい。Ｏ(N^2*D)で解ける。
ある日にちに着ている服が何か、前日あるいは明日来ている服はわからないので、これを全探索する。＝＞Ｏ(N^2)
日にちとが番号が出てきて順番を考えたくなくなったらDPにしたくなる。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ll D, N;
	ll t[205];
	ll a[205];
	ll b[205];
	ll c[205];
	ll ans = 0LL;
	ll dp[205][205];
	FOR(i, 0, 205)FOR(j, 0, 205)dp[i][j] = 0;
	cin >> D >> N;
	FOR(i, 0, D) {
		cin >> t[i];
	}
	FOR(i, 0, N) {
		cin >> a[i] >> b[i] >> c[i];
	}

	FOR(i, 1, D) {
		FOR(j, 0, N) {
			if (a[j] <= t[i] && t[i] <= b[j]) {
				FOR(k, 0, N) {
					if (a[k] <= t[i - 1] && t[i - 1] <= b[k]) {
						dp[i][j] = max(dp[i][j], dp[i - 1][k] + abs(c[j] - c[k]));
					}

				}
			}
		}
	}

	FOR(i, 0, N) {
		ans = max(ans, dp[D - 1][i]);
	}

	cout << ans << endl;

	return 0;
}
