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

/* -----  2017/10/28  Problem: Snackdown qual 2017  SNAKPROC / Link: https://www.codechef.com/SNCKQL17/problems/SNAKPROC  ----- */
/* ------問題------

is strings (HT)* ?

-----問題ここまで----- */
/* -----解説等-----

実査に前から交互になっているかシュミレーションする

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  FOR(_i, 0, N) {
	  ll num; cin >> num;
	  string s; cin >> s;
	  int x = 0;
	  bool f = 1;
	  FOR(i, 0, s.size()) {
		  if (s[i] == 'H') {
			  x++;
			  if (x != 1)f = false;
		  }
		  if (s[i] == 'T') {
			  if (x == 1)x = 0;
			  else f = false;
		  }
	  }
	  if (x != 0)f = false;
	  if (f) {
		  cout <<"Valid" << endl;
	  }
	  else {
		  cout << "Invalid" << endl;
	  }
  }

  return 0;
}
