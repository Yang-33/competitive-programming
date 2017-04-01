#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)

/* -----  2017/03/31  Problem: JOI予選 2009 2  / Link: https://www.ioi-jp.org/joi/2008/2009-yo-prob_and_sol/2009-yo-t2/2009-yo-t2.html  ----- */
/* ------問題------

先日，オンラインでのプログラミングコンテストが行われた． W大学とK大学のコンピュータクラブは以前からライバル関係にあり， このコンテストを利用して両者の優劣を決めようということになった．
今回，この2つの大学からはともに10人ずつがこのコンテストに参加した． 長い議論の末，参加した10人のうち，得点の高い方から3人の得点を合計し，大学の得点とすることにした．
W大学およびK大学の参加者の得点のデータが与えられる． このとき，おのおのの大学の得点を計算するプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

最大値を三つ持っておくか、ソートして上から３つとればよい。

----解説ここまで---- */

ll N;

ll ans[2];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int a[2][10];
  FOR(j,0,2)
  FOR(i, 0, 10)cin >> a[j][i];

  N = 10;
  sort(a[0], a[0] + N);
  sort(a[1], a[1] + N);
  ans[0] = ans[1] = 0;
  FOR(i, 0, 2)FOR(j, 0, 3) {
      ans[i] += a[i][10 - j - 1];
  }
  cout << ans[0] <<" "<<ans[1]<< endl;

  return 0;
}
