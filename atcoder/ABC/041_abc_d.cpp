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

/* -----  2019/04/04  Problem: ABC 041 D / Link: http://abc041.contest.atcoder.jp/tasks/abc041_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M; cin >> N >> M;
	VVI NG(N, VI(N, 0));
	FOR(i, 0, M) {
		int a, b; cin >> a >> b;
		a--, b--;
		NG[b][a] = 1;
	}
	// NG[stateof][nx]=1ならだめ。
	VVL dp(1 << N, VL(N, 0));
	FOR(i, 0, N) {
		dp[1 << i][i] = 1;
	}

	FOR(state, 0, 1 << N) {
		FOR(i, 0, N) {
			if (state & 1 << i) {
				FOR(to, 0, N) {
					if (state & 1 << to)continue;
					bool ok = 1;
					FOR(j, 0, N) {
						if (state & 1 << j) {
							ok &= !NG[j][to];
						}
					}

					if (ok) {
						dp[state | (1 << to)][to] += dp[state][i];
					}
				}
			}
		}
	}
	LL ans = 0;
	FOR(i, 0, N) {
		ans += dp[(1 << N) - 1][i];
	}
	cout << ans << "\n";

	return 0;
}
