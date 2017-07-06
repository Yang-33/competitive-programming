#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
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

/* -----  2017/07/07  Problem: AOJ 0530 JOI 2007 (NU contest 14 E) / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0530  ----- */
/* ------問題------

みて

-----問題ここまで----- */
/* -----解説等-----

川渡りはグラフの遷移を拡張して何回大きくジャンプしたかを状態に持たせると簡単に表現できる。
はじめのジャンプではコストがかからないのでジャンプできる場所は0初期化すればよい。
最後の石からは大ジャンプをしてもしなくても一緒なので、
答えは0~Mかい大ジャンプをしたものを反対側の岸のうち、最小で到達できるものをとればよい。

----解説ここまで---- */

ll H, M;
int masu[152][1003];
int dp[152][1003][80];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	while (1) {
		int ans = INT_MAX;
		FOR(i, 0, 152)FOR(j, 0, 1003) {
			masu[i][j] = INF;
			FOR(k, 0, 80)dp[i][j][k] = INF;
		}

		cin >> H >> M;
		if (H == 0 && M == 0)break;

		FOR(i, 0, H) {
			int dataset; cin >> dataset;
			FOR(j, 0, dataset) {
				int pos, suberi; cin >> pos >> suberi;
				pos--;
				masu[i][pos] = suberi;
			}
		}

		FOR(j, 0, 1003) {
			masu[H][j] = 0;
		}

		FOR(i, 0, 2)
			FOR(j, 0, 1003) {
			int m = 0; if (i)m++;
			if (masu[i][j] != INF)dp[i][j][m] = 0;
		}

		FOR(i, 0, H) {//h
				FOR(j, 0, 1003) {//now
					if (masu[i][j] == INF)continue;
					FOR(k, 0, 1003) {//nx
						FOR(m, 0, M+1) {
						if (masu[i + 1][k] != INF) {
							dp[i + 1][k][m] = min(dp[i + 1][k][m], dp[i][j][m] + (masu[i][j] + masu[i + 1][k])*abs(j - k));
							//1
						}
						if (masu[i + 2][k] != INF) {
							dp[i + 2][k][m + 1] = min(dp[i + 2][k][m + 1], dp[i][j][m] + (masu[i][j] + masu[i + 2][k])*abs(j - k));
							//2
						}
					}
				}
			}
		}

		FOR(m, 0, M + 1) {
			FOR(j, 0, 1003)
				ans = min(ans, dp[H][j][m]);
		}
		cout << ans << endl;
	}
	return 0;
}
