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

/* -----  2019/07/23  Problem: AOJ 0163 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0163  ----- */


int main() {
	int a[7][7] = {
		{ 0,300,500,600,700,1350,1650 },
	{ 6,0,350,450,600,1150,1500 },
	{ 13,7,0,250,400,1000,1350 },
	{ 18,12,5,0,250,850,1300 },
	{ 23,17,10,5,0,600,1150 },
	{ 43,37,30,25,20,0,500 },
	{ 58,52,45,40,35,15,0 }
	};
	int b;
	while (cin >> b, b) {
		int c, d, e, f, g; cin >> c >> d >> e >> f >> g;
		c = c * 60 + d;
		f = f * 60 + g;
		if (c >= 1050 && c <= 1170 || f >= 1050 && f <= 1170) {
			if (a[max(b, e) - 1][min(b, e) - 1] <= 40) {
				int o = a[min(b, e) - 1][max(b, e) - 1] / 2;
				if (o % 50)o += 50 - o % 50;
				cout << o << "\n";
			}
			else cout << a[min(b, e) - 1][max(b, e) - 1] << "\n";
		}
		else cout << a[min(b, e) - 1][max(b, e) - 1] << "\n";
	}
	return 0;
}