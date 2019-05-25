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

/* -----  2019/05/25  Problem: chokudai_speedrun2 K / Link: __CONTEST_URL__  ----- */
struct HopcroftKarp {
	vector< vector< int > > graph;
	vector< int > dist, match;
	vector< bool > used, vv;

	HopcroftKarp(int n, int m) : graph(n), match(m, -1), used(n) {}

	void add_edge(int u, int v) {
		graph[u].push_back(v);
	}

	void bfs() {
		dist.assign(graph.size(), -1);
		queue< int > que;
		for (int i = 0; i < graph.size(); i++) {
			if (!used[i]) {
				que.emplace(i);
				dist[i] = 0;
			}
		}

		while (!que.empty()) {
			int a = que.front();
			que.pop();
			for (auto &b : graph[a]) {
				int c = match[b];
				if (c >= 0 && dist[c] == -1) {
					dist[c] = dist[a] + 1;
					que.emplace(c);
				}
			}
		}
	}

	bool dfs(int a) {
		vv[a] = true;
		for (auto &b : graph[a]) {
			int c = match[b];
			if (c < 0 || (!vv[c] && dist[c] == dist[a] + 1 && dfs(c))) {
				match[b] = a;
				used[a] = true;
				return (true);
			}
		}
		return (false);
	}

	int bipartite_matching() {
		int ret = 0;
		while (true) {
			bfs();
			vv.assign(graph.size(), false);
			int flow = 0;
			for (int i = 0; i < graph.size(); i++) {
				if (!used[i] && dfs(i)) ++flow;
			}
			if (flow == 0) return (ret);
			ret += flow;
		}
	}

	void output() {
		for (int i = 0; i < match.size(); i++) {
			if (~match[i]) {
				cout << match[i] << "-" << i << endl;
			}
		}
	}
};

template<typename M>
struct UnionFind {
	using t = typename M::t;
	vector<int> data;
	vector<t>Mdata;
	UnionFind(int n) { data.assign(n, -1); Mdata.assign(n, M::id()); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			Mdata[x] = M::op(Mdata[x], Mdata[y]);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	t query(int x) { return Mdata[root(x)]; }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
	void add(int x, const t val) { x = root(x); Mdata[x] = M::op(Mdata[x], val); }
	void update(int x, const t val) { x = root(x); Mdata[x] = M::upd(Mdata[x], val); }
};


void solve_flow() {
	LL N;
	cin >> N;
	VL a(N), b(N);
	VL d;
	vector<PLL>c;
	FOR(i, 0, N) {
		cin >> a[i] >> b[i];
		if (a[i] > b[i])swap(a[i], b[i]);
		c.push_back(PLL(a[i], b[i]));
		d.push_back(a[i]);
		d.push_back(b[i]);
	}
	SORT(d);
	UNIQ(d);

	HopcroftKarp F(N, SZ(d));
	FOR(i, 0, N) {
		int j = lower_bound(ALL(d), a[i]) - d.begin();
		int k = lower_bound(ALL(d), b[i]) - d.begin();
		F.add_edge(i, j);
		F.add_edge(i, k);
	}
	LL ans = F.bipartite_matching();


	cout << (ans) << "\n";
}
void solve_uf() {
	LL N;
	cin >> N;
	VL a(N), b(N);
	VL d;
	FOR(i, 0, N) {
		cin >> a[i] >> b[i];
		d.push_back(a[i]);
		d.push_back(b[i]);
	}
	SORT(d);
	UNIQ(d);
	struct info {
		using t = int;
		static t op(const t& a, const t& b) { return (a + b); }
		static t upd(const t& a, const t& b) { return b; }
		static t id() { return 0; }
	};
	UnionFind<info>uf(SZ(d));
	FOR(i, 0, N) {
		int j = lower_bound(ALL(d), a[i]) - d.begin();
		int k = lower_bound(ALL(d), b[i]) - d.begin();
		uf.unionSet(j, k);
		uf.add(k, 1);
	}
	LL ans = 0;
	FOR(i, 0, SZ(d)) {
		if (uf.root(i) == i) {
			ans += min(uf.size(i), uf.query(i));
		}
	}


	cout << (ans) << "\n";

}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve_uf();

	return 0;
}
