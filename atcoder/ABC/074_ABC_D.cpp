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

/* -----  2019/03/19  Problem: ABC 074 D / Link: http://abc074.contest.atcoder.jp/tasks/abc074_d  ----- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VVL a(N, VL(N));
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			cin >> a[i][j];
		}
	}

	bool ok = 1;
	VVL use(N, VL(N, 1));
	FOR(k, 0, N) {
		FOR(i, 0, N) {
			FOR(j, 0, N) {
				ok &= (a[i][j] <= a[i][k] + a[k][j]);
				if (i != j && j != k && i != k && (a[i][j] == a[i][k] + a[k][j])) {
					use[i][j] = 0;
				}
			}
		}
	}


	LL ans = 0;
	FOR(i, 0, N) {
		FOR(j, i, N) {
			if (use[i][j])ans += a[i][j];
		}
	}
	cout << (ok ? ans : -1) << endl;

	return 0;
}
