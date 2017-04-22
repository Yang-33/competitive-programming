#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
#define debug(x) cout<<#x<<": "<<x<<endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };

/* -----  2017/04/21  Problem: CodeForces410 C div2 / Link:  ----- */
/* ------–â‘è------



-----–â‘è‚±‚±‚Ü‚Å----- */
/* -----‰ðà“™-----



----‰ðà‚±‚±‚Ü‚Å---- */


int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

ll N;

ll ans = 0LL;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	int a[100050];
	FOR(i, 0, N) {
		cin >> a[i];
	}
	int g = a[0];
	FOR(i, 0, N) {
		g = gcd(a[i], g);
	}
	if (g >= 2) {
		cout << "YES" << endl;
		cout << 0 << endl;
		return 0;
	}

	a[N] = 0;
	FOR(i, 0, N) {
		if (a[i] % 2 == 0)continue;
		int gg = gcd(a[i], a[i + 1]);
		if(gg%2!=0){
		while (gcd(a[i], a[i + 1]) % 2 != 0) {
				ans += 1;
				int s = a[i];
				a[i] = a[i + 1] - a[i];
				a[i + 1] = a[i + 1] + s;
			}
		}
	}

	g = a[0];
	FOR(i, 0, N) {
		g = gcd(a[i], g);
	}

	if (g%2 != 0) {
		//cout << "no af che" << endl;
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	cout << ans << endl;

	return 0;
}