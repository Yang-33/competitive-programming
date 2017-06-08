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

/* -----  2017/04/29  Problem: ARC 073 A / Link: http://arc073.contest.atcoder.jp/tasks/arc073_a  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

連続する区間幅がT未満ならその差を、T以上ならTを加算していけばよい。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  ll t;
  cin >> N>>t;
  ll a[200010];

  FOR(i, 0, N) {
	  cin >> a[i];
  }
  a[N] = a[N-1]+t;
  int now = 0;
  FOR(i, 0, N) {
	  if (a[i] + t >= a[i + 1])ans += a[i + 1] - a[i];
	  else ans += t;
  }


  cout << ans << endl;

  return 0;
}
