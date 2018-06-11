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

/* -----  2018/06/11  Problem: AOJ 2149 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2149  ----- */
/* ------問題------

Nathan O. Davis くんは，あるゲームを攻略中であり，非常にレアなアイテムを手に入れようと四苦八苦していた．このレアなアイテムは，カジノのスロットマシーンで特殊な絵柄を一列に揃えたときに手に入れることができる．スロットマシーンには N 個のリールがあり，ボタンを一回押すと現在回転している最も左側のリールが停止する．そのため，このレアアイテムを手に入れるためには N 回ボタンを押す必要がある．また，特殊な絵柄で停止させるためにはあるタイミングでボタンを押す必要がある．ところが，このボタンを押すタイミングは非常にシビアであるため，なかなか上手くいかずに困っていた．そこで，Nathan くんはメモリビューアを利用して，ゲーム中におけるメモリの値を確認しながらゲームを解析することにした．

Nathan くんの解析の結果，その特殊な絵柄でリールを停止させるためには，ボタンが押された時に，メモリの 007E0D1F 番地に書き込まれた「乱数」が特定の値になっている必要があることを突き止めた．乱数の値は 1 フレーム毎に線形合同法によって変化しており，またボタンが押されたかどうかの判定は 1 フレーム毎に 1 回行われていることも分かった．ここで，線形合同法とは擬似乱数を生成するための方法の一つであり，以下の式によって値を決定する．

x' = (A × x + B) mod C

ここで，x は現在の乱数の値，x' は次の乱数の値，A, B, C は何らかの定数である．また，y mod z は y を z で割ったときの余りを表す．

例えば，2 個のリールを持つスロットマシーンで A = 5，B = 7，C = 11 で，最初の「乱数」の値が 10 であったとする．そして，特殊な絵柄でリールを止めるための条件は，左側のリールが 2，右側のリールが 4 であったとする．このとき，1 フレーム目における乱数の値は (5 × 10 + 7) mod 11 = 2 であるため，1 フレーム目にボタンを押せば左側のリールは特殊な絵柄で停止する．続く 2 フレーム目での乱数の値は (5 × 2 + 7) mod 11 = 6 であるから，2 フレーム目にボタンを押しても右側のリールは特殊な絵柄では停止しない．続く 3 フレーム目では乱数の値が (5 × 6 + 7 ) mod 11 = 4 になるので，3 フレーム目にボタンを押せば右側のリールは特殊な絵柄で停止する．よって，最短 3 フレームで全てのリールを特殊な絵柄で停止されることができ，レアなアイテムを手に入れることができる．

あなたの仕事は，最短で何フレーム目に全てのリールを特殊な絵柄で停止させることができるかを求めるプログラムを書いて，Nathan くんがレアなアイテムを手に入れられるよう助けてあげることである．

-----問題ここまで----- */
/* -----解説等-----

書きます

----解説ここまで---- */

void solve() {
	LL N, A, B, C, X;
	while (cin >> N >> A >> B >> C >> X, N) {
		VL y(N);
		FOR(i, 0, N) {
			cin >> y[i];
		}
		const int Max = 10000;
		int cnt = 0;
		int id = 0;
		int  k = 0;
		for (k = 0; k <= Max; k++) {
			if (X == y[id])id++;
			if (id == N) {
				break;
			}
			X = (A*X + B) % C;
			cnt++;
		}
		if (k == Max + 1) {
			cnt = -1;
		}
		cout << cnt << endl;
	}


}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solve();
	return 0;
}