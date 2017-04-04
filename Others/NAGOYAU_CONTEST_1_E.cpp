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

/* -----  2017/04/05  Problem:  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

ll N,M,T;

ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N>>M>>T;
  int a[110];
  FOR(i, 0, N) {
      cin >> a[i];
  }
  int nt = 0;
  int ns = 0;
  if (a[0] - M >= 0)ans += a[0] - M;
  ns = a[0] - M;
  nt = a[0] + M;
  FOR(i, 0, N-1) {
      if (nt >= a[i + 1] - M) {
          nt = a[i + 1] + M;
      }
      else {
          ans += (a[i + 1] - M - nt);
          ns = a[i + 1] - M;
          nt = a[i + 1] + M;
      }
  }
  if (T >= nt)
      ans += (T - nt);

  cout << ans << endl;

  return 0;
}
