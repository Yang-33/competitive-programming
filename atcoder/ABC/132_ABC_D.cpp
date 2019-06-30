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

/* -----  2019/06/29  Problem: ABC 132 D / Link: http://abc132.contest.atcoder.jp/tasks/abc132_d  ----- */

class GModInt {
public:
	static int Mod;	int x; GModInt() : x(0) { }GModInt(signed sig) { if ((x = sig % Mod + Mod) >= Mod) x -= Mod; }GModInt(signed long long sig) { if ((x = sig % Mod + Mod) >= Mod) x -= Mod; }int get() const { return x; }	GModInt &operator+=(GModInt that) { if ((x += that.x) >= Mod) x -= Mod; return *this; }	GModInt &operator-=(GModInt that) { if ((x += Mod - that.x) >= Mod) x -= Mod; return *this; }GModInt &operator*=(GModInt that) { x = (unsigned long long)x * that.x % Mod; return *this; }GModInt &operator/=(GModInt that) { return *this *= that.inverse(); }GModInt operator+(GModInt that) const { return GModInt(*this) += that; }GModInt operator-(GModInt that) const { return GModInt(*this) -= that; }GModInt operator*(GModInt that) const { return GModInt(*this) *= that; }GModInt operator/(GModInt that) const { return GModInt(*this) /= that; }GModInt inverse() const { long long a = x, b = Mod, u = 1, v = 0; while (b) { long long t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }return GModInt(u); }bool operator==(GModInt that) const { return x == that.x; }bool operator!=(GModInt that) const { return x != that.x; }GModInt operator-() const { GModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
int GModInt::Mod = MOD;
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

const mint mintzero = mint(0);
const mint mintone = mint(1);
mint modinv(mint a) { return mintone / mint(a); }

vector<mint> fact, inv_fact;

void init_fact(int n) {
	fact.resize(n);
	fact[0] = mintone;
	for (int i = 1; i < n; i++) {
		fact[i] = fact[i - 1] * mint(i);
	}
	inv_fact.resize(n);
	inv_fact[n - 1] = modinv(fact[n - 1]);
	for (int i = n - 2; i >= 0; i--) {
		inv_fact[i] = mint(i + 1) * inv_fact[i + 1];
	}
}
mint nCr(int n, int r) {
	if (n < r || n < 0 || r < 0) return mintzero;
	return fact[n] * inv_fact[r] * inv_fact[n - r];
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	init_fact(3e6);
	LL N, K; cin >> N >> K;
	LL B = K;
	LL R = N - K;
	FOR(i, 1, K + 1) {
		mint ans = nCr(R + 1, i)*nCr(B - 1, B - i);
		cout << ans.get() << "\n";
	}

	return 0;
}
