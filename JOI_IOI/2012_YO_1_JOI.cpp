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

/* -----  2017/05/01  Problem: JOI予選 2012 1  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0576  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

最大値をとる。

----解説ここまで---- */



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ll l,a,b,c,d;

	ll ans = 0LL;

	cin >> l>>a>>b>>c>>d;
	ll x = (a + c - 1) / c;
	ll y = (b + d - 1) / d;
	ans = l - max(y,x);
	cout << ans << endl;

	return 0;
}
