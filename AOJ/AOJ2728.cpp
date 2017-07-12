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

/* -----  2017/07/12  Problem: AOJ 2728  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2728  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

英語ができない。
題意は元のパスワードからより離れたパスワードのうち、値の重複がないものを探すとある。
10桁だけどお祈りをすると時間の女神が微笑んで通る。

----解説ここまで---- */

string N;
int sizen;
ll  ans ;
ll origin;
ll maxn = 0;
int cnt[10];
ll pswd = 0;
void dfs(int i, ll sum) {
	if (i == sizen) {
		ll tmp = min(abs(origin - sum), maxn - abs(origin - sum));
		if (pswd <= tmp) {
			if (pswd < tmp)ans = sum;
			else ans = min(ans, sum);
			pswd = tmp;
			//debug(ans);
		}
	}
	else {
		FOR(j, 0, 10) {
			if (cnt[j])continue;
			cnt[j] = 1;
			dfs(i + 1, sum * 10LL + j);
			cnt[j] = 0;
		}
	}
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  maxn = 1;
  sizen = N.size();
  FOR(i, 0, N.size())maxn *= 10;
  ans = maxn;
  //debug(ans);
  //debug(maxn);
  origin = 0;
  FOR(i, 0, N.size())origin *= 10, origin += N[i] - '0';
  //debug(origin);
  dfs(0,0LL);
  int cc = 0;
  ll temp = ans;
  while (temp) {
	  cc++;
	  temp /= 10;
  }
  FOR(i, 0, sizen-cc)cout << 0;
  cout << ans << endl;

  return 0;
}
