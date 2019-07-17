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

/* -----  2019/07/14  Problem: AOJ 0062 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0062  ----- */

int main() {
	string s;
	while (cin >> s) {
		VI a; {
			for (auto c : s) {
				a.push_back(c - '0');
			}
		}
		while (SZ(a) > 1) {
			VI b;
			FOR(i, 0, SZ(a) - 1) {
				b.push_back((a[i] + a[i + 1]) % 10);
			}
			a = b;
		}
		LL ans = a.front();
		cout << (ans) << "\n";
	}

	return 0;
}
