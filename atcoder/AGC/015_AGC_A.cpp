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
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

/* -----  2017/05/27  Problem: AGC 015 A / Link: http://agc015.contest.atcoder.jp/tasks/agc015_a  ----- */
/* ------問題------

すぬけ君は、整数を N 個持っています。
このうち最小のものは A、最大のものは B です。
すぬけ君が持っている整数の総和としてありうる値は何通りあるでしょうか。

-----問題ここまで----- */
/* -----解説等-----

B<Aまたは、N=1かつA≠Bは組み合わせを持たない。
そうでないとき、N-1個はAでもう一つはB,から一つはAで残りのN-1個はBまでの整数値をとることができ、ここに含まれる整数はすべてN個の整数で作り出すことができる。
したがってその個数は B(N-1)+A - A(N-1)+B + 1 となる。

----解説ここまで---- */

ll N, A, B;

ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> A >> B;
	if (A > B) {
		cout << 0 << endl;
		return 0;
	}
	if (N == 1 && A != B) {
		cout << 0 << endl;
		return 0;
	}
	ans = B*(N - 1) + A - (A*(N - 1) + B - 1);

	cout << ans << endl;

	return 0;
}