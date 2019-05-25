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

/* -----  2019/05/25  Problem: ABC 127 D / Link: http://abc127.contest.atcoder.jp/tasks/abc127_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	vector<LL> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	vector<PLL>c;
	FOR(i, 0, M) {
		LL x, y; cin >> x >> y;
		c.push_back(PLL(y, x));
	}
	RSORT(c);
	SORT(a);
	DD(De(a));
	LL k = 0;
	FOR(i, 0, M) {
		DD(de(c[i]));
		LL idx = lower_bound(a.begin() + k, a.end(), c[i].first) - a.begin();
		DD(de(idx));
		idx = min(idx, k + c[i].second);
		idx = min(idx, N);
		FOR(p, k, idx) {
			a[p] = c[i].first;
		}
		DD(De(a));
		k = idx;
	}
	LL ans = accumulate(ALL(a), 0LL);

	cout << (ans) << "\n";

	return 0;
}
