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
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2019/03/12  Problem: ABC 083 B / Link: http://abc083.contest.atcoder.jp/tasks/abc083_b  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, A, B; cin >> N >> A >> B;
	LL ans = 0LL;
	auto f = [&](LL x) {
		LL ret = 0;
		while (x) {
			ret += x % 10;
			x /= 10;
		}

		return A<=ret && ret<=B;
	};
	FOR(i, 1, N + 1) {
		if (f(i))ans += i;
	}
	
	
	cout << (ans) << "\n";

	return 0;
}
