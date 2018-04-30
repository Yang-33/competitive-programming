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

/* -----  2018/04/20  Problem: AOJ 2222 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2222  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

SCC+DPみたいな典型をすればよい。
組合せの計算は非自明だと思う。
末端の色を決めると先端まできまることがあるので、絵を書けばわかる。

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



LL dfs(int v, VVI& G) {
	LL ret = 1;
	FOR(i, 0, SZ(G[v])) {
		int nv = G[v][i];
		ret *= dfs(nv, G);
		ret %= MOD;
	}
	return (ret + 1) % MOD;
}


LL N, M;
LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	SCC scc(N);

	FOR(i, 0, M) {
		int a, b; cin >> a >> b;
		a--, b--;
		scc.addEdge(a, b);
	}
	scc.scc();
	VVI G = scc.get_graph_DAG();
	//debug(N);
	N = SZ(G);
	// reverse;
	VVI rG(N);
	FOR(i, 0, N) {
		FOR(j, 0, SZ(G[i])) {
			int nv = G[i][j];
			rG[nv].push_back(i);
		}
	}
	ans = 1;
	FOR(i, 0, N) {
		if (SZ(G[i]) == 0)
			ans *= dfs(i, rG);
		ans %= MOD;
	}

	cout << ans << "\n";

	return 0;
}
