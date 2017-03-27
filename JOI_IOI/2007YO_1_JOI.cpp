#include <iostream>
#include <algorithm>
using namespace std;

/* -----  2017/03/27  Problem: JOI莠磯∈ 2007 1 / Link: http://www.ioi-jp.org/joi/2006/2007-yo-prob_and_sol/2007-yo-problems/2007-yo-t1/2007-yo-t1.html  ----- */
/* ------蝠城｡

JOI高校の2人の生徒 A さんと B さんは， 情報，数学，理科，英語の4教科の試験を受けた．
A さんと B さんのこれら4教科の得点が与えられると， Aさんの合計点 S と Bさんの合計点 T のうち大きな方を出力するプログラムを作成せよ．
ただし， 同点の場合は S (= T) を出力せよ．

-----問題ここまで----- */
/* -----解説等-----

最大値をとろう。

----解説ここまで---- */


int ans = 0;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int a, b, c, d, e, f, g, h;
  cin >> a >> b >> c >> d;
  cin >> e >> f >> g >> h;
  ans = max(a + b + c + d, e + f + g + h);
  cout << ans << endl;

  return 0;
}
