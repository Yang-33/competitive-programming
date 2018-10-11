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

/* -----  2018/10/13  Problem: ARC 039 D / Link: http://arc039.contest.atcoder.jp/tasks/arc039_d  ----- */
/* ------問題------

高橋君とあなたはTK国でHS会社という旅行会社を経営しています。 TK国は N 個の頂点と M 本の辺からなる連結な単純無向グラフです。各頂点にはそれぞれ 1 から N の番号が振られています。
HS会社では、顧客ごとに旅行計画を立てて提供するサービスを行っています。 これまでは、旅行計画を温もりのある手作業で作成していました。 ですが突然の旅行ブームがTK国に訪れ、ナウでヤングな若者は皆旅行をするようになりました。もちろん会社は大忙し、とうとうコンピューターに頼ることにしました。
HS会社では、顧客から始点、中継点、終点という 3 つの頂点を与えられるので、始点から中継点を通り終点へと到着するような旅行計画を提供しています。 ただし、顧客が退屈しないように、同じ辺を複数回通るような旅行計画は提供しないようにしています。同じ頂点を複数回通る事に制限はありません。つまり旅行計画は、始点から中継点を通り終点に到着するトレイルです。
あなたはとりあえず、顧客ごとにそのような旅行計画は存在するのかどうかだけを判別するプログラムを書くことにしました。

-----問題ここまで----- */
/* -----解説等-----

// a,b,cが同じトレイル
// 頂点は何回使ってもよいが辺は1回のみ
// オイラー路と一緒の感覚
// - cmp(a,b) or cmp(b,c)なら必ず可能(2本以上あるといえるそうでないならそもそも成分には含まれないため)
// そうでないがcmp(a,c)なら無理 (u-vの辺は一本なので)
// - 木を見て、一直線のpathにあれば良い

// 一直線の判定ができればよい
// 距離を見て一直線ならdist(a,c)= dist(a,b) + dist(b,c)
// そうでないときは無駄な経路を通るので大きい値になる
ということを考えました。あっていた

----解説ここまで---- */

struct UnionFind {
	vector<int> data;
	UnionFind(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

struct TwoEdgeConnectedComponent {
	UnionFind uf;
	vector<vector<int>> g;
	vector<pair<int, int>> edges;
	vector<int> used, ord, low, comp;

	TwoEdgeConnectedComponent(int v) : uf(v), g(v), used(v, 0), comp(v), ord(v), low(v) {}

	void add_edge(int x, int y) {
		g[x].push_back(y);
		g[y].push_back(x);
		edges.push_back(minmax(x, y));
	}

	void dfs(int idx, int& k, int par = -1) {
		used[idx] = true;
		ord[idx] = k++;
		low[idx] = ord[idx];

		for (auto &to : g[idx]) {
			if (!used[to]) {
				dfs(to, k, idx);
				low[idx] = min(low[idx], low[to]);
				if (ord[idx] >= low[to]) uf.unionSet(idx, to);
			}
			else if (to != par) {
				low[idx] = min(low[idx], ord[to]);
			}
		}
	}
	vector<int> decomposition(vector<vector<int>>& resG, int root = 0) {
		int kk = 0;
		dfs(root, kk);

		int ptr = 0;
		vector<int> color(g.size());
		for (int i = 0; i < (int)g.size(); i++) {
			if (i == uf.root(i)) color[i] = ptr++;
		}

		resG.resize(ptr);
		for (int i = 0; i < (int)g.size(); i++) {
			comp[i] = color[uf.root(i)];
		}
		for (auto &e : edges) {
			int x = comp[e.first], y = comp[e.second];
			if (x == y) continue;
			resG[x].push_back(y);
			resG[y].push_back(x);
		}
		return comp;
	}
};

struct LCAT {
	int n, h;
	vector<vector<int> > G, par, lad;
	vector<int> dep, nxt, len, pth, ord, hs;
	LCAT() {}
	LCAT(int n) :
		n(n), G(n), dep(n), nxt(n, -1), len(n), pth(n), ord(n), hs(n + 1, 0) {
		h = 1;
		while ((1 << h) <= n) h++;
		par.assign(h, vector<int>(n, -1));

		for (int i = 2; i <= n; i++) hs[i] = hs[i >> 1] + 1;
	}

	void dfs(int v, int p, int d, int f) {
		if (nxt[v]<0) {
			par[0][nxt[v] = v] = p;
			len[v] = dep[v] = d;
			for (int u : G[v]) {
				if (u == p) continue;
				dfs(u, v, d + 1, 0);
				if (len[v]<len[u]) nxt[v] = u, len[v] = len[u];
			}
		}
		if (!f) return;
		pth[v] = lad.size();
		lad.emplace_back();
		for (int k = v;; k = nxt[k]) {
			lad.back().emplace_back(k);
			pth[k] = pth[v];
			if (k == nxt[k]) break;
		}
		for (;; p = v, v = nxt[v]) {
			for (int u : G[v])
				if (u != p && u != nxt[v]) dfs(u, v, d + 1, 1);
			if (v == nxt[v]) break;
		}
	}

	void build(int r = 0) {
		dfs(r, -1, 0, 1);
		for (int k = 0; k + 1<h; k++) {
			for (int v = 0; v<n; v++) {
				if (par[k][v]<0) par[k + 1][v] = -1;
				else par[k + 1][v] = par[k][par[k][v]];
			}
		}
	}

	int lca(int u, int v) {
		if (dep[u]>dep[v]) swap(u, v);
		for (int k = 0; k<h; k++) {
			if ((dep[v] - dep[u]) >> k & 1) {
				v = par[k][v];
			}
		}
		if (u == v) return u;
		for (int k = h - 1; k >= 0; k--) {
			if (par[k][u] != par[k][v]) {
				u = par[k][u];
				v = par[k][v];
			}
		}
		return par[0][u];
	}
	int distance(int u, int v) {
		return dep[u] + dep[v] - dep[lca(u, v)] * 2;
	}
};
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M; cin >> N >> M;
	TwoEdgeConnectedComponent twg(N);
	FOR(i, 0, M) {
		int a, b; cin >> a >> b;
		a--, b--;
		twg.add_edge(a, b);
	}
	VVI treeG;
	VI cmp = twg.decomposition(treeG);
	LCAT LcaS(SZ(treeG));
	LcaS.G = treeG;
	LcaS.build();
	auto cmp2 = [&cmp](int a, int b) {
		return cmp[a] == cmp[b];
	};
	int Q; cin >> Q;
	FOR(_, 0, Q) {
		int a, b, c; cin >> a >> b >> c;
		a--, b--, c--;
		if (cmp2(a, b) || cmp2(b, c)) {
			cout << "OK" << endl;
		}
		else if (cmp2(a, c)) {
			cout << "NG" << endl;
		}
		else { // dist check
			int D1 = LcaS.distance(cmp[a], cmp[c]);

			int D2 = LcaS.distance(cmp[a], cmp[b]) + LcaS.distance(cmp[b], cmp[c]);
			if (D1 == D2) {
				cout << "OK" << endl;
			}
			else {
				cout << "NG" << endl;
			}
		}
	}


	return 0;
}