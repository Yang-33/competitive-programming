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

/* -----  2017/05/01  Problem: JOI予選 2012 2  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0577  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

自分の数があるかを検索したいのでsetに入れておけば自分の一個しかないかを確認できる。

----解説ここまで---- */


ll a[205][205];
ll ans[205];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ll N;
	multiset<ll>s[3];
	cin >> N;
	FOR(i, 0, N) {
		cin >> a[0][i] >> a[1][i] >> a[2][i];
		s[0].insert(a[0][i]);
		s[1].insert(a[1][i]);
		s[2].insert(a[2][i]);
	}
	
	FOR(x, 0, 3) {
		FOR(i, 0, N) {
			if (s[x].count(a[x][i]) == 1) {
				ans[i] += a[x][i];
			}

		}
	}
	FOR(i,0,N)
	cout << ans[i] << endl;

	return 0;
}
