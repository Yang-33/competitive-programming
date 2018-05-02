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
const LL MOD = 1234567891;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/05/02  Problem: yukicoder 137  / Link: http://yukicoder.me/problems/no/137  ----- */
/* ------問題------

貯金箱さんは A 国に住んでいます．この国では通貨の単位は円と呼ばれ，A 1  A1 円玉，A 2  A2 円玉，…，A N  AN 円玉の，N N 種類の硬貨が使われています．
貯金箱さんは硬貨を貯めに貯めて，どの硬貨も 10 100  10100 枚持っています．あるとき，貯金箱さんは M M 円の買い物をすることになりました．ところが，「わたしの持っている硬貨でちょうど M M 円を支払う方法は何通りだろう？」とふと疑問に思ってしまい，気になって買い物ができず困っています．
貯金箱さんが硬貨でちょうど M M 円を支払う方法の個数を 1,234,567,891 1,234,567,891 で割った余りを求めるプログラムを書いてください．2 2 つの支払い方が同じであるとは，どの種類の硬貨も同じ枚数使うこととします．


-----問題ここまで----- */
/* -----解説等-----

これすごい
無限個使えるから愚直は厳しい。蟻本：個数制限付きナップザックのように、個数を2^xで表現する。
これによって重みが異なるコインが1枚だけあるようになる。
これで計算時間がlogに落ちるが、Mが大きすぎる。
---解説を見た---
重みが2の累乗を書けていくことを考えると、Mの下桁はどんどん変化できなくなっていく。
したがって最初のDPを終えた後に、Mの最下位のbitが同じdpのみ残して、残りは0にする。
メモリが足りないが、2*a[i]を,dpの添字を半分にしてa[i]だけindexをすすめるとすれば辻褄が合う。
これを繰り返すと、答えはなんとdp[0]。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}

	VL dp(50004, 0);
	dp[0] = 1;
	while (M) {
		FOR(i, 0, N) {
			FORR(j, 50000, a[i] - 1) {
				dp[j] += dp[j - a[i]];
				dp[j] %= MOD;
			}
		}
		// Mの下位桁から使用しなくなるので圧縮
		FOR(i, 0, 25001)dp[i] = dp[2 * i + M % 2];
		FOR(i, 25001, 50004)dp[i] = 0;

		M /= 2;
	}

	ans = dp[0];
	cout << ans << "\n";

	return 0;
}
