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
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 998244353;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif

/* -----  2018/10/11  Problem: EDU052 E / Link: __CONTEST_URL__  ----- */
/* ------問題------

A種類の文字をつかって長さNの文字列をつくる。
数列Bが与えられ、先頭からb個、後ろからb個を反転し、場所をswapするという動作を繰り返して同一になる文字列は一緒とみなした時、
何個文字列を作ることができるか。

-----問題ここまで----- */
/* -----解説等-----

まず、少し考えるとb[i],b[i+1]で区切られる区間はそれぞれ独立している。
したがってこの区間c[i] = b[i+1]-b[i]を考えれば良い。
これについて、反転してswapするということは区間を全部reverseすることになり、これでおなじになるものを除けば良いことになる。
これは全体のA^(2*c[i])個のうち、左右対称である=左と右が一緒なので片側を決めば良い。
これはA^(c[i])個。
よって各c[i]について(ALL-片側)/2 + 方側をかけていけば良い。

----解説ここまで---- */

template <::std::uint_fast32_t MODULO> class modint {
public:
	using uint32 = ::std::uint_fast32_t; using uint64 = ::std::uint_fast64_t; using value_type = uint32; uint32 a; modint() noexcept : a(0) {}modint(const uint32 x) noexcept : a(x) {}modint operator+(const modint &o) const noexcept { return a + o.a < MODULO ? modint(a + o.a) : modint(a + o.a - MODULO); }modint operator-(const modint &o) const noexcept { return modint(a < o.a ? a + MODULO - o.a : a - o.a); }modint operator*(const modint &o) const noexcept { return modint(static_cast<uint64>(a) * o.a % MODULO); }modint operator/(const modint &o) const { return modint(static_cast<uint64>(a) * (~o).a % MODULO); }modint &operator+=(const modint &o) noexcept { return *this = *this + o; }modint &operator-=(const modint &o) noexcept { return *this = *this - o; }modint &operator*=(const modint &o) noexcept { return *this = *this * o; }modint &operator/=(const modint &o) { return *this = *this / o; }modint operator~() const noexcept { return pow(MODULO - 2); }modint operator-() const noexcept { return a ? modint(MODULO - a) : *this; }modint operator++() noexcept { return a == MODULO - 1 ? a = 0 : ++a, *this; }modint operator--() noexcept { return a ? --a : a = MODULO - 1, *this; }bool operator==(const modint &o) const noexcept { return a == o.a; }bool operator!=(const modint &o) const noexcept { return a != o.a; }bool operator<(const modint &o) const noexcept { return a < o.a; }bool operator<=(const modint &o) const noexcept { return a <= o.a; }bool operator>(const modint &o) const noexcept { return a > o.a; }bool operator>=(const modint &o) const noexcept { return a >= o.a; }explicit operator bool() const noexcept { return a; }explicit operator uint32() const noexcept { return a; }modint pow(uint32 x) const noexcept { uint64 t = a, u = 1; while (x) { if (x & 1)u = u * t % MODULO; t = (t * t) % MODULO; x >>= 1; }	return modint(u); }
	uint32 get() const noexcept { return a; }
};
using mint = modint<MOD>;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M, A; cin >> N >> M >> A;
	VL b(M);
	FOR(i, 0, M) {
		cin >> b[i];
	}
	VL c(M); {
		LL prev = 0;
		FOR(i, 0, M) {
			c[i] = b[i] - prev;
			prev = b[i];
		}
		DD(De(c));
	}
	const mint a = A%MOD;
	mint ans = 1;
	const mint Apo = a.pow(N - 2 * b.back());
	ans *= Apo;
	{
		const mint two = 2;
		for (LL C : c) {
			mint all = a.pow(2 * C);
			mint kaibun = a.pow(C);
			mint ret = (all - kaibun) / two + kaibun;
			ans *= ret;

		}
	}
	cout << ans.get() << endl;



	return 0;
}
