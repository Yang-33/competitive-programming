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

/* -----  2019/07/13  Problem: AOJ 0033 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0033  ----- */

int main() {

	int T; cin >> T;
	FOR(_, 0, T) {
		int N = 10;
		vector<int> a(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
		}
		LL ans = 0LL;
		FOR(st, 0, 1 << N) {
			LL b = 0;
			LL c = 0;
			bool ok = 1;
			FOR(i, 0, N) {
				if (st & 1 << i) {
					ok &= b < a[i];
					b = a[i];
				}
				else {
					ok &= c < a[i];
					c = a[i];
				}
			}
			ans |= ok;
		}
		cout << (ans ? "YES" : "NO") << "\n";
	}
	return 0;
}
