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

/* -----  2019/07/07  Problem: ABC 133 D / Link: http://abc133.contest.atcoder.jp/tasks/abc133_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	vector<LL> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	LL asum = accumulate(a.begin(), a.end(), 0LL);
	FOR(i, 0, N - 1) {
		if (i % 2 == 0) {
			asum -= 2 * a[i];
		}
	}
	LL xn = asum;
	vector<LL>ans(N); {
		ans.back() = xn;
		ans.front() = 2 * a.back() - xn;
		xn = ans.front();
	}
	FOR(i, 1, N) {
		ans[i] = 2 * a[i - 1] - xn;
		xn = ans[i];
	}
	FOR(i, 0, N) {
		cout << ans[i] << " \n"[i + 1 == N];
	}

	return 0;
}
