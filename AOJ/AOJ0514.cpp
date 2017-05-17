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


ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int s[400];
  int x[1010];
  int y[1010];
  int z[1010];
  vector<int >v;
  while (1) {
	  vector<int >v;

	  int a, b, c, n; cin >> a >> b >> c;
	  if (a == 0 && b == 0 && c == 0)break;
	  cin>> n;
	  FOR(i, 0, 400)s[i] = 2;// わからん

	  FOR(i, 0, 1010)x[i] = y[i] = z[i] = 0;
	  FOR(i, 0, n) {
		  int p;
		  cin >> x[i] >> y[i] >> z[i] >> p;
		  x[i]--; y[i]--; z[i]--;
		  if (p == 1) {
			  s[x[i]] = 1;
			  s[y[i]] = 1;
			  s[z[i]] = 1;
		  }
		  else v.push_back(i);
	  }
	  //以降１にはならない2->0とするだけ
	  FOR(j, 0, v.size())
		  FOR(ii, 0, v.size()) {

		  int i = v[ii];

		  if (s[x[i]] == 1 && s[y[i]] == 1)s[z[i]] = 0;
		  else if (s[x[i]] == 1 && s[z[i]] == 1)s[y[i]] = 0;
		  else if (s[z[i]] == 1 && s[y[i]] == 1)s[x[i]] = 0;
	  }

	  FOR(i, 0, a + b + c)
		  cout << s[i] << endl;
  }
  return 0;
}
