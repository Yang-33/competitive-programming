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

/* -----  2017/05/28  Problem:  / Link:   ----- */
/* ------問題------

Consecutive Snakes

-----問題ここまで----- */
/* -----解説等-----

三分探索
おわり

----解説ここまで---- */

ll s[100010];
ll ans = 0LL;

ll func_cost(ll piv, ll n, ll L) {
	ll sum = 0;
	FOR(i, 0, n) {
		sum += abs(piv+i*L-s[i]);
	}

	return sum;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int _T; cin >> _T;
	FOR(_t, 0, _T) {
		//init 
		FOR(i, 0, 100010)s[i] = 0;
		ll N, L, A, B; cin >> N >> L >> A >> B;
		FOR(i, 0, N)cin >> s[i];
		sort(s, s + N);
		
		ll l = A, r = B-L*N;
		FOR(i, 0, 200) {
			ll mid1 = (2 * l + r) / 3;
			ll mid2 = (2 * r + l) / 3;
			if (func_cost(mid1, N, L) > func_cost(mid2, N, L)) {
				l = mid1;
			}
			else {
				r = mid2;
			}
		}
		
		ll a = func_cost(l, N, L);
		ll b = func_cost(r, N, L);
		ans = min(a, b);

		cout << ans << endl;

	}


	return 0;
}
