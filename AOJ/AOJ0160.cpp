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

/* -----  2019/07/23  Problem: AOJ 0160 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0160  ----- */


int main() {
	int N;
	while (cin >> N, N) {
		LL ans = 0LL;
		FOR(i, 0, N) {
			LL a, b, c, w; cin >> a >> b >> c >> w;
			LL s = a + b + c;
			if (s <= 60 && w <= 2)ans += 600;
			else if (s <= 80 && w <= 5)ans += 800;
			else if (s <= 100 && w <= 10)ans += 1000;
			else if (s <= 120 && w <= 15)ans += 1200;
			else if (s <= 140 && w <= 20)ans += 1400;
			else if (s <= 160 && w <= 25)ans += 1600;
		}
		cout << (ans) << "\n";
	}

	return 0;
}
