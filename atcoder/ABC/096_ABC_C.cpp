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

/* -----  2019/03/04  Problem: ABC 096 C / Link: http://abc096.contest.atcoder.jp/tasks/abc096_c  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL H, W; cin >> H >> W;
	vector<string> a(H);
	for (int i = 0; i < H; ++i) {
		cin >> a[i];
	}
	auto is_in = [](int a, int b, int c) {
		return a <= b && b < c;
	};
	LL ans = 0;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (a[i][j] == '#') {
				LL cnt = 0;
				FOR(k, 0, 4) {
					int ny = i + DY[k], nx = j + DX[k];
					if (is_in(0, ny, H) && is_in(0, nx, W)) {
						cnt += a[ny][nx] == '#';
					}
				}
				if (cnt == 0) {
					ans = -1;
				}
			}
		}
	}

	cout << (ans != -1 ? "Yes" : "No") << "\n";

	return 0;
}
