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

/* -----  __MAKE_TIME__  Problem: __PROBLEM__ / Link: __CONTEST_URL__  ----- */

template<typename SemiRing>struct Kitamasa { using T = typename SemiRing::t1; using VT = vector<T>; VT c; vector<VT> rs; int m;	Kitamasa(const VT &C) :c(C), rs(1), m(c.size()) { rs[0].assign(2 * m + 1, SemiRing::id1()); rs[0][1] = SemiRing::id2(); }VT merge(const VT &x, const VT &y) { VT z(2 * m + 1, SemiRing::id1()); for (int i = 1; i <= m; i++)for (int j = 1; j <= m; j++)z[i + j] = SemiRing::add(z[i + j], SemiRing::mul(x[i], y[j])); for (int i = 2 * m; i > m; z[i--] = SemiRing::id1())for (int j = 1; j <= m; j++)z[i - j] = SemiRing::add(z[i - j], SemiRing::mul(c[m - j], z[i])); return z; }T calc(const VT &A, long long n) { assert((int)A.size() == m); VT res(rs[0]); for (int i = 0; n; i++, n >>= 1) { if (i >= (int)rs.size())rs.emplace_back(merge(rs[i - 1], rs[i - 1])); if (~n & 1) continue; res = merge(res, rs[i]); }T ans = SemiRing::id1(); for (int i = 1; i <= m; i++) ans = SemiRing::add(ans, SemiRing::mul(res[i], A[i - 1])); return ans; } };

int main() {
	struct A {
		using t1 = unsigned int;
		static const t1 id1() { return 0; }
		static const t1 id2() { return UINT32_MAX; }
		static t1 add(const t1& l, const t1& r) {
			return l ^ r;
		}
		static t1 mul(const t1& l, const t1& r) {
			return l & r;
		}
	};
	int K, M; cin >> K >> M;
	vector<A::t1>a(K), c(K);
	FOR(i, 0, K) {
		cin >> a[i];
	}
	FOR(i, 0, K) {
		cin >> c[i];
	}
	reverse(ALL(c));
	Kitamasa<A> mats(c);
	cout << mats.calc(a, --M) << endl;

	return 0;
}
