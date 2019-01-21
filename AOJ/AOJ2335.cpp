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

/* -----  2019/01/21  Problem: AOJ 2335 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2335  ----- */
/* ------問題------

点(0, 0) から点(N, M) まで、碁盤目状の道を通って進む方法は何通りあるか答えよ。
基本的には右か上に１マス進むが、途中で、ちょうどK 回だけ寄り道をする。
「寄り道をする」とは、左か下に１マス進むことである。
K 回の寄り道をすませていない場合、いったん点(N, M) に着いた後でも歩き続ける。途中で点(0, 0) に戻ってくる場合もある。
家はこの街の隅に建っているので、X 座標またはY 座標が負になるような点に入ることはできない。
しかし、X 座標がN より大きな点、または、Y 座標がM より大きな点には入ることができる。

-----問題ここまで----- */
/* -----解説等-----

まず，縦横独立に考えて良い．
縦についてのみ考える．縦に無駄行動をk回挟むとする．
すると，H+2*k回移動し，内H+k回は↑へ，k回は↓へ移動することになる．
このとき，↑を+1,↓を-1としたときの前からの総和が常に0以上であれば良い．
これはカタラン数であり，組合せ的に解ける．
また，縦，横は先に空のものを並べると考えれば(AAAAAA,BBBBBBの並び替え)，H+W個から，W個置き場所を決める組合せ*1なので，
H+W C W となる．
よって答えはh+w=Kとして，\sum (H+W C W )* カタラン数(H+h,h) *カタラン数(W+w,w)である．

----解説ここまで---- */

template <::std::uint_fast32_t MODULO> class modint {
public:
	using uint32 = ::std::uint_fast32_t; using uint64 = ::std::uint_fast64_t; using value_type = uint32; uint32 a; modint() noexcept : a(0) {}modint(const signed x) noexcept : a(x) {}modint(const long long x) noexcept : a(x%MODULO) {}modint(const uint32 x) noexcept : a(x) {}modint operator+(const modint &o) const noexcept { return a + o.a < MODULO ? modint(a + o.a) : modint(a + o.a - MODULO); }modint operator-(const modint &o) const noexcept { return modint(a < o.a ? a + MODULO - o.a : a - o.a); }modint operator*(const modint &o) const noexcept { return modint(static_cast<uint64>(a) * o.a % MODULO); }modint operator/(const modint &o) const { return modint(static_cast<uint64>(a) * (~o).a % MODULO); }modint &operator+=(const modint &o) noexcept { return *this = *this + o; }modint &operator-=(const modint &o) noexcept { return *this = *this - o; }modint &operator*=(const modint &o) noexcept { return *this = *this * o; }modint &operator/=(const modint &o) { return *this = *this / o; }modint operator~() const noexcept { return pow(MODULO - 2); }modint operator-() const noexcept { return a ? modint(MODULO - a) : *this; }modint operator++() noexcept { return a == MODULO - 1 ? a = 0 : ++a, *this; }modint operator--() noexcept { return a ? --a : a = MODULO - 1, *this; }bool operator==(const modint &o) const noexcept { return a == o.a; }bool operator!=(const modint &o) const noexcept { return a != o.a; }bool operator<(const modint &o) const noexcept { return a < o.a; }bool operator<=(const modint &o) const noexcept { return a <= o.a; }bool operator>(const modint &o) const noexcept { return a > o.a; }bool operator>=(const modint &o) const noexcept { return a >= o.a; }explicit operator bool() const noexcept { return a; }explicit operator uint32() const noexcept { return a; }modint pow(uint32 x) const noexcept { uint64 t = a, u = 1; while (x) { if (x & 1)u = u * t % MODULO; t = (t * t) % MODULO; x >>= 1; }	return modint(u); }
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

// (0,0)から(h,w)へ移動するときに，y≦x+kのみを経由して移動する経路数
// 2点の座標を指定したいときは差分だけ見れば良い．
mint Keiro(int h, int w, int k = 0) {
	return nCr(h + w, w) - nCr(h + w, w + k + 1);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	init_fact(2e6 + 6);
	LL W, H, K; cin >> W >> H >> K;

	mint ans = 0;

	FOR(h, 0, K + 1) {
		int w = K - h;
		// a,a,b,b,a,a,b,a,b,a,b みたいな並べ方の数
		mint ret = nCr((W + 2 * w) + (H + 2 * h), (W + 2 * w));

		ret *= Keiro(h, H + h);
		ret *= Keiro(w, W + w);
		ans += ret;
	}

	cout << ans.get() << endl;

	return 0;
}
