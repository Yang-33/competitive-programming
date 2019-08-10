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

/* -----  2019/08/04  Problem: AOJ 0209 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0209  ----- */

template<class T>void rotate2dR(vector<vector<T>>& a) { // rorateToR
	vector<vector<T>> res(a[0].size(), vector<T>(a.size()));
	FOR(i, 0, (int)a.size())FOR(j, 0, (int)a[0].size())res[j][a.size() - i - 1] = a[i][j];
	a = res;
}

int main() {

	int N, n;
	while (cin >> N >> n, N) {
		vector<vector<int>> a(N, vector<int>(N));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> a[i][j];
			}
		}
		vector<vector<int>> b(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> b[i][j];
			}
		}
		PII ans(INF, INF);
		FOR(rot, 0, 4) {
			rotate2dR(b);
			FOR(i, 0, N - n + 1) {
				FOR(j, 0, N - n + 1) {
					bool ok = 1;
					FOR(y, 0, n) {
						FOR(x, 0, n) {
							if (b[y][x] == -1)continue;
							ok &= b[y][x] == a[y + i][x + j];
						}
					}
					if (ok) {
						DD(de(rot,i, j));
						FOR(y, 0, n) {
							FOR(x, 0, n) {
								if (b[y][x] != -1) {
									ans = min(ans, PII(i+y, j+x));
								}
							}
						}
					}
				}
			}

		}
		if (ans.first == INF)puts("NA");
		else cout << ans.second + 1 << " " << ans.first + 1 << "\n";
	}

	return 0;
}
