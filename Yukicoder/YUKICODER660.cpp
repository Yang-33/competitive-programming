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

/* -----  2019/01/22  Problem: yukicoder 660  / Link: http://yukicoder.me/problems/no/660  ----- */
/* ------問題------

雪子さんは東西に無限に続く1次元の道に立っています。 雪子さんは現在地点から N 歩東に進んだ場所にある自宅に帰ろうとしています。
しかし、雪子さんは酔っ払ってしまっており、足元がおぼつきません。ですので、歩こうとすると 1 歩東または西に進みます。
雪子さんは 2×N 歩を超えて歩くと、疲れてしまって歩くのをやめてしまい、帰宅できません。
雪子さんが自宅の位置に到達すると、必ず歩くのをやめて自宅に入ります。それ以降は歩くことをしません。
雪子さんが疲れてしまう前、すなわち 2×N 歩以下の歩数で自宅に入る歩き方として、有り得るものの総数を出力してください。この値はとても大きくなるので、109+7 で割った余りを答えてください。

-----問題ここまで----- */
/* -----解説等-----

カタラン数っぽく解ける．
二次元の経路数としてみると，(東の総移動回数，西の総移動回数)としてみれる．
Nishi = [0,N/2]とすると，Higashi=N+Nishiとなる．
y≦x+Nを移動すればよさそうだが，これではゴール地点からも移動可能になるので重複してしまう．
更に領域を厳しくする．y≦x+(N-1)を移動し，最後に初めて必ずy=x+Nを踏むとする．
これは(N+Nishi-1,Nishi)へy≦x+(N-1)を移動する経路数としれみれるので，これを足し合わせればよい．

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


// (0,0)から(h,w)へ移動するときに，y≦x+kのみを経由して移動する経路数
// 2点の座標を指定したいときは差分だけ見れば良い．
mint Keiro(int h, int w, int k) {
	return mint(nCr(h + w, w)) - mint(nCr(h + w, w + k + 1));
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	init_fact(2e6 + 6);
	LL N; cin >> N;
	mint ans = 0;
	mint pre = 0;
	FOR(i, 0, N / 2 + 1) {
		mint ret = Keiro(N + i-1, i, N - 1);
		ans += ret;
	}

	cout << ans.get() << "\n";

	return 0;
}
