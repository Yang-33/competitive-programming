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

/* -----  2019/03/04  Problem: yukicoder 737  / Link: http://yukicoder.me/problems/no/737  ----- */

template <::std::uint_fast32_t MODULO> class modint {
public:
	using uint32 = ::std::uint_fast32_t; using uint64 = ::std::uint_fast64_t; using value_type = uint32; uint32 a; modint() noexcept : a(0) {}modint(const uint32 x) noexcept : a(x) {}modint operator+(const modint &o) const noexcept { return a + o.a < MODULO ? modint(a + o.a) : modint(a + o.a - MODULO); }modint operator-(const modint &o) const noexcept { return modint(a < o.a ? a + MODULO - o.a : a - o.a); }modint operator*(const modint &o) const noexcept { return modint(static_cast<uint64>(a) * o.a % MODULO); }modint operator/(const modint &o) const { return modint(static_cast<uint64>(a) * (~o).a % MODULO); }modint &operator+=(const modint &o) noexcept { return *this = *this + o; }modint &operator-=(const modint &o) noexcept { return *this = *this - o; }modint &operator*=(const modint &o) noexcept { return *this = *this * o; }modint &operator/=(const modint &o) { return *this = *this / o; }modint operator~() const noexcept { return pow(MODULO - 2); }modint operator-() const noexcept { return a ? modint(MODULO - a) : *this; }modint operator++() noexcept { return a == MODULO - 1 ? a = 0 : ++a, *this; }modint operator--() noexcept { return a ? --a : a = MODULO - 1, *this; }bool operator==(const modint &o) const noexcept { return a == o.a; }bool operator!=(const modint &o) const noexcept { return a != o.a; }bool operator<(const modint &o) const noexcept { return a < o.a; }bool operator<=(const modint &o) const noexcept { return a <= o.a; }bool operator>(const modint &o) const noexcept { return a > o.a; }bool operator>=(const modint &o) const noexcept { return a >= o.a; }explicit operator bool() const noexcept { return a; }explicit operator uint32() const noexcept { return a; }modint pow(uint32 x) const noexcept { uint64 t = a, u = 1; while (x) { if (x & 1)u = u * t % MODULO; t = (t * t) % MODULO; x >>= 1; }	return modint(u); }
	uint32 get() const noexcept { return a; }
};
using mint = modint<MOD>;

using PMM = pair<mint, mint>;
const PMM ee = PMM(-1, 0);
const mint two = 2;
PMM dp[62][62][2];
PMM f(const string&s, int id, int leftcnt, bool less) {
	if (leftcnt < 0)return PMM(0, 0);
	if (id < 0) {
		return PMM(leftcnt == 0, 0);
	}
	if (dp[id][leftcnt][less] != ee)return dp[id][leftcnt][less];


	PMM res = PMM(0, 0);
	int Max = less ? 1 : s[id] - '0';
	FOR(nx, 0, Max + 1) {
		PMM a = f(s, id - 1, leftcnt - (nx == 1), less || (nx < Max));
		res.first += a.first; // 場合の数
		res.second += (two.pow(id)*nx)*a.first + a.second;
	}


	return dp[id][leftcnt][less] = res;
}

string to_binString(LL val) {
	string str;
	while (val != 0) {
		if ((val & 1) == 0)
			str += "0";
		else
			str += "1";
		val >>= 1;
	}
	reverse(str.begin(), str.end());
	return str;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	fill(**dp, **dp + 62 * 62 * 2, ee);
	LL N; cin >> N;
	string s = to_binString(N);
	reverse(ALL(s));
	DD(de(s));
	mint ans = 0;
	FOR(i, 1, 62) {
		ans += f(s, SZ(s) - 1, i, 0).second * mint(i);
	}

	cout << (ans.get()) << "\n";

	return 0;
}
