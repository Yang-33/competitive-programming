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

/* -----  2018/06/10  Problem: AOJ 2012 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2012  ----- */
/* ------問題------

ケン・マリンブルーは，宇宙ヤシガニを求めて全銀河を旅するスペースハンターである．宇宙ヤシガニは，宇宙最大とされる甲殻類であり，成長後の体長は 400 メートル以上，足を広げれば 1,000 メートル以上にもなると言われている．既に多数の人々が宇宙ヤシガニを目撃しているが，誰一人として捕らえることに成功していない．

ケンは，長期間の調査によって，宇宙ヤシガニの生態に関する重要な事実を解明した．宇宙ヤシガニは，驚くべきことに，相転移航法と呼ばれる最新のワープ技術と同等のことを行い，通常空間と超空間の間を往来しながら生きていた．さらに，宇宙ヤシガニが超空間から通常空間にワープアウトするまでには長い時間がかかり，またワープアウトしてからしばらくは超空間に移動できないことも突き止めた．

そこで，ケンはついに宇宙ヤシガニの捕獲に乗り出すことにした．戦略は次のとおりである．はじめに，宇宙ヤシガニが通常空間から超空間に突入する際のエネルギーを観測する．このエネルギーを e とするとき，宇宙ヤシガニが超空間からワープアウトする座標 (x, y, z) は以下の条件を満たすことがわかっている．

x, y, z はいずれも非負の整数である．
x + y2 + z3 = e である．
上記の条件の下で x + y + z の値を最小にする．
これらの条件だけでは座標が一意に決まるとは限らないが，x + y + z の最小値を m としたときに，ワープアウトする座標が平面 x + y + z = m 上にあることは確かである．そこで，この平面上に十分な大きさのバリアを張る．すると，宇宙ヤシガニはバリアの張られたところにワープアウトすることになる．バリアの影響を受けた宇宙ヤシガニは身動きがとれなくなる．そこをケンの操作する最新鋭宇宙船であるウェポン・ブレーカー号で捕獲しようという段取りである．

バリアは一度しか張ることができないため，失敗するわけにはいかない．そこでケンは，任務の遂行にあたって計算機の助けを借りることにした．あなたの仕事は，宇宙ヤシガニが超空間に突入する際のエネルギーが与えられたときに，バリアを張るべき平面 x + y + z = m を求めるプログラムを書くことである．用意されたテストケースの全てに対して正しい結果を出力したとき，あなたのプログラムは受け入れられるであろう．

-----問題ここまで----- */
/* -----解説等-----

全探索

----解説ここまで---- */

void solve() {
	LL N;
	while (cin >> N, N) {
		LL ans = LINF;
		for (LL z = 0; z*z*z <= N; z++) {
			for (LL y = 0; y*y <= N; y++) {
				LL x = N - z * z*z - y * y;
				if (x >= 0 && x <= N) {
					ans = min(ans, x + y + z);
				}
			}
		}
		cout << ans << endl;
	}

}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}