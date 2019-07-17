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

/* -----  2019/07/14  Problem: HUPC2019day1 B / Link: __CONTEST_URL__  ----- */

using ll = long long;
bool getdivmul(ll n) {
	ll res = 1;
	for (ll i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			res *= i;
			if (res >= 2 * n) return true;
			if (n / i != i && n / i != n) res *= n / i;
			if (res >= 2 * n) return true;
		}
	}
	return false;
}

ll ans[100005];
template<class Type>
Type solve(Type res = Type()) {
	ll Q; cin >> Q;

	for (ll i = 1; i <= 100000; i++) {
		ans[i] = ans[i - 1] + getdivmul(i);
	}

	for (int q = 0; q < Q; q++) {
		ll N; cin >> N;
		cout << ans[N] << endl;
	}
	return res;
}
int main(void) {
	cin.tie(0); ios_base::sync_with_stdio(false);
	solve(0);
	return 0;
}
