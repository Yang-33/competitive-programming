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

/* -----  2019/07/20  Problem: AOJ 0103 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0103  ----- */


int main() {
	LL N; cin >> N;
	FOR(_, 0, N) {
		int out = 0;
		LL ans = 0LL;
		VI a(4, 0);
		VI b(4, 0);
		while (out != 3) {
			string s; cin >> s;
			if (s == "HIT") {
				a[0] = 1;
				ans += a[3] == 1;
				FOR(i, 1, 4) {
					b[i] = a[i - 1];
				}
				a = b;
			}
			else if (s == "HOMERUN") {
				a[0] = 1;
				FOR(i, 0, 4) {
					ans += a[i] == 1;
					a[i] = 0;
				}
			}
			else {
				out++;
			}
		}

		cout << (ans) << "\n";
	}

	return 0;
}
