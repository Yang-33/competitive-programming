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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/12/14  Problem: ARC 010 D / Link: http://arc010.contest.atcoder.jp/tasks/arc010_d  ----- */
/* ------問題------

電波

-----問題ここまで----- */
/* -----解説等-----

ある人を選択したときの伝搬を考える。
これは有向グラフでの依存関係をみることになる。
閉路の人はだれを選んでも大丈夫なので、SCCでつぶしてDAGを考える。
indeg==0の人を全員選ぶと最少人数で伝達可能になる。

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
		vector<set<int>> s(sccsize_k);
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
	vector<int >get_color() {
		return cmp;
	}
};


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	using PD = pair<double, double >;
	vector<PD>f(N);
	FOR(i, 0, N) {
		cin >> f[i].first >> f[i].second;
	}
	LL M; cin >> M;
	vector<PD>s(M);
	FOR(i, 0, M) {
		cin >> s[i].first >> s[i].second;
	}
	auto dist = [](const PD& a, const PD& b) {
		auto p2 = [](double a) {
			return a * a;
		};
		return p2(a.first - b.first) + p2(a.second - b.second);
	};
	vector<double >Closest(N, 1e36);
	FOR(i, 0, N) {
		FOR(j, 0, M) {
			Closest[i] = min(Closest[i], dist(f[i], s[j]));
		}
	}
	SCC Scc(N);
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			if (i == j)continue;
			if (dist(f[i], f[j]) < Closest[i]) {
				Scc.addEdge(i, j);
			}
		}
	}
	int sz = Scc.scc();
	VI in(sz, 0);
	VVI G = Scc.get_graph_DAG();
	FOR(i, 0, sz) {
		FOR(j, 0, SZ(G[i])) {
			int nx = G[i][j];
			in[nx]++;
		}
	}

	LL ans = 0;
	FOR(i, 0, sz) {
		if (!in[i])ans++;
	}

	cout << ans << endl;

	return 0;
}