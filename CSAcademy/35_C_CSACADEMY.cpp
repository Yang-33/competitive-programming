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

/* -----  2017/10/02  Problem: CS academy 35 D / Link: https://csacademy.com/contest/round-35/task/least-even-digits/  ----- */
/* ------問題------

N*Nの盤面がある。(a[i][j])
最小手順で魔法陣的なやつをつくれ

-----問題ここまで----- */
/* -----解説等-----

縦と横の総和が一緒でなくてはならないので、先にその値を求める。
その後値の不足分を貪欲に埋めていけばよい。

----解説ここまで---- */

ll N;
int a[1000][1000];
int r[1000];
int c[1000];
ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  FOR(i, 0, N) {
	  FOR(j, 0, N) {
		  cin >> a[i][j];
	  }
  }
  int mx = 0;
  FOR(i, 0, N) {
	  FOR(j, 0, N) {
		  r[i] += a[i][j];
	  }
	  mx = max(mx, r[i]);
  }
  FOR(j, 0, N) {
	  FOR(i, 0, N) {
		  c[j] += a[i][j];
	  }
	  mx = max(mx, c[j]);
  }
  FOR(i, 0, N) {
	  FOR(j, 0, N) {
		  int add = mx - max(r[i], c[j]);
		  r[i] += add;
		  c[j] += add;
		  a[i][j] += add;
		  cout << a[i][j] << " ";
	  }
	  cout << endl;
  }

  //cout << ans << endl;
  return 0;
}
