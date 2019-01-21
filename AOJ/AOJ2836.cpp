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

/* -----  2019/01/21  Problem: AOJ 2836 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2836  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

深さが必ずN-1までであり，かつ移動先が[0,N]であるM回移動の方法．
これは，y<=x+(N-1) ∧ y>=x以内で±1の移動を経路上で行う移動数になる．

難しすぎる．
経路上での移動としてカタラン数を求めるときのノリで包除で解く．
上下のはみでる部分を反転していくとして，繰り返される反転部分を包除する．

----解説ここまで---- */

template <::std::uint_fast32_t MODULO> class modint {
public:
	using uint32 = ::std::uint_fast32_t; using uint64 = ::std::uint_fast64_t; using value_type = uint32; uint32 a; modint() noexcept : a(0) {}modint(long long x)noexcept :a(x%MODULO) {}modint operator+(const modint &o) const noexcept { return a + o.a < MODULO ? modint(a + o.a) : modint(a + o.a - MODULO); }modint operator-(const modint &o) const noexcept { return modint(a < o.a ? a + MODULO - o.a : a - o.a); }modint operator*(const modint &o) const noexcept { return modint(static_cast<uint64>(a) * o.a % MODULO); }modint operator/(const modint &o) const { return modint(static_cast<uint64>(a) * (~o).a % MODULO); }modint &operator+=(const modint &o) noexcept { return *this = *this + o; }modint &operator-=(const modint &o) noexcept { return *this = *this - o; }modint &operator*=(const modint &o) noexcept { return *this = *this * o; }modint &operator/=(const modint &o) { return *this = *this / o; }modint operator~() const noexcept { return pow(MODULO - 2); }modint operator-() const noexcept { return a ? modint(MODULO - a) : *this; }modint operator++() noexcept { return a == MODULO - 1 ? a = 0 : ++a, *this; }modint operator--() noexcept { return a ? --a : a = MODULO - 1, *this; }bool operator==(const modint &o) const noexcept { return a == o.a; }bool operator!=(const modint &o) const noexcept { return a != o.a; }bool operator<(const modint &o) const noexcept { return a < o.a; }bool operator<=(const modint &o) const noexcept { return a <= o.a; }bool operator>(const modint &o) const noexcept { return a > o.a; }bool operator>=(const modint &o) const noexcept { return a >= o.a; }explicit operator bool() const noexcept { return a; }explicit operator uint32() const noexcept { return a; }modint pow(uint32 x) const noexcept { uint64 t = a, u = 1; while (x) { if (x & 1)u = u * t % MODULO; t = (t * t) % MODULO; x >>= 1; }	return modint(u); }
	uint32 get() const noexcept { return a; }
};
using mint = modint<MOD>;
const mint mintzero = mint(0); const mint mintone = mint(1);
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


// y<=x+(N-1) ∧ y>=x以内で±1の移動を経路上で行う移動数
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2836
mint Wkeiro(int n, int m) {
	mint ret = 0; // 包除で解く．
	for (LL j = -m; j <= m; ++j) {
		if (m + j * (n + 2) < 0) continue;
		LL s = (m + (n + 2) * j) / 2;
		if (s < 0 || s > m) continue;
		mint binom = nCr(m, s);
		if (j % 2 == 0) ret += binom;
		else ret -= binom;
	}
	return ret;
}

// y = x+n+1, y = x+k1の間を通る長さmの経路数(境界含まず)
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2836
mint Wkeiro2(int n, int m, int k1 = -1) {
	// x+y = m
	// y=x+n+1
	// y=x-k1
	// (a,b)
	// 
	mint ans = 0;
	for (int x = 0; x <= m; x++) {
		int y = m - x;
		if (y < x + n + 1 && y > x + k1) { // !
			mint ret = nCr(m, x);
			{
				int b = k1; // !
				int c = y - x;
				int sig = -1;
				while (true) {
					int nc = b * 2 - c;
					// x+y=m
					// y-x=nc
					// x = (m-nc)/2
					int nx = (m - nc) / 2;
					if (nx > m)break;
					ret += (sig > 0 ? nCr(m, nx) : -nCr(m, nx));
					sig = -sig;
					c = nc;
					b -= n + 2;
				}
			}
			{
				int b = n + 1; // !
				int c = y - x;
				int sig = -1;
				while (true) {
					int nc = b * 2 - c;
					// x+y=m
					// y-x=nc
					// x = (m-nc)/2
					int nx = (m - nc) / 2;
					if (nx < 0)break;
					ret += (sig > 0 ? nCr(m, nx) : -nCr(m, nx));
					sig = -sig;
					c = nc;
					b += n + 2;
				}
			}
			ans += ret;
		}
	}
	return ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	init_fact(2e6 + 6);
	LL N, M; cin >> N >> M;
	mint ans = Wkeiro2(N - 1, M) - Wkeiro2(N - 2, M);

	cout << ans.get() << "\n";

	return 0;
}
