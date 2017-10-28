#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
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

/* -----  2017/10/28  Problem:  / Link:   ----- */
/* ------問題------

覚えてない

-----問題ここまで----- */
/* -----解説等-----

うける

----解説ここまで---- */


int main() {
	//cin.tie(0);
	//ios_base::sync_with_stdio(false);
	ll N, M;

	//cin >> M >> N;
	scanf("%lld%lld", &M, &N);
	int s[1005];
	vector<int> p(3005,0);
	vector<ll>pat;

	FOR(i, 0, M) {
		scanf("%d", s+i);
		//cin >> s[i];
	}
	FOR(i, 0, N) {
		scanf("%d", &p[i]);
		 // cin >> p[i];
	}
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	FOR(i, 0, N)FOR(j, i, N) {
		pat.push_back((ll)p[i] * p[j]);
	}

	sort(pat.begin(), pat.end());

	FOR(i, 0, M) {
		ll num = *lower_bound(pat.begin(), pat.end(), (ll)s[i]);
		printf("%lld\n", num - s[i]);
	}

	return 0;
}
