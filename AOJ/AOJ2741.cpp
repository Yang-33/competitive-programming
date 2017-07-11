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

/* -----  2017/07/11  Problem: AOJ 2711  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2711&lang=jp ----- */
/* ------問題------


-----問題ここまで----- */
/* -----解説等-----

ゲーム。
各状態のデッキの状況を記録、かつ得点を引数にわたす。

----解説ここまで---- */

ll N, M;
int a[55];
int b[55];
ll ans = 0LL;
int dp[55][55][55][55][2][3];

int dfs(int as, int at, int bs, int bt, int turn, int pass, int asum, int bsum) {
	int& ret = dp[as][at][bs][bt][turn][pass];
	if (ret != INF&&ret != -INF)return ret;
	if (!turn) {
		if (at < N) {
			if (a[at] > 0) {//1
				ret = max(ret, dfs(as, at + 1, bs, bt, turn ^ 1, 0, asum + a[at], bsum));
			}
			else {//-1
				ret = max(ret, dfs(as, at + 1, bs, bt, turn ^ 1, 0, asum, 0));
			}
		}
		//つまないpass)
		if (as == at&&bs == bt) {
			if (pass == 0)ret = max(ret, dfs(as, at, bs, bt, turn ^ 1, 1, 0, 0));
			else if (pass == 1)ret = max(ret, 0);
		}
		else {
			ret = max(ret, dfs(at, at, bt, bt, turn ^ 1, 0, 0, 0) + asum - bsum);
		}
	}
	else {
		if (bt < M) {
			if (b[bt] > 0) {//1
				ret = min(ret, dfs(as, at, bs, bt + 1, turn ^ 1, 0, asum, bsum + b[bt]));
			}
			else {//-1
				ret = min(ret, dfs(as, at, bs, bt + 1, turn ^ 1, 0, 0, bsum));
			}
		}
		//つまない(pass)
		if (as == at&&bs == bt) {
			if (pass == 0)ret = min(ret, dfs(as, at, bs, bt, turn ^ 1, 1, 0, 0));
			else if (pass == 1)ret = min(ret, 0);
		}
		else {
			ret = min(ret, dfs(at, at, bt, bt, turn ^ 1, 0, 0, 0) + asum - bsum);
		}
	}

	return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	FOR(i, 0, N)cin >> a[i];
	FOR(i, 0, M)cin >> b[i];

	FOR(i, 0, 55)FOR(j, 0, 55)FOR(k, 0, 55)FOR(l, 0, 55)FOR(m, 0, 2)FOR(n, 0, 3) {
		if (m == 0)dp[i][j][k][l][m][n] = -INF;
		else dp[i][j][k][l][m][n] = INF;
	}

	ans = dfs(0, 0, 0, 0, 0, 0, 0, 0);
	cout << ans << endl;

	return 0;
}