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

/* -----  2017/08/01  Problem: KotamanegiOJ_Otemae E  / Link: https://kotamanegi.com/JudgeSystem/Problems/view/index.php?page=42  ----- */
/* ------問題------

オセロ。
次の手が与えられるので盤面を更新せよ

-----問題ここまで----- */
/* -----解説等-----

実装をね、しません。(ICPCのをはっつけた)

----解説ここまで---- */

ll N;

ll ans = 0LL;
string s[8];

void f(int x, int y, int turn) {
	char cc; char aite;
	if (turn == 0)cc = 'b',aite='w';
	else cc = 'w', aite = 'b';
	s[y][x] = cc;
	int ret = 0;
	int mode = 1;
	FOR(k, 0, 8) {
		int nx = x + dx[k]; int ny = y + dy[k];
		bool flag = 0;
		for (;;) {
			if (!(0 <= nx&&nx < 8 && 0 <= ny&&ny < 8))break;
			if (s[ny][nx] == '-')break;
			if (s[ny][nx] == cc) {
				flag = 1;
				break;
			}
			nx += dx[k]; ny += dy[k];
		}
		if (flag) {
			int mx = x; int my = y;
			int cnt = 0;
			while (!(mx == nx&&my == ny)) {
				if (mode)s[my][mx] = cc;
				mx += dx[k]; my += dy[k];
				if (cnt > 0)ret++;
				cnt++;
			}
		}
	}
	
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	FOR(i, 0, 8) {
		cin >> s[i];
	}
	int C;
	string T;
	cin >> C >> T;
	int x = T[0] - 'A';
	int y = T[1] - '1';
	f(x, y, C);

	FOR(i, 0, 8) {
		cout << s[i] << endl;
	}
	return 0;
}
