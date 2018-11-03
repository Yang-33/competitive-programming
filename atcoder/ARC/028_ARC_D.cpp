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

/* -----  2018/11/03  Problem: ARC 028 D / Link: http://arc028.contest.atcoder.jp/tasks/arc028_d  ----- */
/* ------問題------

高橋商店では N 種類の商品が売られています。「どの種類の商品がいくつあるか」の情報が与えられるので、「合計 M 個の商品を選ぶ方法」の数を求めて下さい。
ただし、同じ種類の商品は区別しないこととします。
いや、これは少し簡単過ぎるので、ちょっとした注文も追加しよう。
整数 k, x からなる Q 個の注文を用意したので、それぞれについて「ki 種類目の商品をちょうど xi 個選ばなければならないとき、合計 M 個の商品を選ぶ方法」の数を求めて下さい。

-----問題ここまで----- */
/* -----解説等-----

戻すDP.sigmaさんの途中の式変形が間違っていて厳しい気持ちになってしまった。
普通のDPをする。毎回戻していてはO(QNM)となり論外。
ここで1個除外するyukicoder155を思い出す。
重複組合せDPの式を反転するとクエリO(1)を達成できる。

----解説ここまで---- */
template <size_t E, bool T = 1>
class FastScanner {
	char e[E | 1], *t, *a;
	const double A = strtod("NaN", nullptr);
	FILE*o;
	bool i() { size_t n = fread(e, 1, E, o); e[n] = 0; a = e + n; t = e; return n; }
	bool i(ptrdiff_t n) { size_t s = fread(e, 1, E, o); e[n += s] = 0; a = e + n; t = e; return s; }
public:
	FastScanner(FILE*o = stdin) :e{}, t(e), a(e + E), o(o)
	{i(); }
	bool scan(double&n) { if (!*t && !i()) { n = A; return 0; }char*s; n = strtod(t, &s); while (s == t)if (!i()) { n = A; return 0; }if (s >= a) { ptrdiff_t h = a - t; memcpy(e, t, h); if (i(h))n = strtod(e, &t); }return 1; }
	bool scan(char&n) { n = *t++; if (n)return 1; if (!i())return 0; n = *t++; return 1; }
	bool scan(char*n) { char*s = nullptr; for (;; ++t) { char h = *t; if (!h) { if (s) { ptrdiff_t r = t - s; memcpy(n, s, r); n += r; }if (!i()) { *n = 0; return s; }h = *e; if (s)s = e; }if (!isspace(h)) { if (!s) { s = t; } } else if (s) { ptrdiff_t r = t - s; memcpy(n, s, r); n[r] = 0; ++t; return 1; } } }
	template<class O, bool I = T>
	bool scan(O&n, typename std::enable_if<std::is_signed<O>::value>::type*_1 = 0, typename std::enable_if<I>::type*_2 = 0) { bool s = 0, h = 0; n = 0; for (;; ++t) { char r = *t; if (!r) { if (!i())return s; r = *t; }if (isdigit(r)) { s = 1; n = n * 10 + r - '0'; } else if (s) { ++t; break; } else if (r == '-') { h = 1; } }if (h)n = -n; return 1; }
	template<class O, bool I = T>
	bool scan(O&n, typename std::enable_if<std::is_signed<O>::value>::type*_1 = 0, typename std::enable_if<!I>::type*_2 = 0) { bool s = 0, h = 0; n = 0; for (;; ++t) { char r = *t; if (!r) { if (!i())return s; r = *t; }if (isdigit(r)) { s = 1; n = n * 10 + r - '0'; } else if (s) { break; } else if (r == '-') { h = 1; } }if (h)n = -n; return 1; }
	template<class O, bool I = T>
	bool scan(O&n, typename std::enable_if<!std::is_signed<O>::value>::type*_1 = 0, typename std::enable_if<I>::type*_2 = 0) { bool s = 0; n = 0; for (;; ++t) { char h = *t; if (!h) { if (!i())return s; h = *t; }if (isdigit(h)) { s = 1; n = n * 10 + h - '0'; } else if (s) { ++t; return 1; } } }
	template<class O, bool I = T>
	bool scan(O&n, typename std::enable_if<!std::is_signed<O>::value>::type*_1 = 0, typename std::enable_if<!I>::type*_2 = 0) { bool s = 0; n = 0; for (;; ++t) { char h = *t; if (!h) { if (!i())return s; h = *t; }if (isdigit(h)) { s = 1; n = n * 10 + h - '0'; } else if (s) { return 1; } } }
	template<class O, class...I>
	bool scan(O&&n, I&&...s) { return scan(n) && scan(s...); }
	bool scanln(char*n) { char*s = t, *h = n; for (;; ++t) { char r = *t; if (!r) { ptrdiff_t d = t - s; memcpy(h, s, d); h += d; if (!i()) { *h = 0; return h - n; }s = e; r = *e; }if (r == '\n') { ++t; ptrdiff_t d = t - s; memcpy(h, s, d); h[d] = 0; return 1; } } }
	template<class O, class...I>
	bool scanln(O&&n, I&&...s) { return scanln(n) && scanln(s...); }
	char peek() { if (!*t)i(); return*t; }
	bool ignore(char n) { for (;; ++t) { if (!*t && !i())return 0; if (*t - n)return 1; } }
	bool ignore() { for (;; ++t) { if (!*t && !i())return 0; if (!isspace(*t))return 1; } }
	bool advance() { if (!*t && !i())return 0; return*++t; }
	bool advance(ptrdiff_t n) { if (!*t && !i())return 0; for (ptrdiff_t s = a - t; s <= n;) { n -= s; if (!i())return 0; s = a - t; }t += n; return  *t; }
	template<class O>
	O next() { O n; scan(n); return n; }
	template<class O>
	FastScanner&operator>>(O&n) { scan(n); return*this; }
};
template <::std::uint_fast32_t MODULO> class modint {
public:
	using uint32 = ::std::uint_fast32_t; using uint64 = ::std::uint_fast64_t; using value_type = uint32; uint32 a; modint() noexcept : a(0) {}modint(const uint32 x) noexcept : a(x) {}modint operator+(const modint &o) const noexcept { return a + o.a < MODULO ? modint(a + o.a) : modint(a + o.a - MODULO); }modint operator-(const modint &o) const noexcept { return modint(a < o.a ? a + MODULO - o.a : a - o.a); }modint operator*(const modint &o) const noexcept { return modint(static_cast<uint64>(a) * o.a % MODULO); }modint operator/(const modint &o) const { return modint(static_cast<uint64>(a) * (~o).a % MODULO); }modint &operator+=(const modint &o) noexcept { return *this = *this + o; }modint &operator-=(const modint &o) noexcept { return *this = *this - o; }modint &operator*=(const modint &o) noexcept { return *this = *this * o; }modint &operator/=(const modint &o) { return *this = *this / o; }modint operator~() const noexcept { return pow(MODULO - 2); }modint operator-() const noexcept { return a ? modint(MODULO - a) : *this; }modint operator++() noexcept { return a == MODULO - 1 ? a = 0 : ++a, *this; }modint operator--() noexcept { return a ? --a : a = MODULO - 1, *this; }bool operator==(const modint &o) const noexcept { return a == o.a; }bool operator!=(const modint &o) const noexcept { return a != o.a; }bool operator<(const modint &o) const noexcept { return a < o.a; }bool operator<=(const modint &o) const noexcept { return a <= o.a; }bool operator>(const modint &o) const noexcept { return a > o.a; }bool operator>=(const modint &o) const noexcept { return a >= o.a; }explicit operator bool() const noexcept { return a; }explicit operator uint32() const noexcept { return a; }modint pow(uint32 x) const noexcept { uint64 t = a, u = 1; while (x) { if (x & 1)u = u * t % MODULO; t = (t * t) % MODULO; x >>= 1; }	return modint(u); }
	uint32 get() const noexcept { return a; }
};
constexpr size_t BUF_SIZE = (1 << 17);
FastScanner<BUF_SIZE> CIN(stdin);
using mint = modint<MOD>;
const int r() { int a; scanf("%d", &a); return a; }
mint dp[2003][2003];
mint memo[2003][2003];

int main() {
	int N, M, Q;
	CIN.scan(N, M, Q);
	VI a(N);
	FOR(i, 0, N) {
		CIN.scan(a[i]);
	}
	dp[0][0] = 1;
	FOR(i, 0, N) {
		FOR(j, 0, M + 1) {
			dp[i + 1][j] = dp[i][j];
			if (j - 1 >= 0) {
				dp[i + 1][j] += dp[i + 1][j - 1];
			}
			if (j - 1 - a[i] >= 0) {
				dp[i + 1][j] -= dp[i][j - 1 - a[i]];
			}
		}
	}
	FOR(rev, 0, N) {
		FOR(j, 0, M + 1) {
			memo[rev][j] = dp[N][j]; // !
			if (j - 1 >= 0) {
				memo[rev][j] -= dp[N][j - 1]; // !!
			}
			if (j - 1 - a[rev] >= 0) {
				memo[rev][j] += memo[rev][j - 1 - a[rev]];
			}
		}
	}

	int k, x;
	FOR(_, 0, Q) {
		CIN.scan(k, x);
		printf("%d\n", memo[k-1][M-x].get());
	}

	return 0;
}
