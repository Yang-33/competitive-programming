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



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

int pe[110];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int _T;  cin >> _T;
	FOR(_t, 0, _T) {
		bool f = 1;
		int n; int m;
		cin >> n >> m;

		FOR(j, 1, n + 1) {
			pe[j] = -1;
		}

		int ver = 0;
		FOR(i, 0, m) {
			int a, b; cin >> a >> b;
			if (pe[a] == -1 && pe[b] == -1) {
				pe[a] = pe[b]=ver;
				ver++;
			}
			else f = 0;
		}
		int lef = n - ver * 2;
		if (lef >= 0 && lef % 2 == 0)f = 1;
		else f = 0;

		if (f)
			cout << "yes" << endl;
		else
			cout << "no" << endl;

	}

	return 0;
}
