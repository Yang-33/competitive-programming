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

/* -----  2019/07/14  Problem: AOJ 0048 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0048  ----- */


int main() {
	double w;
	while (cin >> w) {
		string s;
		if (w <= 48.0) s = "light fly";
		else if (w <= 51.0) s = "fly";
		else if (w <= 54.0) s = "bantam";
		else if (w <= 57.0) s = "feather";
		else if (w <= 60.0) s = "light";
		else if (w <= 64.0) s = "light welter";
		else if (w <= 69.0) s = "welter";
		else if (w <= 75.0) s = "light middle";
		else if (w <= 81.0) s = "middle";
		else if (w <= 91.0) s = "light heavy";
		else s = "heavy";
		cout << s << "\n";
	}


	return 0;
}
