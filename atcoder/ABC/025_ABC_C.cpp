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

/* -----  2019/04/09  Problem: ABC 025 C / Link: http://abc025.contest.atcoder.jp/tasks/abc025_c  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N = 3;
	VVI tate(N - 1, VI(N));
	LL sum = 0;
	FOR(i, 0, N - 1) {
		FOR(j, 0, N) {
			cin >> tate[i][j];
			sum += tate[i][j];
		}
	}
	VVI yoko(N, VI(N - 1));
	FOR(i, 0, N) {
		FOR(j, 0, N - 1) {
			cin >> yoko[i][j];
			sum += yoko[i][j];
		}
	}
	VVI state(N, VI(N, -1));
	function<LL(int)> f = [&](int num) {
		if (num == N * N) {
			LL ret = 0;
			FOR(i, 0, N - 1) {
				FOR(j, 0, N) {
					if (state[i][j] == state[i + 1][j]) {
						ret += tate[i][j];
					}
					//else ret -= tate[i][j];
				}
			}
			FOR(i, 0, N) {
				FOR(j, 0, N - 1) {
					if (state[i][j] == state[i][j + 1]) {
						ret += yoko[i][j];
					}
					//else ret -= yoko[i][j];
				}
			}
			return ret;
		}
		LL ret = (num % 2 ? LINF : -LINF);
		FOR(i, 0, N) {
			FOR(j, 0, N) {
				if (state[i][j] == -1) {
					state[i][j] = (num % 2);
					if (num % 2) {
						ret = min(ret, f(num + 1));
					}
					else {
						ret = max(ret, f(num + 1));

					}
					state[i][j] = -1;
				}
			}
		}
		return ret;
	};
	LL ans = f(0);
	cout << ans << "\n";
	cout << sum - ans << endl;
	return 0;
}
