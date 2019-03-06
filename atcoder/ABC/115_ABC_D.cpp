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

/* -----  2019/02/27  Problem: ABC 115 D / Link: http://abc115.contest.atcoder.jp/tasks/abc115_d  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	VL lsum(100);
	VL lPsum(100);
	lsum[0] = 1;
	lPsum[0] = 1;
	FOR(i, 1, 51) {
		lsum[i] = 1 + lsum[i - 1] + 1 + lsum[i - 1] + 1;
		lPsum[i] = 0 + lPsum[i - 1] + 1 + lPsum[i - 1] + 0;
	}
	LL N, X; cin >> N >> X;
	function<LL(int, LL&)> dfs = [&](int LV, LL &leftX) {
		LL Pcnt = 0;
		if (leftX > 0) {// B
			leftX--;
		}
		if (leftX > 0) { // block
			if (leftX >= lsum[LV-1]) {
				Pcnt += lPsum[LV-1];
				leftX -= lsum[LV-1];
			}
			else {
				Pcnt += dfs(LV - 1, leftX);
			}
		}
		if (leftX > 0) { // P
			Pcnt++;
			leftX--;
		}
		if (leftX > 0) { // block
			if (leftX >= lsum[LV-1]) {
				Pcnt += lPsum[LV-1];
				leftX -= lsum[LV-1];
			}
			else {
				Pcnt += dfs(LV - 1, leftX);
			}
		}
		if (leftX > 0) {// B
			leftX--;
		}

		return Pcnt;
	};

	ans = dfs(N, X);
	cout << ans << "\n";

	return 0;
}
