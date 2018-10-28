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

/* -----  2018/10/27  Problem: ARC 033 D / Link: http://arc033.contest.atcoder.jp/tasks/arc033_d  ----- */
/* ------問題------

高橋君は、見たことのない N 次多項式 P(x) を見つけたそうです。
この多項式の係数は全て正整数だそうです。高橋君はあなたに P(0) 〜 P(N) の値を教えてくれました。さてここで、あなたは P(T) の値を当てることができるでしょうか。

-----問題ここまで----- */
/* -----解説等-----

N次多項式の点はN+1点あればほぼ完璧に求めることができる。
ラグランジュ補間でも解けてしまったが、スプライン補間の方が数学的に正しそう。
(スプライン補間はラグランジュ補間を細かく使ったものなので)

----解説ここまで---- */

template <::std::uint_fast32_t MODULO> class modint {
public:
	using uint32 = ::std::uint_fast32_t; using uint64 = ::std::uint_fast64_t; using value_type = uint32; uint32 a; modint() noexcept : a(0) {}modint(const uint32 x) noexcept : a(x) {}modint operator+(const modint &o) const noexcept { return a + o.a < MODULO ? modint(a + o.a) : modint(a + o.a - MODULO); }modint operator-(const modint &o) const noexcept { return modint(a < o.a ? a + MODULO - o.a : a - o.a); }modint operator*(const modint &o) const noexcept { return modint(static_cast<uint64>(a) * o.a % MODULO); }modint operator/(const modint &o) const { return modint(static_cast<uint64>(a) * (~o).a % MODULO); }modint &operator+=(const modint &o) noexcept { return *this = *this + o; }modint &operator-=(const modint &o) noexcept { return *this = *this - o; }modint &operator*=(const modint &o) noexcept { return *this = *this * o; }modint &operator/=(const modint &o) { return *this = *this / o; }modint operator~() const noexcept { return pow(MODULO - 2); }modint operator-() const noexcept { return a ? modint(MODULO - a) : *this; }modint operator++() noexcept { return a == MODULO - 1 ? a = 0 : ++a, *this; }modint operator--() noexcept { return a ? --a : a = MODULO - 1, *this; }bool operator==(const modint &o) const noexcept { return a == o.a; }bool operator!=(const modint &o) const noexcept { return a != o.a; }bool operator<(const modint &o) const noexcept { return a < o.a; }bool operator<=(const modint &o) const noexcept { return a <= o.a; }bool operator>(const modint &o) const noexcept { return a > o.a; }bool operator>=(const modint &o) const noexcept { return a >= o.a; }explicit operator bool() const noexcept { return a; }explicit operator uint32() const noexcept { return a; }modint pow(uint32 x) const noexcept { uint64 t = a, u = 1; while (x) { if (x & 1)u = u * t % MODULO; t = (t * t) % MODULO; x >>= 1; }	return modint(u); }
	uint32 get() const noexcept { return a; }
};
using mint = modint<MOD>;

mint lagrange_polynomial(const vector<mint> &ys, int n) {
	int k = ys.size() - 1;
	if (n <= k) return ys[n];
	mint qi = 1, qt = n;
	for (int i = 1; i <= k; i++) {
		qi *= (MOD - i);
		qt *= n - i;
	}
	mint res = ys[0] / qi * (qt / n);
	for (int i = 1; i <= k; i++) {
		qi = (qi * i) / (MOD - k + (i - 1));
		res += ys[i] / qi * (qt / (n - i));
	}
	return res;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	vector<mint>a(N + 1);
	FOR(i, 0, N + 1) {
		cin >> a[i].a;
	}
	int T; cin >> T;
	cout << lagrange_polynomial(a, T).get() << endl;


	//cout << ans << "\n";

	return 0;
}
