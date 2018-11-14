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

/* -----  2018/11/12  Problem: ARC 049 C / Link: http://arc049.contest.atcoder.jp/tasks/arc049_c  ----- */
/* ------問題------

高橋君は大会の上位入賞の特典として旅行に行ったときに、「ぬりまーす」という絵の具を買いました。
また、高橋君の手元には N 頂点の有向グラフがあり、グラフの各頂点は 頂点 1, 頂点 2, ..., 頂点 N と表されます。
高橋君は色を塗るのが大好きなので、その「ぬりまーす」を使い、手元の有向グラフの頂点に色を塗って遊ぼうと思っています。 ただし、適当に色を塗っても面白くないので、いくつかの頂点の間に以下のような制約がある条件下で色を塗ります。
タイプ1: ある頂点 x に色を塗るとき、既に頂点 y に色が塗られてなければならない。
タイプ2: ある頂点 u に色を塗るとき、既に頂点 v に色が塗られていてはいけない。
タイプ1の制約の個数は A 個で、タイプ2の制約の個数は B 個です。
最初はどの頂点にも色は塗られていません。 あなたの仕事は、適切な順番でグラフの頂点に色を塗り、最終的に色が塗られている最大の頂点数を求めることです。



-----問題ここまで----- */
/* -----解説等-----

制約は有向辺になる：xを塗るためにはyを塗らないといけないため、y->x
タイプ2が難しく、全探索するための状態を考える必要がある。
B: u->vで塗らないとダメ。/ uを使用しない
自分はuを使用しないことに気がつくことができなかった。
あとはSCCをして、indeg[i]==0から順にトポロジカルソートっぽく見れば良い。

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
	LL A; cin >> A;
	VI x(A), y(A);
	FOR(i, 0, A) {
		cin >> x[i] >> y[i];
		x[i]--, y[i]--;
	}
	int B; cin >> B;
	VI u(B), v(B);
	FOR(i, 0, B) {
		cin >> u[i] >> v[i];
		u[i]--, v[i]--;
	}

	LL ans = 0;
	FOR(state, 0, 1 << B) {
		VI canuse(N, 1);
		SCC scc(N);
		FOR(i, 0, A) {
			scc.addEdge(y[i], x[i]);
		}
		FOR(i, 0, B) {
			if (state & 1 << i) {
				scc.addEdge(u[i], v[i]);
			}
			else {
				canuse[u[i]] = 0;
			}
		}
		int n = scc.scc();
		VVI G = scc.get_graph_DAG();
		VI comp = scc.get_color();
		VI ok(n, 1);
		VI sz(n);
		FOR(i, 0, N) {
			ok[comp[i]] &= canuse[i];
			sz[comp[i]]++;
		}
		VI in(n);
		FOR(i, 0, n) {
			for (int to : G[i]) {
				in[to]++;
			}
		}
		LL res = 0;
		queue<int>q;
		FOR(i, 0, n) {
			if (!in[i]&& sz[i]==1 && ok[i])q.push(i);
		}
		while (!q.empty()) {
			int v = q.front(); q.pop();
			res++;
			for (int nx : G[v]) {
				in[nx]--;
				if (in[nx] == 0 && sz[nx] == 1 && ok[nx]) {
					q.push(nx);
				}
			}
		}
		DD(de(res); De(comp, ok, sz, canuse, in));

		ans = max(ans, res);
	}
	cout << ans << "\n";

	return 0;
}
