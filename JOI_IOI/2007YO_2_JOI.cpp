#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)

/* -----  2017/03/27  Problem: JOI莠磯∈2007 2 / Link: http://www.ioi-jp.org/joi/2006/2007-yo-prob_and_sol/2007-yo-problems/2007-yo-t2/2007-yo-t2.html  ----- */
/* ------蝠城｡

JOI大学のM教授はプログラミングの授業を担当している． 
クラスには30人の受講生がいて各受講生には1番から30番までの出席番号がふられている． この授業の課題を28人の学生が提出した．
提出した28人の出席番号から提出していない2人の出席番号を求めるプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

30とサイズが小さいので昇順に並び替えていない人を前から検出していけばよい。

----解説ここまで---- */


int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int a[28];
  FOR(i, 0, 28) {
      cin >> a[i];
  }
  sort(a, a + 28);
  int x = 0;
  FOR(i, 1, 30+1) {

      if (i != a[x]) {
          cout << i << endl;
      }
      else x++;
  }

  return 0;
}
