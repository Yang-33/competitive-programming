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

/* -----  2019/07/24  Problem: AOJ 0181 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0181  ----- */


int main() {
	LL dan, N;
	while (cin >> dan >> N, dan) {
		vector<LL> a(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
		}
		auto f = [&](LL x) {
			LL sum = 0;
			LL cnt = 1;
			FOR(i, 0, N) {
				if (sum + a[i] > x) {
					cnt++;
					sum = a[i];
					if (sum > x)return false;
				}
				else {
					sum += a[i];
				}
			}
			return cnt <= dan;
		};
		LL L = -1, R = 15'000'00;
		while (R - L > 1) {
			LL m = (L + R) / 2;
			if (f(m)) {
				R = m;
			}
			else {
				L = m;
			}
		}
		LL ans = R;
		cout << (ans) << "\n";
	}

	return 0;
}
