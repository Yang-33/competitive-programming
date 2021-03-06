#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
const ll MOD = 100000;

/* -----  2017/03/31  Problem: JOI予選 2009 6  / Link: https://www.ioi-jp.org/joi/2008/2009-yo-prob_and_sol/2009-yo-t6/2009-yo-t6.html  ----- */
/* ------問題------

あるプログラミングコンテストでは， 競技後の懇親会でビンゴゲームをする習わしがある． 
しかし， このビンゴゲームで使うビンゴカードは少々特殊で， 以下の条件に従って作成される．
ビンゴカードは N 行 N 列のマス目に区切られており， 各マス目には正整数が１つずつ書かれている． それらの整数は全て異なる．
マス目に書かれている整数は 1 以上 M 以下である．
ビンゴカードに書かれているN×N個の整数の合計は S である．
どの列を見たときも， 上から下に向かって整数は昇順に並んでいる．
どのマス目の整数も， そのマス目より左の列のどの整数よりも大きい．
以下は， N = 5, M = 50, S = 685 のときのビンゴカードの例である．


懇親会のために上の条件を満たすビンゴカードをできるだけたくさん作りたい．
ただし， 同一のカードを2枚以上作ってはならない． 作ることができるビンゴカードの枚数の最大値を 100000 で割った余りを出力するプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

 dp[ 見ている個所 ][ 現在の使った数字の総和 ] := 現在可能な組み合わせ
 として値を渡す。
 dp(j,l)=dp(j,l)+dp(j-1,l-i)  i[1,M],j[n,1],l[0,S]　と定義すれば使う数字がiなので l <(+i)= l-i
 としてM以下のiについて、Sに到達するものを数え上げることができる。
 どはつさんの二重ループ解法は解法は天才過ぎて理解できなかった。

----解説ここまで---- */

ll N,M,S;

ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> M >> S;
  ll dp[50][3010];
  FOR(i, 0, 50)FOR(j, 0, 3010)dp[i][j] = 0;
  dp[0][0] = 1;
  ll n = N*N;
  FOR(i, 1, M + 1)
      FORR(j, n, 0)
          FOR(l, i, S + 1) {
      dp[j][l] = (dp[j][l] + dp[j - 1][l - i]) % MOD;
  }

  ans = dp[n][S];
  cout << ans << endl;

  return 0;
}
