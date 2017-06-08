#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

/* -----  2017/04/22  Problem: ARC 072 B / Link: http://arc072.contest.atcoder.jp/tasks/arc072_b  ----- */
/* ------問題------

二人零和有限確定完全情報ゲーム

-----問題ここまで----- */
/* -----解説等-----

なんか書いたらわかるけど正当性は謎。

----解説ここまで---- */

ll N,M;

ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N>>M;
  if (N > M) swap(N, M);
  if (M == N || M == N + 1) cout << "Brown" << endl;
  else cout << "Alice" << endl;
  return 0;
  cout << ans << endl;

  return 0;
}
