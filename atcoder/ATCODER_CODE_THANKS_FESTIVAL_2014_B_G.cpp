#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/07/11  Problem: atcoder code thanks festival 2014 b G 石取りゲーム / Link: http://code-thanks-festival-2014-b-open.contest.atcoder.jp/tasks/code_thanks_festival_14_qualb_g  ----- */
/* ------問題------

N 個の石が積まれた山があり、2 人のプレーヤーが交互にこの山からいくつかの石をとっていくゲームを考えます。最後の石をとったプレーヤーが勝利とし、とれる石の個数は以下のようにして決まります。

一番最初に先手が石をとるときは 1 個以上 P 個以下の好きな個数だけ石をとれます。それ以降については、各プレーヤーは 1 個以上、直前にとられた石の個数 +1 個以下の好きな個数だけ石をとれます。

たとえば、最初に先手が石を 3 個とると、次に後手は 1 個以上 4 個以下の石をとることができます。そこで後手が 2 個の石をとったとすると、次に先手は 1 個以上 3 個以下の石をとることができます。

N と P が決まっていれば、先手か後手のどちらかに必勝法があります。N と P が与えられるので、先手と後手のどちらが必勝であるかを判定するプログラムを作成してください。

-----問題ここまで----- */
/* -----解説等-----

全状態を検査し、最終状態の、勝ちのものから各状態の勝ち負けを決定していく。
n<=pのとき最後の石をとれるので勝ちが確定する。よって前の状態が勝ちであれば現状態は負け、
前の状態が負けであれば現状態は勝ちとなる手が存在する。
これを再帰的に探索すればよい。

----解説ここまで---- */

ll N, P;
int gmemo[501][501];
int game(int n, int p) {
	if (gmemo[n][p] != -1)return gmemo[n][p];
	if (n <= p)return 1;
	gmemo[n][p] = 0;
	FOR(i, 1, p+1) {
		if (game(n - i, i+1) == 0)gmemo[n][p] = 1;
	}
	return gmemo[n][p];
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> P;
	FOR(i, 0, 501)FOR(j, 0, 501)gmemo[i][j] = -1;

	if (game(N, P)==1)
		cout << "first" << endl;
	else
		cout << "second" << endl;

	return 0;
}
