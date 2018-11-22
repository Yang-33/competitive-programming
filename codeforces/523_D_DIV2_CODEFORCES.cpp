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

/* -----  2018/11/23  Problem: CodeForces523 D div2 / Link: http://codeforces.com/contest/1061/problem/D  ----- */
/* ------問題------

[Li:Ri]でテレビを見る。
テレビの視聴コストは、X+Y*(見た時間)であり、テレビは何個つかっても良い。
最小コストをmodして答えろ。

-----問題ここまで----- */
/* -----解説等-----

なんで貪欲でいいんですか?いいですね
適当に状態を変数にして式を書くとこれで良いことが分かるので、前からやっていけば良い
{証明}
前からやっていくとして、終端A,B,Cがあり、候補がD,E,Fとする。
D-A+E-B+F-Cとなり、整理すると(D+E+F) - (A+B+C)となる。したがってどの順番でくっつけても良い
ただ、新規作成 or くっつける のminを保持してやる必要があるだけ。

----解説ここまで---- */

template <::std::uint_fast32_t MODULO> class modint {
public:
	using uint32 = ::std::uint_fast32_t; using uint64 = ::std::uint_fast64_t; using value_type = uint32; uint32 a; modint() noexcept : a(0) {}modint(const uint32 x) noexcept : a(x) {}modint operator+(const modint &o) const noexcept { return a + o.a < MODULO ? modint(a + o.a) : modint(a + o.a - MODULO); }modint operator-(const modint &o) const noexcept { return modint(a < o.a ? a + MODULO - o.a : a - o.a); }modint operator*(const modint &o) const noexcept { return modint(static_cast<uint64>(a) * o.a % MODULO); }modint operator/(const modint &o) const { return modint(static_cast<uint64>(a) * (~o).a % MODULO); }modint &operator+=(const modint &o) noexcept { return *this = *this + o; }modint &operator-=(const modint &o) noexcept { return *this = *this - o; }modint &operator*=(const modint &o) noexcept { return *this = *this * o; }modint &operator/=(const modint &o) { return *this = *this / o; }modint operator~() const noexcept { return pow(MODULO - 2); }modint operator-() const noexcept { return a ? modint(MODULO - a) : *this; }modint operator++() noexcept { return a == MODULO - 1 ? a = 0 : ++a, *this; }modint operator--() noexcept { return a ? --a : a = MODULO - 1, *this; }bool operator==(const modint &o) const noexcept { return a == o.a; }bool operator!=(const modint &o) const noexcept { return a != o.a; }bool operator<(const modint &o) const noexcept { return a < o.a; }bool operator<=(const modint &o) const noexcept { return a <= o.a; }bool operator>(const modint &o) const noexcept { return a > o.a; }bool operator>=(const modint &o) const noexcept { return a >= o.a; }explicit operator bool() const noexcept { return a; }explicit operator uint32() const noexcept { return a; }modint pow(uint32 x) const noexcept { uint64 t = a, u = 1; while (x) { if (x & 1)u = u * t % MODULO; t = (t * t) % MODULO; x >>= 1; }	return modint(u); }
	uint32 get() const noexcept { return a; }
};
using mint = modint<MOD>;
int read() { int in; scanf("%d", &in); return in; }
mint ans = 0;
int main() {
	LL N = read(), x = read(), y = read();
	VL L(N), R(N);
	vector<PLL>ts(N);
	FOR(i, 0, N) {
		L[i] = read(), R[i] = read();
		ts[i] = PLL(L[i], R[i]);
	}
	SORT(ts);
	multiset<LL>se;
	ans = (x + y * (ts[0].second - ts[0].first)) % MOD;
	se.insert(ts[0].second);
	FOR(i, 1, N) {
		if (*se.begin() >= ts[i].first) {
			ans += (x + y * (ts[i].second - ts[i].first)) % MOD;
		}
		else {
			auto it = se.lower_bound(ts[i].first);
			if (it != se.begin()) {
				it--;
				LL ti = *it;
				ans += (min(x, y * (ts[i].first - ti))// 作成するあるいはくっつける
					+ y * (ts[i].second - ts[i].first)) % MOD;
				se.erase(it);
			}
		}
		se.insert(ts[i].second);
	}


	cout << ans.get() << "\n";

	return 0;
}
