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

/* -----  2018/07/31  Problem: yukicoder 194  / Link: http://yukicoder.me/problems/no/194  ----- */
/* ------問題------

yuki君はyukicoderで門松列に対しスーパーリッチ門松列というものがあることを学んだ。
フィボナッチ数列に興味を持ったyuki君は、同様にスーパーフィボナッチ数列というものを考えてみた。

スーパーフィボナッチ数列は、最初のN項A1,A2,...,ANから生成される数列であり、第k項の値F(k)は、直前のN項の和となる。
厳密に書くと、F(k)は以下のように定義される。
- k≤Nならば F(k)=Ak
- k>Nならば F(k)=F(k−1)+F(k−2)+...+F(k−N)=∑1≤i≤NF(k−i)

yuki君は大きな整数Kに対し、F(K)及びS(K)=∑1≤k≤KF(k)がどうなるか気になった。
F(K)およびS(K)の値の10^9+7の剰余を答えよ。

-----問題ここまで----- */
/* -----解説等-----

まずtestcase1-10は簡単で、N個の和を保持しながらF(i)を作成する。この際追加と削除のみ行えばO(1)でできるので全体でO(K)
次にtestcase11-20を考える。これも簡単で行列のN乗、総和を求めることが行列累乗になることを知っていればできる。O(N^3logK)

一発だった、気持ちがいい。

----解説ここまで---- */

template<typename T>
vector<vector<T>> mul(vector<vector<T>> &A, vector<vector<T>> &B) {
	vector<vector<T>> C(A.size(), vector<T>(B[0].size()));
	FOR(i, 0, (int)A.size()) {
		FOR(k, 0, (int)B.size()) {
			if (A[i][k]) {
				FOR(j, 0, (int)B[0].size()) {
					C[i][j] = (C[i][j] + (A[i][k]) * (B[k][j])) % MOD;
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

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, K; cin >> N >> K;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	if (N <= 30) {
		VVL A(N+1, VL(N+1, 0));
		FOR(i, 0, N + 1)A[0][i] = 1;
		FOR(i, 1, N + 1)A[1][i] = 1;
		FOR(i, 2, N + 1)A[i][i - 1] = 1;
		VVL AN = pow(A, K-N);
		VVL Seed(N + 1, VL(1, 0));
		LL sn1 = 2 * accumulate(ALL(a), 0LL) ;
		Seed[0][0] = sn1;
		FOR(i, 0, N)Seed[N-i][0] = a[i];
		VVL res = mul(AN, Seed);
		cout << res[1][0] << " " << (res[0][0]- accumulate(ALL(a), 0LL) +MOD)%MOD << endl;

	}
	else {
		LL sum = 0;
		VL Fib(K, 0);
		FOR(i, 0, N) {
			sum += a[i];
			Fib[i] = a[i];
		}

		FOR(i, N, K) {
			Fib[i] = sum;
			sum = sum - Fib[i-N] + sum;
			sum += MOD, sum %= MOD;
		}
		LL ret = 0;
		FOR(i, 0, K) {
			ret += Fib[i];
			ret %= MOD;
		}
		cout << Fib[K - 1] << " " << ret << endl;
	}

	return 0;
}
