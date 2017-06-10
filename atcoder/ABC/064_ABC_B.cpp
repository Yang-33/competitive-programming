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

/* -----  2017/06/10  Problem: ABC 064 B / Link: http://abc064.contest.atcoder.jp/tasks/abc064_b  ----- */
/* ------問題------

クリスマスもあと半年となり、トナカイのAtCoDeer君はプレゼントを配る計画を立てることにしました。
TopCoDeer通りには N 個の家が並んでいます。i 個目の家は座標 ai にあります。彼はこのすべての家にプレゼントを配ることにしました。
好きな場所から開始し好きな場所で終了することができる時、最小の移動距離を求めなさい。

-----問題ここまで----- */
/* -----解説等-----

端から端まで移動するのが最小であることが分かるので昇順に並べ替えて(最大-最小)とすればよい。

----解説ここまで---- */

ll N;
int a[200];
ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  FOR(i, 0, N)cin >>a[i];
  sort(a, a + N);
  ans = a[N-1] - a[0];
  cout << ans << endl;

  return 0;
}
