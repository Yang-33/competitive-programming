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

/* -----  2018/04/06  Problem: yukicoder 008  / Link: http://yukicoder.me/problems/no/008  ----- */
/* ------問題------

あなたとGrantは、いわゆる「21言っちゃダメゲーム（棒取りゲームというところも）」をしている。

あなたが先攻で、このゲームを何度やっても負けてばかりなので、ルールを拡張して

自然数 NとKを使って以下のゲームを考える。

1. まず先攻のプレイヤーは0が与えられる。
2. そこからN以上を宣言しないように（宣言したら負けになる）与えられた数字の[1,K](1～K)のどれかを加算したものを宣言し相手プレイヤーに渡す。
3. 勝負がつくまで代わり代わりに 2. を繰り返す。

まずあなたが先攻となりゲームを始めます。
この時、どちらも負けないように動くと考え、自然数N,Kが与えられた時、
あなたが勝つことが出来る場合 Win、それ以外は Lose を返す。

このとき、N,Kを変えて、P回ゲームを行うことにする。
それぞれの勝敗を求めてください。

(それっぽいことを知ってる方は簡単ですが、知らない方は難しい考え方が必要かもしれません）

-----問題ここまで----- */
/* -----解説等-----

愚直にgrundy数を出すと計算時間がヤバイので、規則性を発見したい。
連続区間からgurndy数を取り出すときは性質が良くて、今回は周期性がある。
無いときはセグ木でできる。
grundy数は (N-1) % (K+1)
なぜなら、N-1を渡された人は負けで、もう一度負ける目が回ってくるのは、正数しかない連続K区間をもつK+1個小さい値だからである。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N) {
		int n, k; cin >> n >> k;
		ans = (n - 1) % (k + 1);
		cout << (ans == 0 ? "Lose" : "Win") << endl;
	}

	return 0;
}
