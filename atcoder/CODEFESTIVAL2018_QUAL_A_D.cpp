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

/* -----  2018/09/22  Problem: codefestival2018_qual_a D / Link: __CONTEST_URL__  ----- */
/* ------問題------

高橋くんの家は x 軸上の点 0 に、AtCoder 社のオフィスは x 軸上の点 D にあります。 また、x 軸上には N 個のガソリンスタンドがあり、これらの座標は X1,X2,…,XN です。

高橋くんは毎日家からオフィスまで自動車で移動します。 この自動車の燃料タンクの容量は F リットルであり、距離 1 移動するごとに燃料を 1 リットル消費します。 高橋くんは燃料タンクが満タンの状態で家を出発し、ガソリンスタンドを通るごとに以下のようにして自動車の燃料を補給します。

燃料が T リットル以上残っている場合、燃料を補給しない。
そうでない場合、燃料タンクが満タンになるまで燃料を補給する。
オフィスへの移動の際、自動車は x 軸正方向にしか進むことができません。ガソリンスタンドでもオフィスでもない場所で燃料タンクが空になった場合、オフィスへの移動は失敗となります。

あなたは N 個のガソリンスタンドのうちのいくつか (0 個でも構いません) を書店に建て替えようとしています。 書店に建て替えるガソリンスタンドの集合であって、建て替えのあとも高橋くんが上記の方法で家からオフィスまで自動車で移動できるようなものの個数を 109+7 で割ったあまりを求めてください。

-----問題ここまで----- */
/* -----解説等-----

dpをする。dp[i]:=iを建てるときの総数
とすると、適当な場所から、範囲に移動できることを考えることができる。
すると、[s,t)に対して、s-i-1箇所はあってもなくても良いことになる。
dp[i]*2^(s-i-1)をdp[k](K=[s,t))に加算すれば良い。
というのは、s+1に到着するときは、sは書店と考える。
これはsに到着した後にs+1をどちらの状態にすべきかを考えればよいためである。

これ最後のことだけ考えれば良いので、かなり簡単では…？

----解説ここまで---- */
long long  powmod(long long  x, long long  n, long long  mod = MOD) {
	long long  res = 1;
	while (n > 0) {
		if (n & 1) {
			res = (res*x) % mod;
		}
		x = (x*x) % mod;
		n >>= 1;
	}
	return res;
}
template <::std::uint_fast32_t MODULO> class modint {
public:
	using uint32 = ::std::uint_fast32_t; using uint64 = ::std::uint_fast64_t; using value_type = uint32; uint32 a; modint() noexcept : a(0) {}modint(const uint32 x) noexcept : a(x) {}modint operator+(const modint &o) const noexcept { return a + o.a < MODULO ? modint(a + o.a) : modint(a + o.a - MODULO); }modint operator-(const modint &o) const noexcept { return modint(a < o.a ? a + MODULO - o.a : a - o.a); }modint operator*(const modint &o) const noexcept { return modint(static_cast<uint64>(a) * o.a % MODULO); }modint operator/(const modint &o) const { return modint(static_cast<uint64>(a) * (~o).a % MODULO); }modint &operator+=(const modint &o) noexcept { return *this = *this + o; }modint &operator-=(const modint &o) noexcept { return *this = *this - o; }modint &operator*=(const modint &o) noexcept { return *this = *this * o; }modint &operator/=(const modint &o) { return *this = *this / o; }modint operator~() const noexcept { return pow(MODULO - 2); }modint operator-() const noexcept { return a ? modint(MODULO - a) : *this; }modint operator++() noexcept { return a == MODULO - 1 ? a = 0 : ++a, *this; }modint operator--() noexcept { return a ? --a : a = MODULO - 1, *this; }bool operator==(const modint &o) const noexcept { return a == o.a; }bool operator!=(const modint &o) const noexcept { return a != o.a; }bool operator<(const modint &o) const noexcept { return a < o.a; }bool operator<=(const modint &o) const noexcept { return a <= o.a; }bool operator>(const modint &o) const noexcept { return a > o.a; }bool operator>=(const modint &o) const noexcept { return a >= o.a; }explicit operator bool() const noexcept { return a; }explicit operator uint32() const noexcept { return a; }modint pow(uint32 x) const noexcept { uint64 t = a, u = 1; while (x) { if (x & 1)u = u * t % MODULO; t = (t * t) % MODULO; x >>= 1; }	return modint(u); }
	uint32 get() const noexcept { return a; }
};
using Mint = modint<MOD>;

template<class T>
struct RaBIT {
	int n; vector<T> bit0, bit1;
	RaBIT(int sz) :n(sz), bit0(n + 1, 0), bit1(n + 1, 0) {}

	T subsum(vector<T>& bit, int i) {
		T s = 0;
		while (i > 0) {
			(s += bit[i]);
			i -= i & -i;
		}
		return s;
	}
	void add(vector<T>& bit, int i, T x) {
		while (i <= n) {
			(bit[i] += x);
			i += i & -i;
		}
	}
	void rangeadd(int a, int b, T x) {
		a++;
		add(bit0, a, -(x * (a - 1)));
		add(bit1, a, x);
		add(bit0, b + 1, x * b);
		add(bit1, b + 1, -x);
	}
	T query(int a, int b) {
		a++;
		return ((subsum(bit1, b) * b + subsum(bit0, b))
			- (subsum(bit1, a - 1) * (a - 1) + subsum(bit0, a - 1)));
	}
};


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL D, F, T, N; cin >> D >> F >> T >> N;
	VL a(N + 2, 0);
	FOR(i, 1, N + 1) {
		cin >> a[i];
	}
	a[N + 1] = D;
	N += 2;
	RaBIT<Mint> pyon(N);
	pyon.rangeadd(0, 1, 1);
	auto two = [](LL x) {
		return powmod(2, x);
	};

	T = F - T;
	FOR(i, 0, N - 1) {
		LL val = pyon.query(i, i + 1).get();
		LL s = upper_bound(ALL(a), a[i] + T) - a.begin();
		LL t = upper_bound(ALL(a), a[i] + F) - a.begin();
		if (s == N) {
			val *= two(N - i - 2);
			val %= MOD;
			pyon.rangeadd(N - 1, N, val);
		}
		else {
			val *= two(s - i - 1);
			val %= MOD;
			pyon.rangeadd(s, t, val);
		}
	}
	LL ans = pyon.query(N - 1, N).get();
	cout << ans << "\n";

	return 0;
}
