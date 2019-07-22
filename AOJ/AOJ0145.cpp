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

/* -----  2019/07/21  Problem: AOJ 0145 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0145  ----- */



int main() {
	// となりあうものを最適なmerge
	// -> 区間dp
	int N; cin >> N;
	VVL dp(N, VL(N, LINF));
	vector<LL> a(N), b(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i] >> b[i];
	}
	// [L,R]
	function<LL(int, int)>f = [&](int L, int R) {
		if (L == R)return 0LL;
		if (dp[L][R] != LINF)return dp[L][R];
		LL ret = LINF;
		FOR(c, L, R) {
			LL Lcost = f(L, c);
			LL Rcost = f(c + 1, R);
			LL mergecost = a[L] * b[c] * a[c + 1] * b[R];
			ret = min(ret, Lcost + Rcost + mergecost);
		}
		return dp[L][R] = ret;
	};
	LL ans = f(0, N - 1);
	cout << ans << "\n";

}