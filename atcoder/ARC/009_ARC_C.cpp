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

/* -----  2018/12/06  Problem: ARC 009 C / Link: http://arc009.contest.atcoder.jp/tasks/arc009_c  ----- */
/* ------問題------

　高橋君は10月20日が誕生日なので、友達を誕生会に呼ぼうと考えています。
 　そこで恥ずかしがり屋な彼は、みんなに招待状を送ることにしました。

  　高橋君はなかなか手紙の良い文面が思いつかなかったので、全員分の手紙を書き終えたのは誕生日の前日でした。
   　慌てて友達 N 人の家のポストに 1 つずつ手紙を入れていったのですが、誤ってそのうち K 人の手紙を、別の友達のポストに入れてしまいました。

	　帰った後にそのことに気づいた高橋君はとても焦っています。
	 　彼を少しでも元気づけるために、ポストと入れられた手紙の考えられる組み合わせの数を 1,777,777,777 (素数) で割った余りを教えてあげてください。


-----問題ここまで----- */
/* -----解説等-----

結局、N個からK個選択し、このK個について、モンモール数であればよい。
nCrのときに10^18をかけていて死んでいた。うく

----解説ここまで---- */

const long long mod = 1'777'777'777;
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

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, K; cin >> N >> K;
	auto momm = [](LL k) {
		VL dp(k + 10, 0);
		dp[2] = 1;
		dp[3] = 2;
		FOR(i, 4, k + 1) {
			dp[i] = (i - 1)*((dp[i - 1] + dp[i - 2]) % mod) % mod;
		}
		return dp[k];
	};
	auto nCrS = [](LL n, LL r) {
		if (n < r || n < 0 || r < 0) return 0LL;
		long long ret = 1;
		for (long long x = n; x >= n - r + 1; x--) {
			ret *= x % mod; ret %= mod; // x%modで落ちた、
		}
		ret *= inv_fact[r];
		return ret % mod;
	};

	// nCk*mm(k)
	init_fact(1000000);
	LL ans = nCrS(N, K);
	ans *= momm(K);
	ans += mod;
	ans %= mod;
	cout << ans << endl;

	return 0;
}
