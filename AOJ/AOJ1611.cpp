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

/* -----  2019/06/03  Problem: AOJ 1611 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/1611  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	while (cin >> N, N) {
		vector<int> a(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
		}
		// 区間dpする
		// dp(L,R):= [L,R]を
		VVI dp(N, VI(N, -1));
		function<int(int, int)> f = [&](int L, int R) {
			if (L == R)return 0;
			int& ret = dp[L][R];
			if (ret != -1)return ret;
			ret = 0;
			if (R - L >= 1 && f(L + 1, R - 1) == R - L - 1
				&& abs(a[L] - a[R]) <= 1) {
				ret = R - L + 1;
			}
			FOR(m, L, R) {
				ret = max(ret, f(L, m) + f(m + 1, R));
			}
			return ret;
		};
		LL ans = f(0, N - 1);
		cout << (ans) << "\n";
	}


	return 0;
}
