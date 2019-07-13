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

/* -----  2019/07/13  Problem: AOJ 0034 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0034  ----- */


int main() {

	int N = 10;
	vector<int>L(N);
	while (cin >> L[0]) {
		char sep;
		FOR(i, 1, 10) {
			cin >> sep >> L[i];
		}
		int V1, V2; cin >> sep >> V1 >> sep >> V2;
		DD(de(V1, V2));
		VI sum(N); {
			sum[0] = L[0];
			FOR(i, 1, N) {
				sum[i] = sum[i - 1] + L[i];
			}
			double t = sum.back() / (0.0+V1 + V2);
			double D1 = t * V1;
			DD(de(D1));
			FOR(i, 0, 10) {
				if (D1 <= sum[i]) {
					cout << i + 1 << endl;
					break;
				}
			}
		}
	}

	return 0;
}
