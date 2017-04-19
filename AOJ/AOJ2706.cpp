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

/* -----  2017/04/19  Problem:  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

なんか書くと分母に来るものがn乗の形になればよいので、
素因数分解して大きい方にそろえればよいが、分子は何でもよいことに気が付くので、
結局素因数だけとりだせばよい。

----解説ここまで---- */

int gcd(int p, int q) {
	if (q == 0) {
		return p;
	}
	else {
		return gcd(q, p%q);
	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int a, b;
	cin >> a >> b;
	b /= gcd(a, b);
	int ans = 1;
	for(int i=2;i*i<=b;i++){
		if (b%i == 0) {
			while (b%i == 0) {
				b /= i;
			}
			ans *= i;
		}

	}

	cout << ans*b << endl;

	return 0;
}
