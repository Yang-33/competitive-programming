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

/* -----  2019/07/27  Problem: ABC 135 C / Link: http://abc135.contest.atcoder.jp/tasks/abc135_c  ----- */


// ?
// わからん…

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VL a(N + 1);
	FOR(i, 0, N + 1) {
		cin >> a[i];
	}
	VL b(N);
	FOR(i, 0, N) {
		cin >> b[i];
	}

	LL ans = 0;
	FOR(i, 0, N) {
		LL mae = min(a[i], b[i]);
		a[i] -= mae;
		b[i] -= mae;
		LL tugi = min(a[i + 1], b[i]);
		a[i + 1] -= tugi;
		b[i] -= tugi;
		ans += tugi + mae;
	}
	cout << ans << "\n";

	return 0;
}
