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

/* -----  2019/07/13  Problem: AOJ 0026 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0026  ----- */


int main() {
	char sep;
	int x, y, s;
	VVI m(10, VI(10, 0));
	auto isin = [](int y, int x) {return 0 <= y && y < 10 && 0 <= x && x < 10; };


	while (cin >> x >> sep >> y >> sep >> s) {
		if (s == 1 || s == 3) {
			FOR(i, -2, 2 + 1) {
				FOR(j, -2, 2 + 1) {
					int ny = y + i;
					int nx = x + j;
					if (abs(ny - y) + abs(nx - x) <= (s == 3) + 1 && isin(ny, nx))m[ny][nx]++;
				}
			}

		}
		else {
			FOR(i, -1, 1 + 1) {
				FOR(j, -1, 1 + 1) {
					int ny = y + i;
					int nx = x + j;
					if (isin(ny, nx))m[ny][nx]++;
				}
			}
		}
	}
	int zerocnt = 0;
	int mx = 0;
	FOR(i, 0, 10) {
		FOR(j, 0, 10) {
			mx = max(mx, m[i][j]);
			zerocnt += m[i][j] == 0;
		}
	}
	cout << zerocnt << "\n";
	cout << mx << "\n";


	return 0;
}
