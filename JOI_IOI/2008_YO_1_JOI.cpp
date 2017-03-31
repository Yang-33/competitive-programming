#include <iostream>
using namespace std;
typedef long long ll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)

/* -----  2017/03/31  Problem: JOI予選 2008 1  / Link: http://www.ioi-jp.org/joi/2007/2008-yo-prob_and_sol/2008-yo-t1/2008-yo-t1.html  ----- */
/* ------問題------

太郎君はよくJOI雑貨店で買い物をする． JOI雑貨店には硬貨は500円，100円，50円，10円，5円，1円が十分な数だけあり，いつも最も枚数が少なくなるようなおつりの支払い方をする．
太郎君がJOI雑貨店で買い物をしてレジで1000円札を1枚出した時，もらうおつりに含まれる硬貨の枚数を求めるプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

最大硬貨で払えそうなら払える分だけ払えばよい。
よくよく考えたら場合分けいらない。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  int c[] = { 500,100,50,10,5,1 };
  int l = 1000 - N;
  FOR(i, 0, 6) {
      int m = l / c[i];
      if (m) {
          ans += m;
          l -= m*c[i];
      }
  }
  cout << ans << endl;

  return 0;
}
