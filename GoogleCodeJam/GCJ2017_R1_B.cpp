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

/* -----  2017/04/30  Problem: GCJ 2017 Round1A B / Link: https://code.google.com/codejam/contest/dashboard?c=5304486#s=p2  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

90%~110%の絵を描いていたら区間同士の重複を求めていけばよいことに気が付いた。
またこれは端から貪欲にとっていけばよいということもスケジューリングの問題から学んでいるので
解ける問題だったが、結局全探索してしまう発想のコードしか書けず悲しかった。
区間の重複がなくなったら範囲の最大値の中で最小のものをきりはなしていけばいいかんじに区間が動いてくれそう。
これを実装する。
スケジューリング系問題を解きまくってこういう区間実装を得意になりたい。

----解説ここまで---- */

void solve(int t) {
	int N, P; cin >> N >> P;
	int seibun[50];

	FOR(i, 0, N) {
		cin >> seibun[i];
	}
	
	int data[50][50];

	FOR(i, 0, N) {
		FOR(j, 0, P) {
			cin >> data[i][j];
		}
	}
	int ans; //kits num




	cout << "Case #" << t + 1 << ": " << ans << endl;
}


int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int t;

  cin >> t;
  FOR(i, 0, t) {
	  solve(i);
  }
  return 0;
}
