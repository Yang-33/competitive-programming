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

/* -----  2017/04/17  Problem: JOI予選 2015 3  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0621  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

各行にどれだけ各色があるかを確認し、二本の軸に対して全探索すればいい。
白は[0,H-2)青は[白+1,H-1)[青+1,H)までを見ればいい。

たぶん人生で初めて見た競プロの問題だけど、当時はこんな問題を解ける人すごすぎると思ってた。

----解説ここまで---- */

ll H, W;
ll w[50];
ll b[50];
ll r[50];
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> H >> W;
	string s[50];
	FOR(i, 0, H) {
		cin >> s[i];
	}
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (s[i][j] == 'W')w[i]++;
			if (s[i][j] == 'B')b[i]++;
			if (s[i][j] == 'R')r[i]++;
		}
	}

	ans = LINF;
	FOR(i, 0, H - 2) {

		FOR(j, i + 1, H - 1) {
			FOR(k, j + 1, H) {
				ll ret = 0;
				FOR(ii, 0, j)ret += b[ii] + r[ii];
				FOR(ii, j, k)ret += r[ii] + w[ii];
				FOR(ii, k, H)ret += w[ii] + b[ii];
				ans = min(ans, ret);
			}
		}


	}


	cout << ans << endl;

	return 0;
}