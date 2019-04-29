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

/* -----  2019/04/29  Problem: AOJ 1250 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/1250  ----- */


int main() {
	LL N; cin >> N;
	FOR(_, 0, N) {
		LL ans = 0;
		vector<LL> a(9);
		FOR(i, 0, 9) {
			scanf("%llx", &a[i]);
		}

		LL x = a.back();
		FOR(i, 0, 32) {
			LL xsum = 0;
			FOR(j, 0, 8) {
				xsum += a[j] ^ ans;
			}
			if ((xsum & 1LL << i) != (x & 1LL << i)) {
				ans |= 1LL << i;
			}
		}
		printf("%llx\n", ans);
	}


	return 0;
}
