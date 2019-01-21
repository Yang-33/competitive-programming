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

/* -----  2019/01/21  Problem: yukicoder 665  / Link: http://yukicoder.me/problems/no/665  ----- */
/* ------問題------

1^k+⋯+n^k modulo 10^9+7を計算してください。

-----問題ここまで----- */
/* -----解説等-----

ファウルハーバーの公式から計算してもO(K^2)で間に合う．
多項式補間でもできて，底が1..Kまで列挙すればよい．こちらはO(KlogMOD)でできる．

----解説ここまで---- */

template <::std::uint_fast32_t MODULO> class modint {
public:
	using uint32 = ::std::uint_fast32_t; using uint64 = ::std::uint_fast64_t; using value_type = uint32; uint32 a; modint() noexcept : a(0) {}modint(const signed x) noexcept : a(x) {}modint(const long long x) noexcept : a(x%MODULO) {}modint(const uint32 x) noexcept : a(x) {}modint operator+(const modint &o) const noexcept { return a + o.a < MODULO ? modint(a + o.a) : modint(a + o.a - MODULO); }modint operator-(const modint &o) const noexcept { return modint(a < o.a ? a + MODULO - o.a : a - o.a); }modint operator*(const modint &o) const noexcept { return modint(static_cast<uint64>(a) * o.a % MODULO); }modint operator/(const modint &o) const { return modint(static_cast<uint64>(a) * (~o).a % MODULO); }modint &operator+=(const modint &o) noexcept { return *this = *this + o; }modint &operator-=(const modint &o) noexcept { return *this = *this - o; }modint &operator*=(const modint &o) noexcept { return *this = *this * o; }modint &operator/=(const modint &o) { return *this = *this / o; }modint operator~() const noexcept { return pow(MODULO - 2); }modint operator-() const noexcept { return a ? modint(MODULO - a) : *this; }modint operator++() noexcept { return a == MODULO - 1 ? a = 0 : ++a, *this; }modint operator--() noexcept { return a ? --a : a = MODULO - 1, *this; }bool operator==(const modint &o) const noexcept { return a == o.a; }bool operator!=(const modint &o) const noexcept { return a != o.a; }bool operator<(const modint &o) const noexcept { return a < o.a; }bool operator<=(const modint &o) const noexcept { return a <= o.a; }bool operator>(const modint &o) const noexcept { return a > o.a; }bool operator>=(const modint &o) const noexcept { return a >= o.a; }explicit operator bool() const noexcept { return a; }explicit operator uint32() const noexcept { return a; }modint pow(uint32 x) const noexcept { uint64 t = a, u = 1; while (x) { if (x & 1)u = u * t % MODULO; t = (t * t) % MODULO; x >>= 1; }	return modint(u); }
	uint32 get() const noexcept { return a; }
};
using mint = modint<MOD>;
mint lagrange_polynomial(const vector<mint> &ys, long long  n) {
	int k = ys.size() - 1;
	if (n <= k) return ys[n];
	n %= MOD;
	mint qi = 1, qt = n;
	for (int i = 1; i <= k; i++) {
		qi *= (MOD - i);
		qt *= n - i;
	}
	mint res = ys[0] / (qi * n);
	for (int i = 1; i <= k; i++) {
		(qi *= i) /= (MOD - k + (i - 1));
		res += ys[i] / (qi * (n - i));
	}
	return res * qt;
}

mint Faulhhaber_polynomial_interpolation(long long n, int k) {
	vector<mint>a(k + 2);
	FOR(i, 1, (k + 1) + 1) {
		a[i] = a[i - 1] + mint(i).pow(k);
	}
	return lagrange_polynomial(a, n);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, K; cin >> N >> K;

	cout << Faulhhaber_polynomial_interpolation(N, K).get() << endl;

	return 0;
}
