#include <iostream>
using namespace std;

/* -----  2017/03/22  Problem: RUPC2017 DAY1 A / Link:
 * http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=RitsCamp17Day1&pid=A
 */
/* ------問題------

リンク参照

-----問題ここまで----- */
/* -----解説等-----

本来N-１試合必要だが、一人休むごとに１試合減っていくのだからN-M-1試合必要になる。
愚直にシュミレーションしても間に合う。

----解説ここまで---- */

int main() {
  int N, M;
  cin >> N >> M;
  cout << N - M - 1 << endl;
  return 0;
}