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

/* -----  2019/07/21  Problem: AOJ 0133 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0133  ----- */

template<class T>void rotate2dR(vector<vector<T>>& a) { // rorateToR
	vector<vector<T>> res(a[0].size(), vector<T>(a.size()));
	FOR(i, 0, (int)a.size())FOR(j, 0, (int)a[0].size())res[j][a.size() - i - 1] = a[i][j];
	a = res;
}

int main() {
	int N = 8;
	vector<vector<char>> a(N, vector<char>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> a[i][j];
		}
	}
	FOR(i, 0, 3) {
		cout << 90 * (i + 1) << "\n";
		rotate2dR(a);
		FOR(y, 0, N) {
			FOR(x, 0, N) {
				cout << a[y][x];
			}cout << "\n";
		}
	}



	return 0;
}
