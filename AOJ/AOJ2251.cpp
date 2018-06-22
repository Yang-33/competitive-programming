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

/* -----  2018/06/24  Problem: AOJ 2251 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2251  ----- */
/* ------問題------

グラフGと、サンタさんへの配達クエリが来る。
サンタさんは初期位置をどこにでもとれるとして、何人いれば配達できるか。

-----問題ここまで----- */
/* -----解説等-----

L人から削減することを考える。
ある頂点からの遷移を考えるとpathをカバーできると良いことになる。
DAGの最小パス被覆ぽいなとなれば勝ちで、in/outのL点のグラフをつくればよい。
L-(matching数)でできる。

----解説ここまで---- */

struct Bipartite_Matching {
	vector<vector<int>> graph;
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

// N 600
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	using LL = long long;
	int N, M, L;

	while (cin >> N >> M >> L, N) {
		vector<vector<LL>>dist(N, vector<LL>(N, 1e18));
		FOR(i, 0, N) {
			dist[i][i] = 0;
		}

		FOR(i, 0, M) {
			LL a, b, c;
			cin >> a >> b >> c;
			dist[a][b] = dist[b][a] = min(dist[a][b], c);
		}
		FOR(k, 0, N)FOR(i, 0, N)FOR(j, 0, N) {
			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
		// グラフはできたのでcheckをする
		Bipartite_Matching F(2 * L);
		vector<LL>p(L), t(L); // L^2
		FOR(i, 0, L) {
			cin >> p[i] >> t[i];
		}

		FOR(i, 0, L) {
			FOR(j, 0, L) {
				if (i == j)continue;
#define IN(x) (x)
#define OUT(x) (x+L)
				if (t[i] + dist[p[i]][p[j]] <= t[j]) {
					F.add_edge(IN(i), OUT(j));
				}
			}
		}

		cout << L - F.bipartite_matching() << endl;


	}

}