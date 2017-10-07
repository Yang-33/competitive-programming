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

/* -----  2017/10/07  Problem: DDCC2017_qual B  / Link: http://ddcc2017-qual.contest.atcoder.jp/tasks/ddcc2017_qual_b  ----- */
/* ------問題------

鉛筆 1 ダースは 12 本、 1 グロスは 144 本、 1 グレートグロスは 1728 本です。
A グレートグロスの鉛筆と、 B グロスの鉛筆と、 C ダースの鉛筆と、 D 本の鉛筆があるとき、合計で鉛筆は何本あるか答えてください。

-----問題ここまで----- */
/* -----解説等-----

自分で数えて

----解説ここまで---- */

ll A,B,C,D;

ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> A>>B>>C>>D;

	ans += A * 1728LL;
	ans += 144LL * B;
	ans += C * 12LL;
	ans += D;
	cout << ans << endl;

	return 0;
}
