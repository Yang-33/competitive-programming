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

/* -----  2018/12/13  Problem: ARC 004 D / Link: http://arc004.contest.atcoder.jp/tasks/arc004_d  ----- */
/* ------問題------

整数 N と M が与えられる時、整数 N を M 個の整数の積で表す方法は何通りあるでしょうか。
その答えを 1,000,000,007 で割った余りを答えてください。

-----問題ここまで----- */
/* -----解説等-----

素数ごとに独立してM個に配置しても重複しない。(事象は独立なので)
あとは-1/+1とするだけなので2^{M-1}をかければ良い。

----解説ここまで---- */

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

long long nHr(int n, int r) {
	if (n == 0 && r == 0) return 1;
	return nCr(n + r - 1, r);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	// 素数を全部置く時、素数ごとの配置の仕方は独立
	LL ans = 1;
	N = abs(N);
	init_fact(1e6);
	for (LL i = 2; i*i <= N; i++) {
		LL cnt = 0;
		while (N%i == 0) {
			cnt++; N /= i;
		}
		if (cnt) {
			(ans *= nHr(M, cnt)) %= mod;
		}
	}
	if (N > 1)		(ans *= nHr(M, 1)) %= mod;

	(ans *= modpow(2, M - 1)) %= mod;

	cout << ans << "\n";

	return 0;
}
