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

/* -----  2019/04/06  Problem: ABC 031 C / Link: http://abc031.contest.atcoder.jp/tasks/abc031_c  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	vector<LL> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	LL ans = -LINF;
	FOR(i, 0, N) {
		LL ret = -LINF;
		LL subans = -LINF;
		FOR(j, 0, N) {
			if (i == j)continue;
			int a = i, b = j;
			if (a > b)swap(a, b);
			LL ta = 0, ao = 0;
			FOR(k, a, b + 1) {
				if (k % 2 == a % 2) {
					ta += A[k];
				}
				else {
					ao += A[k];
				}
			}
			if (ret < ao) {
				ret = ao;
				subans = ta;
			}
		}
		ans = max(ans, subans);
	}
	
	
	cout << (ans) << "\n";

	return 0;
}
