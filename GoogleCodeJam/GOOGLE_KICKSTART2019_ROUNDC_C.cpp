//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
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

/* -----  2019/05/26  Problem: google_kickstart2019_roundC C / Link: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050ff2  ----- */

// 
void solve(int testcasenum) {

	int N, K; cin >> N >> K;
	DD(de(N, K));
	vector<LL> P(N);
	for (int i = 0; i < N; ++i) {
		cin >> P[i];
	}
	vector<LL> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		A[i]--;
	}
	VVI as(1000);
	FOR(i, 0, N) {
		as[A[i]].push_back(P[i]);
	}
	FOR(i, 0, 1000) {
		SORT(as[i]);
	}

	LL ans = LINF;
	DD(de(ans));
	auto test = [&]() {
		// napsack
		VVL dp(K + 1, VL(2, LINF));
		dp[0][0] = 0;

		FOR(i, 0, 1000) {// O(NK)
			FORR(k, K - 1, 0 - 1) {
				FOR(j, 0, SZ(as[i])) {
					if (k + (j + 1) <= K) {
						dp[k + (j + 1)][0] = min(dp[k + (j + 1)][0], dp[k][0] + 2 * as[i][j]);
						dp[k + (j + 1)][1] = min(dp[k + (j + 1)][1], dp[k][0] + 1 * as[i][j]);
						dp[k + (j + 1)][1] = min(dp[k + (j + 1)][1], dp[k][1] + 2 * as[i][j]);
					}
				}
			}
		}
		FOR(i, 0, K + 1) {
			DD(de(dp[i][0], dp[i][1]))
		}
		ans = (dp[K][1]);

		DD(de(ans));
	};
	test();
	//if (0) { // OK but TLE...??
	//	FOR(fin, 0, 1000) {
	//		if (SZ(as[fin]) == 0)continue;
	//		// napsack
	//		VL dp(K + 1, LINF);
	//		dp[0] = 0;
	//		FOR(i, 0, 1000) {// O(NK)
	//			if (fin == i)continue;
	//			if (SZ(as[i]) == 0)continue;
	//			FORR(k, K - 1, 0 - 1) {
	//				if (dp[k] == LINF)continue;
	//				FOR(j, 0, SZ(as[i])) {
	//					if (k + (j + 1) <= K)
	//						dp[k + (j + 1)] = min(dp[k + (j + 1)], dp[k] + 2 * as[i][j]);
	//				}
	//			}
	//		}
	//		LL ret = dp[K];
	//		FOR(j, 0, SZ(as[fin])) {
	//			if (K - (j + 1) >= 0)
	//				ret = min(ret, dp[K - (j + 1)] + as[fin][j]);
	//		}

	//		ans = min(ans, ret);
	//	}
	//}

	cout << "Case #" << testcasenum << ": " << ans << endl;
}

int main() {

	int T; cin >> T;
	DD(de(T));
	FOR(t, 0, T) {
		solve(t + 1);
	}

	return 0;
}
