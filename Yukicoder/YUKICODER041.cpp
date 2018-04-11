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
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/04/11  Problem: yukicoder 041  / Link: http://yukicoder.me/problems/no/041  ----- */
/* ------問題------

太郎くんは六並び国に住んでいます。
この国では、1 円玉のほか、6 つの数字からなるゾロ目、つまり、111111 円玉、222222 円玉、…、999999 円玉の、合計 10 種類の硬貨が使われています。
貯金箱くんは硬貨を貯めに貯めて、どの硬貨も、1020 枚以上持っています。
しかし、太郎くんが M 円のお買い物したかったのです。
太郎くんは、貯金箱くんに合計でちょうど M 円分の硬貨をくれるように頼みました。
貯金箱くんは、せっかく貯めた硬貨をあげるのを渋り、問題に答えられたらあげることにしました。
貯金箱くんは、「僕が M 円をあげるために渡さなければいけない最小の硬貨の枚数は何枚？」という問題を出しましたが太郎くんは一瞬で答えてしまいました。
そこで、もう 1 問、貯金箱くんは、「僕が M 円をあげるために硬貨を渡す方法は何通り？」という問題に切り替えました。
今度は太郎君が困ってしまいました。
あなたは、貯金箱くんが M 円を太郎くんに渡す方法のパターン数を 109+9 で割った余りを求めるプログラムを書いて下さい。

-----問題ここまで----- */
/* -----解説等-----

1円玉のみで支払うとき、すべての金額について払うことができ、ある金額については1通り。
次に111111円について考える。111111円の倍数で構成される金額は、111111->1とみて、DPで組み合わせ数を求めることができる。
最後に端数を考える。端数については1円のみで支払うしかない。
したがってもとめるDPは、dp[i]:=111111*i円支払う際の組み合わせ

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	const LL mod = 1000000009;
	VI dp(1e5 + 10, 1);

	FOR(c, 1, 10) {
		FOR(i, 0, 1e5) {
			(dp[i + c] += dp[i]) %= mod;
		}
	}

	int T; cin >> T;
	FOR(t, 0, T) {
		LL m; cin >> m;
		ans = dp[m / 111111];
		cout << ans << "\n";
	}

	return 0;
}
