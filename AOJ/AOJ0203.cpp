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

/* -----  2019/08/04  Problem: AOJ 0203 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0203  ----- */


int main() {
	int H, W;
	while (cin >> W >> H, W || H) {
		vector<vector<int>> s(H, vector<int>(W));
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				cin >> s[i][j];
			}
		}
		const int MU = 0;
		const int BRD = 1;
		const int JMP = 2;
		// いい感じにdp
		VVL dp(H + 2, VL(W, 0));
		FOR(j, 0, W) {
			if (s[0][j] != BRD)dp[0][j] = 1;
		}
		FOR(i, 0, H) {
			FOR(j, 0, W) {
				if (s[i][j] == MU) {
					if (i == H - 1) {
						dp[i + 1][j] += dp[i][j];
					}
					else {
						if (s[i + 1][j] != BRD)dp[i + 1][j] += dp[i][j];
						if (j&&s[i + 1][j - 1] == MU)dp[i + 1][j - 1] += dp[i][j];
						if (j + 1 < W&&s[i + 1][j + 1] == MU)dp[i + 1][j + 1] += dp[i][j];
					}
				}
				else if (s[i][j] == JMP) {
					dp[i + 2][j] += dp[i][j];
				}
			}
		}


		LL ans = 0;
		FOR(j, 0, W) {
			ans += dp[H][j];
			ans += dp[H + 1][j];
		}
		cout << ans << "\n";
	}
}