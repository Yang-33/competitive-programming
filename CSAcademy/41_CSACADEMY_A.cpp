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

/* -----  2017/08/09  Problem: 41_csacademy A  / Link: https://csacademy.com/contest/round-41/tasks/  ----- */
/* ------問題------

サイズが偶数の数列が与えられる。2個づつのペアを作成したとき、その差をとる。
この差の絶対値の総和が最小となるようにペアを選択したとき、その総和は。

-----問題ここまで----- */
/* -----解説等-----

数値が連続している際、a,b,c,dのときは(a,b),(c,d)とするのがよい。三角不等式的なもの
a,b,b,cのときは、絶対値をいろいろな組でとればこれも不等式から昇順の最も近い二組をとればよいことが分かる。
したがって昇順に並べて二つの差の合計を求めればよい。

----解説ここまで---- */

ll N;

ll ans = 0LL;
ll a[1003];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N) {
		cin >> a[i];
	}
	sort(a, a + N);
	FOR(i, 0, N) {
		ans += a[i+1] - a[i ];
		i++;
	}
	cout << ans << endl;

	return 0;
}
