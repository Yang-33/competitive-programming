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

/* -----  2017/04/15  Problem: AGC 013 A / Link: http://agc013.contest.atcoder.jp/tasks/agc013_a  ----- */
/* ------問題------

長さ N の配列 A が与えられます。
A を何箇所かで切って、A の連続した部分であるようないくつかの数列に分けます。
この時、分けられたあとの数列は全て、単調非減少または単調非増加な列になっている必要があります。
最小で何個の数列に分ければ良いかを求めて下さい。

-----問題ここまで----- */
/* -----解説等-----

数列の頭から見て単調増加か単調減少かを教えるものがあればよい。
単調増加・単調増加という場合ももちろんあるのでフラグとして「まだわからない」というものを作った瞬間に
区間が一つ増えるとすればＯ(N)で見ることができる。

----解説ここまで---- */


int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  ll N;
  ll ans = 0LL;
  ll a[100100];
  cin >> N;
  FOR(i, 0, N) {
	  cin >> a[i];
  }
  ans = 1;
  ll m = a[0];
  int flag=2;

  FOR(i, 0, N) {
	  if (flag == 2) {
		  if (m == a[i])continue;
		  else if (m < a[i])flag = true;
		  else flag = false;
	  }
	  if (flag == true) {
		  if (a[i] >= m) {
			  m = a[i];
			  continue;
		  }
		  else {
			  flag = 2;
			  m = a[i];
			  ans++;
		  }
	  }
	  else {
		  if (a[i] <= m) {
			  m = a[i];
			  continue;

		  }
		  else {
			  flag = 2;
			  m = a[i];
			  ans++;
		  }
	  }
  }

  cout << ans << endl;

  return 0;
}
