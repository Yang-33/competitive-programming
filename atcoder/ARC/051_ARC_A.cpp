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

/* -----  2018/11/18  Problem: ARC 051 A / Link: http://arc051.contest.atcoder.jp/tasks/arc051_a  ----- */
/* ------問題------

白く塗られた二次元平面を考えます。
まず、(x1,y1) からの距離が r 以下の部分を赤く塗ります。
そのあと、 x2≦x≦x3,y2≦y≦y3 を満たす (x,y) を青く塗ります。
なお、赤く塗られた後、更に青く塗られた部分は紫色になるとします。
赤く塗られた部分と青く塗られた部分が存在するかどうかをそれぞれ判定してください。

-----問題ここまで----- */
/* -----解説等-----

めんどい…

----解説ここまで---- */

int main() {
	int x1, x2, r, x3, y1, y2, y3;
	cin >> x1 >> y1 >> r;
	cin >> x2 >> y2 >> x3 >> y3;

	using P = complex<double>;
	P c = P(x1, y1);
	if (x1 + r <= x3 && x2 <= x1 - r && y1 + r <= y3 && y2 <= y1 - r) {
		cout << "NO" << endl;
		cout << "YES" << endl;
	}
	else if (abs(c - P(x2, y2)) <= r
		&& abs(c - P(x3, y3)) <= r
		&& abs(c - P(x3, y2)) <= r
		&& abs(c - P(x2, y3)) <= r) {
		cout << "YES" << endl;
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		cout << "YES" << endl;
	}
}