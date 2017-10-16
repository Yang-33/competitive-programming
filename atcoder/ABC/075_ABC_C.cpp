#include "bits/stdc++.h"
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

/* -----  2017/10/16  Problem: nagoya_19_06 ABC075 C / Link: https://abc075.contest.atcoder.jp/tasks/abc075_c  ----- */
/* ------問題------

自己ループと二重辺を含まない N 頂点 M 辺の無向連結グラフが与えられます。
i(1≦i≦M) 番目の辺は頂点 ai と頂点 bi を結びます。
グラフから辺を取り除いたとき、グラフ全体が非連結になるような辺のことを橋と呼びます。
与えられた M 本のうち橋である辺の本数を求めてください。

ノート
自己ループ とは、ai=bi(1≦i≦M) であるような辺 i のことをいいます。
二重辺 とは、ai=aj かつ bi=bj(1≦i<j≦M) であるような辺の組 i,j のことをいいます。
無向グラフが 連結 であるとは、グラフの任意の二頂点間に経路が存在することをいいます。

-----問題ここまで----- */
/* -----解説等-----

人のライブラリ使って恥ずかしくないのお？
実際に端の列挙を行うアルゴリズムがあるのでこれを張ります。

----解説ここまで---- */
struct UnionFind
{
	vector< int > data;

	UnionFind(int sz)
	{
		data.assign(sz, -1);
	}

	bool unite(int x, int y)
	{
		x = find(x), y = find(y);
		if (x == y) return (false);
		if (data[x] > data[y]) swap(x, y);
		data[x] += data[y];
		data[y] = x;
		return (true);
	}

	int find(int k)
	{
		if (data[k] < 0) return (k);
		return (data[k] = find(data[k]));
	}

	int size(int k)
	{
		return (-data[find(k)]);
	}
};

struct LowLink
{
	UnionFind uf;
	vector< vector< int > > g;
	vector< int > used, ord, low, parent;

	LowLink(size_t v) : g(v), used(v, 0), ord(v), low(v), uf(v), parent(v, -1) {}

	virtual void add_edge(int x, int y)
	{
		g[x].push_back(y);
		g[y].push_back(x);
	}

	void dfs(int idx, int &k, int par = -1)
	{
		used[idx] = true;
		ord[idx] = k++;
		low[idx] = ord[idx];

		for (auto &to : g[idx]) {
			if (!used[to]) {
				dfs(to, k, idx);
				low[idx] = min(low[idx], low[to]);
				parent[to] = idx;
				if (ord[idx] >= low[to]) uf.unite(idx, to);
			}
			else if (to != par) {
				low[idx] = min(low[idx], ord[to]);
			}
		}
	}

	void dfs()
	{
		int k = 0;
		dfs(0, k);
	}
};

struct ArticulationPoints : LowLink
{
	ArticulationPoints(size_t v) : LowLink(v) {}

	vector< int > build()
	{
		LowLink::dfs();
		vector< int > vs;
		int sum = 0;
		for (int i = g.size() - 1; i >= 1; i--) {
			if (parent[i] == 0) ++sum;
			else if (ord[parent[i]] <= low[i]) vs.push_back(parent[i]);
		}
		if (sum > 1)vs.push_back(0);
		sort(begin(vs), end(vs));
		vs.erase(unique(begin(vs), end(vs)), end(vs));
		return (vs);
	}
};

struct BiConnectedComponents : LowLink
{
	vector< pair< int, int > > edges;
	vector< int > comp;

	BiConnectedComponents(size_t v) : LowLink(v), comp(v) {}

	void add_edge(int x, int y)
	{
		LowLink::add_edge(x, y);
		edges.push_back(minmax(x, y));
	}

	int operator[](int k)
	{
		return (comp[k]);
	}

	vector< pair< int, int > > build(vector< vector< int > > &t)
	{
		LowLink::dfs();
		int ptr = 0;
		vector< int > cc(g.size());
		for (int i = 0; i < g.size(); i++) {
			if (i == uf.find(i)) cc[i] = ptr++;
		}

		t.resize(ptr);
		for (int i = 0; i < g.size(); i++) {
			comp[i] = cc[uf.find(i)];
		}
		vector< pair< int, int > > vs;
		for (auto &e : edges) {
			int x = comp[e.first], y = comp[e.second];
			if (x == y) continue;
			vs.emplace_back(e.first, e.second);
			t[x].push_back(y);
			t[y].push_back(x);
		}
		sort(begin(vs), end(vs));
		return (vs);
	}
};


void solve()
{
	int V, E;
	cin >> V >> E;
	BiConnectedComponents graph(V);
	vector< vector< int > > malta;
	for (int i = 0; i < E; i++) {
		int s, t;

		cin >> s >> t;
		s--; t--;
		graph.add_edge(s, t);
	}
	cout << (int)graph.build(malta).size() << endl;

}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
}