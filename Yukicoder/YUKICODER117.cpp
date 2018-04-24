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

/* -----  2018/04/24  Problem: yukicoder 117  / Link: http://yukicoder.me/problems/no/117  ----- */
/* ------問題------

1 以上 N 以下の N 個の整数の中から，相異なる K 個の整数を選ぶパターンの数を C(N,K) と書きます．
1 以上 N 以下の N 個の整数の中から，相異なる K 個の整数を選び，順番に並べるパターンの数を P(N,K) と書きます．
1 以上 N 以下の N 個の整数の中から，重複を許して K 個の整数を選ぶパターンの数を H(N,K) と書きます．
（具体例はサンプル1の説明に書いてあるので必要ならば参照せよ．）
クエリが T 個与えられ，各クエリでは C(N,K),P(N,K),H(N,K) のどれかが与えられるので，その値を mod 109+7 で求めるプログラムを書いて下さい．

-----問題ここまで----- */
/* -----解説等-----

verify問題。
kirikaさんの整数論pdfではinverseの方が速いとの記述があったけどあんまり変わらなかった…

----解説ここまで---- */
const long long mod = 1e9 + 7;

long long modpow(long long a, long long b) {
	if (b == 0) return 1;
	return modpow(a * a % mod, b / 2) * (b & 1 ? a : 1) % mod;
}

long long modinv(long long a) {
	return modpow(a, mod - 2);
}


inline long long  inverse(long long  a, long long  m) {
	long long  b = m, u = 1, v = 0;
	while (b) {
		long long  t = a / b;
		swap(a -= t * b, b);
		swap(u -= t * v, v);
	}
	return (u % m + m) % m;
}


vector<long long> fact, inv_fact;
void init_fact(int n) {
	fact.resize(n);
	fact[0] = 1;
	for (int i = 1; i < n; i++) {
		fact[i] = i * fact[i - 1] % mod;
	}
	inv_fact.resize(n);
	inv_fact[n - 1] = inverse(fact[n - 1], mod);
	for (int i = n - 2; i >= 0; i--) {
		inv_fact[i] = (i + 1) * inv_fact[i + 1] % mod;
	}
}

long long nPr(int n, int r) {
	if (n < r || n < 0 || r < 0) return 0;
	return fact[n] * inv_fact[n - r] % mod;
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
	int T; scanf("%d", &T);

	LL ans = 0LL;
	init_fact(2e6+1);
	FOR(t, 0, T) {
		char c[3];
		int a, b;
		scanf("%1s(%d,%d)", c, &a, &b);
		if (c[0] == 'C') {
			ans = nCr(a, b);
		}
		else if (c[0] == 'P') {
			ans  = nPr(a, b);
		}
		else {// H
			ans = nHr(a, b);
		}
		printf("%lld\n", ans);
	}

	return 0;
}
