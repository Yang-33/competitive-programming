//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i, s, t) for (int i = s; i < t; i++)
/* -----  2017/03/22  Problem: RUPC2017 DAY1 B / Link:
 * http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=RitsCamp17Day1&pid=B
 */
/* ------問題------

リンク参照

-----問題ここまで----- */
/* -----解説等-----

作りたいグループ数はlcm(N,M)/Mでつくることができるので各グループの中に
a[i]を入れていけばよい。vectorで持つといいかんじにsortできるので最小値と最大値を簡単に取り出すことができる。
初団体戦はすぐに実装できたが添え字が違っていたことで答えがおかしくなり焦ったがWAなしでAC。

----解説ここまで---- */

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main() {
  int M, N;
  int a[1010];
  cin >> N >> M;
  FOR(i, 0, N) {
    cin >> a[i];
    //
  }

  int T = lcm(N, M) / M;
  vector<int> box[T];
  int next = 0;

  FOR(i, 0, T) {
    FOR(j, 0, M) {
      box[i].push_back(a[(next + j) % N]);
      //
    }
    next = (next + M) % N;
  }

  long long ans = 0;
  FOR(i, 0, T) {
    sort(box[i].begin(), box[i].end());
    ans += (box[i][M - 1] - box[i][0]);
  }

  cout << ans << endl;
}
