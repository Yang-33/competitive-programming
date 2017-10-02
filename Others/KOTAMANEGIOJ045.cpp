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

/* -----  2017/10/02  Problem: Kotamanegi OJ 045  / Link: https://kotamanegi.com/JudgeSystem/Problems/view/index.php?page=45  ----- */
/* ------問題------

こたまねぎ君達は航海のために船を買ったのですが、前日に船が水に浮かばない欠陥船だという事がわかってしまいました。
詐欺に遭ってしまった彼らはどうにかして大きな船を調達したいのですが、もうお金がありません。
そこで、この欠陥船をのこぎりで2つに切って、水に浮かぶようにするというアイデアを採用することになりました。
あなたの仕事は、できるだけ多くの物資を乗せるために、切った船の大きさが最大になるような切り方を提案する事です。
欠陥船はn等分でき、それぞれの部分iについて浮力はAiです。
切った後の船の浮力の和が0以上の時、船は浮きます。

追記 船を三つ以上に切ることはできません。

-----問題ここまで----- */
/* -----解説等-----

三つ以上に切れないので、これはi番目で切断するかしないかの二択。
累積和をもっておけば即時に切断位置について値のチェックができる。

----解説ここまで---- */

ll N;
ll a[100005];
ll sum[100005];
ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  FOR(i, 0, N) {
	  cin >> a[i];
	  sum[i + 1] = sum[i] + a[i];
  }
  FOR(i, 1, N+1) {
	  ll l = sum[i];
	  ll r = sum[N]-sum[i];
	  if (l >= 0)ans = max(ans, i);
	  if (r >= 0)ans = max(ans, N-i);
  }
  if (ans == 0)ans = -1;
  cout << ans << endl;

  return 0;
}
