#include <bits/stdc++.h>
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

/* -----  2018/04/23  Problem: yukicoder 102  / Link: http://yukicoder.me/problems/no/102  ----- */
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

最後に勝てば完全に勝てるので、最後だけ見れば良い
grundy数は各山について (枚数)%4

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	FOR(i, 0, 4) {
		int a; cin >> a;
		ans ^= a % 4;
	}

	cout << (ans?"Taro":"Jiro") << "\n";

	return 0;
}
