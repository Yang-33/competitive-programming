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

/* -----  2019/01/20  Problem: ARC 059 D / Link: http://arc059.contest.atcoder.jp/tasks/arc059_d  ----- */
/* ------問題------

しぐはキーボードを製作しました。シンプルさを極限まで追求したこのキーボードには、0 キー、1 キー、バックスペースキーの 3 つしかキーがありません。

手始めに、しぐはこのキーボードで簡単なテキストエディタを操作してみることにしました。このエディタには常に一つの文字列が表示されます（文字列が空のこともあります）。エディタを起動した直後では、文字列は空です。キーボードの各キーを押すと、文字列が次のように変化します。

0 キー: 文字列の右端に文字 0 が挿入される。
1 キー: 文字列の右端に文字 1 が挿入される。
バックスペースキー: 文字列が空なら、何も起こらない。そうでなければ、文字列の右端の 1 文字が削除される。
しぐはエディタを起動し、これらのキーを合計で N 回押しました。その結果、いまエディタに文字列 s が表示されています。このようなキーの押し方の個数を 109+7 で割った余りを求めてください。

-----問題ここまで----- */
/* -----解説等-----

解法1:dp O(N^2)
適当な気持ちでdpを考えると，dp(i,正しい文字列の数，今のindex)みたいになり，O(N^3)となる．
今のindexと正しい文字列の数は似ていてアなので，これを改善したい．
最終的に長さがMになれば良い．
長さがMになる操作数のみを数えて，最後にこれを2^s.size()で割れば良い．

解法2:経路数への帰着 O(N) (天才)
後ろから見る．(もうここが若干天才)
操作を+1,-1とみたときに，最終的な数列の長さmはmax(+1の数 - -1の数)となり，
それっぽく書くとmax(a_i+...+a_N)となる．
後ろからみたとき，(+1の数)-(-1の数)=Mとなればよく，不等号をつければ経路数に帰着できる．
y-x≦Mとして，y≦x+Mである．これはy=x+Mよりも必ず下を通って，N回x++ory++をする経路数であることがわかる．
N回行ったときの最終地点はN個なので，全部計算する．
これは長さN以下なのでf(M)-f(M-1)をすればちょうどMの場合の数がわかる．

±1についての問題にも適用できるし，f(M)-f(M-1)も典型だし，経路数も有名でないぐらいの典型だし良い勉強になった．

----解説ここまで---- */

template <::std::uint_fast32_t MODULO> class modint {
public:
	using uint32 = ::std::uint_fast32_t; using uint64 = ::std::uint_fast64_t; using value_type = uint32; uint32 a; modint() noexcept : a(0) {}modint(const uint32 x) noexcept : a(x) {}modint operator+(const modint &o) const noexcept { return a + o.a < MODULO ? modint(a + o.a) : modint(a + o.a - MODULO); }modint operator-(const modint &o) const noexcept { return modint(a < o.a ? a + MODULO - o.a : a - o.a); }modint operator*(const modint &o) const noexcept { return modint(static_cast<uint64>(a) * o.a % MODULO); }modint operator/(const modint &o) const { return modint(static_cast<uint64>(a) * (~o).a % MODULO); }modint &operator+=(const modint &o) noexcept { return *this = *this + o; }modint &operator-=(const modint &o) noexcept { return *this = *this - o; }modint &operator*=(const modint &o) noexcept { return *this = *this * o; }modint &operator/=(const modint &o) { return *this = *this / o; }modint operator~() const noexcept { return pow(MODULO - 2); }modint operator-() const noexcept { return a ? modint(MODULO - a) : *this; }modint operator++() noexcept { return a == MODULO - 1 ? a = 0 : ++a, *this; }modint operator--() noexcept { return a ? --a : a = MODULO - 1, *this; }bool operator==(const modint &o) const noexcept { return a == o.a; }bool operator!=(const modint &o) const noexcept { return a != o.a; }bool operator<(const modint &o) const noexcept { return a < o.a; }bool operator<=(const modint &o) const noexcept { return a <= o.a; }bool operator>(const modint &o) const noexcept { return a > o.a; }bool operator>=(const modint &o) const noexcept { return a >= o.a; }explicit operator bool() const noexcept { return a; }explicit operator uint32() const noexcept { return a; }modint pow(uint32 x) const noexcept { uint64 t = a, u = 1; while (x) { if (x & 1)u = u * t % MODULO; t = (t * t) % MODULO; x >>= 1; }	return modint(u); }
	uint32 get() const noexcept { return a; }
};
using mint = modint<MOD>;
mint modinv(mint a) {return mint(1) / mint(a);}

vector<mint> fact, inv_fact;

void init_fact(int n) {
	fact.resize(n);
	fact[0] = 1;
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
	if (n < r || n < 0 || r < 0) return mint(0);
	return fact[n] * inv_fact[r] * inv_fact[n - r];
}


// (0,0)から(h,w)へ移動するときに，y≦x+kのみを経由して移動する経路数
mint f2(int h, int w, int k) {
	return mint(nCr(h + w, w)) - mint(nCr(h + w, w + k + 1));
}

// 移動数nで，y≦x+kのみを経由して移動する経路数:O(n)
mint f(int n, int k) {
	mint ret = 0;

	FOR(h, 0, n + 1) {
		if (h - k <= n - h)// 見落としがち
			ret += f2(h, n - h, k)*mint(2).pow(h);
	}
	return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	init_fact(10004);
	int N; cin >> N;
	string s; cin >> s;

	mint ans = f(N, SZ(s)) - f(N, SZ(s) - 1);
	ans /= mint(2).pow(SZ(s));
	cout << ans.get() << endl;


	//dp[0][0] = 1;

	//FOR(i, 0, N) {
	//	FOR(j, 0, N) {
	//		dp[i + 1][j + 1] += dp[i][j] * 2;
	//		dp[i + 1][max(0, j - 1)] += dp[i][j];
	//	}
	//}
	//mint ans = dp[N][SZ(s)];
	//ans /= mint(2).pow(SZ(s));
	//cout << ans.get() << endl;


	return 0;
}
