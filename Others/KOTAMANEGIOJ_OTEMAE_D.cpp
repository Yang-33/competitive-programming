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

/* -----  2017/08/01  Problem: KotamanegiOJ_Otemae D  / Link: https://kotamanegi.com/JudgeSystem/Problems/view/index.php?page=28  ----- */
/* ------問題------

olphe君「今日もまたダントツ1位だったなあ」
そうです。olphe君は今日の大手前プロコンでも圧倒的強さで1位を奪っていったのです。
問題数Nと各問題の得点Piと2位の人の得点Sが与えられるので、olphe君が獲得しうる点数のうち最小のものを求めてください 。
但し、0点で1位になることはできないとします。

-----問題ここまで----- */
/* -----解説等-----

全列挙してSを超える値を作成し、その最小値をとる。
S==0の場合はpで最小のものを得点にすればよい。

----解説ここまで---- */

ll N;
int p[11];
ll S;
ll ans = LINF;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N) {
		cin >> p[i];
	}
	cin >> S;

	FOR(i, 0, (1 << N)) {
		ll m = 0;
		FOR(j, 0, N) {
			if (i&(1 << j))m += p[j];
		}
		if (m >= S)ans = min(ans, m);
	}
	if (ans == 0) {
		sort(p, p + N);
		ans = p[0];
	}
	cout << ans << endl;

	return 0;
}
