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

/* -----  2017/04/30  Problem: GCJ2017 Round1B B / Link: https://code.google.com/codejam/contest/8294486/dashboard#s=p1  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

void solve(int ttt) {
	string ans = "A";
	string s = "ROYGBV";
	int N;
	cin >> N;
	int c[6];
	bool f = true;
	FOR(i, 0, 6) {
		cin >> c[i];
	}
	if (c[1] == c[4] && c[0] == 0 && c[2] == 0 && c[3] == 0 && c[5] == 0) {
		FOR(i, 0, c[1]) {
			ans += s[1] + s[4];
		}
	}
	else if (c[3] == c[0] && c[1] == 0 && c[2] == 0 && c[4] == 0 && c[5] == 0) {
		FOR(i, 0, c[3]) {
			ans += s[0] + s[3];
		}
	}
	else if (c[2] == c[5] && c[0] == 0 && c[1] == 0 && c[3] == 0 && c[4] == 0) {
		FOR(i, 0, c[5]) {
			ans += s[2];
			ans += s[5];
		}
		debug(ans);
	}
	else if (c[1] > c[4] + 1 || c[3] > c[0] + 1 || c[5] > c[2] + 1)f = false;
	else {
		cout << "adf" << endl;
		c[0] = c[0] - c[3];
		c[2] = c[2] - c[5];
		c[4] = c[4] - c[1];
		if (c[0] <= c[2] + c[4] && c[2] <= c[0] + c[4] && c[4] <= c[2] + c[0]) {
			int sum = c[0] + c[2] + c[4];
			int b = -1;
			int maxn = max(c[0], max(c[2], c[4]));
			/*3ショックをいい感じに並べる*/
			if (maxn == c[0]) {
				FOR(i, 0, c[0]) {
					ans += s[0];
					if (c[2] > 0) {
						ans += s[2]; c[2]--;
					}
					else if (c[4] > 0) {
						ans += s[4]; c[4]--;
					}
				}
				if()
			}

			
			FOR(i, 0, sum) {
				int maxn = max(c[0], max(c[2], c[4]));

				if (maxn == c[0] && b != 0) {
					ans += s[0];
					c[0]--;
					b = 0;
				}
				else if (maxn == c[2] && b != 2) {
					ans += s[2];
					c[2]--;
					b = 2;
				}
				else if (maxn == c[4] && b != 4) {
					ans += s[4];
					c[4] --;
					b = 4;
				}
				/*debug(i);
				debug(ans);
				cout << c[0] << " " << c[2] << " " << c[4] << " " << endl;*/
			}
			//元に戻す

			FOR(i, 1, sum + 1) {
				if (c[1] && (ans.substr(i, 1) == "B")) {
					string ss = ans.substr(0, i );
					string aa = "B";
					FOR(i, 0, c[1]) {
						aa += s[1];
						aa += s[4];
					}
					ans = ss + aa + ans.substr(i + 1);
					c[1] = 0;
				}
				if (c[3] && (ans.substr(i, 1) == "R")) {
					string ss = ans.substr(0, i );
					string aa = "R";
					FOR(i, 0, c[3]) {
						aa += s[3];
						aa += s[0];
					}
					ans = ss + aa + ans.substr(i + 1);
					c[3] = 0;
				}if (c[5] && (ans.substr(i, 1) == "Y")) {
					string ss = ans.substr(0, i );
					string aa = "Y";
					FOR(i, 0, c[5]) {
						aa += s[5];
						aa += s[2];
					}
					ans = ss + aa + ans.substr(i + 1);
					c[5] = 0;
				}
			}


		}
		else f = false, cout << "false" << endl;
	}


	if (f == false)ans = "AIMPOSSIBLE";

	cout << "Case #" << ttt << ": " << ans.substr(1) << endl;
	//	printf("Case #%d: %.10f\n", ttt, ans);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll T;

	cin >> T;
	FOR(i, 0, T) {
		solve(i + 1);
	}
	return 0;
}
