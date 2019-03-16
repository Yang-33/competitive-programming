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

/* -----  2019/03/12  Problem: ABC 078 D / Link: http://abc078.contest.atcoder.jp/tasks/abc078_d  ----- */



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, Z, W; cin >> N >> Z >> W;
	vector<LL> a(N + 1);
	a.front() = W;
	for (int i = 0; i < N; ++i) {
		cin >> a[i + 1];
	}
	VVL dp(N + 1, VL(2, -1e18));
	function<LL(int, bool)> f = [&](int pos, bool turn) {
		if (dp[pos][turn] != -1e18)return dp[pos][turn];
		LL ret;
		if (!turn) {
			ret = -LINF;
			FOR(i, pos + 1, N + 1) {
				if (i == N)ret = max(ret, abs(a[pos] - a.back()));
				else ret = max(ret, f(i, !turn));
			}
		}
		else {
			ret = LINF;
			FOR(i, pos + 1, N + 1) {
				if (i == N)ret = min(ret, abs(a[pos] - a.back()));
				else ret = min(ret, f(i, !turn));
			}
		}
		return dp[pos][turn] = ret;
	};

	LL ans = f(0, 0);


	cout << (ans) << "\n";

	return 0;
}
