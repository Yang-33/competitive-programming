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

/* -----  2019/04/07  Problem: ABC 029 D / Link: http://abc029.contest.atcoder.jp/tasks/abc029_d  ----- */


LL dp[11][11][2];
LL f(const string &target, int i = 0, int onecnt = 0, int less = 0) {
	if (i == -1) {
		return onecnt;
	}
	if (dp[i][onecnt][less] != -1 && less == 1)return dp[i][onecnt][less];
	LL res = 0;
	int num = target[i] - '0';
	int Max = (less ? 9 : num);
	FOR(nx, 0, Max + 1) {
		res += f(target, i - 1, onecnt + (nx == 1), less || nx < Max);
	}
	if (less == 1)return dp[i][onecnt][less] = res;
	return res;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL n; cin >> n;
	string N = to_string(n);
	FOR(i, 0, 11)FOR(j, 0, 11)FOR(k, 0, 2)dp[i][j][k] = -1;
	reverse(ALL(N));
	LL ret1 = f(N, SZ(N) - 1);
	LL ans = ret1;
	cout << ans << "\n";

	return 0;
}

