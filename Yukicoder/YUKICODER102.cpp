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

/* -----  2017/09/14  Problem: yukicoder102  / Link: https://yukicoder.me/problems/no/102  ----- */
/* ------問題------

太郎君と次郎君は机の上に、トランプのカードのうち何枚かをスート（♤♡♢♧）別に重ねて置いてあるのを見つけました。
そこで二人は、これらを４つの山としてゲームをすることにしました。

ゲームのルールは以下の通りです。
・場に４つの山が用意される。
・プレイヤーは交互に山からカードを取り手札とする
　・１回に取れるのは１つの山から１枚～３枚のみ（複数の山からまとめてとることはできない）
 　・パスはできず必ず１枚はカードを取らなければならない
  ・４つの山それぞれについて、最後のカードを取った場合、相手の手札の半分（奇数枚の場合は切り上げ）を奪うことができる
  ・すべての山が無くなったとき、手札が多いほうが勝ち

  太郎君と次郎君は透視能力があるため山の残り枚数が分かるうえ、テレパシーで相手の心が読めるため、常に最善手でゲームを進めることができます。

  ４つの山にあるカードの枚数が与えられるので、
  太郎君が先行でゲームを始めた場合に太郎君と次郎君のどちらが勝つかを出力してください。

-----問題ここまで----- */
/* -----解説等-----

解法1はメモ化再帰。
N^4ぐらいでまわるので間に合う。通常のゲーム
解法2は問題をよく読む。
最後にカードをとれば盤面のカード+相手の半分のカードを手に入れることができるのでうれしい気持ちになれる。
したがってただのNimになる。

----解説ここまで---- */


// 解法1
//vector<int> n(4, 0);
//int a[14][14][14][14];
//
//int f() {
//	int& ret = a[n[0]][n[1]][n[2]][n[3]];
//	if (accumulate(n.begin(), n.end(), 0) == 0) return 0;
//
//	if (ret != -1)return ret;
//	ret = 0;
//	FOR(j, 0, 4) {
//		FOR(i, 1, min(n[j], 3) + 1) {
//			n[j] -= i;
//			if (f() == 0)ret = 1;
//			n[j] += i;
//		}
//	}
//	return ret;
//}
//
//int main() {
//	cin.tie(0);
//	ios_base::sync_with_stdio(false);
//
//	FOR(i, 0, 4)cin >> n[i];
//	FOR(i, 0, 14)FOR(j, 0, 14)FOR(k, 0, 14)FOR(l, 0, 14)a[i][j][k][l] = -1;
//
//	if (f())cout << "Taro" << "\n";
//	else cout << "Jiro" << "\n";
//
//	return 0;
//}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int grundy = 0;

	FOR(i, 0, 4) {
		int a; cin >> a;
		grundy ^= (a % 4);
	}
	cout << ((grundy != 0) ? "Taro" : "Jiro") << "\n";

}
