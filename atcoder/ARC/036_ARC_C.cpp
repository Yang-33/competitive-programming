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

/* -----  2018/10/24  Problem: ARC 036 C / Link: http://arc036.contest.atcoder.jp/tasks/arc036_c  ----- */
/* ------問題------

高橋くんはゲーム会社に勤めている。
高橋くんは上司から、乱数表を作るよう指示を受けた。
乱数表は 0,1 のいずれかでのみ構成される長さ N の数列で、そのうちいくつかの要素には、どちらの値が入るかが決まっている。
ところで高橋くんは、上司から「あまり分布が偏った乱数表は作らないでほしい」という注文も受けている。具体的には、乱数表からどのような連続する部分列を取り出しても、その部分列に含まれる 0 の個数と 1 の個数の差が K 以下でなければならない。
高橋くんはこのような条件を満たす乱数表が全部でいくつあるのか数えることにした。

-----問題ここまで----- */
/* -----解説等-----

ウォーキングのグリッドを考えて、0/1を-1/+1を対応させる。
この時、このグラフのtop/downの差がK以下であるような経路数を求めればいいことになる。
状態の区別は(ith,+top,-down)でよい。
これ難しいなあ

----解説ここまで---- */

template <::std::uint_fast32_t MODULO> class modint {
public:
	using uint32 = ::std::uint_fast32_t; using uint64 = ::std::uint_fast64_t; using value_type = uint32; uint32 a; modint() noexcept : a(0) {}modint(const uint32 x) noexcept : a(x) {}modint operator+(const modint &o) const noexcept { return a + o.a < MODULO ? modint(a + o.a) : modint(a + o.a - MODULO); }modint operator-(const modint &o) const noexcept { return modint(a < o.a ? a + MODULO - o.a : a - o.a); }modint operator*(const modint &o) const noexcept { return modint(static_cast<uint64>(a) * o.a % MODULO); }modint operator/(const modint &o) const { return modint(static_cast<uint64>(a) * (~o).a % MODULO); }modint &operator+=(const modint &o) noexcept { return *this = *this + o; }modint &operator-=(const modint &o) noexcept { return *this = *this - o; }modint &operator*=(const modint &o) noexcept { return *this = *this * o; }modint &operator/=(const modint &o) { return *this = *this / o; }modint operator~() const noexcept { return pow(MODULO - 2); }modint operator-() const noexcept { return a ? modint(MODULO - a) : *this; }modint operator++() noexcept { return a == MODULO - 1 ? a = 0 : ++a, *this; }modint operator--() noexcept { return a ? --a : a = MODULO - 1, *this; }bool operator==(const modint &o) const noexcept { return a == o.a; }bool operator!=(const modint &o) const noexcept { return a != o.a; }bool operator<(const modint &o) const noexcept { return a < o.a; }bool operator<=(const modint &o) const noexcept { return a <= o.a; }bool operator>(const modint &o) const noexcept { return a > o.a; }bool operator>=(const modint &o) const noexcept { return a >= o.a; }explicit operator bool() const noexcept { return a; }explicit operator uint32() const noexcept { return a; }modint pow(uint32 x) const noexcept { uint64 t = a, u = 1; while (x) { if (x & 1)u = u * t % MODULO; t = (t * t) % MODULO; x >>= 1; }	return modint(u); }
	uint32 get() const noexcept { return a; }
};
using mint = modint<MOD>;

mint dp[302][302][302];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, K; cin >> N >> K;
	string s; cin >> s;
	dp[0][0][0] = 1;

	FOR(i, 0, N) {
		FOR(mx, 0, K + 1) {
			FOR(mi, 0, K + 1) {
				if (dp[i][mx][mi] == 0)continue;

				// 最小、最大について
				if (s[i] == '0' || s[i] == '?') {
					int zemx = max(0, mx - 1);
					dp[i + 1][zemx][mi + 1] += dp[i][mx][mi];
				}
				if (s[i] == '1' || s[i] == '?') {
					int zemi = max(0, mi - 1);
					dp[i + 1][mx + 1][zemi] += dp[i][mx][mi];
				}
			}
		}
	}

	mint ans;
	FOR(i, 0, K + 1) {
		FOR(j, 0, K + 1) {
			if (i + j <= K) {
				ans += dp[N][i][j];
			}
		}
	}

	cout << ans.get() << "\n";

	return 0;
}
