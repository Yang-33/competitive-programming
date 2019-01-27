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
//const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2019/01/27  Problem: StairsColoring / Link: __CONTEST_URL__  ----- */
/* ------問題------

n 番目のカタラン数は C'(n)=C(2n,n)−C(2n−1,n-1) で与えられる。
整数 k が与えられて、k^C'(n) を 1000000123 で割ったあまりを求めよ。
n,k≦10^9

-----問題ここまで----- */
/* -----解説等-----

1000000122=2×3×11×2089×7253より，
リュカの定理を使用．
modを素因数分解し，素因数が小さい時のみO(log_P N)で計算可能．
その後CRTでまとめる．

----解説ここまで---- */


const int MAX_P = 10000;
long long Fact[MAX_P];

long long mod(long long a, long long m) {
	return (a % m + m) % m;
}
long long pow(long long a, long long n, long long m) {
	if (n == 0) return 1 % m;
	long long t = pow(a, n / 2, m);
	t = mod(t * t, m);
	if (n & 1) t = mod(t * a, m);
	return t;
}
long long modinv(long long a, long long m) {
	a = mod(a, m);
	if (a == 1) return 1;
	else return mod((1 - m * modinv(m % a, a)) / a, m);
}

// build n! table
void make_table(long long p) {
	Fact[0] = 1;
	for (int i = 1; i < p; ++i) {
		Fact[i] = (Fact[i - 1] * i) % p;
	}
}

// find the value of "a" (n! = a p^e)
long long true_fact(long long n, long long p, long long& e) {
	e = 0;
	if (n == 0) return 1;
	long long res = true_fact(n / p, p, e);
	e += n / p;

	if ((n / p) % 2 != 0) return res * (p - Fact[n%p]) % p;
	return res * Fact[n%p] % p;
}

// nCr mod.p
long long calc_com(long long n, long long r, long long p) {
	if (n < 0 || r < 0 || n < r) return 0;
	long long e1, e2, e3;
	long long a1 = true_fact(n, p, e1), a2 = true_fact(r, p, e2), a3 = true_fact(n - r, p, e3);
	if (e1 > e2 + e3) return 0;
	return a1 * modinv(a2 * a3 % p, p) % p;
}

// 中国剰余定理
long long extGCD(long long a, long long b, long long &p, long long &q) {
	if (b == 0) { p = 1; q = 0; return a; }
	long long d = extGCD(b, a%b, q, p);
	q -= a / b * p;
	return d;
}

pair<long long, long long> ChineseRem(const vector<long long> &b, const vector<long long> &m) {
	long long r = 0, M = 1;
	for (int i = 0; i < (int)b.size(); ++i) {
		long long p, q;
		long long d = extGCD(M, m[i], p, q); // p is inv of M/d (mod. m[i]/d)
		if ((b[i] - r) % d != 0) return make_pair(0, -1);
		long long tmp = (b[i] - r) / d * p % (m[i] / d);
		r += M * tmp;
		M *= m[i] / d;
	}
	return make_pair(mod(r, M), M);
}

class StairsColoring {
public:
	// 1000000122 = 2×3×11×2089×7253
	int coloringCount(long long N, long long K) {
		long long MOD = 1000000123;
		vector<long long> mod_factor({ 2,3,11,2089,7253 }); // !
		int n = (int)mod_factor.size();
		vector<long long> vb(n);

		for (int i = 0; i < n; ++i) {
			long long p = mod_factor[i];
			make_table(p);
			vb[i] = mod(calc_com(N * 2, N, p) - calc_com(N * 2, N - 1, p), p); // !
		}

		pair<long long, long long> e = ChineseRem(vb, mod_factor);
		return (int)pow(K, e.first, MOD); // !(e.firstが求めるcombinationの値)
	}
};

int main() {
	StairsColoring solve;
	cout << solve.coloringCount(3, 2) << endl;
	cout << solve.coloringCount(2, 2) << endl;
	cout << solve.coloringCount(1, 1) << endl;
	cout << solve.coloringCount(4, 5) << endl;
	cout << solve.coloringCount(7, 77) << endl;
}
