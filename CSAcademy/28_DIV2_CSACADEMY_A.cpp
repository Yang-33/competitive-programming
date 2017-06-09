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

/* -----  2017/06/09  Problem: CSAcadeny 28 A / Link:  https://csacademy.com/contest/round-28/ ----- */
/* ------問題------

Nが与えられる。このNが奇数なら1を足す。偶数なら2で割る。これを1になるまで繰り返す。
何回で1になるか。

-----問題ここまで----- */
/* -----解説等-----

2で割る動作が2回に一回は起きるので愚直にやって間に合う。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  while (N != 1) {
	  if (N % 2 == 1)N++, ans++;
	  else N = N / 2, ans++;
  }
  cout << ans << endl;

  return 0;
}
