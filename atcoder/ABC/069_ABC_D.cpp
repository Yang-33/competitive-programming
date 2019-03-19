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

/* -----  2019/03/19  Problem: ABC 069 D / Link: http://abc069.contest.atcoder.jp/tasks/abc069_d  ----- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL H, W; cin >> H >> W;
	int N; cin >> N;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	VVI ans(H, VI(W, 0));
	int idx = 0;
	FOR(i, 0, H) {
		if (i % 2 == 0) {
			FOR(j, 0, W) {
				if (a[idx])ans[i][j] = idx, a[idx]--;
				if (!a[idx])idx++;
			}
		}
		else {
			FORR(j, W - 1, 0 - 1) {
				if (a[idx])ans[i][j] = idx, a[idx]--;
				if (!a[idx])idx++;
			}
		}
	}
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			cout << ans[i][j] + 1 << " \n"[j == W - 1];
		}
	}

	return 0;
}
