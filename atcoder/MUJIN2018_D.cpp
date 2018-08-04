#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/08/04  Problem: mujin2018 D / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */


int dp[1000][1000];

int rev[1000];

int f(int x, int y) {
	if (x == 0 || y == 0)return 0;
	if (dp[x][y] != -1)return dp[x][y];

	int X = x; int Y = y;
	dp[x][y] = 1;

	if (x < y) {
		x = rev[x];
	}
	else {
		y = rev[y];
	}

	if (x > y) {
		x = x - y;
	}
	else {
		y = y - x;
	}
	int res = f(x, y);

	return dp[X][Y] = res;

}

int g(int n) {
	string s = to_string(n);
	int res = 0;;

	FOR(i, 0, SZ(s)) {
		res *= 10;
		res += s[SZ(s) - 1 - i] - '0';
	}
	return res;

}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	fill(*dp, *dp + 1000 * 1000, -1);

	FOR(i, 1, 1000) {
		rev[i] = g(i);
	}

	FOR(x, 1, N + 1) {
		FOR(y, 1, M + 1) {
			f(x, y);
		}
	}

	int ans = 0;
	FOR(x, 1, N + 1) {
		FOR(y, 1, M + 1) {
			if (dp[x][y] == 1) {
				ans++;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
