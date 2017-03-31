#include <iostream>
#include <string>
using namespace std;

typedef long long ll;
#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)

/* -----  2017/03/31  Problem: JOI予選 2008 2  / Link: http://www.ioi-jp.org/joi/2007/2008-yo-prob_and_sol/2008-yo-t2/2008-yo-t2.html  ----- */
/* ------問題------

与えられた文字列内の連続する3文字が，JOIまたはIOIという並びになっている個所がそれぞれ何個所あるのかを数え上げるプログラムを作成せよ．
文字列はアルファベットの大文字だけからなる．
例えば下図の「JOIOIOI」という文字列にはJOIが1個所，IOIが2個所に含まれている．

-----問題ここまで----- */
/* -----解説等-----

愚直にチェック。

----解説ここまで---- */

string N;

ll ans1 = 0LL;
ll ans2 = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  FOR(i, 0, N.size() - 2) {
      if (N.substr(i, 3) == "JOI")ans1++;
      if (N.substr(i, 3) == "IOI")ans2++;
  }
  cout << ans1 << endl;
  cout << ans2 << endl;

  return 0;
}
