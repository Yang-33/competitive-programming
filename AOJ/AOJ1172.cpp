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

/* -----  2017/06/27  Problem: ICPC2012国内予選A / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1172&lang=jp  ----- */
/* ------問題------

N≦X≦2Nをみたす素数Xの個数は。N≦123456.

-----問題ここまで----- */
/* -----解説等-----

素数集合から、N≦X≦2Nをみたす素数Xの個数を数える。

----解説ここまで---- */

ll N;

ll ans = 0LL;

vector<ll> prime;
void init_prime() {
	prime.push_back(2);
	for (int i = 3; i < 250000; i += 2) {
		bool f = false;
		for (int j = 3; j*j <= i; j += 2) {
			if (i%j == 0) {
				f = true;
				break;
			}
		}
		if (!f) prime.push_back(i);
	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	init_prime();
	
	int n;
	while (cin >> n,n) {
		auto it1 = lower_bound(prime.begin(),prime.end(),n+1);
		auto it2 = lower_bound(prime.begin(), prime.end(), 2 * n + 1);

		cout << it2 - it1 << endl;
	}
	return 0;
}
