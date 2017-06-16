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
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

/* -----  2017/06/16  Problem: AOJ 2311  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2311  ----- */
/* ------問題------

おせろ
探索はせず一回置くときのの最適な置き方をしたときの最終盤面は。

-----問題ここまで----- */
/* -----解説等-----

頑張る。指定された場所からの全方向への盤面更新を行う。
1人目の際は上優先で左優先。 (max<numで更新)
2人目の際は下優先で右優先。（max<=numで更新）
というルールを守って更新すればよい。
実装ゲーだ。

----解説ここまで---- */

ll N;
string s[8];
ll ans = 0LL;

int f(int x, int y, char c, int mode) {
	int ret = 0;
	FOR(k, 0, 8) {
		int nx = x + dx[k]; int ny = y + dy[k];
		bool flag = 0;
		for (;;) {
			if (!(0 <= nx&&nx < 8 && 0 <= ny&&ny < 8))break;
			if (s[ny][nx] == '.')break;
			if (s[ny][nx] == c) {
				flag = 1;
				break;
			}
			nx += dx[k]; ny += dy[k];
		}
		if (flag) {
			int mx = x; int my = y;
			int cnt = 0;
			while (!(mx == nx&&my == ny)) {
				if (mode)s[my][mx] = c;
				mx += dx[k]; my += dy[k];
				if (cnt > 0)ret++;
				cnt++;
			}
		}
	}
	return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	FOR(i, 0, 8)cin >> s[i];

	int turn = 0;
	int change = 0;
	for (;;) {
		int x = -1; int y = -1; int remax = 0;
		FOR(i, 0, 8) {
			FOR(j, 0, 8) {
				if (s[i][j] == '.') {
					char c; if (turn % 2 == 0)c = 'o'; else c= 'x';
					int point = f(j, i, c, 0);
					if (point >= remax&&point >= 1 && turn % 2 == 1) {
						x = j; y = i;
						remax = point;
					}
					else if (point > remax &&point >= 1) {
						x = j; y = i;
						remax = point;
					}
				}
			}
		}
		if (remax == 0) {
			if (change == 0) {
				change = 1;
				turn++;
				continue;
			}
			else if (change == 1)break;
		}
		else {
			char c; if (turn % 2 == 0)c = 'o'; else c='x';
			f(x, y, c, 1);
			change = 0;
			turn++;
		}

	}

	FOR(i, 0, 8)cout << s[i] << endl;

	return 0;
}
