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

/* -----  2017/10/28  Problem: SnackDown Online Qualifier 2017  » Same Snake / Link: https://www.codechef.com/SNCKQL17/problems/SAMESNAK  ----- */
/* ------問題------

交錯判定

-----問題ここまで----- */
/* -----解説等-----

幾何をやったら通らなかったので、
†場     合     わ     け†

----解説ここまで---- */

ll N;
ll ans = 0LL;
ll x11, y11, x12, y12, x21, y21, x22, y22;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(_i, 0, N) {
		bool flag = 0;
		cin >> x11 >> y11 >> x12 >> y12;
		cin >> x21 >> y21 >> x22 >> y22;
		int t, m1, m2;
		if (x11 == x12) m1 = 0;
		else m1 = 1;
		if (x21 == x22) m2 = 0;
		else m2 = 1;
		if (x11 == x12 && y11 == y12) m1 = m2;
		else if (x21 == x22 && y21 == y22) m2 = m1;
		if (m1 == 0 && m2 == 0) {
			if (x11 != x21) flag = 1;
			else {
				if ((y11 < y21 && y11 < y22 && y12 < y21 && y12 < y22) || (y11 > y21 && y11 > y22 && y12 > y21 && y12 > y22)) flag = 1;

			}

		}
		else if (m1 == 1 && m2 == 1) {
			if (y11 != y21) flag = 1;
			else {
				if ((x11 < x21 && x11 < x22 && x12 < x21 && x12 < x22) || (x11 > x21 && x11 > x22 && x12 > x21 && x12 > x22)) flag = 1;

			}
		}
		else {
			if ((x11 == x21 && y11 == y21) || (x11 == x22 && y11 == y22) || (x12 == x21 && y12 == y21) || (x12 == x22 && y12 == y22)) {
				flag = 0;
			}
			else {
				flag = 1;
			}
		}
		if (!flag) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}

	return 0;
}
