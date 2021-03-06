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

/* -----  2019/04/07  Problem: ABC 027 B / Link: http://abc027.contest.atcoder.jp/tasks/abc027_b  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	vector<LL> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	LL sum = accumulate(ALL(a), 0LL);
	if (sum%N != 0) {
		cout << -1 << endl;
		return 0;
	}

	LL ans = 0LL;
	LL p = sum / N;
	LL subsum = 0;
	LL subcnt = 0;
	FOR(i, 0, N) {
		if (!subcnt && a[i] == p) {
			continue;
		}
		if (subsum + a[i] == (subcnt + 1)*p) {
			ans += subcnt;
			subcnt = 0, subsum = 0;
		}
		else {
			subcnt++;
			subsum += a[i];
		}
	}
	assert(subcnt == 0);
	cout << (ans) << "\n";

	return 0;
}
