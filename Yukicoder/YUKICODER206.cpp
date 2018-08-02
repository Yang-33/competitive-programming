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

/* -----  2018/08/02  Problem: yukicoder 206  / Link: http://yukicoder.me/problems/no/206  ----- */
/* ------問題------

長さLの数列A=A[0],A[1],…,A[L−1]、長さMの数列B=B[0],B[1],…,B[M−1]がある。
数列A, Bはそれぞれ、重複する要素がない数列である。すなわち、
0≤i<j≤L−1を満たす全ての(i,j)組について、A[i]≠A[j]が成り立ち、
0≤i<j≤M−1を満たす全ての(i,j)組について、B[i]≠B[j]が成り立つ。
また、数列A,Bのどの要素も1以上N以下の整数である。

ここで、「数列Xに値Yが含まれる」を定義する。
数列Xの要素の内、一つ以上の要素の値がYであるとき、「数列Xに値Yが含まれる」と定義する。
数列Xのどの要素の値もYでない場合、「数列Xに値Yが含まれない」と定義する。

数列Bの全ての要素に(一様に)vを加算した数列をBvとしたとき、
数列Aにも数列Bvにも含まれるような整数値はいくつあるか求めよ。
(ただしvの変域は、0<=v<=Q−1とする。)

-----問題ここまで----- */
/* -----解説等-----

0/1のFFT.(NTT)
Bをシフトしていくことを考える。(bit並列でも解ける。)
aindex=bindex+q となるものを探せば良いことになる。
fftっぽさからかんがえると、(i)*(k-i)=kのような関係を作りたい。
これはbの列を反転させれば実現できて、aindex+bindex = N+q ->aindex + N-bindex = q
となる。あとはqを動かしていけば全ての答えを得ることができるのでできる。　
FFTではなくNTTを貼った。

----解説ここまで---- */

using ll = long long;
namespace NTT { 
	std::vector<int> tmp;
	size_t sz = 1;

	inline int powMod(int n, int p, int m) {
		int res = 1;
		while (p) {
			if (p & 1) res = (ll)res * n % m;
			n = (ll)n * n % m;
			p >>= 1;
		}
		return (int)res;
	}
	inline int invMod(int n, int m) {
		return powMod(n, m - 2, m);
	}

	template <int Mod, int PrimitiveRoot>
	struct NTTPart {
		static std::vector<int> ntt(std::vector<int> a, bool inv = false) {
			size_t mask = sz - 1;
			size_t p = 0;
			for (size_t i = sz >> 1; i >= 1; i >>= 1) {
				auto& cur = (p & 1) ? tmp : a;
				auto& nex = (p & 1) ? a : tmp;
				int e = powMod(PrimitiveRoot, (Mod - 1) / sz * i, Mod);
				if (inv) e = invMod(e, Mod);
				int w = 1;
				for (size_t j = 0; j < sz; j += i) {
					for (size_t k = 0; k < i; ++k) {
						nex[j + k] = (cur[((j << 1) & mask) + k] + (ll)w * cur[(((j << 1) + i) & mask) + k]) % Mod;
					}
					w = (ll)w * e % Mod;
				}
				++p;
			}
			if (p & 1) std::swap(a, tmp);
			if (inv) {
				int invSz = invMod(sz, Mod);
				for (size_t i = 0; i < sz; ++i) a[i] = (ll)a[i] * invSz % Mod;
			}
			return a;
		}
		static std::vector<int> mul(std::vector<int> a, std::vector<int> b) {
			a = ntt(a);
			b = ntt(b);
			for (size_t i = 0; i < sz; ++i) a[i] = (ll)a[i] * b[i] % Mod;
			a = ntt(a, true);
			return a;
		}
	};

	constexpr int M[] = { 1224736769, 469762049, 167772161 };
	constexpr int PR[] = { 3, 3, 3 };
	constexpr int NTT_CONVOLUTION_TIME = 1;

	inline void garner(std::vector<int> *c, int mod) {
		if (NTT_CONVOLUTION_TIME == 1) {
			for (auto& x : c[0]) x %= mod;
		}
		else if (NTT_CONVOLUTION_TIME == 2) {
			const int r01 = invMod(M[0], M[1]);
			for (size_t i = 0; i < sz; ++i) {
				c[1][i] = (c[1][i] - c[0][i]) * (ll)r01 % M[1];
				if (c[1][i] < 0) c[1][i] += M[1];
				c[0][i] = (c[0][i] + (ll)c[1][i] * M[0]) % mod;
			}
		}
		else if (NTT_CONVOLUTION_TIME == 1) {
			const int R01 = invMod(M[0], M[1]);
			const int R02 = invMod(M[0], M[2]);
			const int R12 = invMod(M[1], M[2]);
			const int M01 = (ll)M[0] * M[1] % mod;
			for (size_t i = 0; i < sz; ++i) {
				c[1][i] = (c[1][i] - c[0][i]) * (ll)R01 % M[1];
				if (c[1][i] < 0) c[1][i] += M[1];
				c[2][i] = ((c[2][i] - c[0][i]) * (ll)R02 % M[2] - c[1][i]) * R12 % M[2];
				if (c[2][i] < 0) c[2][i] += M[2];
				c[0][i] = (c[0][i] + (ll)c[1][i] * M[0] + (ll)c[2][i] * M01) % mod;
			}
		}
	}
	std::vector<int> mul(std::vector<int> a, std::vector<int> b, int mod) {
		for (auto& x : a) x %= mod;
		for (auto& x : b) x %= mod;

		size_t m = a.size() + b.size() - 1;
		sz = 1;
		while (m > sz) sz <<= 1;
		tmp.resize(sz);
		a.resize(sz, 0);
		b.resize(sz, 0);

		std::vector<int> c[NTT_CONVOLUTION_TIME];
		if (NTT_CONVOLUTION_TIME >= 1) c[0] = NTTPart<M[0], PR[0]>::mul(a, b);
		if (NTT_CONVOLUTION_TIME >= 2) c[1] = NTTPart<M[1], PR[1]>::mul(a, b);
		if (NTT_CONVOLUTION_TIME >= 3) c[2] = NTTPart<M[2], PR[2]>::mul(a, b);
		for (auto& v : c) v.resize(m);
		garner(c, mod);
		return c[0];
	}
}; 


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int L, M, N; cin >> L >> M >> N;
	int sz = N;
	VI a(sz), b(sz);
	FOR(i, 0, L) {
		int num; cin >> num;
		a[num-1] = 1;
	}

	FOR(i, 0, M) {
		int num; cin >> num;
		b[sz - num] = 1;
	}

	const int mod = 100000 * 1 + 1;
	auto c(NTT::mul(a, b, mod));
	int Q; cin >> Q;
	FOR(q, 0, Q) {
		cout << c[N-1+q] << "\n";
	}

	return 0;
}
