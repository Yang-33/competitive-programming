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

/* -----  2019/04/29  Problem: AOJ 2165 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2165  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	while (cin >> N, N) {
		vector<LL> a(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
		}
		double ansval = LINF;
		int anss, ansa, ansc;
		FOR(S, 0, 15 + 1) {
			FOR(A, 0, 15 + 1) {
				FOR(C, 0, 15 + 1) {

					const int M = 256;
					VI cnt(M);
					LL R = S;
					FOR(i, 0, N) {
						R = (A*R + C) % M;
						cnt[(a[i] + R) % M]++;
					}
					double ret = 0;
					FOR(i, 0, M) {
						if (cnt[i]) {
							double x = cnt[i];
							ret -= x / N * log(x / N);
						}
					}


					if (ret + 1e-9 < ansval) {
						ansval = ret;
						anss = S;
						ansa = A;
						ansc = C;
					}
				}
			}
		}
		cout << anss << " " << ansa << " " << ansc << endl;

	}

	return 0;
}
