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

/* -----  2019/03/21  Problem: ABC 056 D / Link: http://abc056.contest.atcoder.jp/tasks/abc056_d  ----- */

struct Cumusum {
	vector<LL>csum;
	Cumusum(vector<LL>&a) {
		csum.assign((int)a.size() + 1, 0);
		for (int i = 0; i < (int)a.size(); i++) {
			csum[i + 1] = csum[i] + a[i];
		}
	}
	LL query(int l, int r) {
		return csum[r] - csum[l];
	}
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, K; cin >> N >> K;
	vector<LL> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}

	// prebuild back dp
	VVL dpB(N + 1, VL(K + 1, 0));
	dpB[N][0] = 1;
	FORR(i, N, 0) {
		int A = a[i - 1];
		FOR(k, 0, K + 1 - A) {
			dpB[i - 1][k + A] |= dpB[i][k];
		}
		FOR(k, 0, K + 1) {
			dpB[i - 1][k] |= dpB[i][k];
		}
	}


	VL dp(K + 1, 0);
	dp[0] = 1;
	LL ans = N;
	FOR(i, 0, N) {

		// build back dp cumsum
		Cumusum asum(dpB[i+1]);


		// query [K-a[i]-s,K-s) is exist
		bool exist = 0;
		FOR(s, 0, K+1) {
			if (dp[s]) {
				int L = max(0LL, K - s - a[i]);
				int R = max(0LL, K - s);
				exist |= asum.query(L, R) > 0;
			}
		}
		// if(exist)need.
		ans -= exist;

		// front dp
		FORR(k, K - a[i], 0 - 1) {
			dp[a[i] + k] |= dp[k];
		}
	}

	cout << (ans) << "\n";

	return 0;
}
