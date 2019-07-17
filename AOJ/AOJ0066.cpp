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

/* -----  2019/07/14  Problem: AOJ 0066 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0066  ----- */


int main() {
	string s;
	auto check = [&](char c) {
		int N = 3;
		VVI a(N, VI(N, 0)); {
			FOR(i, 0, 9) {
				a[i / 3][i % 3] = s[i];
			}
		}
		bool ok = 0;
		FOR(i, 0, N) {
			bool r = 1;
			FOR(j, 0, N) {
				r &= a[i][j] == c;
			}
			ok |= r;
		}
		FOR(j, 0, N) {
			bool r = 1;
			FOR(i, 0, N) {
				r &= a[i][j] == c;
			}
			ok |= r;
		}
		{
			bool r = 1;
			FOR(i, 0, N) {
				r &= a[i][i] == c;
			}
			ok |= r;
		}
		{
			bool r = 1;
			FOR(i, 0, N) {
				r &= a[i][N - i - 1] == c;
			}
			ok |= r;
		}

		return ok;
	};
	while (cin >> s) {
		char ans = 'd';
		if (check('o'))ans = 'o';
		if (check('x'))ans = 'x';

		cout << ans << "\n";
	}

	return 0;
}
