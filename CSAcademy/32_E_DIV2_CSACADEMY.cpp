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

/* -----  2017/06/09  Problem: CSAcademy 32 E / Link: https://csacademy.com/contest/round-32/task/equidistant-points/  ----- */
/* ------問題------

Nが与えられる。
二次元平面上に以下の条件をすべて満たす点をN個出力せよ。
・N組の点について、その距離は1
・残りのすべてのペアについて、その点の距離は1未満10^-4以上

-----問題ここまで----- */
/* -----解説等-----

なぞなぞ。
単位円上に点を置けば中心との距離が1になる。また単位円上の点の両端の距離を1にすればN個のペアができる。
あとは両端の点の間でかつ単位円上の弧の上に点を置けばよい。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  printf("%.10lf %.10lf\n", 0.0, 0.0);
  printf("%.10lf %.10lf\n", 1.0, 0.0);
  FOR(i, 0, N - 2) {
	  double thi =(PI/3.0)-(double)i* (PI/3.0) / (1.0*(N - 2));
	  printf("%.10lf %.10lf\n", cos(thi),sin(thi) );

  }

  return 0;
}
