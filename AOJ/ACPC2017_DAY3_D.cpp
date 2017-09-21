#include "bits/stdc++.h"
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/09/20  Problem: ACPC2017_day3_d  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

dp[cost][A]:=コストがcost、片側の満足度がAのときの他方の満足度の最大値B
としてDP.
答えはcost,Aについて、dp[cost][A],Aの最小の最大値

----解説ここまで---- */

const int INF = 12345678;
const int A = 10000;
int dp[101][A + 1];

int main()
{
	int n, C;
	cin >> n >> C;
	vector<int> a(n), b(n), c(n);
	FOR(i, 0, n) cin >> a[i] >> b[i] >> c[i];

	fill(dp[0], dp[101], -INF);
	dp[0][0] = 0;
	FOR(i, 0, n) {
		for (int cost = C; cost >= 0; --cost) {
			if (cost + c[i] <= C) {
				int nx = cost + c[i];
				FOR(j, 0, A + 1) {
					dp[nx][min(A, j + a[i])] = max(dp[nx][min(A, j + a[i])], dp[cost][j] + b[i]);
					dp[nx][min(A, j + b[i])] = max(dp[nx][min(A, j + b[i])], dp[cost][j] + a[i]);
				}
			}
		}
	}

	int ans = 0;
	FOR(i, 0, C + 1)FOR(j, 0, A + 1) {
		ans = max(ans, min(j, dp[i][j]));
	}

	cout << ans << endl;
}