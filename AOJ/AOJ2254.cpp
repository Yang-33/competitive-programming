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

/* -----  2017/06/16  Problem: AOJ 2254  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2254&lang=jp ----- */
/* ------問題------

Ｎ地点をすべて巡回する。この時jに到達したことがあれば補助を得てiへのコストがT(i,j)で与えられる。
T(i,0)は助けなしにiへ到達するのに必要なコスト。
最小距離を求める。

-----問題ここまで----- */
/* -----解説等-----

状態数が少なく順序関係を気にしない最小値を求めたいのでbit DPをする。
ある地点に訪れているかによって加算する値が変わるのでそこを考慮できるように
地点に訪れたかを各iについて記録する。

----解説ここまで---- */

ll N;
ll dp[1 << 16];
ll ans = 0LL;
ll a[16][17];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	for (;;) {
		cin >> N;
		if (N == 0)break;
		FOR(i, 0, N) {
			FOR(j, 0, N + 1) {
				cin >> a[i][j];
			}
		}

		FOR(i, 0, 1 << N)dp[i] = LINF;
		dp[0] = 0;

		FOR(i, 0, 1 << N) {
			bool f[18];
			FOR(j, 0, N) {
				f[j] = 0;
				if (i&(1 << j)) {
					f[j] = 1;
				}
			}

			FOR(j, 0, N) {//jへ行く
				FOR(k, 0, N) {
					if (f[k] == 1 && f[j] == 0) {
						dp[i | 1 << j] = min(dp[i | 1 << j], dp[i] + a[j][k + 1]);
					}
					else if (f[k] == 0 && f[j] == 0) {
						dp[i | 1 << j] = min(dp[i | 1 << j], dp[i] + a[j][0]);
					}
				}
			}
		}
		ans = dp[(1 << N) - 1];
		cout << ans << endl;
	}
	return 0;
}
