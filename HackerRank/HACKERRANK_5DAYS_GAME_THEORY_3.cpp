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

/* -----  2017/09/15  Problem: hackerrank_5days_game_theory_3  / Link: https://www.hackerrank.com/contests/5-days-of-game-theory/challenges/day-1-a-chessboard-game  ----- */
/* ------問題------

盤面の(1,1)側にしか進めないチェスのナイトがある。2人のプレイヤーで交互に動かしたとき、
最適な動きをしたとするとどちらが勝つか。

-----問題ここまで----- */
/* -----解説等-----

grundy数。終局面を0にしてあとはメモ化再帰で現在の盤面を求めておわり

----解説ここまで---- */

VVI game;

int grundy(int x, int y) {
	int &g = game[x][y];
	if (g != -1)return g;

	set<int>se;
	if (x - 2 > 0) {
		if (y + 1 < 16 && y + 1 > 0)se.insert(grundy(x - 2, y + 1));
		if (y - 1 < 16 && y - 1 > 0)se.insert(grundy(x - 2, y - 1));
	}
	if (y-2>0) {
		if (x + 1 < 16 && x + 1 > 0)se.insert(grundy(x + 1, y - 2));
		if (x - 1 < 16 && x - 1 > 0)se.insert(grundy(x - 1, y - 2));
	}
	int subg = 0;
	while (se.count(subg))subg++;
	return g = subg;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	game = VVI(16, VI(16, -1));
	FOR(t, 0, T) {
		int X, Y;
		cin >> X >> Y;
		cout << ((grundy(X,Y)!=0)?"First":"Second") << "\n";
	}
	return 0;
}
