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
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/01  Problem: yukicoder 314  / Link: http://yukicoder.me/problems/no/314  ----- */
/* ------問題------

たろうくんはケンケンパが好きです。
ケンケンパとは片足跳びの「ケン」と両足着地の「パ」とを繰り返す遊びです。
今、たろうくんは長さNの新しいケンケンパコースを作ろうと考えています。
楽しいケンケンパコースにするために、次の2つの条件を守ってコースを作らないといけません。

1. 「ケン」は3回以上続いてはいけない
2. 「パ」は「ケン」のあとにしか置けない

たろうくんは何通りのコースが作れるのか気になっていますが、幼稚園児なので計算がうまくできません。
そこで、たろうくんの代わりに何通りのコースが作れるかを求めてあげてください。
ただし、答えは非常に大きくなる可能性があるので109+7で割った余りを出力してください。

-----問題ここまで----- */
/* -----解説等-----

試行を重ねるごとにどこにパを置くかがかわってくるので、状態遷移のdpを書けばよい。
dp(i,k)i番目について、{パ、ケン、ケンケン}とおいてきたような組み合わせ数

状態遷移の小さいdpなので、行列累乗でも解ける！(思いついて)


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

	LL N; cin >> N;
	vector<vector<mint>> dp(N + 1, vector<mint>(3, 0));
	dp[0][0] = 1;
	FOR(i, 0, N) {
		dp[i + 1][1] += dp[i][0];
		dp[i + 1][2] += dp[i][1];
		dp[i + 1][0] += dp[i][1];
		dp[i + 1][0] += dp[i][2];
	}

	mint ans = 0;
	FOR(i, 0, 3) {
		ans += dp[N][i];
	}
	
	cout << ans.get() << "\n";

	return 0;
}
