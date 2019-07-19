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

/* -----  2019/07/19  Problem: AOJ 0086 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0086  ----- */


int main() {
	int a, b;
	VI deg(100);
	auto f = [&]() {
		int odd = 0;
		FOR(i, 0, 100) {
			if (deg[i] & 1)odd++;
		}
		if (deg[0] & 1 && deg[1] & 1 && odd == 2)cout << "OK\n";
		else cout << "NG\n";
		deg.assign(100, 0);
	};
	while (cin >> a >> b) {

		if (a == 0 && b == 0) {
			f();
		}
		else {
			deg[a - 1]++, deg[b - 1]++;
		}
	}

	return 0;
}
