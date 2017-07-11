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

/* -----  2017/07/11  Problem: Typical DP contest B game / Link: http://tdpc.contest.atcoder.jp/tasks/tdpc_game  ----- */
/* ------問題------

リンクを参照

-----問題ここまで----- */
/* -----解説等-----

tdpcのゲーム
ゲーム問題の練習用にミニマックス法の再帰で書いた。

----解説ここまで---- */

ll A, B;
ll a[1003];
ll b[1003];

ll ans = 0LL;
ll memo[1003][1003][2];

ll dfs(int p1, int p2, int turn) {
	ll &res = memo[p1][p2][turn];
	if (res != -1)return res;

	if (p1 == A&&p2 == B)return 0;

	if (turn == 0) {//max
		res = 0;
		if (p1 < A)res = max(res, dfs(p1 + 1, p2, turn ^ 1) + a[p1]);
		if (p2 < B)res = max(res, dfs(p1, p2 + 1, turn ^ 1) + b[p2]);
	}
	else {//min
		res = LINF;
		if (p1 < A)res = min(res, dfs(p1 + 1, p2, turn ^ 1));
		if (p2 < B)res = min(res, dfs(p1, p2 + 1, turn ^ 1));
	}

	return res;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> A >> B;

	FOR(i, 0, A)cin >> a[i];
	FOR(i, 0, B)cin >> b[i];

	FOR(i, 0, 1003)FOR(j, 0, 1003)FOR(k, 0, 2)memo[i][j][k] = -1;

	ans = dfs(0, 0, 0);
	cout << ans << endl;

	return 0;
}
