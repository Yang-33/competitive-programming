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

/* -----  2017/04/17  Problem: JOI予選 2015 1  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0619  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

高い方から貪欲にとる。

----解説ここまで---- */



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ll N;

	ll ans = 0LL;
	int a[4];
	int b[2];
	FOR(i, 0, 4) {
		cin >> a[i];
	}
	FOR(i, 0, 2)cin >> b[i];
	sort(a, a + 4);
	sort(b, b + 2);
	FOR(i, 0, 3)ans += a[3 - i];
	ans += b[1];
	cout << ans << endl;

	return 0;
}
