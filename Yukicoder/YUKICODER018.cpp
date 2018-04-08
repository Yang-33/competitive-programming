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

/* -----  2018/04/08  Problem: yukicoder 018  / Link: http://yukicoder.me/problems/no/018  ----- */
/* ------問題------

太郎君は暗号に興味があり、新しい暗号方式を考えていました。
そこで大昔に開発されたシーザー暗号を参考にし、
すこし変更することでもうちょっと複雑な暗号方式を作ろうと思いつきました。

シーザー暗号とは、平文(暗号化されていない文)のアルファベットを、
右に N回 ずらしたもので、たとえば N=1 の場合、
'A'は'B'になり、'M'は'N'になり、'Z'は'A'になります。

そこで太郎君は、文字ごとに N の値を変更することを考え、
1文字目なら N=1、そして2文字目なら N=2、…のように、
「i文字目の文字をi回右にずらす」ことにしました。
(ずらした結果、文字'Z'を超える場合はシーザー暗号と同様に文字'A'へ戻ります)
右にずらすとはアルファベット順の次の文字にするということにします。
そして太郎君は、この新しい暗号方式を「うーさー暗号」と名づけました。

入力に「うーさー暗号」で暗号化された文字列が与えられるので、
これを復号した文字列を出力してください。

-----問題ここまで----- */
/* -----解説等-----

mod26をやるだけです。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	FOR(i, 0, SZ(s)) {
		int dec = (i + 1) % 26;
		int n = s[i] - 'A';
		int add =(26 + n - dec) % 26;
		s[i] = 'A' +  add;
	}
	cout << s << "\n";

	return 0;
}
