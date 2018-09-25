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

/* -----  2018/09/23  Problem: yukicoder 271  / Link: http://yukicoder.me/problems/no/271  ----- */
/* ------問題------

あるnに対する[1,2,…,n]の置換(permutation) xに対し、f(x)を辞書順でxの次の置換とする。 ただし、xが辞書順で最後のもの[n,n−1,…,1]である場合は、f(x)を辞書順で最初のもの[1,2,…,n]として定義する。 たとえば、f([1,2,3])=[1,3,2], f(f([3,1,2]))=f([3,2,1])=[1,2,3] となる。
置換xの転倒数(inversion number)をinv(x)と表す。 たとえば、inv([2,1,3])=1,inv([3,2,1])=3である。
置換pが与えられたとき、置換の列Aを、A0=p, Ai=f(Ai−1) (i∈[1,2,…]) として定義する。 つまり、Aiはpにfをi回適用したものである。 たとえば、p=[2,1,3] なら A=[[2,1,3],[2,3,1],[3,1,2],[3,2,1],[1,2,3],…] となる。 Aの添字は0から始まることに注意せよ。
整数N, 整数K, 長さNの置換pが入力として与えられる。∑i=0K−1inv(Ai)を1000000007で割った余りを求めよ。

-----問題ここまで----- */
/* -----解説等-----

わかりません。僕は解説を実装しました。

----解説ここまで---- */

template<typename type>
struct BIT { // 1-index
	int N;
	int nn;
	vector<type> data;
	BIT(int n) {
		N = n + 1;
		data = vector<type>(n + 1, 0);
		nn = 1;
		while (nn * 2 <= N)nn *= 2;
	}
	void add(int i, type w) { // a[i] += w
		for (int x = i; x <= N; x += x & -x) {
			data[x] += w;
		}
	}
	type sum(int i) { // iまでの和 [1,i]
		type ret = 0;
		for (int x = i; x > 0; x -= x & -x) {
			ret += data[x];
		}
		return ret;
	}
	// [l, r]
	type sum(int l, int r) {
		if (l > r) return 0;
		return sum(r) - sum(l - 1);
	}
};
template <::std::uint_fast32_t MODULO> class modint {
public:
	using uint32 = ::std::uint_fast32_t; using uint64 = ::std::uint_fast64_t; using value_type = uint32; uint32 a; modint() noexcept : a(0) {}modint(const uint32 x) noexcept : a(x) {}modint operator+(const modint &o) const noexcept { return a + o.a < MODULO ? modint(a + o.a) : modint(a + o.a - MODULO); }modint operator-(const modint &o) const noexcept { return modint(a < o.a ? a + MODULO - o.a : a - o.a); }modint operator*(const modint &o) const noexcept { return modint(static_cast<uint64>(a) * o.a % MODULO); }modint operator/(const modint &o) const { return modint(static_cast<uint64>(a) * (~o).a % MODULO); }modint &operator+=(const modint &o) noexcept { return *this = *this + o; }modint &operator-=(const modint &o) noexcept { return *this = *this - o; }modint &operator*=(const modint &o) noexcept { return *this = *this * o; }modint &operator/=(const modint &o) { return *this = *this / o; }modint operator~() const noexcept { return pow(MODULO - 2); }modint operator-() const noexcept { return a ? modint(MODULO - a) : *this; }modint operator++() noexcept { return a == MODULO - 1 ? a = 0 : ++a, *this; }modint operator--() noexcept { return a ? --a : a = MODULO - 1, *this; }bool operator==(const modint &o) const noexcept { return a == o.a; }bool operator!=(const modint &o) const noexcept { return a != o.a; }bool operator<(const modint &o) const noexcept { return a < o.a; }bool operator<=(const modint &o) const noexcept { return a <= o.a; }bool operator>(const modint &o) const noexcept { return a > o.a; }bool operator>=(const modint &o) const noexcept { return a >= o.a; }explicit operator bool() const noexcept { return a; }explicit operator uint32() const noexcept { return a; }modint pow(uint32 x) const noexcept { uint64 t = a, u = 1; while (x) { if (x & 1)u = u * t % MODULO; t = (t * t) % MODULO; x >>= 1; }	return modint(u); }
	uint32 get() const noexcept { return a; }
};
using mint = modint<MOD>;


struct factorialNums {
	VL a;
	vector<mint> fact;
	factorialNums(VL &p):a(SZ(p)),fact(1e5+5) {
		BIT<int>bit(SZ(p));
		FORR(i, SZ(p) - 1, 0 - 1) {
			a[i] = bit.sum(p[i]);
			bit.add(p[i], 1);
		}
		fact[0] = 1;
		FOR(i, 1, SZ(fact)) {
			fact[i] = mint(i) * fact[i - 1];
		}
	}
	mint add(LL K) {
		FOR(i, 0, SZ(a)) {
			LL t = K + a[SZ(a) - 1 - i];
			a[SZ(a) - 1 - i] = t % (i + 1);
			K = t / (i + 1);
		}
		return mint(K);
	}
	mint inv() {
		mint ret = 0;
		mint v = 0;
		mint f = 1;
		FORR(i, SZ(a) - 1, 0 - 1) {
			mint k = SZ(a) - 1 - i;
			ret += mint(a[i]) * fact[k.get()] * k*(k - 1) / mint(4);
			ret += f * mint(a[i])*mint(a[i] - 1) / mint(2);
			ret += mint(a[i])*v;
			v += mint(a[i])*f;
			f *= SZ(a) - i;
		}
		return ret;
	}

};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, K; cin >> N >> K;
	VL p(N);
	FOR(i, 0, N) {
		cin >> p[i];
	}
	factorialNums fns(p);
	mint i1 = fns.inv();
	mint m = fns.add(K);
	mint i2 = fns.inv();

	mint ans = 0;
	ans = m * fns.fact[N] * N*(N - 1)/(mint(4)) + i2 - i1;

	cout << ans.get() << "\n";

	return 0;
}
