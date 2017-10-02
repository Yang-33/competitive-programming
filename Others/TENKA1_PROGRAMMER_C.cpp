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

/* -----  2017/09/30  Problem: Tenka1_programmer C  / Link: http://tenka1-2017.contest.atcoder.jp/tasks/tenka1_2017_c  ----- */
/* ------問題------

整数 N が与えられる。

4⁄N=1⁄h+1⁄n+1⁄w を満たす正整数 h,n,w を求めよ。

条件を満たす解が複数ある場合、どれを出力しても良い。

-----問題ここまで----- */
/* -----解説等-----

3変数でも等式ならば一つの変数はほかの二つできまることが分かるのでこれをつかう。
3500^2全探索で間に合う。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(h, 1, 3501) {
		FOR(n, 1, 3501) {
			ll up = N*h*n;
			ll low = 4 * h*n - N*(n + h);
			if (low <= 0)continue;
			if (up%low == 0) {
				cout << h<<" "<<n<<" "<<up/low << endl;
				return 0;
			}
		}
	}
	assert(0);

	return 0;
}
