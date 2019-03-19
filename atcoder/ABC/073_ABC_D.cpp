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

/* -----  2019/03/19  Problem: ABC 073 D / Link: http://abc073.contest.atcoder.jp/tasks/abc073_d  ----- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M, R; cin >> N >> M >> R;
	VL a(R);
	FOR(i, 0, R) {
		cin >> a[i];
		a[i]--;
	}
	VVL d(N, VL(N, LINF));
	FOR(i, 0, M) {
		LL a, b, c; cin >> a >> b >> c;
		a--, b--;
		d[a][b] = d[b][a] = min(d[a][b], c);
	}
	FOR(i, 0, N) {
		d[i][i] = 0;
	}
	FOR(k, 0, N)FOR(i, 0, N)FOR(j, 0, N)d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	LL ans = LINF;
	SORT(a);
	do {
		LL ret = 0;
		FOR(i, 0, R - 1) {
			ret += d[a[i]][a[i + 1]];
		}
		ans = min(ans, ret);
	} while (next_permutation(ALL(a)));
	cout << ans << endl;

	return 0;
}
