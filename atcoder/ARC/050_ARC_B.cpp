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

/* -----  2018/11/07  Problem: ARC 050 B / Link: http://arc050.contest.atcoder.jp/tasks/arc050_b  ----- */
/* ------問題------

高橋君は赤い花を R 本、青い花を B 本持っています。高橋君は次の 2 種類の花束を作ることができます。
x 本の赤い花と 1 本の青い花からなる花束
1 本の赤い花と y 本の青い花からなる花束
高橋君が作ることのできる花束の個数の最大値を求めてください。すべての花を使い切る必要はありません。

-----問題ここまで----- */
/* -----解説等-----

K本つくるならば、少なくとも赤い花も青い花もK本必要で、かつ、貪欲に作成して足りる必要がある。
K本作れるなら、K+1本も作れるので、二分探索すれば良い。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL R, B; cin >> R >> B;
	LL needR, needB; cin >> needR >> needB;

	auto f = [&](LL x) {
		LL a = R, b = B;
		if (a < x || b < x)return false;
		a -= x, b -= x;
		LL cnt = max(0LL, a / (needR - 1))
			+ max(0LL, b / (needB - 1));
		return cnt >= x;
	};
	LL L = 0; LL Rr = 1e18;
	while (Rr - L > 1) {
		LL mid = (L + Rr) / 2;
		if (f(mid)) {
			L = mid;
		}
		else {
			Rr = mid;
		}
	}
	ans = L;

	cout << ans << "\n";

	return 0;
}
