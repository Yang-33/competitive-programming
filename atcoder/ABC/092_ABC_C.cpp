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

/* -----  2019/03/08  Problem: ABC 092 C / Link: http://abc092.contest.atcoder.jp/tasks/abc092_c  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	vector<LL> a(N + 3);
	for (int i = 0; i < N; ++i) {
		cin >> a[i + 1];
	}

	VL minus(N + 2);
	LL ans = 0;
	FOR(i, 1, N + 2) {
		ans += abs(a[i] - a[i - 1]);
		LL dx1 = a[i] - a[i - 1];
		LL dx2 = a[i + 1] - a[i];
		if (dx1*dx2 < 0) {
			minus[i - 1] = 2 * min(abs(dx1), abs(dx2));
		}
	}
	FOR(i, 0, N) {
		cout << ans - minus[i] << endl;
	}

	return 0;
}
