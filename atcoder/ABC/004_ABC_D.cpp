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

/* -----  2019/04/19  Problem: ABC 004 D / Link: http://abc004.contest.atcoder.jp/tasks/abc004_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL R, G, B; cin >> R >> G >> B;
	// Gsについてみる
	// [[ ]] [[ ]] [[ ]]
	LL ans = LINF;
	FOR(Gs, -1000, 1000 + 1) {
		LL Rs = min(-100 - R / 2, Gs - R);
		LL Bs = max(100 - B / 2, Gs + G);

		LL subcost = 0;

		FOR(i, Rs, Rs + R) {
			subcost += abs(-100 - i);
		}
		FOR(i, Gs, Gs + G) {
			subcost += abs(0 - i);
		}
		FOR(i, Bs, Bs + B) {
			subcost += abs(100 - i);
		}

		ans = min(ans, subcost);
	}


	cout << ans << "\n";

	return 0;
}
