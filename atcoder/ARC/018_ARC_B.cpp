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

/* -----  2018/11/21  Problem: ARC 018 B / Link: http://arc018.contest.atcoder.jp/tasks/arc018_b  ----- */
/* ------問題------

諸君、私は整数が好きだ。
私は格子点が好きだ。
私は面積が好きだ。
私は三角形が好きだ。
私は座標平面上の、頂点が全て格子点上にある、面積が整数の三角形が大好きだ。
格子点の集合をみたとき、その中の任意の 3 点を選んで作ることができる面積が整数の三角形の個数を数えるときは心が踊る。
心が踊るが、格子点が多いと数えるのが面倒臭い。
ぜひ有能なプログラマーである諸君に私の代わりに数えてほしい。
N 個の格子点を与えるので、その中の任意の 3 点を選んで作ることができる、面積が整数の三角形の個数を数えるプログラムを作って欲しい。面積が 0 の三角形は三角形とは認めん！
ちなみに、格子点というのは座標平面上の点 (x,y) のうち x も y も整数である点のことである。

-----問題ここまで----- */
/* -----解説等-----

N^3が許されるのでやる。
面積公式が偶数である^面積が0でないで良い
intにしていたので落ちてた。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	// 面積が整数の三角形の個数
	VL x(N), y(N);
	FOR(i, 0, N) {
		cin >> x[i] >> y[i];
	}
	LL ans = 0;
	FOR(i, 0, N) {
		FOR(j, i + 1, N) {
			FOR(k, j + 1, N) {
				LL a = (x[i] - x[k])*(y[j] - y[k]);
				LL b = (x[j] - x[k])*(y[i] - y[k]);
				if ((a & 1) == (b & 1)) {
					if (a != b)ans++;
				}
			}
		}
	}
	cout << ans << endl;

	return 0;
}
