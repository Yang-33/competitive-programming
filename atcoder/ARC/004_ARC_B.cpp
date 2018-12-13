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

/* -----  2018/12/13  Problem: ARC 004 B / Link: http://arc004.contest.atcoder.jp/tasks/arc004_b  ----- */
/* ------問題------

平面上に N+1 個の点があり、それぞれ 0 から N までの番号が付けられています。
それぞれの点の位置はわかりませんが、0 以上 N 未満の整数 i について、i 番の点と i+1 番の点の距離 di はわかっています。
0 番の点と N 番の点の距離としてとりうる値の最大と最小を求めてください。

-----問題ここまで----- */
/* -----解説等-----

全探索したらなぜか落ちた。
最大辺をもってきたとき、残りがそれ以上なら必ず0にできる。
そうでないなら辺を畳んだときに余りができる。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	LL sum = accumulate(ALL(a), 0LL);
	cout << sum << endl;

	LL ans = LINF;
	LL mx = *max_element(ALL(a));
	if (sum - mx < mx) {
		ans = mx - (sum - mx);
	}
	else {
		ans = 0;
	}
	cout << ans << "\n";

	return 0;
}
