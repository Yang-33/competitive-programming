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

/* -----  2017/05/12  Problem:  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

int N;
string m[300];
bool masu[300][300];


ll solve(int n) {
	FOR(i, 0, 300)FOR(j, 0, 300)masu[i][j] = 0;

	FOR(i, 0, n) {
		cin >> m[i];
	}
	FOR(i, 0, n) {
		FOR(j, 0, n) {
			masu[i][j] = m[i][j] - '0';
		}
	}
	ll ans = 0;//max

	//yoko
	ll ren = 0;
	FOR(i, 0, n) {
		ren = 0;
		FOR(j, 0, n) {
			if (masu[i][j] == 1) {
				ren++;
				ans = max(ans, ren);
			}
			else ren = 0;
		}
	}
	//tate
	FOR(i, 0, n) {
		ren = 0;
		FOR(j, 0, n) {
			if (masu[j][i] == 1) {
				ren++;
				ans = max(ans, ren);
			}
			else ren = 0;
		}
	}

	//右下
	queue<pii>q;
	FOR(i, 0, n) {
		q.push(pii(0, i));
		q.push(pii(i, 0));
	}
	while (!q.empty()) {

		pii s = q.front(); q.pop();
		int y = s.first; int x = s.second;
		ren = 0;
		FOR(i, 0, n) {
			if (0 <= i + x&&i + x < n && 0 <= i + y&&i + y < n) {
				if (masu[y + i][x + i] == 1) {
					ren++;
					ans = max(ans, ren);
				}
				else ren = 0;
			}
			else break;
		}
	}


	//左下
	FOR(i, 0, n) {
		q.push(pii(0, i));
		q.push(pii(i, n-1));
	}
	while (!q.empty()) {

		pii s = q.front(); q.pop();
		int y = s.first; int x = s.second;
		ren = 0;
		FOR(i, 0, n) {
			if (0 <= -i + x&&-i + x < n && 0 <= i + y&&i + y < n) {
				if (masu[y + i][x - i] == 1) {
					ren++;
					ans = max(ans, ren);
				}
				else ren = 0;
			}
			else break;
		}
	}
	return ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	for (;;) {
		cin >> N;
		if (N == 0)break;

		cout << solve(N) << endl;
	}
	return 0;
}
