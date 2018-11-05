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

/* -----  2018/11/05  Problem: ARC 047 B / Link: http://arc047.contest.atcoder.jp/tasks/arc047_b  ----- */
/* ------問題------

座標平面上に N 個の点があります。
これらの点は全て、x 座標 と y 座標の値が共に整数です。つまり格子点上にあります。
そのうえ、これらの点は全て、ある点 P とのマンハッタン距離が同じであることがわかっています。ここで、マンハッタン距離とは、 2 つの点の座標がそれぞれ (a,b),(c,d) であるとき、 |a−c|+|b−d| で計算される距離のことです。
そして、点 P も格子点上にあります。
点 P としてあり得る点を 1 つ挙げてください。

-----問題ここまで----- */
/* -----解説等-----

45度回転をする。一意に大きさは定まるが、与えられた点の端から中心を求める際に足りていない場所から補間することができない。
よって上下左右のどれを選択するかを全部試して配置を検討すれば良い。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VL x(N), y(N);
	VL mx(N), my(N);
	FOR(i, 0, N) {
		cin >> x[i] >> y[i];
		mx[i] = x[i] - y[i];
		my[i] = x[i] + y[i];
	}
	DD(De(mx, my));
	LL xmin = *min_element(ALL(mx));
	LL xmax = *max_element(ALL(mx));
	LL ymin = *min_element(ALL(my));
	LL ymax = *max_element(ALL(my));

	LL W = abs(xmax - xmin);
	LL H = abs(ymax - ymin);
	LL acW = max(H, W);
	DD(de(W, H, acW));
	auto check = [&](LL cx, LL cy) {
		LL rcx = (cx + cy) / 2;
		LL rcy = (-cx + cy) / 2;
		LL dist = abs(x.front() - rcx) + abs(y.front() - rcy);
		bool ok = 1;
		FOR(i, 1, N) {
			if (dist != abs(x[i] - rcx) + abs(y[i] - rcy))ok = 0;

		}
		DD(de(cx, cy, rcx, rcy,ok));
		return ok;
	};
	LL ansx, ansy;
	if (check(xmin + acW / 2, ymin + acW / 2)) {
		ansx = (xmin + ymin + acW) / 2, ansy = (-xmin + ymin) / 2;
	}
	else if (check(xmax - acW / 2, ymin + acW / 2)) {
		ansx = (xmax + ymin) / 2, ansy = (-xmax + ymin + acW) / 2;
	}
	else if (check(xmin + acW / 2, ymax - acW / 2)) {
		ansx = (xmin + ymax) / 2, ansy = (-xmin + ymax - acW) / 2;
	}
	else if (check(xmax - acW / 2, ymax - acW / 2)) {
		ansx = (xmax + ymax - acW) / 2, ansy = (-xmax + ymax) / 2;
	}

	cout << ansx << " " << ansy << endl;
	return 0;
}
