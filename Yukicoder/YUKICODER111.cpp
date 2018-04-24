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

/* -----  2018/04/24  Problem: yukicoder 111  / Link: http://yukicoder.me/problems/no/111  ----- */
/* ------問題------

「あばばばばばば、ばあ！」
保吉は女を後ろにしながら、我知らずにやにや笑ひ出した。

芥川龍之介 あばばばば http://www.aozora.gr.jp/cards/000879/card14.htmlより


何故保吉は「にやにや笑ひ出した」のでしょうか？
そう、お察しのように「あばばばばばば」をローマ字に置き換えた「ababababababa」という文字列が回文になっていたからです。
文字列Sは"a"の後ろに"ba"が複数回続く長さLの文字列です。 長さLが与えられるとSは一意に決まります。 例えばL=3のときSは"aba"、L=5のときは"ababa"となります。 Lが与えられるので、対応するSの中に長さ2以上の回文がいくつ含まれるかを答えてください。

回文とは、前から読んでも後ろから読んでも同じ文字列のことです。 より厳密にはSのi番目の文字をSiとすると、 0≤k≤j−i (i≤j)であるようなすべてのkについて、 Si+k=Sj−kであるとき、文字列Si+Si+1+⋯+Sjは長さj−i+1の回文となります。
例えば"ababa"という文字列は前から読んでも後ろから読んでも"ababa"という文字列になるため、長さ5の回文です。
一方"abab"という文字列は後ろから読むと"baba"という文字列になり、前から読んだ時と一致しないため回文ではありません。

-----問題ここまで----- */
/* -----解説等-----

(ab)^{+}b : 1+...+N個
(ba)^{+}a : 1+...+N-1個
ある。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	N /= 2;
	ans = N * (N + 1) / 2;
	N--;
	ans += N * (N + 1) / 2;
	cout << ans << "\n";

	return 0;
}
