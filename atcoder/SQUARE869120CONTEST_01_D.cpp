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

/* -----  2019/04/28  Problem: square869120Contest_01 D / Link: __CONTEST_URL__  ----- */

template<typename T>
struct CumulativeSum2D {
	int H, W;
	vector< vector< T > >data;
	CumulativeSum2D(int H_, int W_) : data(H_ + 1, vector< T >(W_ + 1, 0)) { H = H_, W = W_; };
	inline void add(int y, int x, T val) { //a[y][x](0≦p<N)をdata[y][x]に(0<p≦N)
		if (y > (int)data.size() || x > (int)data[0].size()) {
			DD(de(y,x))
			return;
		}
		data[y + 1][x + 1] += val;
	}//->buildする
	inline void build() {//data imos/cumsum
		FOR(i, 0, H)FOR(j, 0, W)data[i + 1][j + 1] += data[i + 1][j];
		FOR(i, 0, H)FOR(j, 0, W)data[i + 1][j + 1] += data[i][j + 1];
	}
	inline T query(int y, int x) {//アクセス位置変更用, (imos)
		return (data[y + 1][x + 1]);
	}

	inline void rangeaddhei(int sy, int sx, int ty, int tx, T val) { //閉区間 [(sy,sx),(ty,tx)]に加算(imos)
		add(sy, sx, val);		add(ty + 1, sx, -val);
		add(sy, tx + 1, -val);	add(ty + 1, tx + 1, val);
	}
	inline void rangeaddhan(int sy, int sx, int ty, int tx, T val) { //半閉区間 [(sy,sx),(ty,tx))に加算(imos)
		add(sy, sx, val);	add(ty, sx, -val);
		add(sy, tx, -val);  add(ty, tx, val);
	}
};

template <std::uint_least32_t MODULO> class modint {
public:
using uint32 = std::uint_least32_t; using uint64 = std::uint_least64_t; using iint64 = std::int_fast64_t; class optimize_tag_t {}; static constexpr optimize_tag_t optimize_tag{}; public:using value_type = uint32; value_type a; static constexpr value_type cst(iint64 x) noexcept { x %= static_cast<iint64>(MODULO); if (x < static_cast<iint64>(0)) { x += static_cast<iint64>(MODULO); }return static_cast<value_type>(x); }constexpr modint(optimize_tag_t, const value_type &x) noexcept : a(x) {}constexpr modint() noexcept : a(static_cast<value_type>(0)) {}constexpr modint(const iint64 &x) noexcept : a(cst(x)) {}constexpr modint operator+(const modint &o) const noexcept { return modint(optimize_tag, a + o.a < MODULO ? a + o.a : a + o.a - MODULO); }constexpr modint operator-(const modint &o) const noexcept { return modint(optimize_tag, a < o.a ? a + MODULO - o.a : a - o.a); }constexpr modint operator*(const modint &o) const noexcept { return modint(optimize_tag, static_cast<value_type>(static_cast<uint64>(a) * static_cast<uint64>(o.a) % static_cast<uint64>(MODULO))); }constexpr modint operator/(const modint &o) const { return modint(optimize_tag, static_cast<value_type>(static_cast<uint64>(a) * static_cast<uint64>((~o).a) % static_cast<uint64>(MODULO))); }modint &operator+=(const modint &o) noexcept { if ((a += o.a) >= MODULO)a -= MODULO; return *this; }modint &operator-=(const modint &o) noexcept { if (a < o.a)a += MODULO; a -= o.a; return *this; }modint &operator*=(const modint &o) noexcept { a = static_cast<value_type>(static_cast<uint64>(a) * static_cast<uint64>(o.a) % static_cast<uint64>(MODULO)); return *this; }modint &operator/=(const modint &o) { a = static_cast<uint64>(a) * (~o).a % MODULO; return *this; }constexpr modint inverse() const noexcept { assert(a != static_cast<value_type>(0) && "0 does not have inverse"); return pow(static_cast<uint64>(MODULO - static_cast<value_type>(2))); }constexpr modint operator~() const noexcept { return inverse(); }constexpr modint operator-() const noexcept { if (a == static_cast<value_type>(0)) { return modint(optimize_tag, static_cast<value_type>(0)); } else { return modint(optimize_tag, MODULO - a); } }modint &operator++() noexcept { if (++a == MODULO) { a = static_cast<value_type>(0); }return *this; }modint &operator--() noexcept { if (a == static_cast<value_type>(0)) { a = MODULO; }--a; return *this; }constexpr bool operator==(const modint &o) const noexcept { return a == o.a; }constexpr bool operator!=(const modint &o) const noexcept { return a != o.a; }constexpr bool operator<(const modint &o) const noexcept { return a < o.a; }constexpr bool operator<=(const modint &o) const noexcept { return a <= o.a; }constexpr bool operator>(const modint &o) const noexcept { return a > o.a; }constexpr bool operator>=(const modint &o) const noexcept { return a >= o.a; }constexpr explicit operator bool() const noexcept { return a; }constexpr explicit operator value_type() const noexcept { return a; }modint pow(iint64 inx) const noexcept { if (inx < 0)assert(a != static_cast<value_type>(0) && "not pow index < 0"); uint64 x = inx; uint64 t = a, u = 1; while (x) { if (x & 1)u = u * t % MODULO; t = (t * t) % MODULO; x >>= 1; }return modint(optimize_tag, static_cast<value_type>(u)); }
constexpr value_type get() const noexcept { return a; }
};
using mint = modint<MOD>;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL H, W, K; cin >> H >> W >> K;
	CumulativeSum2D<int> csum(H + 10, W + 10);
	FOR(i, 0, K) {
		int x, y; cin >> x >> y;
		x--, y--;
		csum.rangeaddhei(y + 2, 0, H - 1, x-1, -1);
		csum.rangeaddhei(0, x + 2, y-1, W - 1, -1);
	}
	csum.build();
	vector<vector<mint>>dp(H + 1, vector<mint>(W + 1));
	dp[0][0] = 1;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (csum.query(i, j) >= 0) {
				if (csum.query(i, j + 1)>=0)dp[i][j + 1] += dp[i][j];
				if (csum.query(i + 1, j)>=0)dp[i + 1][j] += dp[i][j];
			}
		}
	}
	LL ans = dp[H - 1][W - 1].get();

	cout << (ans) << "\n";

	return 0;
}
