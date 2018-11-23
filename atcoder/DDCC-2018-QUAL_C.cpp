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

/* -----  2018/11/23  Problem: DDCC-2018-qual C / Link: __CONTEST_URL__  ----- */
/* ------問題------

高橋君の飼い犬の BISCO は, ディスコ株式会社で働いている. ある日, BISCO は 10 年間の功績を認められ, 社長の WISCO からプレゼントとして正方形のチップを 100 枚渡された.
BISCO は, これらのチップを以下のように 10 行 10 列に並べた.
ここで, 上から a 番目, 左から b 番目にあるチップを「チップ (a,b)」と表す.
さて, BISCO はこれらのチップに以下のようにして整数を書き込むことにした.
まず, 数列 P=(P1,P2,P3,…,P10) と Q=(Q1,Q2,Q3,…,Q10) を決める. これらの項の値はすべて正の整数でなければならない.
次に, 各チップ (i,j) に整数 Pi×Qj を書き込む.
このとき, チップに書き込む整数はすべて 1 以上 N 以下でなければならない. この条件が満たされたときのみ, 書き込みが成功する.
BISCO は, 書き込みが成功するような数列 P,Q の決め方が何通り存在するかに興味を持った.
彼のために, 書き込みが成功するような (P1,P2,P3,…,P10,Q1,Q2,Q3,…,Q10) の組合せとして考えられるものの個数を 1 000 000 007 で割った余りを求めなさい.

-----問題ここまで----- */
/* -----解説等-----

片側の列の最大値がXであるとき、反対側はN/Xが最大値になる。
それぞれ数え上げるためには、片側の列の最大値がちょうどXになれば良い。
これは適当な包除でできる。

とおもったら、i^10-(i-1)^10だった(中学算数的にそれはそう)

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

	LL in; cin >> in;
	mint N = in;

	mint ans = N.pow(10);
	mint pre = 1;
	FOR(s, 2, in + 1) {
		mint just = mint(s).pow(10) - pre;
		DD(de(just.get()));
		pre += just;
		mint val = (in / s)%MOD;
		ans += just * (val.pow(10));
	}
	DD(de(ans.get()));
	cout << ans.get() << "\n";

	return 0;
}
