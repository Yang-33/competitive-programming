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

/* -----  2019/07/14  Problem: HUPC2019day1 D / Link: __CONTEST_URL__  ----- */

using ll = long long;
template<class Type>
Type solve(Type res = Type()) {
	ll A, B; cin >> A >> B;

	res = -1;
	for (ll a = 1; a < A; a++) {
		ll V = (a + B);

		ll C1 = a + 1; // 貪欲
		ll C2 = V / A + (V - V / A * A); // 特殊

		if (C1 > C2) {
			res = V;
			break;
		}
	}
	return res;
}
int main(void) {
	cin.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15) << solve<ll>() << endl;
	return 0;
}