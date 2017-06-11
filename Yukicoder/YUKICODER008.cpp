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

/* -----  2017/06/11  Problem: yukicoder008 / Link: http://yukicoder.me/problems/no/8  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

ゲーム理論の問題。
Kだけ値を進められるとき、N-(k+1)番目の値をいう必要のある人が負ける。出る。
また、N-k-1番目の値をいわないようにするためにはN-2(k+1)をいわなければよい。
これを帰納的に繰り返せば、自分のターンにN-s(k+1)をいわなければよい。
相手にこれを言わせることができればあなたの勝ちなので、
じぶんが N-1≡0(mod(k+1))の地点にいるかどうかを確認すれば良い。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  FOR(i, 0, N) {
	  int n, k;
	  cin >> n >> k;
	  if ((n - 1) % (k + 1) != 0)cout << "Win" << endl;
	  else cout << "Lose" << endl;
  }

  return 0;
}
