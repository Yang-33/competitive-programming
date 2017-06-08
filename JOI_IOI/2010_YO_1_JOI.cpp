#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)

/* -----  2017/04/02  Problem: JOI予選 2010 1  / Link: https://www.ioi-jp.org/joi/2009/2010-yo-prob_and_sol/2010-yo-t1/2010-yo-t1.html  ----- */
/* ------問題------

太郎君は10冊の本を購入した． 後日， レシートをもとに価格を調べようとしたが， レシートには汚れがあり， ある本の価格が読み取れなかった． 
その本の価格を， 10冊の総額と他の9冊の価格から計算することにした．
価格が読み取れなかった本の価格を出力するプログラムを書け． なお，本の価格はすべて正の整数である． また，消費税を考慮する必要はない．

-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  FOR(i, 0, 9) {
      int x; cin >> x;
      N -= x;
  }
  ans = N;
  cout << ans << endl;

  return 0;
}
