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

/* -----  2019/07/02  Problem: square869120Contest02 D / Link: https://atcoder.jp/contests/s8pc-2/tasks/  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int Q; cin >> Q;
	vector<LL>primes = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53 };
	function<PLL(LL, LL, LL)>f = [&](LL n, int idx, LL Up) {
		PLL ret = PLL(1, 1);
		if (idx == SZ(primes))return ret;
		LL p = primes[idx];
		LL muls = p;
		FOR(i, 1, Up + 1) {
			if (n <	 muls)break;
			PLL a = f(n / muls, idx + 1, i);
			LL mulcnt = a.first;
			LL minval = a.second;
			if (ret.first < mulcnt * (i + 1)) {
				ret.first = mulcnt * (i + 1);
				ret.second = minval * muls;
			}
			else if (ret.first == mulcnt * (i + 1)) {
				if (ret.second > minval*muls) {
					ret.second = minval * muls;
				}
			}

			muls *= p;
		}
		return ret;
	};
	FOR(_, 0, Q) {
		LL n; cin >> n;
		auto it = f(n,0,60);
		cout << it.first << " " << it.second << "\n";
	}


	return 0;
}
