#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/06/10  Problem: AOJ 1611 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1611  ----- */
/* ------問題------

2個同時だるま落としをやったときに最大何個消せるか。

-----問題ここまで----- */
/* -----解説等-----

どうみても区間DP.
セオリー道理にやってよい。

2つの遷移ができればよい。
X[.最適..]X -> [最適]
[最適..][.最適.] -> [最適]

区間DPを理解していない人間なので最悪を書いてしまった。

----解説ここまで---- */


void solve(int N) { // 簡単
	VI a(N);
	FOR(i, 0, N) {
		scanf("%d", &a[i]);
	}
	VVI checkdp(N + 1, VI(N + 1, 0));
	VVI dp(N + 1, VI(N + 1, 0));
	int ans = 0;

	FOR(alen, 2, N + 1) {
		FOR(i, 0, N) {
			int j = alen + i - 1;
			if (j >= N) continue;
			if (dp[i + 1][j - 1] == alen - 2 && abs(a[i] - a[j]) <= 1) dp[i][j] = alen;
			FOR(k, i, j) {
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
			}
		}
	}
	cout << dp[0][N - 1] << endl;
}

int main() { // 最悪の方
	int N;
	while (cin >> N, N) {
		VI a(N);
		FOR(i, 0, N) {
			scanf("%d", &a[i]);
		}
		VVI checkdp(N + 1, VI(N + 1, 0));

		int ans = 0;

		VVI dp(N + 1, VI(N + 1, 0));


		FOR(i, 0, N - 1) {
			if (abs(a[i] - a[i + 1]) <= 1) {
				checkdp[i][i + 1] = 1;
				dp[i][i + 1] = 2;
				ans = 2;
			}
		}

		for (int alen = 4; alen <= N; alen += 1) {// 長さalenを合成
			for (int s = 0; s < N; s++) {
				for (int spl = s + 1; spl < alen + s - 1; spl++) {
					int end = alen + s - 1;
					// checkdp[s][spl], checkdp[spl + 1][end] merge;
					// あとで境界処理をすること
					if (end < N) {// cond
						if (checkdp[s][spl] && checkdp[spl + 1][end]) {
							checkdp[s][end] = 1;
							dp[s][end] = alen;
							ans = max(ans, alen);
						}
						if (abs(a[s] - a[end]) <= 1 && checkdp[s + 1][spl] && checkdp[spl + 1][end - 1]) {
							checkdp[s][end] = 1;
							dp[s][end] = alen;
							ans = max(ans, alen);
						}

						if (abs(a[s] - a[end]) <= 1 && checkdp[s + 1][end - 1]) {

							checkdp[s][end] = 1;
							dp[s][end] = alen;
							ans = max(ans, alen);
						}
					}
				}
			}
		}
		//cout << "PREANS" << ans << endl;
		//int ss, tt;
		//while (cin >> ss >> tt) {
		//	cout << "(s:" << ss << ",t" << tt << "):" << checkdp[ss][tt] << endl;
		//}
		// くくりはmergeできたので、O XM O みたいなのを合成する

		// max / + 

		for (int alen = 2; alen <= N; alen++) {// 長さalenを合成
			for (int s = 0; s < N; s++) {
				for (int spl = s + 1; spl < alen + s - 1; spl++) {
					int end = alen + s - 1;
					if (end < N) {// cond
						dp[s][end] = max({ dp[s][end],dp[s][spl] + dp[spl + 1][end] });
						ans = max(ans, dp[s][end]);
					}
				}
			}
		}


		cout << ans << endl;
	}



	return 0;
}