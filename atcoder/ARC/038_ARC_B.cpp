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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DEBUG(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);

/* -----  2018/10/19  Problem: ARC 038 B / Link: http://arc038.contest.atcoder.jp/tasks/arc038_b  ----- */
/* ------問題------

H 行 W 列のマス目とチェスの駒が 1 つあります。i(1≦i≦H) 行目 j(1≦j≦W) 列目のマスを、マス (i,j) と呼ぶことにします。このとき、左上のマスがマス (1,1) で右下のマスがマス (H,W) となっています。また、マス (1,1) 以外のいくつかのマスには障害物が置いてあります。ゲーム好きな兄妹がこのマス目と駒を使って以下のようなゲームをしようとしています。

最初、駒をマス (1,1) に置く。
プレイヤーは自分のターンに、駒を 1 つ下か 1 つ右下か 1 つ右のマスのうち障害物のないいずれかのマスに動かさなければならない。つまり、駒がマス (i,j) にあるときは、マス (i+1,j) かマス (i+1,j+1) かマス (i,j+1) のうち障害物のないいずれかのマスに動かさなければならない。ただしこのとき、マス目の外に動かすことはできない。すなわち、i=H のときは下や右下には動かせず、j=W のときは右下や右には動かせない。
交互にターンを繰り返し、自分のターンに駒を動かせなくなったプレイヤーの負けとなる（もう一方のプレイヤーが勝ちとなる）。
2 人ともが勝ちを目指して最適な戦略をとったとき、先手と後手のどちらが勝つでしょうか？

-----問題ここまで----- */
/* -----解説等-----

盤面のサイズは小さいので、この盤面のgrundy数を計算すればよい。
O(HW)ぐらい

----解説ここまで---- */


int DY[3] = { 1, 1, 0, };
int DX[3] = { 0, 1, 1, };
int memo[110][110];
int H, W;
int f(int y, int x, const VS& vs) {
	if (memo[y][x] != -1)return memo[y][x];

	set<int>se;
	FOR(k, 0, 3) {
		int ny = y + DY[k], nx = x + DX[k];
		if (0 <= ny && ny < H && 0 <= nx && nx < W) {
			if (vs[ny][nx] != '#')
				se.insert(f(ny, nx, vs));
		}
	}

	int subgame = 0;
	while (se.count(subgame))subgame++;
	return memo[y][x] = subgame;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> H >> W;
	VS vs(H);
	FOR(i, 0, H) {
		cin >> vs[i];
	}
	fill(*memo, *memo + 110 * 110, -1);
	int ans = f(0, 0, vs);
	DEBUG(debug(ans));
	VVI res(H, VI(W, 0));
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			res[i][j] = memo[i][j];
		}
	}

	DEBUG(D(res));
	cout << (ans ? "First" : "Second") << endl;

	return 0;
}