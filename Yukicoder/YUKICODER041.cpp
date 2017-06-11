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
const ll MOD = 1000000009;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/06/11  Problem: yukicoder041 / Link: http://yukicoder.me/problems/no/41  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

10^10=111111*10^5=1.11111*10^5*10^5
お金の払い方を考えると111111の倍数でない分は全部1円玉で払うことになる。
したがってこれは1-9の9枚の硬貨で払うとしたときの個数制限なしdpに帰着できる。
dp[ 値段 ] :=現在の値段での支払いの組み合わせ
として各値段から状態を遷移させる。またすべての値段について1円玉のみでの支払いが可能なため、
先に全部の値段について初期値を1にした。

MOD=10^+「9」、なぜなのか。

----解説ここまで---- */

ll N;
ll m[10050];
ll dp[100010];
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N)cin >> m[i];

	FOR(i, 0, 100000)dp[i] = 1;

	FOR(i, 1, 9 + 1) {
		FOR(j, 0, 100000) {
			(dp[i + j] += dp[j]) %= MOD;
		}
	}
	FOR(i, 0, N) {
		ans = dp[m[i] / 111111LL] ;
		cout << ans << endl;
	}
	return 0;
}
