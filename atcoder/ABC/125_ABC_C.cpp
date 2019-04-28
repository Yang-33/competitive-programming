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

/* -----  2019/04/27  Problem: ABC 125 C / Link: http://abc125.contest.atcoder.jp/tasks/abc125_c  ----- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	vector<LL> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}

	VL R(N), L(N);
	FOR(i, 0, N) {
		L[i] = (i ? __gcd(L[i - 1], a[i]) : a[i]);
	}
	reverse(ALL(a));

	FOR(i, 0, N) {
		R[i] = (i ? __gcd(R[i - 1], a[i]) : a[i]);
	}
	LL ans = 0;
	FOR(i, 0, N) {
		if (i == 0) {
			ans = max(ans, (R[N - i - 2]));
		}
		else if (i == N - 1) {
			ans = max(ans, (L[i - 1]));
		}
		else {
			ans = max(ans, __gcd(L[i-1], R[N - i - 2]));
		}
	}


	cout << (ans) << "\n";

	return 0;
}
