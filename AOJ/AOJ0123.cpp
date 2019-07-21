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

/* -----  2019/07/21  Problem: AOJ 0123 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0123  ----- */


int main() {

	double t1, t2;
	while (cin >> t1 >> t2) {
		if (t1 < 35.5&&t2 < 71.)puts("AAA");
		else if (t1 < 37.5&&t2 < 77.)puts("AA");
		else if (t1 < 40.&&t2 < 83.)puts("A");
		else if (t1 < 43.&&t2 < 89.)puts("B");
		else if (t1 < 50.&&t2 < 105.)puts("C");
		else if (t1 < 55.&&t2 < 116.)puts("D");
		else if (t1 < 70.&&t2 < 148.)puts("E");
		else puts("NA");
	}

	return 0;
}
