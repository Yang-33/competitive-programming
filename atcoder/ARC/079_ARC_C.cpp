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

/* -----  2017/07/29  Problem: ARC 079 C / Link: http://arc079.contest.atcoder.jp/tasks/arc079_c  ----- */
/* ------問題------

長さ N の非負整数列 ai に対し、数列の最大値が N−1 以下になるまで以下の操作を繰り返し行うことを考えます。なお、この操作はD問題で考える操作と同一です。
数列のうち最も大きい要素を求める、複数ある場合はどれか 1 つ選ぶ。この要素の値を N 減らす。これ以外の要素の値を 1 増やす。
なお、この操作を行い続けると、いつかは数列の最大値が N−1 以下になることが証明できます。
ここで、数列 ai が与えられるので、何回操作を行うことになるかを求めてください

-----問題ここまで----- */
/* -----解説等-----

最大値は各削減においてN/(N-1)となるので愚直にシュミレーションして間に合う。

・点数とか考えずにできることを考えよう！

----解説ここまで---- */

ll N;
ll a[51];
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N)cin >> a[i];
	
	FOR( x, 0,1000000) {
		FOR(i, 0, N) {
			if (a[i] >= N) {
				ll d = a[i] / N;
				ans += d;
				a[i] -= d*N;
				FOR(j, 0, N) {
					if (i != j)a[j] += d;
				}
			}
		}
	}
	
	
	
	
	cout << ans << endl;

	return 0;
}
