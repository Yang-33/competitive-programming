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

/* -----  2019/08/04  Problem: AOJ 0206 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0206  ----- */


int main() {

	LL L;
	while (cin >> L, L) {
		LL ans = 0LL;
		int N = 12;
		LL sum = 0;
		FOR(i, 0, N) {
			LL a, b; cin >> a >> b;
			sum += a - b;
			if (sum >= L && ans == 0)ans = i + 1;
		}
		if (ans == 0)puts("NA");
		else cout << (ans) << "\n";
	}


	return 0;
}
