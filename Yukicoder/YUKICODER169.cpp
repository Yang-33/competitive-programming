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

/* -----  2018/07/26  Problem: yukicoder 169  / Link: http://yukicoder.me/problems/no/169  ----- */
/* ------問題------

ゆきこちゃんは、大きなサイズのファイルをコピーをしようとしています。
コピーに時間がかかるので、しばらくして確認すると
「K%完了しました。あとS分かかります。」
と表示されていました。
ゆきこちゃんは、このファイルコピーに全体で何分かかるか知りたくなりましたが、
算数が苦手なので、計算することができません。
あなたは、ゆきこちゃんの代わりに全体の処理時間(分)を計算してあげてください。
答えは、小数部分の切り捨てをし、整数部分のみを答えてください。
時間あたりのコピーの速さは、一定であると仮定する。
ゆきこちゃんの見た完了のパーセンテージは小数も表示されるが、ちょうど整数になっていたタイミングであると仮定して良い。

-----問題ここまで----- */
/* -----解説等-----

ans*(1-K/100) = Sを変形する。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int K, S; cin >> K >> S;

	LL ans = 100*S/(100-K);

	cout << ans << "\n";

	return 0;
}
