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

/* -----  2019/06/29  Problem: ABC 132 F / Link: http://abc132.contest.atcoder.jp/tasks/abc132_f  ----- */

template <std::uint_least32_t MODULO> class modint {
public:
using uint32 = std::uint_least32_t; using uint64 = std::uint_least64_t; using iint64 = std::int_fast64_t; class optimize_tag_t {}; static constexpr optimize_tag_t optimize_tag{}; public:using value_type = uint32; value_type a; static constexpr value_type cst(iint64 x) noexcept { x %= static_cast<iint64>(MODULO); if (x < static_cast<iint64>(0)) { x += static_cast<iint64>(MODULO); }return static_cast<value_type>(x); }constexpr modint(optimize_tag_t, const value_type &x) noexcept : a(x) {}constexpr modint() noexcept : a(static_cast<value_type>(0)) {}constexpr modint(const iint64 &x) noexcept : a(cst(x)) {}constexpr modint operator+(const modint &o) const noexcept { return modint(optimize_tag, a + o.a < MODULO ? a + o.a : a + o.a - MODULO); }constexpr modint operator-(const modint &o) const noexcept { return modint(optimize_tag, a < o.a ? a + MODULO - o.a : a - o.a); }constexpr modint operator*(const modint &o) const noexcept { return modint(optimize_tag, static_cast<value_type>(static_cast<uint64>(a) * static_cast<uint64>(o.a) % static_cast<uint64>(MODULO))); }constexpr modint operator/(const modint &o) const { return modint(optimize_tag, static_cast<value_type>(static_cast<uint64>(a) * static_cast<uint64>((~o).a) % static_cast<uint64>(MODULO))); }modint &operator+=(const modint &o) noexcept { if ((a += o.a) >= MODULO)a -= MODULO; return *this; }modint &operator-=(const modint &o) noexcept { if (a < o.a)a += MODULO; a -= o.a; return *this; }modint &operator*=(const modint &o) noexcept { a = static_cast<value_type>(static_cast<uint64>(a) * static_cast<uint64>(o.a) % static_cast<uint64>(MODULO)); return *this; }modint &operator/=(const modint &o) { a = static_cast<uint64>(a) * (~o).a % MODULO; return *this; }constexpr modint inverse() const noexcept { assert(a != static_cast<value_type>(0) && "0 does not have inverse"); return pow(static_cast<uint64>(MODULO - static_cast<value_type>(2))); }constexpr modint operator~() const noexcept { return inverse(); }constexpr modint operator-() const noexcept { if (a == static_cast<value_type>(0)) { return modint(optimize_tag, static_cast<value_type>(0)); } else { return modint(optimize_tag, MODULO - a); } }modint &operator++() noexcept { if (++a == MODULO) { a = static_cast<value_type>(0); }return *this; }modint &operator--() noexcept { if (a == static_cast<value_type>(0)) { a = MODULO; }--a; return *this; }constexpr bool operator==(const modint &o) const noexcept { return a == o.a; }constexpr bool operator!=(const modint &o) const noexcept { return a != o.a; }constexpr bool operator<(const modint &o) const noexcept { return a < o.a; }constexpr bool operator<=(const modint &o) const noexcept { return a <= o.a; }constexpr bool operator>(const modint &o) const noexcept { return a > o.a; }constexpr bool operator>=(const modint &o) const noexcept { return a >= o.a; }constexpr explicit operator bool() const noexcept { return a; }constexpr explicit operator value_type() const noexcept { return a; }modint pow(iint64 inx) const noexcept { if (inx < 0)assert(a != static_cast<value_type>(0) && "not pow index < 0"); uint64 x = inx; uint64 t = a, u = 1; while (x) { if (x & 1)u = u * t % MODULO; t = (t * t) % MODULO; x >>= 1; }return modint(optimize_tag, static_cast<value_type>(u)); }
constexpr value_type get() const noexcept { return a; }
};
using mint = modint<MOD>;

// N以下の数について、i*j<=Nとなるiについて、jでまとめる. 2*sqrt(N)ぐらいになる
// ex:24:  (cnt,[x,x+k),N/cnt)
// (1,[1,2),24), (1,[2,3),12), (1,[3,4),8), (1,[4,5),6),
// (2,[5,7),4), (2,[7,9)3,), (4,[9,13),2), (12,[13,24),1)
vector<tuple<LL, LL, LL, LL>> split_n_under_segment(LL n) {
	vector<tuple<LL, LL, LL, LL>>ret;
	for (LL i = 1; i <= n;) {
		LL j = n / i;
		if (i <= j) {
			ret.push_back(tuple<LL, LL, LL, LL>(1, i, i + 1, j));
			DD(de(1, i, i + 1, j));
			i++;
		}
		else {
			ret.push_back(tuple<LL, LL, LL, LL>(n / j - i + 1, i, n / j + 1, j));
			DD(de(n / j - i + 1, i, n / j + 1, j));
			i = n / j + 1;
		}
	}
	return ret;
}

// abc 132 F
LL solve(LL K, LL N) {

	auto f = [](LL n) {
		// make a group
		vector<mint>ret;
		auto it = split_n_under_segment(n);
		for (auto i : it) {
			ret.push_back(get<0>(i));
		}
		return ret;
	};
	split_n_under_segment(N);
	vector<mint> x = f(N);
	int sz = (int)x.size();
	vector<mint>dp(sz + 1, 0);
	dp[0] = 1;
	FOR(k, 0, K) {
		vector<mint>csum(sz + 1, 0);
		FOR(i, 0, sz) {
			csum[i + 1] += csum[i] + dp[i];
		}
		auto dpquery = [&](int L, int R) {
			return csum[R] - csum[L];
		};
		vector<mint>nx(sz + 1, 0);
		FOR(i, 0, sz) {
			nx[i] += x[i] * dpquery(0, sz - i);
		}
		nx.swap(dp);
	}

	mint res = 0;
	for (auto it : dp)res += it;

	return res.get();
}

LL x(LL a, LL N, LL K, LL cnt) {
	if (cnt == K) {
		return 1;
	}
	else {
		LL ret = 0;
		FOR(i, 1, N + 1) {
			if (a*i <= N) {
				ret += x(i, N, K, cnt + 1);
			}
			else break;
		}
		return ret;
	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, K; cin >> N >> K;
	cout << solve(K, N) << endl;
	//DD(de(x(1, N, K, 0)));
	return 0;
	auto f = [](LL K, LL n) {
		LL ret = x(1, n, K, 0);
		return ret;
	};

	FOR(K, 1, 5) {
		FOR(n, 1, 50) {
			LL ans = f(K, n);
			DD(de(K, n, ans, solve(K, n)));
		}

	}

	return 0;
}
