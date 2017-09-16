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

/* -----  2017/09/16  Problem: ARC 038 B / Link: http://arc038.contest.atcoder.jp/tasks/arc038_b  ----- */
/* ------問題------

H 行 W 列のマス目とチェスの駒が 1 つあります。i(1≦i≦H) 行目 j(1≦j≦W) 列目のマスを、マス (i,j) と呼ぶことにします。このとき、左上のマスがマス (1,1) で右下のマスがマス (H,W) となっています。また、マス (1,1) 以外のいくつかのマスには障害物が置いてあります。ゲーム好きな兄妹がこのマス目と駒を使って以下のようなゲームをしようとしています。

最初、駒をマス (1,1) に置く。
プレイヤーは自分のターンに、駒を 1 つ下か 1 つ右下か 1 つ右のマスのうち障害物のないいずれかのマスに動かさなければならない。つまり、駒がマス (i,j) にあるときは、マス (i+1,j) かマス (i+1,j+1) かマス (i,j+1) のうち障害物のないいずれかのマスに動かさなければならない。ただしこのとき、マス目の外に動かすことはできない。すなわち、i=H のときは下や右下には動かせず、j=W のときは右下や右には動かせない。
交互にターンを繰り返し、自分のターンに駒を動かせなくなったプレイヤーの負けとなる（もう一方のプレイヤーが勝ちとなる）。
2 人ともが勝ちを目指して最適な戦略をとったとき、先手と後手のどちらが勝つでしょうか？

-----問題ここまで----- */
/* -----解説等-----

盤面のサイズは小さいので、この盤面のgrundy数を計算すればよい。
Ｏ(HW)ぐらい
grundy数が小さいときはsetじゃなくてbitsetの方がいい気がしてきた。(遅いので)

----解説ここまで---- */

LL N, W, H;
string masu[102];
int ans = 0;
int memo[102][102];
int DX[8] = { 1, 0, 1, -1, 1, 1, -1, -1 };
int DY[8] = { 1, 1, 0, 0, 1, -1, 1, -1 };

int grundy(int h, int w) {
	if (memo[h][w] != -1)return memo[h][w];
	set<int>se;
	FOR(i, 0, 3) {
		int nh = h + DY[i];
		int nw = w + DX[i];
		if (nh < H&&nw < W) {
			if (masu[nh][nw] != '#') {
				//cout << "insert" << endl;
				se.insert(grundy(nh, nw));
				//cout << "end insert" << endl;
			}
		}
	}

	int subg = 0;
	while (se.count(subg))subg++;

	return memo[h][w] = subg;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> H >> W;
	FOR(i, 0, H) {
		cin >> masu[i];
	}
	FOR(i, 0, 102)FOR(j, 0, 102)memo[i][j] = -1;
	//cout << "adfa" << endl;
	cout << ((grundy(0, 0) != 0) ? "First" : "Second") << "\n";

	return 0;
}