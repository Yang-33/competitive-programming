#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
/* -----  2017/04/02  Problem: JOI予選 2010 2  / Link: https://www.ioi-jp.org/joi/2009/2010-yo-prob_and_sol/2010-yo-t2/2010-yo-t2.html  ----- */
/* ------問題------

JOI さんは一人ですごろく遊びをしている． このすごろくには一直線上に N 個のマスがあり，それぞれ移動の指示が書かれている．
スタート地点は 1 マス目であり，ゴールはNマス目である． JOI さんはゴールするまで次を繰り返す．

サイコロを振って出た目の数だけ現在のマスから進み，そのマスの指示に従う． 指示に従って移動した先のマスの指示には従わない．
ちょうど N マス目に止まる時だけでなく，移動先が N マス目を超える場合もゴールとなる．
すごろくの盤面と， M 回分のサイコロの出る目が与えられたとき，サイコロを何回振ったところでゴールするかを出力するプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

シュミレーション可能なサイズなのでルール通りに実装する。実装によっては配列外アクセスで撃墜できそう。

----解説ここまで---- */

ll N,M;

ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N>>M;
  int masu[1010];
  int sai[1010];
  FOR(i, 0, N)cin >> masu[i];
  FOR(i, 0, M)cin >>sai[i] ;

  int pos = 1;
  FOR(i, 0, M) {
      ans = i + 1;
      pos += sai[i];
      if (pos >= N)break;
      pos += masu[pos - 1];
      if (pos >= N)break;

  }
  cout << ans << endl;

  return 0;
}
