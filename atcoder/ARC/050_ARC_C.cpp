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

/* -----  2018/11/08  Problem: ARC 050 C / Link: http://arc050.contest.atcoder.jp/tasks/arc050_c  ----- */
/* ------問題------

数字の 1 を A 個並べてできる整数を x とします。
また、数字の 1 を B 個並べてできる整数を y とします。
x と y の最小公倍数を M で割った余りを求めてください。

-----問題ここまで----- */
/* -----解説等-----

長さnの1...1列を1{n}とする。
lcm(1{x},1{y})は1{x}*1{y}/gcd(1{x},1{y})である。互除法から、gcd(1{x},1{y})=1{gcd(x,y)}であることが示せる。
よって、あとは1{x}と、1{y}/1{gcd(x,y)}が求められれば良い。
1{x}は、10*x+1を繰り返せばできる。したがって行列累乗可能。(ここが全然みえなくて大変だった)
1{a}/1{b}については、実験すると10000...00001の列の繰り返しになる。
正確には長さbのブロックがa/b個できる。ブロックは10^b+1で、これを10^b*X+1しているので、これも行列累乗で計算できる。
あとはこれを実装すれば良い。
結構好き。

----解説ここまで---- */
int mod;
template<typename T>
vector<vector<T>> mul(const vector<vector<T>> &A, const  vector<vector<T>> &B) {
	vector<vector<T>> C(A.size(), vector<T>(B[0].size()));
	FOR(i, 0, (int)A.size()) {
		FOR(k, 0, (int)B.size()) {
			if (A[i][k]) {
				FOR(j, 0, (int)B[0].size()) {
					C[i][j] = (C[i][j] + (1LL * A[i][k]) * (B[k][j])) % mod;
				}
			}
		}
	}
	return C;
}
template<typename T>
vector<vector<T>> pow(vector<vector<T>> A, long long n) {
	vector<vector<T>> B((int)A.size(), vector<T>((int)A.size()));
	FOR(i, 0, (int)A.size()) {
		B[i][i] = 1;
	}
	n--;
	while (n > 0) {
		if (n & 1) B = mul(B, A);
		A = mul(A, A);
		n >>= 1;
	}
	return B;
}
long long modpow(long long a, long long b, long long mod) {
	if (b == 0) return 1;
	return modpow(a * a % mod, b / 2, mod) * (b & 1 ? a : 1) % mod;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL A, B; int  M; cin >> A >> B >> M;
	mod = M;
	LL gcd = __gcd(A, B);
	// A*B/gcd
	VVL ten(2, VL(2, 1));
	// 10 1  ('1'(x) )
	// 0  1  (   1   )
	ten[0][0] = 10; ten[1][0] = 0;
	VVL resA = pow(ten, A);
	LL resAs = (resA[0][0] + resA[0][1]) % mod;
	VVL BgcdTen(2, VL(2, 1));
	BgcdTen[0][0] = modpow(10, gcd, mod); BgcdTen[1][0] = 0;
	VVL resB = pow(BgcdTen, B / gcd);
	LL resBs = (resB[0][0] + resB[0][1]) % mod;
	DD(De(resA, resB); de(A, B, gcd));
	LL ans = resBs * resAs;
	ans %= mod;
	cout << ans << endl;

	return 0;
}
