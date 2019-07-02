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

/* -----  2019/07/02  Problem: square869120Contest02 B / Link: https://atcoder.jp/contests/s8pc-2/tasks/  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, Q; cin >> N >> Q;
	vector<LL> a(Q);
	for (int i = 0; i < Q; ++i) {
		cin >> a[i];
	}
	set<LL> b;
	FOR(state, 0, 1 << Q) {
		LL c = 1;
		FOR(i, 0, Q) {
			if (state & 1 << i) {
				c *= a[i];
			}
		}
		if (c > N)continue;

		b.insert(c);
	}
	vector<LL>d(ALL(b));
	for (auto it : a) {
		for (auto &e : d) {
			if (e%it == 0) {
				e /= it;
			}
		}
	}
	LL ans = 0LL;
	for (auto it : d) {
		if (it == 1)ans++;
	}


	cout << (ans) << "\n";

	return 0;
}
