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

/* -----  2017/05/12  Problem:  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  string s;
  int n;
  vector<pair<string, int>>v;
  while (cin >> s >> n) {
	  v.push_back(mp(s, n));
  }

  sort(v.begin(), v.end());
  cout << v[0].first << endl;
  cout << v[0].second;


  FOR(i, 1, v.size()) {
	  if (v[i].first == v[i - 1].first) {
		  cout << " " << v[i].second;
	  }
	  else {
		  cout << endl;
		  cout << v[i].first << endl;
		  cout << v[i].second;
	  }

  }
  cout << endl;

  return 0;
}
