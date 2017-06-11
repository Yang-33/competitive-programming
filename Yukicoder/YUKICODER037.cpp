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

/* -----  2017/06/11  Problem: yukicoder037 / Link: http://yukicoder.me/problems/no/37----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

時間に依存しないv[i]をできるだけ詰めることができる。。
500≦2^9なので半分の値を使用するならば10回までしか詰めれない
よって選択可能な個数は150個以下になる。
結局150個での0-1ナップザックをすればよい。

----解説ここまで---- */

ll T,N;
ll c[20];
ll v[20];
ll nv[20][10];
ll dp[10500];
ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> T >> N;
  FOR(i, 0, N)cin >> c[i];
  FOR(i, 0, N)cin >> v[i];

  FOR(i, 0, N) {
	  ll V = v[i];
	  FOR(j, 0, 10) {
		  nv[i][j] = V;
		  V /= 2;
	  }
  }
  FOR(i, 0, N) {
	  FOR(j, 0, 10) {
		  FORR(t,10001,-1){
			  dp[t+c[i]] = max(dp[t+c[i]], dp[t] + nv[i][j]);
			  
		  }
	  }
  }
  FOR(i, 0, T + 1) {
	  ans = max(ans, dp[i]);
  }
  cout << ans << endl;

  return 0;
}
