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

/* -----  2017/10/02  Problem: CS academy 35 B / Link:  https://csacademy.com/contest/round-35/task/decreasing-subarrays/ ----- */
/* ------問題------

整数a[i]がNこ与えられる
各a[i]について狭義減少列をもとめよ。

-----問題ここまで----- */
/* -----解説等-----

条件に当てはまる場合はその末尾を記録しておき、条件が崩れた際に、塗りつぶせばよい。
最後の部分が塗りつぶし忘れるので、それも忘れない。

----解説ここまで---- */

ll N;
int a[100010];
int b[100010];
ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  FOR(i, 0, N) {
	  cin >> a[i];
  }
  int x = -1;
  int cnt = 0;
  int id = 0;
  int end = 0;
  vector<int >v;
  FOR(i, 0, N) {
	  if (a[i] > a[i + 1]) {
		  end = i + 1;
	  }
	  else {
		  FOR(j, id, end+1) {
			  b[j] = end + 1 - id;
		  }
		  id = i + 1;
		  end = i + 1;
	  }
  }
  FOR(j, id, end + 1) {
	  b[j] = end +  - id;
  }
  FOR(i, 0, N) {
	  cout << b[i] << " ";
  }
  return 0;
}
