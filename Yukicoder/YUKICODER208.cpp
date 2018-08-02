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

/* -----  2018/08/02  Problem: yukicoder 208  / Link: http://yukicoder.me/problems/no/208  ----- */
/* ------問題------

将棋の王将の駒は8方向に1マス移動できる。
(0,0)にいる時は、(−1,1),(0,1),(1,1),(−1,0),(1,0),(−1,−1),(0,−1),(1,−1)のいずれかに移動できる。
今、王将が(0,0)のマスにいる。
一刻も早く(x,y)のマスに移動したい。
しかし、味方の歩兵が(x2,y2)にいて邪魔になっている。
(0,0)から(x,y)に移動する最短手数を求めよ。
ただし、歩兵を動かすことは出来ない。
この将棋盤は無限に大きく、負の座標のマスも存在する。(入力には負の座標は与えられない)

-----問題ここまで----- */
/* -----解説等-----

斜めに移動できるので、だいたいmax(X,Y)で移動できる。
ただし、y=|x|上に邪魔な点と目標のマスへ行くときはダメなので+1回必要。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL x, y; cin >> x >> y;
	LL ans = max(x, y);
	LL x1, y1;  cin >> x1 >> y1;
	if (x == y&&x1 == y1&&x*y1 == y*x1&& x1<x)ans++;

	cout << ans << "\n";

	return 0;
}
