#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
const ll LINF = 1e16;

/* -----  2017/04/24  Problem: JOI予選 2014 4  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0611  ----- */
/* ------問題------

みて

-----問題ここまで----- */
/* -----解説等-----

グラフではあるが辺の数が多すぎる。
状態は前には戻らないので各町にいる状態で移動するかしないかを
dp[ 現在の町 ][ 現在の日付 ] := 現在の町での最小疲れ度
として移動する、しないの遷移をすればよい。

----解説ここまで---- */



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ll N, M; cin >> N >> M;
	ll ans = LINF;
	ll d[1010];
	ll c[1010];
	vector<vector<ll> >dp(N + 1, vector<ll>(M + 1, LINF));

	FOR(i, 0, N) {
		cin >> d[i];
	}
	FOR(i, 0, M) {
		cin >> c[i];
	}
	dp[0][0] = 0;
	FOR(i, 0, N) {
		FOR(j, 0, M) {
			dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + d[i] * c[j]);
		}
	}
	FOR(i, N, M + 1) {
		ans = min(ans, dp[N][i]);
	}

	cout << ans << endl;

	return 0;
}
