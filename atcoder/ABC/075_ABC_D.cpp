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

/* -----  2019/03/19  Problem: ABC 075 D / Link: http://abc075.contest.atcoder.jp/tasks/abc075_d  ----- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, K; cin >> N >> K;
	VL x(N), y(N);
	FOR(i, 0, N) {
		cin >> x[i] >> y[i];
	}
	auto in = [](LL a, LL b, LL c) {
		return a <= b && b <= c;
	};
	LL ans = LLONG_MAX;

	FOR(i, 0, N) {
		FOR(j, 0, N) {
			FOR(k, 0, N) {
				FOR(l, 0, N) {
					LL cnt = 0;
					LL xmax = -LINF, xmin = LINF;
					LL ymax = -LINF, ymin = LINF;
					FOR(id, 0, N) {
						if (in(x[i], x[id], x[j]) && in(y[k], y[id], y[l])) {
							cnt++;
							xmax = max(xmax, x[id]);
							xmin = min(xmin, x[id]);
							ymax = max(ymax, y[id]);
							ymin = min(ymin, y[id]);
						}
					}
					if (cnt >= K) {
						ans = min(ans, (xmax - xmin)*(ymax - ymin));
					}
				}
			}
		}
	}
	cout << ans << endl;

	return 0;
}
