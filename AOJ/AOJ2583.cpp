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

/* -----  2017/06/20  Problem: AOJ 2583  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2583&lang=jp ----- */
/* ------問題------

テキストの修正

-----問題ここまで----- */
/* -----解説等-----

上が空白なら自分に対応する要素があるので、線を引く。
あとは.を空白にすればよい。

----解説ここまで---- */

ll N;
string s[1000];
ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  while (1) {
	  cin >> N;
	  if (N == 0)break;
	  FOR(i, 0, N)cin >> s[i];
	  FOR(i, 1, N) {
		  int pos = 0;
		  for (pos = 0; s[i].size() > pos&&s[i][pos] == '.'; pos++) {
			  s[i][pos] = ' ';
		  }
		  if (pos == 0)continue;
		  pos--;
		  s[i][pos] = '+';
		  for(int k=i-1;k>=0&&pos<s[k].size()&&s[k][pos]==' ';k--){
			  s[k][pos] = '|';
		  }
	  }

	  FOR(i, 0, N) {
		  cout << s[i] << endl;
	  }
  }
  return 0;
}
