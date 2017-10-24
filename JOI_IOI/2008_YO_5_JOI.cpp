#include "bits/stdc++.h"
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

/* -----  2017/10/23  Problem: nu_3  / Link: http://joi2008yo.contest.atcoder.jp/tasks/joi2008yo_e  ----- */
/* ------問題------

IOI製菓では， 創業以来の伝統の製法で煎餅（せんべい）を焼いている． この伝統の製法は， 炭火で一定時間表側を焼き， 表側が焼けると裏返して， 炭火で一定時間裏側を焼くというものである． この伝統を守りつつ， 煎餅を機械で焼いている． この機械は縦 R (1 ≦ R ≦ 10) 行, 横 C (1 ≦ C ≦ 10000) 列の長方形状に煎餅を並べて焼く． 通常は自動運転で， 表側が焼けたら一斉に煎餅を裏返し裏側を焼く．
ある日， 煎餅を焼いていると， 煎餅を裏返す直前に地震が起こり何枚かの煎餅が裏返ってしまった． 幸いなことに炭火の状態は適切なままであったが， これ以上表側を焼くと創業以来の伝統で定められている焼き時間を超えてしまい， 煎餅の表側が焼けすぎて商品として出荷できなくなる． そこで， 急いで機械をマニュアル操作に変更し， まだ裏返っていない煎餅だけを裏返そうとした． この機械は， 横の行を何行か同時に裏返したり縦の列を何列か同時に裏返したりすることはできるが， 残念なことに， 煎餅を１枚ごと裏返すことはできない．
裏返すのに時間がかかると， 地震で裏返らなかった煎餅の表側が焼けすぎて商品として出荷できなくなるので， 横の何行かを同時に１回裏返し， 引き続き， 縦の何列かを同時に１回裏返して， 表側を焼きすぎずに両面を焼くことのできる煎餅， つまり， 「出荷できる煎餅」の枚数をなるべく多くすることにした． 横の行を１行も裏返さない，あるいは， 縦の列を１列も裏返さない場合も考えることにする． 出荷できる煎餅の枚数の最大値を出力するプログラムを書きなさい．
地震の直後に， 煎餅が次の図のような状態になったとする． 黒い丸が表側が焼ける状態を， 白い丸が裏側が焼ける状態を表している．

-----問題ここまで----- */
/* -----解説等-----

各行、列ではひっくり返すかひっくり返さないかの二択。
これは全探索ができそうなのでやる。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	LL H, W;
	cin >> H >> W;
	VVL masu(H, VL(W));

	FOR(i, 0, H) {
		FOR(j, 0, W) {
			cin >> masu[i][j];
		}
	}
	FOR(bit, 0, 1 << H) {//全部やる 0count
		LL ret = 0;
		FOR(j, 0, W) {
			LL sub = 0;
			FOR(i, 0, H) {
				if (bit & (1 << i)) {
					if (masu[i][j] == 0)sub++;
				}
				else if (!(bit & (1 << i)))
					if (masu[i][j] == 1)sub++;
			}
			ret += max(H - sub, sub);
		}
		ans = max(ret, ans);
	}

	cout << ans << "\n";

	return 0;
}
