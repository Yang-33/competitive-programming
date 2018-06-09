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

/* -----  2018/05/26  Problem: AOJ 2712 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2712  ----- */
/* ------問題------

頂点に正の値を持つ無向グラフが与えられる。 頂点には 1 から N の番号がついており、i 番目の頂点は wi の値を持っている。 1 番目の頂点からスタートし、直前に通った辺を通ることができないという制約のもとでグラフ上を移動することができる。 各頂点では，初めて訪れた時に限りその頂点が持つ値の点数を得られる。
取得できる点数の総和の最大値を求めよ。

-----問題ここまで----- */
/* -----解説等-----

とりあえず閉路がめんどくさいので、押しつぶして木にする。
閉路について考えると、問題の制約から1つでない頂点で構成されている閉路の頂点にはすべて到達することが可能でかつ、
木の根から来て根へもどるような操作が可能である。
したがって次のような情報があれば良い。
1:ある頂点に訪れて、また戻ってこれるときの最大値
2:ある頂点に訪れて、最終的に葉に到達して終了するときの最大値
これは、2回木DPをすればよい。
先に戻ってこれる値を計算して、その後、
(葉を含めたときの最大値)-(戻ってくるときの最大値)を、子から計算すれば良い。
ライブラリがバグってて辛かった(しかも原因不明)

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

	// build, renew resG(empty -> tree), return color
	vector<int> get_graph(vector<vector<int>>& resG, int root = 0) {
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

int N, M, W[100000];
vector<vector<int>> resG;
vector<int> groupW, groupSZ;

LL back[100005];
LL adv[100005];
// vを選択したときの最大値
// 頂点に2つの値を持たせる
// 葉まで行かずに返ってくる値(back)
// 葉を決めてしまう場合の値(adv)
LL ff(int v, int p = -1) {
	for (int nv : resG[v]) {
		if (nv == p)continue;
		ff(nv, v);
		back[v] += back[nv];
	}
	LL res = back[v];

	if (back[v] || groupSZ[v] > 1)back[v] += groupW[v];

	for (int nv : resG[v]) {
		if (nv == p)continue;
		adv[v] = max(adv[v], res + adv[nv] - back[nv]);
	}

	return adv[v]+=groupW[v];
}

int main() {
	int N, M; cin >> N >> M;
	FOR(i, 0, N) {
		cin >> W[i];
	}
	TwoEdgeConnectedComponent gx(N);

	FOR(i, 0, M) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		gx.add_edge(a, b);
	}
	VI vc = gx.get_graph(resG);

	groupW.assign(resG.size(), 0);
	groupSZ.assign(resG.size(), 0);
	FOR(i, 0, N) {
		groupW[vc[i]] += W[i];
		groupSZ[vc[i]]++;
	}
	LL ans = ff(vc[0]);
	cout << ans << endl;

	return 0;
}