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

/* -----  2019/07/27  Problem: AOJ 0193 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0193  ----- */

int main() {

	int W, H;
	while (cin >> W >> H, W || H) {
		int N; cin >> N;
		vector<int> comvX(N), comvY(N);
		for (int i = 0; i < N; ++i) {
			cin >> comvX[i] >> comvY[i];
			comvX[i]--, comvY[i]--;
		}
		auto calc = [&](int SY, int SX) {
			auto isin = [&](int y, int x) {return 0 <= y && y < H && 0 <= x && x < W; };
			VVI d(H, VI(W, INF));
			queue<PII>q;
			auto IFPUSH = [&](int y, int x, int cost) {
				if (d[y][x] > cost) {
					d[y][x] = cost;
					q.emplace(y, x);
				}
			};
			IFPUSH(SY, SX, 0);
			const int dx1[] = { -1,0,-1,1,-1,0 }, dx2[] = { 0,1,-1,1,0,1 }, dy[] = { -1,-1,0,0,1,1 };
			while (!q.empty()) {
				int y, x;
				tie(y, x) = q.front(); q.pop();
				int cost = d[y][x];

				FOR(k, 0, 6) {
					int ny = y + dy[k];
					int nx = x + (y % 2 == 0 ? dx1[k] : dx2[k]);
					if (isin(ny, nx)) {
						IFPUSH(ny, nx, cost + 1);
					}
				}
			}
			return d;
		};
		vector<VVI>res; {
			FOR(i, 0, N) {
				res.emplace_back(calc(comvY[i], comvX[i]));
			}
		}
		int ans = 0; {
			int Q; cin >> Q;
			res.emplace_back(VVI());
			FOR(_, 0, Q) {
				int qy, qx; cin >> qx >> qy;
				qx--, qy--;
				res.back() = calc(qy, qx);
				int ret = 0; {
					FOR(i, 0, H) {
						FOR(j, 0, W) {
							int mn = INF;
							int id = 0;
							FOR(k, 0, N + 1) {
								if (mn > res[k][i][j]) {
									mn = res[k][i][j];
									id = k;
								}
								else if (mn > res[k][i][j]) {
									id = INF;
								}
							}
							if (id == N)ret++;
						}
					}
				}
				ans = max(ans, ret);
			}

		}
		cout << ans << "\n";

	}

	return 0;
}
