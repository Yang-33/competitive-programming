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

/* -----  2018/07/05  Problem: AOJ 2598 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2598  ----- */
/* ------問題------

リンクをたどって広告を見る。
ある広告について、pポイントを得て、t時間かかり,k回みれる。
またリンクの関係が与えられる。
T時間あったときに最大何ポイント得られるか。

-----問題ここまで----- */
/* -----解説等-----

SCCしたくなりませんかということでSCCする。
SCC後について、ある頂点が含む頂点が2個以上ならそこでぐるぐるできる。
1個のときでも自己辺があれば大丈夫。
あとはDPだが、個数制限付きナップザックは面倒なので2べきでやった。
最後はトポロジカル順序を保ってやれば良い。

----解説ここまで---- */

class SCC {
private:
	const int n;
	vector<vector<int>> G;
	vector<vector<int>> rG;
	vector<int > vs;
	vector<bool> used;
	vector<int > cmp;
	int sccsize_k;
public:
	SCC(int _n) : n(_n), G(_n), rG(_n), used(_n), cmp(_n) {}
	void addEdge(int from, int to) {
		G[from].emplace_back(to);
		rG[to].emplace_back(from);
	}
	void dfs(int v) {
		used[v] = true;
		for (auto&& nxt : G[v]) {
			if (!used[nxt]) dfs(nxt);
		}
		vs.emplace_back(v);
	}
	void rdfs(int v, int k) {
		used[v] = true;
		cmp[v] = k;
		for (auto&& nxt : rG[v]) {
			if (!used[nxt]) rdfs(nxt, k);
		}
		vs.emplace_back(v);
	}
	int scc() {
		for (int v = 0; v < n; v++) {
			if (!used[v]) dfs(v);
		}
		used.assign(n, false);
		sccsize_k = 0;
		for (int i = vs.size() - 1; i >= 0; i--) {
			int v = vs[i];
			if (!used[v]) rdfs(v, sccsize_k++);
		}
		return sccsize_k;
	}
	bool same(int a, int b) {
		return cmp[a] == cmp[b];
	}
	vector<vector<int>>get_graph_DAG() {
		int V = (int)G.size();
		vector<set<int>> s(sccsize_k);//group間に多重辺があるときにこれを解消してDAGにするためのset
		vector<vector<int>> res(sccsize_k);
		for (int i = 0; i < V; ++i) {
			for (auto e : G[i]) {
				s[cmp[i]].insert(cmp[e]);
			}
		}
		for (int i = 0; i < sccsize_k; ++i) {
			for (auto j : s[i]) {
				if (i != j) {
					res[i].push_back(j);
				}
			}
		}
		return res;
	}
	vector<vector<int>>get_graph_naive() { //多重辺のあるDAG
		int V = (int)G.size();
		vector<vector<int>> res(sccsize_k);
		for (int i = 0; i < V; ++i) {
			for (int j = 0; j < (int)G[i].size(); j++) {
				if (!same(i, G[i][j]))res[cmp[i]].push_back(cmp[G[i][j]]);
			}
		}
		return res;
	}

	vector<int >get_color() {
		return cmp;
	}
};


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, T;
	while (cin >> N >> M >> T, N) {
		VI p(N), t(N), k(N);
		FOR(i, 0, N) {
			cin >> p[i] >> t[i] >> k[i];
		}
		SCC Scc(N);
		VI selflp(N, 0);
		FOR(i, 0, M) {
			int a, b;
			cin >> a >> b; a--, b--;
			if (a == b)selflp[a] = 1;
			Scc.addEdge(a, b);
		}
		int K = Scc.scc();
		VI color = Scc.get_color();
		vector<vector<PII>>VtoW(K);
		VI sz(K, 0);
		FOR(i, 0, N)sz[color[i]]++;

		FOR(i, 0, N) {
			if (sz[color[i]] == 1 && !selflp[i]) {
				VtoW[color[i]].push_back(PII(p[i], t[i]));
			}
			else {
				for (int j = 1; ; j *= 2) {
					if (k[i] >= j) {
						VtoW[color[i]].push_back(PII(j*p[i], j*t[i]));
						k[i] -= j;
					}
					else {
						VtoW[color[i]].push_back(PII(k[i] * p[i], k[i] * t[i]));
						break;
					}
				}
			}
		}
		// DP
		VVI dp(K, VI(T + 1, 0));
		VVI G = Scc.get_graph_DAG();
		FOR(i, 0, K) {
			FOR(j, 0, SZ(VtoW[i])) {// 0-1
				FORR(tt, T, 0 - 1) {
					if (tt + VtoW[i][j].second <= T)
						dp[i][tt + VtoW[i][j].second] = max(dp[i][tt + VtoW[i][j].second], dp[i][tt] + VtoW[i][j].first);
				}
			}
			// nx
			FOR(j, 0, SZ(G[i])) {
				FOR(tt, 0, T + 1) {
					dp[G[i][j]][tt] = max(dp[G[i][j]][tt], dp[i][tt]);
				}
			}
		}
		int ans = 0;
		FOR(i, 0, K) {
			FOR(tt, 0, T + 1) {
				ans = max(ans, dp[i][tt]);
			}
		}
		cout << ans << endl;


	}


	return 0;
}
