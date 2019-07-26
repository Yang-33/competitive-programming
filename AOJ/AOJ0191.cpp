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

/* -----  2019/07/26  Problem: AOJ 0191 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0191  ----- */


int main() {

	int N, M;
	while (cin >> N >> M, N) {
		// dp
		vector<vector<double>> a(N, vector<double>(N)); {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					cin >> a[i][j];
				}
			}
		}
		vector<vector<double>>dp(M, vector<double>(N, 0));
		FOR(i, 0, N) {
			dp[0][i] = 1.0;
		}
		auto chmax = [](auto &a, auto b) {
			a = max(a, b);
		};
		FOR(i, 0, M-1) {
			FOR(from, 0, N) {
				FOR(to, 0, N) {
					chmax(dp[i + 1][to], dp[i][from] * a[from][to]);
				}
			}
		}
		double ans = 0.0; {
			FOR(i, 0, N) {
				chmax(ans, dp[M-1][i]);
			}
		}
		ans = round(ans * 100) / 100;
		printf("%.2f\n", ans);
	}

	return 0;
}
