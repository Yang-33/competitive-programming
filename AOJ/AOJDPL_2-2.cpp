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

/* -----  2017/06/25  Problem: AOJ DPL_2  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2  ----- */
/* ------問題------

バイトニック巡回セールスマン (Bitonic TSP)
２次元のユークリッド空間上のN 個の点について、以下の条件を満たす最短経路の距離を求めてください。
x 座標が最小の点を始点、x 座標が最大の点を折り返し点とし、次の手順で点を訪問する。
始点を出発し、x が増加する方向へ進み、折り返し点を訪れる。
折り返し点を出発し、x が減少する方向へ進み、始点へ戻る。
1. 2. を通して各点を少なくとも1度訪れる。

-----問題ここまで----- */
/* -----解説等-----

xを小さい順に並べる。円環上での遷移を考えるとこれは部分問題になる。
一周することを考えたときに二点間の距離を最短になるようにしていけばよい。

名前が好き。

----解説ここまで---- */

ll N;
double x[1010];
double y[1010];
double dp[1010][1010];
double ans = 0LL;
const double eps = 1e-6;
inline double square(double a1) { return a1*a1; }
inline double dist(double x1, double x2,double y1,double y2) {return sqrt(square(x2 - x1) + square(y2 - y1));}
double cost[1010][1010];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  FOR(i, 0, N) {
	  cin >> x[i] >> y[i];
  }
  FOR(i, 0, N) {
	  FOR(j, 0, N) {
		  cost[i][j] = dist(x[i], x[j], y[i], y[j]);
		  dp[i][j] = INF;
	  }
  }
  dp[1][0] = cost[0][1];
  FOR(i, 2, N) {
	  FOR(j, 0, i - 1) {
		  dp[i][j] = min(dp[i][j], dp[i - 1][j] + cost[i - 1][ i]);
		  dp[i][i - 1] = min(dp[i][i - 1], dp[i - 1][j] + cost[j][i]);
	  }
  }
  ans = LINF;
  FOR(i, 0, N - 1) {
	  ans = min(ans, dp[N - 1][i] + cost[i][N - 1]);
  }
  printf("%.10lf\n",ans);

  return 0;
}
