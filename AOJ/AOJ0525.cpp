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


int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  ll N,H,W;
  int m[12][10010];

  ll ans = 0LL;

  while (1) {
	  cin >> H>>W;
	  if (H == 0 && W == 0)break;
	  FOR(i, 0, H)FOR(j, 0, W) {
		  cin >> m[i][j];
	  }
	  int s[12][10010];

	  FOR(i, 0, 1 << H) {
		  FOR(y, 0, H)FOR(x, 0, W)s[y][x] = m[y][x];
		  FOR(j, 0, H) {
			  if (i >> j & 1) {
				  FOR(k, 0, W) {
					  s[j][k] = !(m[j][k]);
				  }
			  }
		  }
		  /*
		  cout << "a------" << endl;
		  FOR(y, 0, H) {
			  FOR(x, 0, W) {
				  cout << s[y][x] << " ";
			  }
			  cout << endl;
		  }
		  cout << "------a" << endl;
		  */
		  ll cnt = 0;
		  FOR(x, 0, W) {
			  int cc = 0;
			  FOR(y, 0, H) {
				  if (s[y][x] == 1) {
					  cc++;
				  }
			  }
			  cc = max(cc, (int)H - cc);
			  cnt += cc;
		  }
		  ans = max(ans, cnt);

	  }

	  cout << ans << endl;
  }

  return 0;
}
