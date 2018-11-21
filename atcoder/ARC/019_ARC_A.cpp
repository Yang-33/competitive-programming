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

/* -----  2018/11/21  Problem: ARC 019 A / Link: http://arc019.contest.atcoder.jp/tasks/arc019_a  ----- */
/* ------問題------

私は今 ARC ゲームズという会社の Ancient Royal Coders という、冒険しながら競技プログラミングの知識が身につくロールプレイングゲームをプレーしている真っ最中である。
といってもまだゲームは始まったばかりで、これから最初のダンジョンへ向かうところだ。とりあえず薬草をいくつか購入するために街にあるショップへ行っておこう。
ショップへ到着し薬草を購入しようとして値段を確認すると、これがなんだか奇妙だ。画面には 1Z0 ゴールド と値段が表示されているが、これは本当に 120 なのだろうか……？
他のアイテムもよく見てみると、なんと一部の数字が似たようなアルファベットに置き換わっているではないか！これでは、値段が 36 進数として解釈されてしまい法外な金額を要求されかねない！
なるほどなるほど、ぼったくりを回避するためにはこの奇妙な表記を数字のみからなる正しい表記に戻すためのプログラムを書かないといけないというわけか。序盤からなかなか骨のあるゲームだ。調べてみたところ、置き換わっている文字の種類は以下のようなものがあるらしい。

-----問題ここまで----- */
/* -----解説等-----

埋め込む。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	map<char, char>Map{ { 'O','0' },{ 'D','0' },{ 'I','1' },
	{ 'Z','2' },{ 'S','5' },{ 'B','8' } };
	FOR(i, 0, SZ(s)) {
		if (isdigit(s[i])) {
			cout << s[i];
		}
		else {
			cout << Map[s[i]];
		}
	}
	cout << endl;

	return 0;
}