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

/* -----  2018/07/28  Problem: yukicoder 176  / Link: http://yukicoder.me/problems/no/176  ----- */
/* ------問題------

Yuki王国では、A円とB円の2種類の郵便切手が発行されています。

あなたは、これら2種類の切手をうまく組み合わせて、
郵便物にT円分以上の切手を貼ろうとしていますが、
切手の合計額がなるべく少なくなるようにしなければなりません。

切手の合計額が最も少なくなるようにしたとき、
何円分の切手を貼ることになるでしょうか？
その合計額を答えてください。

なお、必ずしも両方の種類の切手を使う必要はなく、
切手の枚数に制限はありません。

-----問題ここまで----- */
/* -----解説等-----

こういうのはまず1変数を探索する。
あるyを決定したときに条件を満たすxも一つに定まる。
yの上界はAでよい。これはA以上選択しても総額が減少することは無いため。
	- xA+yB>=T -> xA+(A+'y)B>=T -> A(x+B)+'y*B>=T なので。

想定解がgcdとlcmなんだけどよく分からない。(さっきの'yがらみっぽそう)

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL A, B, T; cin >> A >> B >> T;

	LL ans = (T+B-1)/B*B;// x=0

	for (LL y = 0; y*B <= T && y<=A; ++y) { // sqrt
		LL x = (T - y*B+A-1) / A;
		ans = min(ans, x*A + y*B);
	}

	cout << ans << "\n";

	return 0;
}
