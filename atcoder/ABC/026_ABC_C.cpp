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

/* -----  2019/04/07  Problem: ABC 026 C / Link: http://abc026.contest.atcoder.jp/tasks/abc026_c  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VVI G(N);
	FOR(i, 1, N) {
		int root; cin >> root;
		root--;
		G[root].push_back(i);
	}
	function<LL(int)> f = [&](int v) {
		if (!SZ(G[v]))return 1LL;
		LL mn = LINF, mx = -LINF;
		for (int sub : G[v]) {
			LL ret = f(sub);
			mn = min(mn, ret);
			mx = max(mx, ret);
		}
		return mn + mx + 1;
	};

	LL ans = f(0);


	cout << (ans) << "\n";

	return 0;
}
