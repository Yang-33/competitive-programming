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

/* -----  2019/07/15  Problem: HUPC2019day2 F / Link: __CONTEST_URL__  ----- */

inline LL in() { LL in; scanf("%lld", &in); return in; }
inline void outLL(LL out, bool endl = 1) { printf("%lld%c", out, " \n"[endl]); }

int main() {
	int AN = in(), BN = in();
	LL ans = 0;
	VL asum(2e5 + 10, 0); {
		vector<LL> a(AN);
		for (int i = 0; i < AN; ++i) {
			a[i] = in();
			ans += a[i] * BN;
		}
		FOR(i, 0, AN) {
			asum[a[i]]++;
		}
		FOR(i, 0, 2e5 + 9) {
			asum[i + 1] += asum[i];
		}
	}

	VL bcnt(2e5 + 10, 0); {
		for (int i = 0; i < BN; ++i) {
			LL b = in();
			bcnt[b]++;
		}
	}
	auto query = [&asum](int L, int R) {
		return asum[min(R, (int)2e5 + 9)] - asum[L];
	};
	FOR(B, 1, 2e5 + 10) {
		if (bcnt[B] == 0)continue;
		LL cmulcnt = 0;
		for (int i = 0; i *B <= 2e5; i++) {
			LL ccnt = query(B*i - 1, B*(i + 1) - 1);
			cmulcnt += ccnt * i;
		}

		ans -= cmulcnt * B*bcnt[B];
	}
	outLL(ans);

	return 0;
}
