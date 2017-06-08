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

/* -----  2017/06/03  Problem: ARC 075 A / Link: http://arc075.contest.atcoder.jp/tasks/arc075_a  ----- */
/* ------問題------

点数s(i)が与えられる。総和が10の倍数になるときこの採点マシンは壊れてしまう。採点マシンがだすことのできる最大値は。

-----問題ここまで----- */
/* -----解説等-----

dp[得られる得点]:=はい/いいえ
として0-1ナップザックをすれば得点の取りうる組み合わせを全列挙できる。
あとは上からみていって、10の倍数でない最大値をとればよい。

dpができなくても、s(i)の中で10の倍数ではない最小値をもっておけば、
結果が10の倍数であったときにこれを除けば最大の値を得ることができる。


----解説ここまで---- */

ll N;
ll s[105];
ll dp[200000];
ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  FOR(i, 0, N)cin >> s[i];

  dp[0] = 1;
  FOR(i, 0, N) {
	  FORR(j, 15000, -1) {
		  if(dp[j])
		  dp[j+s[i]] = dp[j];
	  }
  }
  FOR(i, 0, 10001) {
	  if (dp[i]&&i%10!=0)ans = max(ans, i);
  }
  cout << ans << endl;

  return 0;
}
