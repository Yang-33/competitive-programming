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

/* -----  2019/04/10  Problem: ABC 018 D / Link: http://abc018.contest.atcoder.jp/tasks/abc018_d  ----- */

inline int nextCombination(int comb) {
	int x = comb & -comb, y = comb + x;
	return (((comb & ~y) / x) >> 1) | y;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M, P, Q, R; cin >> N >> M >> P >> Q >> R;
	vector<LL>x(R), y(R), z(R);
	for (int i = 0; i < R; ++i) {
		cin >> x[i] >> y[i] >> z[i];
		x[i]--, y[i]--;
	}

	LL ans = 0LL;

	for (int comb = (1 << (P)) - 1; comb < (1 << N); comb = nextCombination(comb)) {
		VL mens(M, 0);
		FOR(i, 0, R) {
			if (comb & 1 << x[i]) {
				mens[y[i]] += z[i];
			}
		}
		RSORT(mens);
		ans = max(ans, accumulate(mens.begin(), mens.begin() + Q, 0LL));

	}


	cout << (ans) << "\n";

	return 0;
}
