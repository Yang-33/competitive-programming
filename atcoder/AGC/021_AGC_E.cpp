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
const LL MOD = 998244353;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2019/01/22  Problem: AGC 021 E / Link: http://agc021.contest.atcoder.jp/tasks/agc021_e  ----- */
/* ------問題------

AtCoder 共和国では、カメレオン科ボールタベルカメレオン属に属するスヌケカメレオンがペットとして大人気です。 りんごさんは、N 匹のスヌケカメレオンの個体をひとつのカゴに入れて飼っています。
何も食べていない状態のスヌケカメレオンは青色です。スヌケカメレオンは、次の規則で変色します。
青いスヌケカメレオンは、これまでに食べた青いボールの個数よりこれまでに食べた赤いボールの個数の方が真に大きくなった時、赤色に変色する。
赤いスヌケカメレオンは、これまでに食べた赤いボールの個数よりこれまでに食べた青いボールの個数の方が真に大きくなった時、青色に変色する。
最初、スヌケカメレオンたちはどの個体も何も食べていない状態です。りんごさんは、スヌケカメレオンたちに、以下の手順を K 回繰り返すことで餌をやりました。

赤いボールまたは青いボールを握る。
握ったボールを、スヌケカメレオンたちの入ったカゴの中に投げ入れる。このとき、いずれか一匹がそのボールを食べる。
りんごさんが K 個のボールを投げ入れたところ、全ての個体が赤色になっていました。りんごさんの K 個のボールの投げ入れ方としてありうるものは何通りあるでしょうか。 998244353 で割った余りを求めてください。ただし、2 つの投げ入れ方が異なるとは、ある i が存在し、i 個目に投げ入れたボールの色が異なることを指します。

-----問題ここまで----- */
/* -----解説等-----

経路数への帰着．まずカタラン数/経路数の問題は，2値X,Yを取扱い，Xはなんでもいいが，Yはなんか取りすぎてはいけない，という制約を二次元グリッドでy≦x+mとして表現していたのであった．(僕の中では) この問題ではABを入れて，N人に指定したとり方をさせ，それぞれについてAを多く取った/同数だがABで取った状態を作成可能なABの組数を求めたい．場合分けをしてみる．
	1. |A|<|B|のとき
		* 誰かがBになる．自明にダメ．
	2. |A|==|B|のとき
		* ABをセットで配り，人の中ではBが多くなってもよいが最後AB(Aになって，Bをとるだけ)/ABが平衡であるようにする．
			* 平衡から次の色を取るとその色になる点に注意
		* これは最後の最後にBを配ることに対応する．Aを最後に配るとすると色はBなので．
		* 最後に辻褄を合わせるとして，|B|-N個まで連続してBを配ってもよいが，N個はそれだけ取るにしても最後に取るにしても辻褄あわせが必要．
		* y≦x+(|B|-N)を満たす領域で(|A|,|B|-1)へ移動し，最後にBとする経路数に帰着された．
			* 最後でjustとは言い難いが問題特有の考察といえそうで，これは思いつかないとダメそう．
	3. |A|>|B|
		* 最低でもN-(|A|-|B|)個は同数でないとだめ．それ以外はAを多く配れるので，順序はどうでも良い．
		* (2)ではN個は辻褄だったが今回はN-(|A|-|B|)個と言える．
		* y≦x+(|B|-(N-(|A|-|B|)))
		* y≦x+(|A|-N)を満たす領域で(|A|,|B|)へ移動する経路数に帰着された．
			* mint Keiroを修正した

本番で解けるかと言うと大変難しい気がする．

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
	if (h - w > k)return mintzero;
	if (k < 0)return mintzero;
	return mint(nCr(h + w, w)) - mint(nCr(h + w, w + k + 1));
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	init_fact(2e6 + 6);
	LL N, K; cin >> N >> K;
	mint ans = 0;
	FOR(R, 0, K + 1) {
		int B = K - R;
		if (R > B) {
			ans += Keiro(B, R, R - N);
		}
		else if (R == B) {
			ans += Keiro(B - 1, R, B - N);
		}
	}


	cout << ans.get() << endl;


	return 0;
}
