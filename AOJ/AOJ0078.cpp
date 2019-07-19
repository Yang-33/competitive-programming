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

/* -----  2019/07/19  Problem: AOJ 0078 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0078  ----- */




int main() {
	int n;
	int cx, cy, cnt;
	while (cin >> n, n) {
		VVI a(3000, VI(3000, 0));
		cx = n / 2;
		cy = n / 2 + 1;
		cnt = 1;
		a[cy][cx] = cnt;
		while (cnt < n*n) {
			cnt++;
			if (a[(cy + 1) % n][(cx + 1) % n] == 0) {
				cx = (cx + 1) % n;
				cy = (cy + 1) % n;
				a[cy][cx] = cnt;
			}
			else {
				cy = (cy + 2) % n;
				a[cy][cx] = cnt;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("% 4d", a[i][j]);
			}
			printf("\n");
		}
	}
}