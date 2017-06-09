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

/* -----  2017/06/09  Problem: CSAcademy 32 A / Link: https://csacademy.com/contest/round-32/task/next-dance-move/  ----- */
/* ------問題------

1,2,3,1,2,3,1,2,3,4 のリズムで構成されるダンスがある。
N番目のリズムは何番を行っていればいいか。

-----問題ここまで----- */
/* -----解説等-----

周期が10なので埋め込む。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  N--;
  int a[] = { 1,2,3,1,2,3,1,2,3,4 };
  N %= 10;
  ans = a[N];
  cout << ans << endl;

  return 0;
}
