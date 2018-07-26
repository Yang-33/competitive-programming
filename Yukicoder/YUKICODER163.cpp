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

/* -----  2018/07/26  Problem: yukicoder 163  / Link: http://yukicoder.me/problems/no/163  ----- */
/* ------問題------

Zeldaは、昨日PCにパスワードを設定した。
今日、PCを起動したが、昨日入力したパスワードでは入れない事に気づいた。
よくよく考えてみると、Caps Lock機能がオンのまま気づかずに入力してしまったようだ。
*として隠されて表示されるため、入力中には気づかなかったらしい。

パスワードは、大文字・小文字の半角アルファベット52種類のみ使用する。
Caps Lockは入力するアルファベットが、小文字の入力なら大文字に、大文字の入力なら小文字として入力される機能である。
昨日入力したはずのパスワードの文字列が与えられるので
誤って設定された「現在の」パスワードを求めてください。

-----問題ここまで----- */
/* -----解説等-----

'a'-'A' = 32なので ^32でひっくり返せるらしい　やべえ

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	FOR(i, 0, SZ(s)) {
		s[i] = (isupper(s[i]) ? tolower(s[i]) : toupper(s[i]));
	}
	string ans = s;
	cout << ans << "\n";

	return 0;
}