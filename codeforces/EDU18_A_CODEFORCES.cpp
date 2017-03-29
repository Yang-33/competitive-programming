#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
const ll LINF = 1e16;
/* -----  2017/03/28  Problem: codeforces Educatinal18 A / Link: http://codeforces.com/contest/792/problem/A  ----- */
/* ------問題------

町の位置が与えられるので最小コストで一本の橋を作る。
また最短のものが複数ある場合にはそのペアの総数を求める。

-----問題ここまで----- */
/* -----解説等-----

値をsortし端から順に最短のものを見つけていけばよい。最短のものが複数あればこれをカウントすればよい。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  ll s[200100];
  FOR(i, 0, N) {
      cin >> s[i];
  }
  sort(s, s + N);
  ll min = LINF;
  ll cnt = 0;
  FOR(i, 0, N - 1) {
      ll d = abs(s[i] - s[i + 1]);
      if (min > d) {
          min = d;
          cnt = 1;
      }
      else if (min == d) {
          cnt++;
      }
  }
  cout << min<<" "<<cnt << endl;

  return 0;
}
