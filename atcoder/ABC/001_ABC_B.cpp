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

/* -----  2019/04/22  Problem: ABC 001 B / Link: http://abc001.contest.atcoder.jp/tasks/abc001_b  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int m; cin >> m;
	int ans = 0;

	if (m < 100)
		ans = 0;
	else if (m <= 5000)
		ans = m / 100;
	else if (m <= 30000)
		ans = m / 1000 + 50;
	else if (m <= 70000)
		ans = (m / 1000 - 30) / 5 + 80;
	else
		ans = 89;
	printf("%02d\n", ans);

	return 0;
}
