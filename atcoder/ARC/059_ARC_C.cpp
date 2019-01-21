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

/* -----  2019/01/20  Problem: ARC 059 C / Link: http://arc059.contest.atcoder.jp/tasks/arc059_c  ----- */
/* ------問題------

競プロ幼稚園には1～Nの番号がついたN人の子供がいます。
えび先生は、区別できないC個のキャンディーを子供たちに分配することにしました。
子供iのはしゃぎ度がxiの時、キャンディーをa個もらうと子供iのうれしさはxiaになります。
幼稚園の活発度はN人の子供たちのうれしさの積になります。
各子供にキャンディーを非負整数個配ってC個配りきる方法それぞれに対して幼稚園の活発度を計算して、その総和を子供たちのはしゃぎ度x1,..,xNの関数とみてf(x1,..,xN)とおきます。
Ai,Bi(1≦i≦N)が与えられるので、 を109+7で割ったあまりを求めてください。

-----問題ここまで----- */
/* -----解説等-----

部分点を考えるとこれを高速化することで解けるhappy問題．
ai=biを考えると，\sum candy_i = Cとなるx_iの分配問題になる．
うれしさの積 \prod x_i^{candy_i}が知りたいので，
dp(i,s):=現在使用したsubCの総和がsのときのうれしさの積
として，dp(N,C)を求めれば良い．遷移はdp(i+1,s+candy)+=dp(i,s)*a(i)となる．(部分点)
満点を取りたい．
a(i)をb(i)まで使えるとする．
O(N^4)のdpとなる．dpの遷移に着目する．
dp[i + 1][add + fromc] += dp[i][fromc] * (mint(x).pow(add));
の，xをa(i)~b(i)はまとめて遷移することができれば，O(N^3)になる．
xにまつわるのは遷移の係数のみなので，O(N^2)で前計算のtableをつくればO(N^3)を達成できる．

----解説ここまで---- */

LL ans = 0LL;
template <::std::uint_fast32_t MODULO> class modint {
public:
	using uint32 = ::std::uint_fast32_t; using uint64 = ::std::uint_fast64_t; using value_type = uint32; uint32 a; modint() noexcept : a(0) {}modint(const uint32 x) noexcept : a(x) {}modint operator+(const modint &o) const noexcept { return a + o.a < MODULO ? modint(a + o.a) : modint(a + o.a - MODULO); }modint operator-(const modint &o) const noexcept { return modint(a < o.a ? a + MODULO - o.a : a - o.a); }modint operator*(const modint &o) const noexcept { return modint(static_cast<uint64>(a) * o.a % MODULO); }modint operator/(const modint &o) const { return modint(static_cast<uint64>(a) * (~o).a % MODULO); }modint &operator+=(const modint &o) noexcept { return *this = *this + o; }modint &operator-=(const modint &o) noexcept { return *this = *this - o; }modint &operator*=(const modint &o) noexcept { return *this = *this * o; }modint &operator/=(const modint &o) { return *this = *this / o; }modint operator~() const noexcept { return pow(MODULO - 2); }modint operator-() const noexcept { return a ? modint(MODULO - a) : *this; }modint operator++() noexcept { return a == MODULO - 1 ? a = 0 : ++a, *this; }modint operator--() noexcept { return a ? --a : a = MODULO - 1, *this; }bool operator==(const modint &o) const noexcept { return a == o.a; }bool operator!=(const modint &o) const noexcept { return a != o.a; }bool operator<(const modint &o) const noexcept { return a < o.a; }bool operator<=(const modint &o) const noexcept { return a <= o.a; }bool operator>(const modint &o) const noexcept { return a > o.a; }bool operator>=(const modint &o) const noexcept { return a >= o.a; }explicit operator bool() const noexcept { return a; }explicit operator uint32() const noexcept { return a; }modint pow(uint32 x) const noexcept { uint64 t = a, u = 1; while (x) { if (x & 1)u = u * t % MODULO; t = (t * t) % MODULO; x >>= 1; }	return modint(u); }
	uint32 get() const noexcept { return a; }
};
using mint = modint<MOD>;

mint dp[403][803];
mint t[403][403];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	{
		FOR(add, 0, 402) {
			FOR(x, 0, 402) {
				t[x + 1][add] += t[x][add] + mint(x + 1).pow(add);
			}
		}
	}
	LL N, C; cin >> N >> C;
	vector<LL> a(N), b(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	FOR(i, 0, N) {
		cin >> b[i];
	}
	dp[0][0] = 1;
	// これを高速に解けば良いO(N^4) - > O(N^3)
	FOR(i, 0, N) {
		FOR(fromc, 0, C + 1) {
			FOR(add, 0, C + 1) {
				if (add + fromc > C)break;
//				dp[i + 1][add + fromc] += dp[i][fromc] * (mint(x).pow(add));


				dp[i + 1][add + fromc] += dp[i][fromc] * (t[b[i]][add] - t[a[i] - 1][add]);
			}
		}
	}


	LL ans = dp[N][C].get();
	cout << ans << endl;

	return 0;
}