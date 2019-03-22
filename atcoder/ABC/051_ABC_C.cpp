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

/* -----  2019/03/22  Problem: ABC 051 C / Link: http://abc051.contest.atcoder.jp/tasks/abc051_c  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
	LL x = tx - sx, y = ty - sy;

	string U = string(y, 'U');
	string R = string(x, 'R');
	string D = string(y, 'D');
	string L = string(x, 'L');
	string ans = U + R + D + L + "LU" + U + R + "RDRD" + D + L + "LU";
	
	
	cout << (ans) << "\n";

	return 0;
}
