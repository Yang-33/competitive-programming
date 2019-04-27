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

/* -----  2019/04/19  Problem: ABC 007 D / Link: http://abc007.contest.atcoder.jp/tasks/abc007_d  ----- */

LL dp[20][2][2];
LL f(string &target, int i = 0, int no = 0, int less = 0) {
	if (i == -1) {
		if (no == 1)return 1;
		else return 0;
	}

	if (dp[i][no][less] != -1 && less == 1)return dp[i][no][less];;
	LL res = 0;
	int num = target[i] - '0';
	int Max = (less ? 9 : num);
	FOR(nx, 0, Max + 1) {
		res += f(target, i - 1, no || nx == 4 || nx == 9, less || nx < Max);
	}
	if (less == 1)return dp[i][no][less] = res;
	return res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL a, b;
	cin >> a >> b;
	a--;

	string A = to_string(a);
	string B = to_string(b);

	fill(**dp, **dp + 20 * 2 * 2, -1);

	reverse(ALL(A));
	reverse(ALL(B));

	LL ret2 = f(A, SZ(A) - 1);
	LL ret1 = f(B, SZ(B) - 1);

	LL ans = ret1 - ret2;
	cout << ans << "\n";

	return 0;
}
