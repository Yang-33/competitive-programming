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

/* -----  2017/06/11  Problem: yukicoder058 / Link: http://yukicoder.me/problems/no/58  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

引き分けもある。
dpで両人のサイコロの出目の確率を
dp[ 振ったサイコロの数 ][ 出目の総和 ]:=　振った回数に対して出目の総和の確率
として求めて、出目が相手よりも大きいものを勝つ場合としてカウントする。

----解説ここまで---- */

ll N, K;

double  ans = 0.0;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;

	double dpa[12][100];
	FOR(i, 0, 100)FOR(j, 0, 12)dpa[j][i] = 0;
	dpa[0][0] = 1;

	FOR(i, 0, N) {
		FOR(d, 1, 6 + 1)
			FORR(j, 70, -1) {
			dpa[i + 1][d + j] += dpa[i][j]/6.0;
		}
	}

	double dpb[12][100];
	FOR(i, 0, 12)FOR(j, 0, 100)dpb[i][j] = 0;
	dpb[0][0] = 1;
	FOR(i, 0, N) {
		if (i < N - K)
			FOR(d, 1, 6 + 1)
			FORR(j, 70, -1) {
			dpb[i + 1][d + j] += dpb[i][j]/6.0;
		}
		else {
			FOR(d, 4, 6 + 1)
				FORR(j, 70, -1) {
				dpb[i + 1][d + j] += (2 * dpb[i][j])/6.0;
			}

		}
	}
	//dpb[N][num]:=N回目にnumが出る総数
	FOR(i, 0, 100) {
		FOR(j, 0, i) {
			ans += dpb[N][i] * dpa[N][j];
		}
	}
	printf("%.10lf\n",ans);
	//double x = 3.5*N;
	//double y = 0;
	//y += 1.0*(N - K)*3.5;
	//y += 1.0*K*5.0;
	//ans = y / (x + y);

	return 0;
}
