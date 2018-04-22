#include <bits/stdc++.h>
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
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/04/19  Problem: yukicoder 095  / Link: http://yukicoder.me/problems/no/095  ----- */
/* ------問題------

Alice was given an undirected graph by her mother as a birthday gift.
Then, as usual, Alice is now playing a game with the graph.

The graph has N nodes, numbered from 1 to N, and node k has 2k−1−1 coins.
When the game starts, Alice is in node 1, and there is no coin at node 1, since 21−1−1=0.
Then Alice will be allowed to move at most K times.
At each move, Alice can go to an adjacent node through an edge, and collect the coins at the node.
The question is that what is the maximum number of coins can Alice collect?
Here please note that Alice does not have to go back to node 1.

-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */



int f(VI& s, VVI& dist) {
	int n = SZ(s);

	VVI dp(1 << n, VI(n, INF));
	dp[1][0] = 0;
	FOR(i, 0, 1 << n) {
		FOR(j, 0, n) {
			if (dp[i][j] == INF)continue;
			if (i & 1 << j) {
				FOR(k, 0, n) {
					if (i & 1 << k)continue;
					dp[i | 1 << k][k] = min(dp[i | 1 << k][k], dp[i][j] + dist[s[j]][s[k]]);
				}
			}
		}
	}
	int ret = INF;
	FOR(i, 0, n) {
		ret = min(ret, dp[(1 << n) - 1][i]);
	}

	return ret;
}

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, K; cin >> N >> M >> K;
	VVI dist(N, VI(N, INF));
	FOR(i, 0, M) {
		int a, b; cin >> a >> b; a--, b--;
		dist[a][b] = dist[b][a] = 1;
	}
	FOR(i, 0, N)dist[i][i] = 0;
	FOR(k, 0, N)FOR(i, 0, N)FOR(j, 0, N)dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	VI Se({ 0 });
	FORR(k, N - 1, 0) {
		Se.push_back(k);
		if (f(Se, dist) <= K) {
			; // ok
		}
		else {
			Se.pop_back();
		}
		if (SZ(Se) == K + 1)break;
	}

	FOR(i, 0, SZ(Se)) {
		ans += (1LL << Se[i]) - 1;
	}
	cout << ans << "\n";
	return 0;
}
