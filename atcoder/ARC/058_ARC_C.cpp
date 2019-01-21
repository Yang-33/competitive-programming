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

/* -----  2019/01/20  Problem: ARC 058 C / Link: http://arc058.contest.atcoder.jp/tasks/arc058_c  ----- */
/* ------問題------

日本の誇る美しいリズムとして、五七五というものがあります。
いろはちゃんは、数列から五七五を探すことにしました。でもこれは簡単だったので、XYZを探すことにしました。
<p>長さ <var>N</var> の、それぞれの値が <var>1～10</var> の数列 <var>a_0, a_1, ..., a_{N-1}</var> を考えます。このような数列は全部で <var>10^N</var> 通りありますが、そのうちXYZを含むものは何通りでしょう？</p>
<p>ただし、XYZを含むとは以下のように定義されます。</p>
<ul>
<li><var>a_x + a_{x+1} + ... + a_{y-1} = X</var></li>
<li><var>a_y + a_{y+1} + ... + a_{z-1} = Y</var></li>
<li><var>a_z + a_{z+1} + ... + a_{w-1} = Z</var></li>
</ul>
<p>を満たす <var>0 ≦ x &lt; y &lt; z &lt; w ≦ N</var> が存在する。</p>

<p>なお、答えは非常に大きくなることがあるので、答えは <var>10^9+7</var> で割ったあまりを出力してください。</p>

-----問題ここまで----- */
/* -----解説等-----

初見で(x,y,z,w)を決め打ちした時，重複組合せっぽくすればいけそうだが，ずれた区間ではX,Y,Zは存在しては行けないことになる．
したがってこの単純な方法では重複して数え上げてしまう．

包除?となるが厳しい．そこで余事象:X,Y,Zを含まないものを考えてみる．
X+Y+Z≦17と小さいので，列の遷移を全部覚えれば良い．
dp(state):=遷移がstateのときの組合せ数
10^N - dp(*)が答えになる．

今でいうと500点ぐらいっぽそう

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

	LL N, X, Y, Z; cin >> N >> X >> Y >> Z;
	mint ans = mint(10).pow(N);
	// 重複組合せは数え方が重複するので厳しい
	// (all)-連続する部分列に*,X,Y,Z,*が入らないような数
	int forbidden = (1 << (X + Y + Z - 1)) | (1 << (Y + Z - 1)) | (1 << (Z - 1));
	int S = 1 << (X + Y + Z);
	vector<mint>dp(S);
	dp[0] = 1;
	int upper = S - 1;
	FOR(_, 0, N) {
		vector<mint>nxdp(S);
		FOR(state, 0, S) {
			FOR(add, 1, 10 + 1) {
				int nx = (state << add) | (1 << (add - 1));
				if ((forbidden&nx) == forbidden)continue;
				int nxstate = nx & upper;
				nxdp[nxstate] += dp[state];
			}
		}
		nxdp.swap(dp);
	}
	FOR(i, 0, SZ(dp)) {
		ans -= dp[i];
	}
	cout << ans.get() << endl;

	return 0;
}