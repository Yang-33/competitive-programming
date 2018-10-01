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

/* -----  2018/10/01  Problem: yukicoder 312  / Link: http://yukicoder.me/problems/no/312  ----- */
/* ------問題------

新人プログラマーである新人君は、プログラムに下記の2種類のコメントを記述している。
・連続した2個分の#の後にコメントが書かれている通常のコメント
(例：## コメント
・連続したN個分の#で書かれているプログラムの区切りコメント
(例：######### (N=9))

上司である貴方は、区切りコメントは不必要な為削除するように新人君に指導する必要がある。
新人君は既に大量の区切りコメントを書いており、手作業で1つずつ削除するのは非効率である。
その為、置換機能で区切りコメントを取り除くことにした。

置換機能とは、指定した文字列を別途指定した文字列に置き換える事である。
今回はいくつかの連続した#からなる文字列を空文字列（長さ0の文字列）に置き換えることで、区切りコメントを取り除く。

無駄が嫌いな貴方は置換を行う際にN個の#を書かなくても区切りコメントを空白に出来る場合があることに気が付いた。
例えば区切りコメントが######### (#9個分)で構成されていた場合には、### (#3個分)を空文字に置換することにより区切りコメントを完全に削除することが出来る。
新人君に対し、通常のコメントを消さずに区切りコメントを完全に消す置換を行う際に記述する必要がある最小の#の個数を教えてあげよう。

ただし、置換は1回しか行えないものとする。(複数回に分けて置換を行うことは出来ない)

-----問題ここまで----- */
/* -----解説等-----

約数列挙してしまえば良いね！
i=3からi+=2の素因数をやると偶数で落ちます。
問題は結局の所、3以上のうち最小の約数を答えろという問題になる。


----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VL se;

	for (LL i = 1; i*i <= N; i++) {
		if (N%i == 0) {
			se.push_back(i);
			if (N / i != i)se.push_back(N / i);
		}
	}
	SORT(se);
	for (auto it : se) {
		if (it >= 3) {
			ans = it; break;
		}
	}
	cout << ans << "\n";

	return 0;
}
