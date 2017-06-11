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

/* -----  2017/06/11  Problem: yukicoder023 / Link: http://yukicoder.me/problems/no/23  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

dp[ 現在与えたダメージ ]:=　ここまでにかけた最小コスト
体力の上限がそこまで高くないので、体力に関して状態を遷移させることができればよい。
また確率2/3で必殺技が発動するのは言い換えればコスト1.5で発動可能とみなせる。
これによって値の遷移が可能になった。
うれしいね。


----解説ここまで---- */

ll H, A, D;
double dp[10001];
double ans = 0.0;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> H >> A >> D;
	
	FOR(i,0,10001) {
		dp[i] = LINF;
	}
	dp[0] = 0;
	FOR(i, 0, H + 1) {
		ll next = min(i + A, H);
		dp[next] = min(dp[next], dp[i] + 1);
		ll nex = min(i + D, H);
		dp[nex] = min(dp[nex], dp[i] + 1.5);
	}

	ans = dp[H];
	cout << ans << endl;

	return 0;
}
