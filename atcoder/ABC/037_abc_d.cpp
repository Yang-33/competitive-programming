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

/* -----  2019/04/05  Problem: ABC 037 D / Link: http://abc037.contest.atcoder.jp/tasks/abc037_d  ----- */

template <std::uint_least32_t MODULO> class modint {
public:
using uint32 = std::uint_least32_t; using uint64 = std::uint_least64_t; using iint64 = std::int_fast64_t; class optimize_tag_t {}; static constexpr optimize_tag_t optimize_tag{}; public:using value_type = uint32; value_type a; static constexpr value_type cst(iint64 x) noexcept { x %= static_cast<iint64>(MODULO); if (x < static_cast<iint64>(0)) { x += static_cast<iint64>(MODULO); }return static_cast<value_type>(x); }constexpr modint(optimize_tag_t, const value_type &x) noexcept : a(x) {}constexpr modint() noexcept : a(static_cast<value_type>(0)) {}constexpr modint(const iint64 &x) noexcept : a(cst(x)) {}constexpr modint operator+(const modint &o) const noexcept { return modint(optimize_tag, a + o.a < MODULO ? a + o.a : a + o.a - MODULO); }constexpr modint operator-(const modint &o) const noexcept { return modint(optimize_tag, a < o.a ? a + MODULO - o.a : a - o.a); }constexpr modint operator*(const modint &o) const noexcept { return modint(optimize_tag, static_cast<value_type>(static_cast<uint64>(a) * static_cast<uint64>(o.a) % static_cast<uint64>(MODULO))); }constexpr modint operator/(const modint &o) const { return modint(optimize_tag, static_cast<value_type>(static_cast<uint64>(a) * static_cast<uint64>((~o).a) % static_cast<uint64>(MODULO))); }modint &operator+=(const modint &o) noexcept { if ((a += o.a) >= MODULO)a -= MODULO; return *this; }modint &operator-=(const modint &o) noexcept { if (a < o.a)a += MODULO; a -= o.a; return *this; }modint &operator*=(const modint &o) noexcept { a = static_cast<value_type>(static_cast<uint64>(a) * static_cast<uint64>(o.a) % static_cast<uint64>(MODULO)); return *this; }modint &operator/=(const modint &o) { a = static_cast<uint64>(a) * (~o).a % MODULO; return *this; }constexpr modint inverse() const noexcept { assert(a != static_cast<value_type>(0) && "0 does not have inverse"); return pow(static_cast<uint64>(MODULO - static_cast<value_type>(2))); }constexpr modint operator~() const noexcept { return inverse(); }constexpr modint operator-() const noexcept { if (a == static_cast<value_type>(0)) { return modint(optimize_tag, static_cast<value_type>(0)); } else { return modint(optimize_tag, MODULO - a); } }modint &operator++() noexcept { if (++a == MODULO) { a = static_cast<value_type>(0); }return *this; }modint &operator--() noexcept { if (a == static_cast<value_type>(0)) { a = MODULO; }--a; return *this; }constexpr bool operator==(const modint &o) const noexcept { return a == o.a; }constexpr bool operator!=(const modint &o) const noexcept { return a != o.a; }constexpr bool operator<(const modint &o) const noexcept { return a < o.a; }constexpr bool operator<=(const modint &o) const noexcept { return a <= o.a; }constexpr bool operator>(const modint &o) const noexcept { return a > o.a; }constexpr bool operator>=(const modint &o) const noexcept { return a >= o.a; }constexpr explicit operator bool() const noexcept { return a; }constexpr explicit operator value_type() const noexcept { return a; }modint pow(iint64 inx) const noexcept { if (inx < 0)assert(a != static_cast<value_type>(0) && "not pow index < 0"); uint64 x = inx; uint64 t = a, u = 1; while (x) { if (x & 1)u = u * t % MODULO; t = (t * t) % MODULO; x >>= 1; }return modint(optimize_tag, static_cast<value_type>(u)); }
constexpr value_type get() const noexcept { return a; }
};
using mint = modint<MOD>;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL H, W; cin >> H >> W;
	vector<vector<LL>> a(H, vector<LL>(W));
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> a[i][j];
		}
	}

	VVL memo(H, VL(W, -1));

	auto is_in = [](int a, int b, int c) { return a <= b && b < c; };
	function<mint(int, int)> f = [&](int h, int w) {
		if (memo[h][w] != -1)return mint(memo[h][w]);
		mint res = 1;
		FOR(k, 0, 4) {
			int ny = h + DY[k], nx = w + DX[k];
			if (is_in(0, ny, H) && is_in(0, nx, W)) {
				if (a[h][w] < a[ny][nx]) {
					res += f(ny, nx);
				}
			}
		}
		memo[h][w] = res.get();
		return res;
	};
	mint ans = 0;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			ans += f(i, j);
		}
	}

	cout << (ans).get() << "\n";

	return 0;
}
