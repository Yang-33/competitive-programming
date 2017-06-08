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

/* -----  2017/04/29  Problem: ARC 073 B / Link: http://arc073.contest.atcoder.jp/tasks/arc073_b  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

dp[現在選択可能な範囲][現在の重さ][現在選んだ個数]としてdpを回す。
これだけでは重さの制限に引っかかってしまうので、重さに着目するとW0に対して＋３の範囲内になることがわかる。
したがってw0ぐらい引いておいた状態を見ればオーダーがい感じに落ちる。
答えは選択可能な個数をi個として、
dp[N][j][i] ただしW-W0*i+j≧0を満たすもののうちの最大値。

----解説ここまで---- */

ll N;

ll ans = 0LL;
ll dp[200][600][200];
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  ll W;
  ll w[105];
  ll v[105];
  cin >> N>>W;
  FOR(i, 0, N) {
	  cin >> w[i] >> v[i];
  }
  ll ww = w[0];
  FORR(i, N-1, -1) {
	  w[i] -= (ww);
	 // cout << w[i] << endl;
  }
  //w
  
  FOR(i, 0, N) {//new
	  FOR(j, 0, 350) {
		  FOR(k, 0, N+1) {
			  if (j - w[i] < 0 || k - 1 < 0) {
				  dp[i + 1][j][k] = dp[i][j][k];
			  }
			  else {
				  dp[i + 1][j][k] = max(dp[i][j][k], dp[i][j - w[i]][k - 1] + v[i]);
			  }
		  }
	  }
  }

  //FOR(i, 0, N) {
	 // FOR(j, 0, 405) {
		//  if (j - w[i] >= 0) {
		//	  dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - w[i]] + v[i]);
		//  }
		//  else {
		//	  dp[i + 1][j] = dp[i][j];
		//  }
	 // }
  //}
  ans = -1;

  FOR(i, 1, N + 1) {
	  FOR(j, 0, i * 3 + 1) {
		  ll k = (ww )*i + j;
		  if (W - k >= 0)
			  ans = max(ans, dp[N][j][i]);
	  }
  }
  if (ans == -1)ans = 0;
  cout << ans << endl;

  return 0;
}
