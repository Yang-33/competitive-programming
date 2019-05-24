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

/* -----  2019/04/13  Problem: GCJ2019_R1A A / Link: __CONTEST_URL__  ----- */


template< unsigned mod >
struct RollingHash {
	vector< unsigned > hashed, power;

	inline unsigned mul(unsigned a, unsigned b) const {
		unsigned long long x = (unsigned long long) a * b;
		unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x, d, m;
		asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (mod));
		return m;
	}

	RollingHash(const string &s, unsigned base = 10007) {
		int sz = (int)s.size();
		hashed.assign(sz + 1, 0);
		power.assign(sz + 1, 0);
		power[0] = 1;
		for (int i = 0; i < sz; i++) {
			power[i + 1] = mul(power[i], base);
			hashed[i + 1] = mul(hashed[i], base) + s[i];
			if (hashed[i + 1] >= mod) hashed[i + 1] -= mod;
		}
	}
	// [l,r)
	unsigned get(int l, int r) const {
		unsigned ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
		if (ret >= mod) ret -= mod;
		return ret;
	}
	// merge hash:h1 + hash:h2
	unsigned connect(unsigned h1, int h2, int h2len) const {
		unsigned ret = mul(h1, power[h2len]) + h2;
		if (ret >= mod) ret -= mod;
		return ret;
	}

	int LCP(const RollingHash< mod > &b, int l1, int r1, int l2, int r2) {
		int len = min(r1 - l1, r2 - l2);
		int low = -1, high = len + 1;
		while (high - low > 1) {
			int mid = (low + high) / 2;
			if (get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
			else high = mid;
		}
		return (low);
	}
};

using RH1 = RollingHash< 1000000007 >;

void solve(int testcasenum) {
	int N; cin >> N;
	VS vs(N);
	FOR(i, 0, N) {
		cin >> vs[i];
		reverse(ALL(vs[i]));
	}
	int ans = 0;
	vector<RH1>prefixs;
	FOR(i, 0, N) {
		prefixs.push_back(RH1(vs[i]));
	}
	VI used(N, 0);
	set<string>usedstr;
	FORR(len, 50, 0) {
		FOR(i, 0, N) {
			if (used[i])continue;
			if (SZ(vs[i]) < len)continue;
			string uses = vs[i].substr(0, len);
			if (usedstr.count(uses))continue;

			FOR(j, i + 1, N) {
				if (used[j])continue;
				if (SZ(vs[j]) < len)continue;
				if (prefixs[i].get(0, len) == prefixs[j].get(0, len)) {
					// match
					usedstr.insert(uses);
					used[i] = used[j] = 1;
					ans += 2;
					break;
				}

			}

		}
	}


	cout << "Case #" << testcasenum << ": ";
	cout << ans << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	FOR(i, 0, T) {
		solve(i + 1);
	}

	return 0;
}
