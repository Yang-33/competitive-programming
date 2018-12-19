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

/* -----  2018/12/19  Problem: codefestival2014_team_relay D / Link: __CONTEST_URL__  ----- */
/* ------問題------

X さんとY さんはFUという名前のゲームで遊んでいます。
このゲームは、縦横ともに長さ n で n×n 個の正方形のマスに区切られた盤面とFUという駒を用いて行われ、X さんは盤面の最上行の各マスに 1 つずつ自分のFUを下向きに、Y さんは盤面の最下行の各マスに 1 つずつ自分のFUを上向きに置いたところから始まります。
プレイヤーは以下のルールに従い、交互に自分のFUをひとつ選んで移動させるということを繰り返します。
X さんのFUは、現在置かれているマスの下に隣接するマスへしか移動できません
Y さんのFUは、現在置かれているマスの上に隣接するマスへしか移動できません
自分のFUを相手のFUと同一マスに置くことで、相手のFUを取ります
このゲームでは、自分の手番をパスすることや、二度続けて自分のFUを動かすことはできません。相手のFUをすべて取ったプレイヤーが勝ちです。
ぬまくんさんは X さんと Y さんの試合を途中から観戦したのですが、どちらが先手か聞いても、X さんと Y さんは試合に深く集中しているため、答えてくれません。幸い、試合は始まったばかりでどちらも相手のFUを取っていないので、盤面の状態からどちらが先手かわかるかもしれません。
そこで、現在の盤面の状態を入力に受け取って、どちらが先手かを求めるプログラムを作成してください。

-----問題ここまで----- */
/* -----解説等-----

vaildな盤面でかつコマを回収してないと書いてあるので何手進んだ局面であるかは上下から見れば分かる。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VS vs(N);
	FOR(i, 0, N) {
		cin >> vs[i];
	}
	int X = 0, Y = 0;
	FOR(j, 0, N) {
		FOR(i, 0, N) {
			if (vs[i][j] == 'X') {
				X += i;
				break;
			}
		}
		FORR(i, N - 1, 0 - 1) {
			if (vs[i][j] == 'Y') {
				Y += N - i - 1;
				break;
			}
		}
	}

	if (X == Y) {
		cout << "Impossible" << endl;
	}
	else {
		cout << "XY"[X < Y] << endl;
	}
	return 0;
}