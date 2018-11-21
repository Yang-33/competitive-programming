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

/* -----  2018/11/21  Problem: ARC 019 B / Link: http://arc019.contest.atcoder.jp/tasks/arc019_b  ----- */
/* ------問題------

ゲームも中盤にさしかかり、ちょうど海に出るための船を手に入れた。早く新たなダンジョンへ挑戦したいところだが、その前に船にかっこいい名前をつけねばならない。
早く先に進みたいので船の名前はデフォルトのものでいいかと思ったが、さすがにそれでは面白くないのでデフォルトの名前から 1 文字だけ変更することにしよう。
ところで、こういう場面でプログラミングコンテストの問題文の登場人物はなぜか「名前が回文になるようにしよう」とかいう訳のわからないこだわりを発揮することが多いのだが、私はそういう普通の登場人物とは違うのだ。私に変なこだわりはないので、船の名前は 回文でない ものにしたい。
さて、デフォルトの名前を 1 文字だけ変更することで、回文でない名前は何通りぐらい作ることができるのだろうか？プログラムを書いて確かめることとしよう。ちなみに船の名前として使える文字はアルファベットの大文字だけだ。
え？「回文でない名前にしたい」というのは「変なこだわり」ではないのかって？言われてみれば確かにその通りだし、やはり私はプログラミングコンテストの登場人物としての宿命から逃れることはできないのかもしれない。しかし、私のような者がこうして変なこだわりを持つことで多くの人がプログラミングコンテストを楽しんでくれるのであれば、それはそれで良いことなのだろう。

-----問題ここまで----- */
/* -----解説等-----

状態は3つ。回文である/一箇所かえると回文になりうる/絶対に回文にならない
それぞれ場合分けすればよい、特に中心に注意

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL ans = 0;
	string s; cin >> s;

	int N = SZ(s);
	VI diff(N, 0);
	int diffcnt = 0;
	FOR(i, 0, N / 2) {
		int j = N - 1 - i;
		if (s[i] == s[j]) {
			;
		}
		else {
			diffcnt++;
			diff[i] = diff[j] = 1;
		}
	}
	// 回分であるならば、回文でないようにすれば良いので
	// 中心以外を25個やる、で良い
	if (diffcnt == 0) {
		// 回分だった
		FOR(i, 0, N / 2) {
			ans += 50;
		}
	}
	else if (diffcnt == 1) {
		// 1個変えて回分になってしまうやつ
		ans += N * 25;
		ans -= 2;
	}
	else {
		// 変えても問題なし
		ans += N * 25;
	}

	cout << ans << endl;

	return 0;
}