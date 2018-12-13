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
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/12/13  Problem: ARC 005 B / Link: http://arc005.contest.atcoder.jp/tasks/arc005_b  ----- */
/* ------問題------

高橋君は来る 7 月 27 日の土用の丑の日に備えて、高級なうなぎを通販で買うことにしました。支払いはネット銀行を通して行います。
　高橋君が利用しているネット銀行のカードの裏には、下図のような縦 9 文字 ×横 9 文字の数字から成る乱数表がついています。支払う時は、この乱数表の指定された位置から縦横斜めの中で指定された向きに 4 文字連続で抜き出して入力し、それが正しいかによって本人確認を行います。
 　下図は「上から 1 文字目、左から 1 文字目」の位置から「右下斜め」の方向が指定された時の 4 文字を抜き出した例です。この場合は 7930 が入力する数字になります。

  図：1 行目 1 文字目から右下方向に 4 文字抜き出す例
  　乱数表の一番端の文字を抜き出した後もさらに文字を抜き出す必要がある場合は、向きを変更して残りの文字を抜き出します。向きの変更は以下のように行います。

   読み込み時に進んでいた方向が上下左右の場合
   向きを 180 度変える
   読み込み時に進んでいた方向が斜めの場合
   角で向きを変更する場合
   向きを 180 度変える
   左右の端で向きを変更する場合
   左右への向きのみ逆にし、上下への向きはそのままにする
   上下の端で向きを変更する場合
   上下への向きのみ逆にし、左右への向きはそのままにする
   　これらの向きの変更を図で示すと下図のようになる。

	図：変更する向きの一覧
	　乱数表、抜き出す最初の数字の位置、抜き出す向きが与えられる時、本人確認のため入力する 4 文字を答えてください。

-----問題ここまで----- */
/* -----解説等-----

シュミレーションすればよい。はみ出たときの処理をどくりつしてやればスッキリかける。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int X, Y; cin >> X >> Y; X--, Y--;
	string s; cin >> s;
	VS vs(9);
	FOR(i, 0, 9) {
		cin >> vs[i];
	}
	int dx = -2, dy = -2;
	if (s == "R") {
		dx = 1; dy = 0;
	}
	else if (s == "U") {
		dx = 0; dy = -1;
	}
	else if (s == "L") {
		dx = -1; dy = 0;
	}
	else if (s == "D") {
		dx = 0; dy = 1;
	}
	else if (s == "RU") {
		dx = 1; dy = -1;
	}
	else if (s == "LU") {
		dx = -1; dy = -1;
	}
	else if (s == "LD") {
		dx = -1; dy = 1;
	}
	else if (s == "RD") {
		dx = 1; dy = 1;
	}
	else {
		assert(0);
	}
	FOR(i, 0, 4) {
		//ans *= 10;
		//ans += (vs[Y][X] - '0');
		cout << vs[Y][X];
		if (X + dx < 0 || X + dx>8) {
			dx *= -1;
		}
		if (Y + dy < 0 || Y + dy>8) {
			dy *= -1;
		}
		X += dx;
		Y += dy;

	}
	cout /*<< ans*/ << "\n";

	return 0;
}
