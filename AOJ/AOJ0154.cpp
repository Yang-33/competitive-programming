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

/* -----  2019/07/23  Problem: AOJ 0154 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0154  ----- */


int main() {
	int M;
	while (cin >> M, M) {
		VVL dp(M + 1, VL(1001, 0));
		vector<int> a(M), b(M);
		for (int i = 0; i < M; ++i) {
			cin >> a[i] >> b[i];
		}
		dp[0][0] = 1;
		FOR(i, 0, M) {
			FOR(s, 0, 1001) {
				FOR(k, 0, b[i] + 1) {
					if (s + k * a[i] <= 1000)
						dp[i + 1][s + k * a[i]] += dp[i][s];
				}
			}
		}
		int Q; cin >> Q;
		FOR(_, 0, Q) {
			int n; cin >> n;
			cout << dp[M][n] << "\n";
		}


	}
}