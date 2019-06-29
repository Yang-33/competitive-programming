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

/* -----  2019/06/01  Problem: M-Solutions2019 E / Link: https://atcoder.jp/contests/m-solutions2019  ----- */

// runtime_modint
//Modはどんな計算もする前に、最初に代入すること！
//Modが素数であるとか確認すること！
class GModInt {
public:
	static int Mod;	int x; GModInt() : x(0) { }GModInt(signed sig) { if ((x = sig % Mod + Mod) >= Mod) x -= Mod; }GModInt(signed long long sig) { if ((x = sig % Mod + Mod) >= Mod) x -= Mod; }int get() const { return x; }	GModInt &operator+=(GModInt that) { if ((x += that.x) >= Mod) x -= Mod; return *this; }	GModInt &operator-=(GModInt that) { if ((x += Mod - that.x) >= Mod) x -= Mod; return *this; }GModInt &operator*=(GModInt that) { x = (unsigned long long)x * that.x % Mod; return *this; }GModInt &operator/=(GModInt that) { return *this *= that.inverse(); }GModInt operator+(GModInt that) const { return GModInt(*this) += that; }GModInt operator-(GModInt that) const { return GModInt(*this) -= that; }GModInt operator*(GModInt that) const { return GModInt(*this) *= that; }GModInt operator/(GModInt that) const { return GModInt(*this) /= that; }GModInt inverse() const { long long a = x, b = Mod, u = 1, v = 0; while (b) { long long t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }return GModInt(u); }bool operator==(GModInt that) const { return x == that.x; }bool operator!=(GModInt that) const { return x != that.x; }GModInt operator-() const { GModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
int GModInt::Mod = 1000003;
typedef GModInt mint;
mint operator^(mint a, unsigned long long k) {
	mint r = 1;
	while (k) {
		if (k & 1) r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}
using mint = GModInt;
vector<mint> fact;

mint calc(int x, int d, int n) {
	mint ret = mint(d) ^ (n);
	mint kim = mint(x) / mint(d);
	if ((LL)kim.get() + n - 1 >= GModInt::Mod)return mint(0);
	if (kim.get() == 0) {
		return ret * fact[(kim.get() + n - 1)];
	}
	ret *= fact[(kim.get() + n - 1)] / fact[kim.get() - 1];
	return ret;
}


void factset(int n) {
	fact.resize(n);
	fact[0] = 1;
	for (int i = 1; i < n; i++) {
		fact[i] = fact[i - 1] * mint(i);
	}
}

// factor: MOD : MOD
int main() {
	factset(3 * 1000003);

	int Q;
	cin >> Q;
	// 


	FOR(z, 0, Q) {
		int x, d, n;
		cin >> x >> d >> n;
		if (x == 0) {
			cout << 0 << "\n";
		}
		else  if (d == 0) {
			cout << ((mint(x) ^ (n)).get()) << "\n";
		}
		else {
			cout << calc(x, d, n).get() << "\n";
		}
	}

}
