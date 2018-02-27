#include <bits/stdc++.h>
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

/* -----  2018/02/27  Problem: 072_arc_b / Link: https://abc059.contest.atcoder.jp/tasks/arc072_b?lang=en  ----- */
/* ------問題------

AliceとBrownはゲームをするのが好きです。今日は以下のゲームを思いつきました。
2つの山があり、はじめにX,Y個の石が置かれています。 AliceとBrownは毎ターン以下の操作を交互に行い、操作を行えなくなったプレイヤーは負けとなります。
片方の山から 2i 個の石を取り、そのうち i 個の石を捨て、残りの i 個の石をもう片方の山に置く。ここで、整数 i(1≦i) の値は山に十分な個数の石がある範囲で自由に選ぶことができる。
Aliceが先手で、二人とも最適にプレイすると仮定したとき、与えられた X,Y に対しどちらのプレイヤーが勝つか求めてください。

-----問題ここまで----- */
/* -----解説等-----

(0,0),(0,1),(1,0),(1,1)は負けの盤面
またそれ以外の任意の盤面は(a,a±1)みたいなところに移動できる。
したがってこれらは負け

----解説ここまで---- */

LL X,Y;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> X>>Y;

	cout << (abs(X-Y)<2?"Brown":"Alice") << "\n";

	return 0;
}
