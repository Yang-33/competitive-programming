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

/* -----  2019/05/19  Problem: ABC 126 C / Link: http://abc126.contest.atcoder.jp/tasks/abc126_c  ----- */

double  POW(double  x, long long n) {
	double  res = 1;
	while (n > 0) {
		if (n & 1) {
			res = (res*x);
		}
		x = (x*x);
		n >>= 1;
	}
	return res;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	LL K; cin >> K;

	auto f = [](int i, LL K) {
		// i*2^ans >=K
		LL two = 1;
		FOR(k, 0, 40) {
			if (i*two >= K) {
				return k;
			}
			two *= 2;
		}
	};
	double ans = 0;
	FOR(i, 1, N + 1) {
		// iがでる
		LL x = f(i, K);
		ans += POW(0.5, x);
	}
	ans /= N;

	cout << fixed << setprecision(10) << ans << endl;

	return 0;
}
