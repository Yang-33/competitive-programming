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
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/06/25  Problem: AOJ DPL_2  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2  ----- */
/* ------問題------

バイトニック巡回セールスマン (Bitonic TSP)

-----問題ここまで----- */
/* -----解説等-----

今度は再帰で書いた。
証明がごちゃごちゃするけど、Ｏ(N^2)でできる。(たぶん)
dp[ 円環の行く道の最初の番号 ][ 円環の帰る道の最後の番号 ]:=　この状態の最小距離  とすることで
この問題が解ける。
やっぱり名前が好き。

----解説ここまで---- */

ll N;
double x[1010];
double y[1010];
double dp[1010][1010];
double ans = 0LL;
const double eps = 1e-6;
inline double square(double a1) { return a1*a1; }
inline double dist(double x1, double x2, double y1, double y2) { return sqrt(square(x2 - x1) + square(y2 - y1)); }



double memo(int l, int r) {
	int p = max(l, r) + 1;
	if (p == N - 1)return dist(x[l], x[p], y[l], y[p]) + dist(x[r], x[p], y[r], y[p]);
	double  &ret = dp[l][r];
	if (ret > 0)return ret;
	return ret = min(memo(p, r) + dist(x[l], x[p], y[l], y[p]), memo(l, p) + dist(x[r], x[p], y[r], y[p]));
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N) {
		cin >> x[i] >> y[i];
	}
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			dp[i][j] = -1;
		}
	}
	ans = memo(0, 0);
	printf("%.10lf\n", ans);

	return 0;
}
