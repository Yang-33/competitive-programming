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

/* -----  2018/11/21  Problem: ARC 018 A / Link: http://arc018.contest.atcoder.jp/tasks/arc018_a  ----- */
/* ------問題------

ぼく、一目惚れをしました。昨日学内ですれ違った彼女の名前、どうしても知りたいんです。いや、名前だけじゃない……！身長も体重も、彼女の全てが知りたい！
でも、僕には彼女に話しかける勇気なんてない。彼女の体重は何 kg なんだろうか...彼女の身長は何 cm くらいなんだろうか...。結局、一晩中彼女のことだけを考えてぜんぜん寝られていない。
さすがに女性にいきなり体重を聞くのは失礼だろう。そんなことは分かっている。そんなものを聞いたりしたら、間違いなく嫌われてしまうだろう。
「うーむ、どうしたものか……ハッ！」
僕の脳内に稲妻が走った。そうだ、身長とBMI(※)を聞けばいいんだ。そうしたら体重を逆算できる。名前はもうどうでもいいや、これは名案だ。
そうと決まれば、 身長[cm] と BMI[kg⁄m2] の2つの値に基づいて 体重[kg] を逆算してくれるプログラムを有能プログラマーである君に作ってもらいたい。

-----問題ここまで----- */
/* -----解説等-----

ちょいちょいHTMLの構造が変わるため、vjudgeが苦労しているっぽい
計算する。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	double height, BMI; cin >> height >> BMI;
	double ans = BMI * height*height / 10000;
	cout << fixed << setprecision(10) << ans << endl;

	return 0;
}
