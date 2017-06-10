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

/* -----  2017/06/10  Problem: ABC 064 C / Link: http://abc064.contest.atcoder.jp/tasks/abc064_c  ----- */
/* ------問題------

AtCoderでは、コンテストに参加すると「色」が付き、これはレートによって次のように変化します：

レート 1-399：灰色
レート 400-799：茶色
レート 800-1199：緑色
レート 1200-1599：水色
レート 1600-1999：青色
レート 2000-2399：黄色
レート 2400-2799：橙色
レート 2800-3199：赤色
また、レートが 3200 以上になると色を自由に変えることができます。
現在 N 人の人がAtCoderのコンテストに参加したことがあり、i 人目の人のレートは ai です。
そのとき、色の種類数の最小値と最大値を求めなさい。

-----問題ここまで----- */
/* -----解説等-----

「     紫     色     」
最小の場合はtargetの人が一か所に固まる、
そうでない場合は取れる色を全部とれば最大値と最小値を得ることができる。

----解説ここまで---- */

ll N;
int c[10];

ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  int a[200];
  FOR(i, 0, N) {
	  cin >> a[i];
  }
  FOR(i, 0, N) {

	  if (a[i] < 400)c[0]++;
	  else if (a[i] < 800)c[1]++;
	  else if (a[i] < 1200)c[2]++;
	  else if (a[i] < 1600)c[3]++;
	  else if (a[i] < 2000)c[4]++;
	  else if (a[i] < 2400)c[5]++;
	  else if (a[i] < 2800)c[6]++;
	  else if (a[i] < 3200)c[7]++;
	  else c[8]++;
  }

  int x = c[8];
  
  FOR(i, 0, 8) {
	  if (c[i] > 0)ans++;
  }
  ans += c[8];
  int ans2 = 0;
  FOR(i, 0, 8) {
	  if (c[i] > 0)ans2++;
  }
  if (ans2 == 0 && x != 0)ans2 = 1;
  cout << ans2<<" "<<ans << endl;

  return 0;
}
