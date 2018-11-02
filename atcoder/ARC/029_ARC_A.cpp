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

/* -----  2018/11/03  Problem: ARC 029 A / Link: http://arc029.contest.atcoder.jp/tasks/arc029_a  ----- */
/* ------問題------

高橋君は友達とキャンプに行くことになった。
高橋君と友達は性能が同じである 2 個の肉焼き器を持っており、それぞれの肉焼き器にお肉を乗せて並行して焼くことができる。一旦肉焼き器にお肉を乗せたら、お肉が焼きあがるまではその肉焼き器からお肉を取り出したり、その肉焼き器に別のお肉を乗せたりはできない。お肉が焼けたらお肉を取り出すことができる。2 つの肉焼き器にまたがって 1 つのお肉を置くことはできない。また、お肉は全部で N 個あり、お肉には 1 から N まで番号が付けられている。お肉 i を焼くのには、どちらの肉焼き器でも時間 ti だけかかる。お肉を肉焼き器に置く動作、取り出す動作には時間がかからない。
高橋君はお肉を焼く係であり、N 個すべてのお肉を焼くことになった。みんなお腹が空いているので、すべてのお肉を焼くのにかかる時間を最小化させたい。
すべてのお肉を焼くのにかかる時間の最小値を求めよ。

-----問題ここまで----- */
/* -----解説等-----

N=4までなので、思考停止2^Nでよい。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	// 4個
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	ans = LINF;
	SORT(a);
	FOR(bit, 0, 1 << N) {
		LL A = 0;
		LL B = 0;
		FOR(i, 0, N) {
			if (bit & 1 << i)A += a[i];
			else B += a[i];
		}
		ans = min(ans, max(A, B));
	}

	cout << ans << "\n";

	return 0;
}