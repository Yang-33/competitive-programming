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

/* -----  2017/06/27  Problem: ICPC2012国内予選B / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1173&lang=jp  ----- */
/* ------問題------

カッコの対応

-----問題ここまで----- */
/* -----解説等-----

stackに積んだり取ったりすればカッコの対応が取れる。
例外処理をして終わり。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  string s;
  while (1) {
	  getline(cin, s);
	  if (s.size() == 1 && s[0] == '.')break;

	  stack<char>sta;
	  bool f = 1;
	  FOR(i, 0, s.size()) {
		  if (s[i] == '(' || s[i] == '[') {
			  sta.push(s[i]);
		  }
		  else if (s[i] == ')') {
			  if (sta.size() == 0) {
				  f = 0;
				  break;
			  }
			  char top = sta.top();
			  if (top == '(') {
				  sta.pop();
			  }
			  else {
				  f = 0;
			  }
		  }
		  else if (s[i] == ']') {
			  if (sta.size() == 0) {
				  f = 0;
				  break;
			  }
			  char top = sta.top();
			  if (top == '[') {
				  sta.pop();
			  }
			  else {
				  f = 0;
			  }
		  }


	  }
	  if (sta.size() != 0)f = 0;

	  if (f) {
		  cout << "yes" << endl;
	  }
	  else {
		  cout << "no" << endl;
	  }
  }

  return 0;
}
