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

/* -----  2017/05/17  Problem:  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

ll N,K;
ll a[100010];

ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  while (1) {
	  cin >> N >> K;
	  if (N == 0)break;
	  FOR(i, 0, N) {
		  cin >> a[i];
	  }
	  ll sum = 0;
	  FOR(i, 0, K) {
		  sum += a[i];
	  }

	  ans = -LINF;
	  ans = max(ans, sum);
	  FOR(i, 0, N - K) {
		  sum -= a[i];
		  sum += a[i + K];
		  ans = max(ans, sum);
	  }

	  cout << ans << endl;
  }
  return 0;
}
