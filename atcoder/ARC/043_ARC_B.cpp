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

/* -----  2018/10/13  Problem: 043_arc_b / Link: https://beta.atcoder.jp/contests/arc043/tasks/arc043_b ----- */
/* ------問題------

高橋君はプログラミングコンテストを開く仕事をしている。
高橋君はストックしている N 個の問題から 4 問を選んでコンテストに出題する。
各問題には「難易度」という正の整数が決められており、 i 番目の問題の難易度は Di である。
選ぶ問題は以下の 3 つの条件を満たしていなければならない。

2 問目の難易度は 1 問目の難易度の 2 倍以上である。
3 問目の難易度は 2 問目の難易度の 2 倍以上である。
4 問目の難易度は 3 問目の難易度の 2 倍以上である。
上の条件のもとで N 個の問題から 4 問選ぶとき、何通りの選び方があるか求めよ。
この値は非常に大きくなり得るので 1,000,000,007(=109+7) で割った余りを求めよ。

-----問題ここまで----- */
/* -----解説等-----

コメントの通り。dp(i,k)のkについて更新をかければよい。区間和がほしいのでBITを使っても良い。

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

	int N; cin >> N;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}

	SORT(a);

	// O(NK)のdpを独立、sumで求める
	// dp(i,k):= ithをk番目に選択する組合せ
	// dp(i,k+1) = \sum dp(X,k) X:[0,a[i]/2]
	// 
	int K = 4;
	// K をまわす方のdp?
	int S = 100005;
	vector<vector<mint>>dp(S + 1, vector<mint>(K + 1, 0));
	vector<vector<mint>>cum(S + 1, vector<mint>(K, 0));
	FOR(i, 0, S + 1) {
		cum[i][0] = 1;
	}
	dp[0][0] = 1;
	FOR(k, 0, K) {
		// dpからcum をつくる
		if (k) {
			FOR(i, 0, S) {
				cum[i + 1][k] = cum[i][k] + dp[i + 1][k];
			}

		}
		// dp遷移
		FOR(i, 0, N) {
			dp[a[i]][k + 1] += cum[a[i] / 2][k];
		}
		//cout << "DEBUG" << endl;
		//FOR(i, 0, 30) {
		//	cout << i << ":" << dp[i][k + 1].get() << " ";
		//}cout << endl;

	}

	// ここcumと一緒
	mint ans = 0;
	FOR(i, 0, S) {
		ans += dp[i][4];
	}
	cout << ans.get() << "\n";

	return 0;
}