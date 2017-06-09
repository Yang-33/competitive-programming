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

/* -----  2017/06/09  Problem: CSAcadeny 28 B / Link:  https://csacademy.com/contest/round-28/ ----- */
/* ------問題------

数列{1,2,3,...,N}が与えられる。
M回の命令が来る。次の命令をすべて実行し終えた後の値Kの位置を出力せよ。
・(0,b)のとき
あたまからbこの数列を反転させる。
・(1,a)
後ろからaこの数列を反転させる。

-----問題ここまで----- */
/* -----解説等-----

Kの位置だけをみていればよい。
あたまから反転させる際にKが含まれていれば反転させる区間の長さから反対の位置に動かす。(1+(num-K))
後ろからも同様に位置を反転させる。(N-num+1)+(N-K)
答えは変更されていったKの値である。

----解説ここまで---- */

ll N,M,K;

ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N>>M>>K;
  FOR(i, 0, M) {
	  int com, num; cin >> com >> num;
	  if (com == 0) {
		  if (num >= K) {
			  K = 1 + (num - K);
		  }
	  }
	  else {
		  if (N - num + 1 <= K) {
			  K = 2 * N - num - K + 1;
		  }
	  }
  }
  ans = K;
  cout << ans << endl;

  return 0;
}
