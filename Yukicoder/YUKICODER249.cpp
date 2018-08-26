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

/* -----  2018/08/26  Problem: yukicoder 249  / Link: http://yukicoder.me/problems/no/249  ----- */
/* ------問題------

あなたとGrantは、いわゆる「21言っちゃダメゲーム（棒取りゲームというところも）」をしている。

このゲームを何度やっても負けてばかりなので、ルールを拡張して正整数 N と K を使って以下のゲームを考える。

1. まず先攻のプレイヤーは 0 が与えられる。
2. そこから N 以上を宣言しないように（宣言したら負けになる）与えられた整数に 1～K のどれかの整数を加算したものを宣言し相手プレイヤーに渡す。
3. 勝負がつくまで代わり代わりに 2. を繰り返す。
このゲームは、NとKが決まったら、先手・後手、どちらが勝つかわかることが知られています。

このとき、N,K を変えて、1000 回ゲームを行うことにする。
まず最初のゲームはあなたが先攻としてゲームを開始します。
2 回目以降のゲームでは、その前のゲームで負けたプレイヤーが自由に先攻か後攻かを選べます。
あなたもGrantもできるだけ勝つ回数が多くなるようにプレーするとしたとき、あなたが勝つ回数を求めてください。
あらかじめすべてのゲームのN,Kは分かっているものとする。

-----問題ここまで----- */
/* -----解説等-----

好きだだけ選択できるとすると、500:500にしかならない

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int ans = 500;
	cout << ans << "\n";

	return 0;
}
