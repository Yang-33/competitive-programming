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

/* -----  2018/03/17  Problem: ARC 092 A / Link: http://arc092.contest.atcoder.jp/tasks/arc092_a  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

LL N;

LL ans = 0LL;



/*----------------------------
二部マッチング O(VE)
はやい
aliveはまだ
-----------------------------*/
struct Bipartite_Matching { // 借り物ライブラリにすること
	vector<vector<int> > graph;
	vector<int> match, alive, used;
	int timestamp;

	Bipartite_Matching(int n) {
		timestamp = 0;
		graph.resize(n);
		alive.assign(n, 1);
		used.assign(n, 0);
		match.assign(n, -1);
	}

	void add_edge(int u, int v) {
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	bool dfs(int v) {
		used[v] = timestamp;
		for (int i = 0; i < (int)graph[v].size(); i++) {
			int u = graph[v][i], w = match[u];
			if (alive[u] == 0) continue;
			if (w == -1 || (used[w] != timestamp && dfs(w))) {
				match[v] = u;
				match[u] = v;
				return (true);
			}
		}
		return (false);
	}

	int bipartite_matching() {
		int ret = 0;
		for (int i = 0; i < (int)graph.size(); i++) {
			if (alive[i] == 0) continue;
			if (match[i] == -1) {
				++timestamp;
				ret += dfs(i);
			}
		}
		return (ret);
	}
};




int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VL a(N);
	VL b(N);
	VL c(N);
	VL d(N);
	FOR(i, 0, N) {
		cin >> a[i] >> b[i];
	}
	FOR(i, 0, N) {
		cin >> c[i] >> d[i];
	}
	Bipartite_Matching F(2 * N);
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			if (a[i] < c[j] && b[i] < d[j]) {
				F.add_edge(i,N+j);
			}
		}
	}
	ans = F.bipartite_matching();
	cout << ans << "\n";

	return 0;
}
