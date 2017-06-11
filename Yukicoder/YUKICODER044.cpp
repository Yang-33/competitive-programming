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

/* -----  2017/06/11  Problem: yukicoder044 / Link: http://yukicoder.me/problems/no/44  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

階段状に進むやつとかフィボナッチ数的なやつ。
絵を描いてわかるタイプ。
状態を前に遷移させていこう。

----解説ここまで---- */

ll N;
ll dp[55];
ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  FOR(i, 0, N+1) {
	  dp[i] = 0;
  }
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  FOR(i, 3, N+1) {
	  dp[i] = dp[i-1] + dp[i-2];
  }
  ans = dp[N];
  cout << ans << endl;

  return 0;
}
