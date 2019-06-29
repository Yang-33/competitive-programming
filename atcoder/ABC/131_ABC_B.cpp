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

/* -----  2019/06/22  Problem: ABC 131 B / Link: http://abc131.contest.atcoder.jp/tasks/abc131_b  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, L;cin >> N >> L;
	LL all = 0;
	FOR(i, 0, N) {
		all += L + i;
	}
	LL ans = 0;
	LL mindiff = LINF;
	FOR(i, 0, N) {
		LL s = 0;
		FOR(j, 0, N) {
			if (i == j)continue;
			s += L + j;
		}
		if (abs(all - s) < mindiff) {
			ans = s;
			mindiff = abs(all - s);
		}
	}
	cout << ans << endl;

	return 0;
}
