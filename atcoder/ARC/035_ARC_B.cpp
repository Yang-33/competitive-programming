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

/* -----  2018/10/24  Problem: ARC 035 B / Link: http://arc035.contest.atcoder.jp/tasks/arc035_b  ----- */
/* ------問題------

高橋くん様は、アットコーダー王国の王様です。
プログラミングコンテスト好きな彼が統治するアットコーダー王国では、年に一度コンテストが開催されます。
このコンテストでは N 問の問題が出題されます。また、順位を付ける際の 1 つの要素としてペナルティというものが存在します。 ある問題を正解したとき、コンテスト開始から経過した時間分だけのペナルティが、各問題ごとに発生します。そして、その発生したペナルティの総和がコンテストペナルティとなります。ARCのペナルティとは異なるルールであることに注意してください。
非常に優秀な国民である貴方には、全ての問題を解く力があります。 しかも、全ての問題について、その問題を正解するためにどれだけ時間をかければよいのかを知っており、ちょうどその時間取り組むと必ず正解することができます。
貴方は、自由な順番で問題を解くことができるので、コンテストペナルティが最小となるように解こうと思いました。
全ての問題を解くときのコンテストペナルティの最小値と、そのような解き方が何通りあるかを 1,000,000,007(109+7) で割った余りを答えて下さい。

-----問題ここまで----- */
/* -----解説等-----



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
	vector<mint>fact(1e4 + 4);
	fact[1] = 1;
	FOR(i, 2, 1e4 + 4) {
		fact[i] = fact[i - 1] * i;
	}

	map<int, int>Map;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
		Map[a[i]]++;
	}
	SORT(a);

	mint ans = 1;
	for (auto it : Map) {
		ans *= fact[it.second];
	}

	LL sum = 0;
	LL tsum = 0;
	FOR(i, 0, N) {
		sum += tsum + a[i];
		tsum += a[i];
	}

	cout << sum << endl;
	cout << ans.get() << "\n";
	return 0;
}
