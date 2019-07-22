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

/* -----  2019/07/23  Problem: AOJ 0162 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0162  ----- */


int main() {
	VL haming; {
		FOR(two, 0, 21) {
			FOR(three, 0, 13) {
				FOR(five, 0, 10) {
					LL ret = 1;
					FOR(i, 0, two) {
						ret *= 2;
						if (ret > 1000000)break;
					}
					FOR(i, 0, three) {
						ret *= 3;
						if (ret > 1000000)break;
					}
					FOR(i, 0, five) {
						ret *= 5;
						if (ret > 1000000)break;
					}

					if (ret <= 1000000)
						haming.emplace_back(ret);
				}
			}
		}
	}
	SORT(haming);
	UNIQ(haming);
	LL L, R;
	while (cin >> L, L) {
		cin >> R;
		LL ans = lower_bound(ALL(haming), R + 1) - lower_bound(ALL(haming), L);
		cout << (ans) << "\n";
	}

	return 0;
}
