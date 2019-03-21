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

/* -----  2019/03/21  Problem: ABC 060 D / Link: http://abc060.contest.atcoder.jp/tasks/abc060_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, W; cin >> N >> W;
	vector<LL> w(N), v(N);
	for (int i = 0; i < N; ++i) {
		cin >> w[i] >> v[i];
	}
	auto chmin = [](LL &a, const LL b) {
		a = min(a, b);
	};
	auto chmax = [](LL& a, const LL b) {
		a = max(a, b);
	};


	vector<VVL>dp(N + 1, VVL(N + 1, VL(3 * (N - 1) + 1, -LINF)));
	dp[0][0][0] = 0;
	FOR(i, 0, N) {
		FOR(k, 0, N) {
			FOR(add, 0, 3 * (N - 1) + 1) {
				if (dp[i][k][add] == -LINF)continue;
				int wi = w[i] - w.front();
				chmax(dp[i + 1][k][add], dp[i][k][add]);
				chmax(dp[i + 1][k + 1][add + wi], dp[i][k][add] + v[i]);
			}
		}
	}
	LL ans = 0;
	FOR(k, 0, N+1) {
		FOR(add, 0, 3 * (N - 1) + 1) {
			LL ws = w.front()*k + add;
			if(ws<=W)
			chmax(ans, dp[N][k][add]);
		}
	}

	cout << (ans) << "\n";

	return 0;
}
