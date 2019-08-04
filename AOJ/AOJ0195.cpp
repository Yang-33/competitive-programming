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

/* -----  2019/07/27  Problem: AOJ 0195 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0195  ----- */


int main() {
	int a, b;
	while (cin >> a >> b, a || b) {
		vector<PII> c;
		c.emplace_back(a + b, 0);
		FOR(i, 1, 5) {
			cin >> a >> b;
			c.emplace_back(a + b, i);
		}
		RSORT(c);
		cout << char(c.front().second + 'A') << " ";
		cout << c.front().first << "\n";
	}

	return 0;
}