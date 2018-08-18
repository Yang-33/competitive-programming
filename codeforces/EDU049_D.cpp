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

/* -----  2018/08/18  Problem: edu049 D / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

SCCして辺が出てないものの最小値の和

----解説ここまで---- */

/* 強連結成分分解 成分数のみ
scc.same(x,y)でx,yの同色判定が可能
*/

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

int N;
int c[200005], a[200005];
LL ans = 0LL;

int main() {
	scanf("%d", &N);
	FOR(i, 0, N) {
		scanf("%d", &c[i]);
	}
	SCC Scc(N);
	FOR(i, 0, N) {
		scanf("%d", &a[i]);
		a[i]--;
		if (a[i] == i)continue;
		Scc.addEdge(i, a[i]);
	}
	int nsz = Scc.scc();
	// outdeg =0を持ってくる
	VI outdeg(nsz, 0);
	VVI G = Scc.get_graph_DAG();
	FOR(i, 0, nsz) {
		FOR(j, 0, SZ(G[i])) {
			outdeg[i]++;
		}
	}
	VI res(nsz, INF);
	VI color = Scc.get_color();
	FOR(i, 0, N) {
		int v = color[i];
		res[v] = min(res[v], c[i]);
	}

	ans = 0;
	FOR(i, 0, nsz) {
		if (!outdeg[i]) {
			ans += res[i];
		}
	}


	cout << ans << "\n";

	return 0;
}
