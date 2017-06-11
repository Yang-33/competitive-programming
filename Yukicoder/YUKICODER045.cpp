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

/* -----  2017/06/11  Problem: yukicoder045 / Link: http://yukicoder.me/problems/no/45  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

dp[ お寿司の番号 ]:=　この番号から始めたときのお寿司の最大おいしさ
として、お寿司を食べるときは次のお寿司を食べてない状態での最適値を現在の値に加算する。
お寿司を食べない方が最適な場合もあるので食べない場合、すなわち次を食べる場合の最適値を現在の値にする。
このため、このMAXを保存して後ろからみていけばよい。
前からでもできた。後ろ2つ目からとるときは食べてもよいときで、直近の後ろからとるときは食べてはいけないとしてループすればよい。

----解説ここまで---- */

ll N;
ll v[1010];
ll dp[1010];
ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  FOR(i, 0, N) {
	  cin >> v[i];
  }
  FOR(i, 0, 1010)dp[i] = 0;
  FORR(i, N - 1, -1) {
	  ll res = 0;
	  FOR(j, i+2, N) {
		  res = max(res, dp[j]);
	  }
	  dp[i] = max(dp[i + 1], v[i] + res);
  }
  ans = dp[0];
  cout << ans << endl;

  return 0;
}
