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

/* -----  2019/04/29  Problem: AOJ 1618 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/1618  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int H, W;
	while (cin >> H >> W, H || W) {
		vector<vector<LL>> a(H, vector<LL>(W));
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				cin >> a[i][j];
			}
		}
		LL ans = 0;
		// 閉区間でやる
		FOR(sy, 0, H) {
			FOR(ty, sy + 2, H) {
				FOR(sx, 0, W) {
					FOR(tx, sx + 2, W) {
						// 外周の最小値
						LL grmin = INF;
						{
							FOR(x, sx, tx + 1) {
								grmin = min(grmin, a[sy][x]);
								grmin = min(grmin, a[ty][x]);
							}
							FOR(y, sy, ty + 1) {
								grmin = min(grmin, a[y][sx]);
								grmin = min(grmin, a[y][tx]);
							}
						}

						bool ok = 1;
						LL costsum = 0;
						FOR(y, sy + 1, ty) {
							FOR(x, sx + 1, tx) {
								ok &= grmin > a[y][x];
								costsum += grmin - a[y][x];
							}
						}
						if (ok)
							ans = max(ans, costsum);

					}
				}
			}
		}
		cout << (ans) << "\n";
	}

	return 0;
}
