#include "bits/stdc++.h"
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
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

/* -----  2017/11/05  Problem: 99_b_div1_codeforces / Link: http://codeforces.com/problemset/problem/138/D  ----- */
/* ------問題------

二人でゲームを行う。
長方形領域の盤面に、L,R,Xが書かれている。
全てのマスをactiveであるとして交互に盤面を選択する。
L,R,Xはそれぞれ、L:最右のactiveな右上のマスからから最左のactiveな左下のマスをinactiveにする。
R: L の左右逆の動作
X: LとRの両方の操作をする
最後に盤面を操作不能にした人の勝ちである。
どちらが勝つか。

-----問題ここまで----- */
/* -----解説等-----

プレイヤーの操作は不偏である。
盤面を分割することになるので、これはgrundy数をメモ化しておけばよいことになる。
斜めに操作するのはめんどくさいので、回転させておけばよい。

----解説ここまで---- */

LL H, W;
string masu[20];
LL ans = 0LL;
LL dp[41][41][41][41][2];


// 閉区間でやった [a,b]
LL grundy(int y1, int y2, int x1, int x2, int bip) {
	if ((y2 - y1 < 1) || (x2 - x1 < 1))return 0;
	LL &res = dp[y1][y2][x1][x2][bip];
	if (res != -1)return res;
	bool se[500] = {};

	FOR(i, 0, H) {
		FOR(j, 0, W) {
			int ny = j + i;
			int nx = j - i + H - 1;
			if (ny % 2 != bip)continue;
			int g = 0;
			if (y1 <= ny&&ny < y2&&x1 <= nx&&nx < x2) {
				if (masu[i][j] == 'R') {
					g = grundy(y1, y2, x1, nx, bip) ^ grundy(y1, y2, nx + 1, x2, bip);
				}
				else if (masu[i][j] == 'L') {
					g = grundy(y1, ny, x1, x2, bip) ^ grundy(ny + 1, y2, x1, x2, bip);
				}
				else if (masu[i][j] == 'X') {
					g = grundy(y1, ny, x1, nx, bip) ^ grundy(y1, ny, nx + 1, x2, bip)
						^ grundy(ny + 1, y2, x1, nx, bip) ^ grundy(ny + 1, y2, nx + 1, x2, bip);
				}
				se[g] = 1;
			}
		}
	}


	LL subg = 0;
	while (se[subg])subg++;
	return res = subg;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> H >> W;
	FOR(i, 0, H) {
		cin >> masu[i];
	}
	fill(****dp, ****dp + 41 * 41 * 41 * 41 * 2, -1);
	int mht = H + W - 1;
	ans = grundy(0, mht, 0, mht, 0) ^ grundy(0, mht, 0, mht, 1);
	cout << (ans != 0 ? "WIN" : "LOSE") << "\n";

	return 0;
}
