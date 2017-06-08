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

/* -----  2017/05/20  Problem: ARC 074 A / Link: http://arc074.contest.atcoder.jp/tasks/arc074_a  ----- */
/* ------問題------

与えられた四角形を辺に平行な2直線のみで分割する際の最大値と最小値の差の最小値は。

-----問題ここまで----- */
/* -----解説等-----

縦横は同じ動作になるので以降基本的には縦に分割することを考える。
縦に分割したときに片側の残りの面積は半分ぐらいに分割してあげたらうれしいという発想になる。
値がどの面積についても負にならないことが確定したら、問題の条件に沿って最大の面積と最小の面積の差について、
これが最小になるものの値をとればよい。
面積が3の倍数で割り切れる場合には3つの面積を同じにできるので答えは０．

----解説ここまで---- */

ll H, W;

ll ans = LINF;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> H >> W;
	ans = min(H, W);
	FOR(w, 1, W) {
		ll s = w*H;
		ll x = (W - w)*(H / 2);
		ll y = H*W - s - x;
		if (y < 1)continue;
		ll M = max(s, max(x, y));
		ll m = min(s, min(x, y));
		if (M - m < ans) {
			ans = min(ans, M - m);
		}
	}
	swap(H, W);
	FOR(w, 1, W) {
		ll s = w*H;
		ll x = (W - w)*(H / 2);
		ll y = H*W - s - x;
		ll M = max(s, max(x, y));
		ll m = min(s, min(x, y));
		ans = min(ans, M - m);
	}

	if (H % 3 == 0 || W % 3 == 0)ans = 0;
	cout << ans << endl;

	return 0;
}