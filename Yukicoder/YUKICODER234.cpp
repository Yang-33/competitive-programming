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

/* -----  2018/08/24  Problem: yukicoder 234  / Link: http://yukicoder.me/problems/no/234  ----- */
/* ------問題------

ちゃろー、センパイ。
今、めぐる、ちょたクエっていう同人ゲームやってるんですけど、クリア後のエクストラダンジョンが酷いんですよね…。
友達の病気を治すために、愛らしいキャラクターのcucumberに頼んで、魔法少女になって課題をこなすってストーリーなんですけど、この課題がすっごく面倒なんです！
課題の迷宮の第 N 階層は、N 段の三角形からできているような形なんですけど…、って言ってもわからないですよね。
簡単に描くとこんなのですね。


この迷宮の第 N 階層の中で、決められたルートを通ると次の階層への階段が現れるんですけど、決められたルートが何なのかヒントが全くないので全部試さないといけないんですよね…。
今までの傾向から言うと、決められたルートって、単純多角形からなるルートなんですけど、それでも、ルートの数が多すぎて…。
あ、単純多角形って、辺が交差しない多角形ですね。ARC037Dを見るとセンパイでもよくわかると思いますよ！
あーもぉ、一体何個ぐらい試さないといけないルートがあるんですかね…！？

-----問題ここまで----- */
/* -----解説等-----

せんぱいも、OEISなら調べられますよね…！？
https://oeis.org/A266513

DP解はメモ化再帰する。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;cin >> N;
	VS a = { "0", "1", "11", "110","2402", "128967", "16767653", "5436906668", "4406952731948", "8819634719356421","43329348004927734247", "522235268182347360718818", "15436131339319739257518081878", "1117847654274955574635482276231683" };
	string ans = a[N];
	cout << ans << "\n";

	return 0;
}
