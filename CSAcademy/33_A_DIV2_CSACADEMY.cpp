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

/* -----  2017/10/02  Problem: CS academy 33 A / Link:  https://csacademy.com/contest/round-33/task/bounding-box/ ----- */
/* ------問題------

N点の二次元座標が与えられる。
このN点をすべて内包する最小の長方形の面性は。

-----問題ここまで----- */
/* -----解説等-----

各座標の最大と最小をとるとそれが最小の長方形の座標になる

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  int xmin = INF;
  int xmax = -INF;
  int ymin = INF;
  int ymax = -INF;
  FOR(i, 0, N) {
	  int x, y; cin >> x >> y;
	  xmin = min(xmin, x);
	  xmax = max(xmax, x);
	  ymin = min(ymin, y);
	  ymax = max(ymax, y);
  }
  ans = abs(xmax - xmin)*abs(ymin-ymax);
  cout << ans << endl;

  return 0;
}
