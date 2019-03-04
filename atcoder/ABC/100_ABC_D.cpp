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

/* -----  2019/03/04  Problem: ABC 100 D / Link: http://abc100.contest.atcoder.jp/tasks/abc100_d  ----- */

LL dp[1003][1003][2][2][2];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	fill(****dp, ****dp + 1003 * 1003 * 2 * 2 * 2, -LINF);
	LL N, M; cin >> N >> M;
	VL x(N), y(N), z(N);
	FOR(i, 0, N) {
		cin >> x[i] >> y[i] >> z[i];
	}
	auto chmax = [](LL &a, LL b) {
		a = max(a, b);
	};

	FOR(a, 0, 2)FOR(b, 0, 2)FOR(c, 0, 2) {
		dp[0][0][a][b][c] = 0;
	}
	FOR(i, 0, N) {
		FOR(j, 0, i + 1) {
			FOR(a, 0, 2) {
				FOR(b, 0, 2) {
					FOR(c, 0, 2) {
						LL addval = (a ? x[i] : -x[i]) + (b ? y[i] : -y[i]) + (c ? z[i] : -z[i]);
						chmax(dp[i + 1][j][a][b][c], dp[i][j][a][b][c]);
						chmax(dp[i + 1][j + 1][a][b][c], dp[i][j][a][b][c] + addval);
					}
				}
			}
		}
	}



	LL ans = 0;
	FOR(a, 0, 2)FOR(b, 0, 2)FOR(c, 0, 2) {
		ans = max(ans, dp[N][M][a][b][c]);
	}
	cout << (ans) << "\n";

	return 0;
}
