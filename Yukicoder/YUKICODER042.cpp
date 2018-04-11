#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (LL(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/04/11  Problem: yukicoder 042  / Link: http://yukicoder.me/problems/no/042  ----- */
/* ------問題------

太郎くんは日本国に住んでいます。
この国では、1 円玉、5 円玉、10 円玉、50 円玉、100 円玉、500 円玉の 6 種類の硬貨が使われています。

貯金箱くんは硬貨を貯めに貯めて、1 円玉も 5 円玉も 10 円玉も 50 円玉も 100 円玉も 500 円玉も、1020 枚以上持っています。
しかし、太郎くんが M 円のお買い物したかったのです。
太郎くんは、貯金箱くんに合計でちょうど M 円分の硬貨をくれるように頼みました。
貯金箱くんは、せっかく貯めた硬貨をあげるのを渋り、問題に答えられたらあげることにしました。
貯金箱くんは、「僕が M 円をあげるために渡さなければいけない最小の硬貨の枚数は何枚？」という問題を出しましたが太郎くんは一瞬で答えてしまいました。
そこで、もう 1 問、貯金箱くんは、「僕が M 円をあげるために硬貨を渡す方法は何通り？」という問題に切り替えました。
今度は太郎君が困ってしまいました。
あなたは、貯金箱くんが M 円を太郎くんに渡す方法のパターン数を 109+9 で割った余りを求めるプログラムを書いて下さい。

-----問題ここまで----- */
/* -----解説等-----

naiveDPではO(M)でこわれる。
dp(i):=i円払う組合せとしてやればいいが、ここでDPを変形する。
dp(x,i):=x番目までの硬化を使用してi円払うときの組合せとして、
式は、dp(x,i) = dp(x-1,i) + dp(x,i-c[x])　となる。
実はdp[x][a*c[x]+b]は、aのx次式で表せる。(天下り的だけど)
したがって5次式であることがわかり、6点あれば補完で解ける。
証明はそのうち。

互いの倍数を考慮すると666で1周期があって、これを上手にまとめるのかなと思って頑張ったけどダメだった。
多項式補完できるのですね…

----解説ここまで---- */

// 繰り返し二乗法
long long  powmod(long long  x, long long  n, long long  mod) {
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

// フェルマーの小定理 a^(p-1)≡1 -> a^-1≡a^(p-2) (mod p∈{素数})
long long  fermat_inv_mod(long long  a, long long  p) {
	return powmod(a, p - 2, p);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	VI c({ 1,5,10,50,100,500 });
	const LL mod = 1000000009;

	VL dp(3010, 0);
	dp[0] = 1;
	FOR(i, 0, 6) {
		FOR(m, 0, 3000) {
			if (m + c[i] <= 3000)
				(dp[m + c[i]] += dp[m]) %= mod;
		}
	}
	FOR(t, 0, T) {
		LL M; cin >> M;
		LL a = M / 500;
		LL b = M % 500;
		LL ans = 0;
		FOR(j, 0, 6) {
			LL L = dp[500 * j + b];
			FOR(k, 0, 6) {
				if (j != k) {
					L *= (a - k) % mod;
					L %= mod;
					L *= fermat_inv_mod(j - k, mod);
					L %= mod;
				}
			}
			ans += L + mod;
			ans %= mod;
		}


		/* naive
		VL dp(M + 501, 0);
		dp[0] = 1;
		FOR(i, 0, 6) {
			FOR(m, 0, M) {
				(dp[m+c[i]] += dp[m])%=mod;
				if (m % 10000000==0)cout << m << endl;
			}
		}
		debug(dp[M]);*/

		cout << ans << "\n";

	}

	return 0;
}
