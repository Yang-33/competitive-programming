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

/* -----  2019/07/20  Problem: AOJ 0102 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0102  ----- */


int main() {
	LL N;
	while (cin >> N, N) {
		vector<vector<LL>> a(N, vector<LL>(N));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> a[i][j];
			}
		}
		VL e(N + 1);
		FOR(i, 0, N) {
			LL s = 0;
			FOR(j, 0, N) {
				s += a[i][j];
				e[j] += a[i][j];
				cout << setw(5) << a[i][j];
			}
			cout <<setw(5)<< s << endl;
			e.back() += s;
		}
		FOR(i, 0, N + 1) {
			cout << setw(5) << e[i];
		}cout << endl;

	}

	return 0;
}
