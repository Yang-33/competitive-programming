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

/* -----  2018/06/25  Problem: AOJ 1311 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1311  ----- */
/* ------問題------

有向グラフGで、1->Nへの最短経路がある。これをもっと短くしてCにしたい。
辺のコストを0上であるならば書き換えることができるが、最低何本書き換えれば良いか。

-----問題ここまで----- */
/* -----解説等-----

最短路上でコスト変化の回数を持ちながら、最短路かどうかを判定すれば良い。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, C;
	while (cin >> N >> M >> C, N) {
		vector<vector<PII>>G(N);
		FOR(i, 0, M) {
			int a, b, c;
			cin >> a >> b >> c;
			a--, b--;
			G[a].push_back(PII(b, c));
		}

		VVI dp(N, VI(N, INF));
		dp[0][0] = 0; // cost
		using tp = tuple<int, int, int >;
		priority_queue<tp, vector<tp>, greater<tp>>q;
		q.push(tp(0, 0, 0));

		while (!q.empty()) {
			//max dp
			int v, k, d;
			tie(d, v, k) = q.top(); q.pop();
			if (dp[v][k] > d)continue;
			FOR(i, 0, SZ(G[v])) {
				int nx = G[v][i].first;
				int cost = G[v][i].second;
				if (dp[nx][k] > dp[v][k] + cost) {
					dp[nx][k] = dp[v][k] + cost;
					q.push(tp(dp[nx][k], nx, k));
				}
				if (k + 1 < N&&dp[nx][k + 1] > dp[v][k]) {
					dp[nx][k + 1] = dp[v][k];
					q.push(tp(dp[nx][k + 1], nx, k + 1));
				}
			}
		}
		int ans = INF;
		FOR(i, 0, N) {
			if (dp[N - 1][i] <= C)
				ans = min(ans, i);
		}
		cout << ans << endl;

	}

	return 0;
}
