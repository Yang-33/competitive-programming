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

/* -----  2019/07/20  Problem: AOJ 0106 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0106  ----- */


int main() {
	int S;
	while (cin >> S, S) {
		LL ans = LINF;
		FOR(a, 0, 51) {
			FOR(b, 0, 51) {
				FOR(c, 0, 51) {
					if (100 * (2 * a + 3 * b + 5 * c) == S) {
						auto f = [](int c, int price, int wari, int wariP) {
							wariP = 100 - wariP;
							LL ret = 0;
							int wariCnt = c / wari;
							c -= wariCnt * wari;
							ret += (price * wariCnt*wari* wariP) / 100;
							ret += price * c;
							return ret;
						};
						LL ret = f(a, 380, 5, 20)
							+ f(b, 550, 4, 15)
							+ f(c, 850, 3, 12);
						ans = min(ans, ret);
					}
				}
			}
		}

		cout << (ans) << "\n";
	}


	return 0;
}
