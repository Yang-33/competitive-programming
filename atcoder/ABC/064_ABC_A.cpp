#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

/* -----  2017/06/10  Problem: ABC 064 A / Link: http://abc064.contest.atcoder.jp/tasks/abc064_a  ----- */
/* ------問題------

AtCoDeer君は、赤、緑、青色のカードを持っています。
それぞれのカードには 1 以上 9 以下の整数が書かれており、赤色のカードには r、緑色のカードには g、青色のカードには b が書かれています。
3 つのカードを左から順に赤、緑、青色の順に並べ、左から整数を読んだときにこれが 4 の倍数であるか判定しなさい。

-----問題ここまで----- */
/* -----解説等-----

4の倍数かどうかの判定は100が4の倍数であるから下二けたについて4の倍数であるかを確認すればよい。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int r, g, b;
  cin >> r>>g>>b;
  int x = 10 * g + b;
  if(x%4==0)
	  cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}
