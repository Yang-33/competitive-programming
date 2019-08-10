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

/* -----  2019/08/04  Problem: AOJ 0205 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0205  ----- */


int main() {
	int N = 5;
	VI a(N);
	while (cin >> a[0], a[0]) {
		FOR(i, 1, N) {
			cin >> a[i];
		}
		bool is_tie = 0; {
			set<int>se;
			FOR(i, 0, N) {
				se.insert(a[i]);
			}
			is_tie |= (SZ(se) == 1 || SZ(se) == 3);
		}
		VI ans(N);
		if (is_tie) {
			FOR(i, 0, N)ans[i] = 3;
		}
		else {
			int mx = *max_element(ALL(a));
			int mn = *min_element(ALL(a));
			if (mx == 2) {
				// 1 win, 2 lose
				FOR(i, 0, N) {
					if (a[i] == 1)ans[i] = 1;
					else ans[i] = 2;
				}
			}
			else { // mx:3
				if (mn == 2) {
					// 2 win, 3 lose
					FOR(i, 0, N) {
						if (a[i] == 2)ans[i] = 1;
						else ans[i] = 2;
					}
				}
				else { // mn 1
					// 3 win 1 lose
					FOR(i, 0, N) {
						if (a[i] == 3)ans[i] = 1;
						else ans[i] = 2;
					}
				}
			}
		}
		FOR(i, 0, N) {
			cout << ans[i] << "\n";
		}
	}

	return 0;
}
