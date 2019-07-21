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

/* -----  2019/07/21  Problem: AOJ 0126 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0126  ----- */


int main() {
	LL T; cin >> T;
	FOR(_, 0, T) {
		if (_)cout << endl;
		int N = 9;
		vector<vector<LL>> a(N, vector<LL>(N));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> a[i][j];
			}
		}
		VVI err(N, VI(N, 0)); {
			FOR(i, 0, N) {
				FOR(j, 0, N) {
					FOR(k, j + 1, N) {
						if (a[i][j] == a[i][k])err[i][j] = err[i][k] = 1;
					}
				}
			} // ->

			// |
			// v
			FOR(j, 0, N) {
				FOR(i, 0, N) {
					FOR(k, i + 1, N) {
						if (a[i][j] == a[k][j])err[i][j] = err[k][j] = 1;
					}
				}
			}
			// block
			FOR(by, 0, 3) {
				FOR(bx, 0, 3) {
					FOR(i, 0, 3) {
						FOR(j, 0, 3) {
							int y = by * 3 + i;
							int x = bx * 3 + j;
							FOR(k, 0, 3) {
								FOR(l, 0, 3) {
									if (i == k && j == l)continue;
									int ny = by * 3 + k;
									int nx = bx * 3 + l;
									if (a[y][x] == a[ny][nx])err[y][x] = err[ny][nx] = 1;
								}
							}
						}
					}
				}
			}
		}
		FOR(i, 0, N) {
			FOR(j, 0, N) {
				cout << " *"[err[i][j]] << a[i][j];
			}cout << "\n";
		}

	}

	return 0;
}
