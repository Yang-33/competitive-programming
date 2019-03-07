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

/* -----  2019/01/06  Problem: EDU_DP T / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

いやこれ面白いな
ref :: https://atcoder.jp/contests/dp/submissions/3956869
dp(i,x):=i回数字を置いたときに、最後においた数字より小さいものがx個存在する組合せ

遷移は'<'のとき、dp(i+1, [0,x)) ← dp(i,x)である。
これは小さい側のどの数字を選んだかわからないから、全部のパラメータに影響を及ぼしうる。
'>'のときは、dp(i+1,[x,N)) ← dp(i,x)である。
同様。

挿入dp的な解き方は理解できていない。

----解説ここまで---- */
template <::std::uint_fast32_t MODULO> class modint {
public:
	using uint32 = ::std::uint_fast32_t; using uint64 = ::std::uint_fast64_t; using value_type = uint32; uint32 a; modint() noexcept : a(0) {}modint(const uint32 x) noexcept : a(x) {}modint operator+(const modint &o) const noexcept { return a + o.a < MODULO ? modint(a + o.a) : modint(a + o.a - MODULO); }modint operator-(const modint &o) const noexcept { return modint(a < o.a ? a + MODULO - o.a : a - o.a); }modint operator*(const modint &o) const noexcept { return modint(static_cast<uint64>(a) * o.a % MODULO); }modint operator/(const modint &o) const { return modint(static_cast<uint64>(a) * (~o).a % MODULO); }modint &operator+=(const modint &o) noexcept { return *this = *this + o; }modint &operator-=(const modint &o) noexcept { return *this = *this - o; }modint &operator*=(const modint &o) noexcept { return *this = *this * o; }modint &operator/=(const modint &o) { return *this = *this / o; }modint operator~() const noexcept { return pow(MODULO - 2); }modint operator-() const noexcept { return a ? modint(MODULO - a) : *this; }modint operator++() noexcept { return a == MODULO - 1 ? a = 0 : ++a, *this; }modint operator--() noexcept { return a ? --a : a = MODULO - 1, *this; }bool operator==(const modint &o) const noexcept { return a == o.a; }bool operator!=(const modint &o) const noexcept { return a != o.a; }bool operator<(const modint &o) const noexcept { return a < o.a; }bool operator<=(const modint &o) const noexcept { return a <= o.a; }bool operator>(const modint &o) const noexcept { return a > o.a; }bool operator>=(const modint &o) const noexcept { return a >= o.a; }explicit operator bool() const noexcept { return a; }explicit operator uint32() const noexcept { return a; }modint pow(uint32 x) const noexcept { uint64 t = a, u = 1; while (x) { if (x & 1)u = u * t % MODULO; t = (t * t) % MODULO; x >>= 1; }	return modint(u); }
	uint32 get() const noexcept { return a; }
};
using mint = modint<MOD>;


LL ans = 0LL;
mint dp[3003][3003];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	string s; cin >> s;
	s = "<" + s;
	dp[0][N] = 1;
	FOR(i, 0, N) {
		int left = N - i;
		FOR(le, 0, left + 1) {
			if (s[i] == '<') {
				dp[i + 1][0] += dp[i][le];
				if (le != left) {
					dp[i + 1][le] -= dp[i][le];
				}
			}
			else {
				if (le != left) {
					dp[i + 1][le] += dp[i][le];
				}
			}
		}
		FOR(le, 0, left + 1) {
			dp[i + 1][le + 1] += dp[i + 1][le];
		}
	}

	ans = dp[N][0].get();

	cout << ans << "\n";

	return 0;
}
