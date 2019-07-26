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

/* -----  2019/07/24  Problem: AOJ 0177 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0177  ----- */

using Double = long double;
Double degToRadian(Double deg) {
	return (deg) / 180 * acos(-1.0);
}
Double spharePointDistance(Double aidorad, Double akeidorad, Double bidorad, Double bkeidorad, Double R) {
	Double x = acos(sin(aidorad)*sin(bidorad) + cos(aidorad)*cos(bidorad)*cos(akeidorad - bkeidorad));
	return R * x;
}

int main() {
	double a, b, c, d;
	while (cin >> a >> b >> c >> d) {
		if (a == -1 && b == -1 && c == -1 && d == -1)break;
		int ans = round(spharePointDistance(degToRadian(a), degToRadian(b), degToRadian(c), degToRadian(d), 6378.1));
		cout << (ans) << "\n";

	}

	return 0;
}
