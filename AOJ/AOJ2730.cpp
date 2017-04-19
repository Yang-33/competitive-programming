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

/* -----  2017/04/19  Problem:  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

なんか実験的に小さいサイズのものを><で囲うと、全部通ることができることに気が付く。
またこれは右でも左でも脱出することができる。
また端が<<<<>...<>>のとき、>...<から右に出たほうが嬉しい、ということを考えると
左端では<<の数、右端では>>>の数がわかればそのうち小さい方を列の長さから引けばよいことになる。
実験は大事だなあ。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  string S;
  cin >> S;
  int l = 0, r = 0;

  FOR(i, 0, S.size()) {
	  if (S[i] == '<')r++;
	  else break;

  }
  FORR(i, S.size() - 1, -1) {
	  if (S[i] == '>')l++;
	  else break;
  }
  ans = (N - min(r, l));

  cout << ans << endl;

  return 0;
}
