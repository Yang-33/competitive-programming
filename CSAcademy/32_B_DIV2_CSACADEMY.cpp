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

/* -----  2017/06/09  Problem: CSAcademy 32 B / Link: https://csacademy.com/contest/round-32/task/food-pairing/  ----- */
/* ------問題------

料理を作る。料理の材料n(i)についての今持っている素材の量が与えらえる。
次にM種類の食事について、各食事についてA(j,i)の素材が必要である。
このなかから２つの料理をふるまう際、あなたは何人に料理を作ることができるか。

-----問題ここまで----- */
/* -----解説等-----

どの二つの料理を作るかについて全探索をする。
ある種類の素材を使わない可能性があるのでそこは例外処理をする。

----解説ここまで---- */

ll N,M;
ll n[40];
ll a[600][40];
ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  FOR(i, 0, N) {
	  cin >> n[i];
  }
  cin >> M;
  FOR(i, 0, M) {
	  FOR(j, 0, N) {
		  cin >> a[i][j];
	  }
  }
  FOR(i, 0, M) {
	  FOR(j, 0, M) {
		  if (i == j)continue;
		  ll cnt = LINF;
		  FOR(k, 0, N) {
			  if (a[i][k] + a[j][k] == 0)continue;
			  else  cnt = min(cnt, n[k]/(a[i][k] + a[j][k]));
		  }
		  ans = max(cnt, ans);
	  
	  }
  }


  cout << ans << endl;

  return 0;
}
