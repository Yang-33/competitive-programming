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

/* -----  2019/01/06  Problem: EDU_DP Y / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

蟻本より包除dpをする。
// dp(i):=[0,i)番目の壁を避けてi番目の壁の位置にたどり着く場合の数
とする。
すると、dp(i) = iまでの経路数 - (どこかの壁を1回以上通ってきてしまう場合の数)
となる。()内は、初めて壁jに到達して、その後は何でも良い(これで区別はできている)
ので、\sum dp(j<i)*keiro(j to i)みたいな感じになる

kyopro_friendsのおかげで解けたよ!

----解説ここまで---- */

template <::std::uint_fast32_t MODULO> class modint {
public:
	using uint32 = ::std::uint_fast32_t; using uint64 = ::std::uint_fast64_t; using value_type = uint32; uint32 a; modint() noexcept : a(0) {}modint(const uint32 x) noexcept : a(x) {}modint operator+(const modint &o) const noexcept { return a + o.a < MODULO ? modint(a + o.a) : modint(a + o.a - MODULO); }modint operator-(const modint &o) const noexcept { return modint(a < o.a ? a + MODULO - o.a : a - o.a); }modint operator*(const modint &o) const noexcept { return modint(static_cast<uint64>(a) * o.a % MODULO); }modint operator/(const modint &o) const { return modint(static_cast<uint64>(a) * (~o).a % MODULO); }modint &operator+=(const modint &o) noexcept { return *this = *this + o; }modint &operator-=(const modint &o) noexcept { return *this = *this - o; }modint &operator*=(const modint &o) noexcept { return *this = *this * o; }modint &operator/=(const modint &o) { return *this = *this / o; }modint operator~() const noexcept { return pow(MODULO - 2); }modint operator-() const noexcept { return a ? modint(MODULO - a) : *this; }modint operator++() noexcept { return a == MODULO - 1 ? a = 0 : ++a, *this; }modint operator--() noexcept { return a ? --a : a = MODULO - 1, *this; }bool operator==(const modint &o) const noexcept { return a == o.a; }bool operator!=(const modint &o) const noexcept { return a != o.a; }bool operator<(const modint &o) const noexcept { return a < o.a; }bool operator<=(const modint &o) const noexcept { return a <= o.a; }bool operator>(const modint &o) const noexcept { return a > o.a; }bool operator>=(const modint &o) const noexcept { return a >= o.a; }explicit operator bool() const noexcept { return a; }explicit operator uint32() const noexcept { return a; }modint pow(uint32 x) const noexcept { uint64 t = a, u = 1; while (x) { if (x & 1)u = u * t % MODULO; t = (t * t) % MODULO; x >>= 1; }	return modint(u); }
	uint32 get() const noexcept { return a; }
};
using mint = modint<MOD>;

const long long mod = 1e9 + 7;
long long modpow(long long a, long long b) {
	if (b == 0) return 1;
	return modpow(a * a % mod, b / 2) * (b & 1 ? a : 1) % mod;
}

long long modinv(long long a) {
	return modpow(a, mod - 2);
}

vector<long long> fact, inv_fact;

void init_fact(int n) {
	fact.resize(n);
	fact[0] = 1;
	for (int i = 1; i < n; i++) {
		fact[i] = i * fact[i - 1] % mod;
	}
	inv_fact.resize(n);
	inv_fact[n - 1] = modinv(fact[n - 1]);
	for (int i = n - 2; i >= 0; i--) {
		inv_fact[i] = (i + 1) * inv_fact[i + 1] % mod;
	}
}
long long nCr(int n, int r) {
	if (n < r || n < 0 || r < 0) return 0;
	return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
}

LL ans = 0LL;
mint dp[3003];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	init_fact(4e5);
	LL H, W, N; cin >> H >> W >> N;
	vector<PII>yx(N);
	FOR(i, 0, N) {
		int y, x; cin >> y >> x;
		y--, x--;
		yx[i] = PII(y, x);
	}
	yx.push_back(PII(H - 1, W - 1));
	SORT(yx);
	N = SZ(yx);
	auto keiro = [&](LL y,LL x) {
		if (y < 0 || x < 0)return 0LL;
		return nCr(y + x, x);
	};

	// dp(i):=[0,i)番目の壁を避けてi番目の壁の位置にたどり着く場合の数
	FOR(i, 0, N) {
		dp[i] = keiro(yx[i].first, yx[i].second);
		FOR(j, 0, i) {
			dp[i] -= dp[j] * keiro(yx[i].first-yx[j].first,yx[i].second-yx[j].second);
		}
	}
	ans = dp[N - 1].get();

	cout << ans << "\n";

	return 0;
}
