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

/* -----  2019/05/29  Problem: AOJ 2601 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2601  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	vector<LL> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}

	auto f = [&]() {
		VL ans(N);
		ans[0] = (a.front() == 0 ? INF : -INF);
		FOR(i, 1, N) {
			ans[i] = ans[i - 1] - 1;
			if (a[i] < 0) {
				ans[i] = min(ans[i], -a[i]);
			}
			if (a[i] == 0) {
				ans[i] = INF;
			}

		}


		return ans;
	};

	VL L = f();
	reverse(ALL(a));
	VL R = f();
	reverse(ALL(a));
	reverse(ALL(R));
	LL ans = 0;
	FOR(i, 0, N) {
		if (a[i] > 0) {
			ans += max(0LL,min(a[i], max(L[i], R[i])));
		}
	}

	cout << (ans) << "\n";

	return 0;
}
