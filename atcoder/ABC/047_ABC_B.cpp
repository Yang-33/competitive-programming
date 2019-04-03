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

/* -----  2019/04/03  Problem: ABC 047 B / Link: http://abc047.contest.atcoder.jp/tasks/abc047_b  ----- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL W, H, N; cin >> W >> H >> N;
	VVL a(H, VL(W, 0));
	auto fillrange = [&](int sy, int sx, int ty, int tx) {
		FOR(i, sy, ty) {
			FOR(j, sx, tx) {
				a[i][j] = 1;
			}
		}
	};
	FOR(i, 0, N) {
		{
			LL x, y, a; cin >> x >> y >> a;
			if (a == 1) {
				fillrange(0, 0, H, x);
			}
			else if (a == 2) {
				fillrange(0, x, H, W);
			}
			else if (a == 3) {
				fillrange(0, 0, y, W);
			}
			else if (a == 4) {
				fillrange(y, 0, H, W);
			}
		}
	}

	LL ans = 0LL; {
		FOR(i, 0, H) {
			FOR(j, 0, W) {
				ans += !a[i][j];
			}
		}
	}


	cout << (ans) << "\n";

	return 0;
}
