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

/* -----  2018/11/15  Problem: ARC 020 C / Link: http://arc020.contest.atcoder.jp/tasks/arc020_c  ----- */
/* ------問題------

高橋君が高校生の頃参加していたコンテストでは、2 つの整数の和を求める問題が出題されたことがありました。あんなものは最強最速の手に掛かればお茶の子さいさいでした。
大学生になった高橋君は、現在あなたと大学生向けのコンテストに参加している真っ最中です。しかし、得意な言語を使う際に必要な統合開発環境が壊れていて、問題を解くどころではないらしいのです。 そこで、チームメイトであるあなたは、統合開発環境の問題が審判団によって対応されるまでに、彼の代わりに以下の問題を解いておくことにしました。
整数 A と B が与えられる。 A を B で割った余りを出力しなさい。ただし、整数 A と整数 B について以下のような特徴があります。
整数 A, B はどちらも 10 進数である。
整数 B は 100 点中 99 点分のテストケースで B=1000000007(109+7)　を満たしている。
整数 A は非常に大きく、かつ部分的に周期性を持ち、以下のような形式で与えられる。
N と a1,a2,..,aN と L1,L2,..,LN が与えられる。これは、整数 A が上の桁から a1 が L1 回、a2 が L2 回、..、aN が LN 回と繰り返された形であることを意味する。
例えば、 N=3,a={123,4,56},L={2,2,1},B=1000000007のとき、A=1231234456であり、A を B で割った余りは 231234449 です。

-----問題ここまで----- */
/* -----解説等-----

SZ(A)={1000001}的な感じで、
A{000001}{0000001}がL個ある数字を求めて、あとはこれを10^{ア}でよい。
{000001}パートは、行列累乗可能。

LCA111と本当に一緒。

----解説ここまで---- */


LL read() { LL x; scanf("%lld", &x); return x; }
LL mod;
template<typename T>
vector<vector<T>> mul(vector<vector<T>> &A, vector<vector<T>> &B) {
	vector<vector<T>> C(A.size(), vector<T>(B[0].size()));
	FOR(i, 0, (int)A.size()) {
		FOR(k, 0, (int)B.size()) {
			if (A[i][k]) {
				FOR(j, 0, (int)B[0].size()) {
					C[i][j] = (C[i][j] + (A[i][k]) * (B[k][j])) % mod;
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
	while (n > 0) {
		if (n & 1) B = mul(B, A);
		A = mul(A, A);
		n >>= 1;
	}
	return B;
}
long long modpow(long long a, long long b) {
	if (b == 0) return 1;
	return modpow(a * a % mod, b / 2) * (b & 1 ? a : 1) % mod;
}
int main() {

	int N = read();
	VL a(N), l(N);
	FOR(i, 0, N) {
		a[i] = read(), l[i] = read();
	}
	mod = read();
	LL ans = 0;
	FOR(i, 0, N) {
		LL asz = (int)to_string(a[i]).size();
		VVL X(2, VL(2, 0));
		X[0][0] = modpow(10, asz);
		X[0][1] = X[1][1] = 1;
		(ans *= modpow(10, asz*l[i])) %= mod;
		VVL ret = pow(X, l[i] - 1);
		LL sum = (ret[0][0] + ret[0][1]) % mod;
		(ans += (a[i] * sum) % mod) %= mod;
	}
	cout << ans << endl;
	return 0;
}//