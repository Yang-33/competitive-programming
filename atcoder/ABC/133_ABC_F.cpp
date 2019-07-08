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

/* -----  2019/07/07  Problem: ABC 133 F / Link: http://abc133.contest.atcoder.jp/tasks/abc133_f  ----- */


struct HLD {
	int n, pos;
	vector<vector<int>> G;
	vector<int> vid, head, sub, parent, depth, inv, type;
	HLD(int nn) :
		n(nn), pos(0), G(n),
		vid(n, -1), head(n), sub(n, 1),
		parent(n, -1), depth(n), inv(n), type(n) {}

	void add_edge(int u, int v) {
		G[u].push_back(v);
		G[v].push_back(u);
	}
	void build(vector<int> rs = { 0 }) {
		int c = 0;
		for (int r : rs) {
			dfs_sz(r);
			head[r] = r;
			dfs_hld(r, c++);
		}
	}

	void dfs_sz(int v) {
		for (int &u : G[v]) {
			if (u == parent[v]) continue;
			parent[u] = v;
			depth[u] = depth[v] + 1;
			dfs_sz(u);
			sub[v] += sub[u];
			if (sub[u] > sub[G[v][0]]) swap(u, G[v][0]);
		}
	}

	void dfs_hld(int v, int c) {
		vid[v] = pos++;
		inv[vid[v]] = v;
		type[v] = c;
		for (int u : G[v]) {
			if (u == parent[v]) continue;
			head[u] = (u == G[v][0] ? head[v] : u);
			dfs_hld(u, c);
		}
	}
	void for_each_edge(int u, int v, const function<void(int, int)>&f) {
		while (1) {
			if (vid[u] > vid[v])swap(u, v);
			if (head[u] != head[v]) {
				f(vid[head[v]], vid[v]);
				v = parent[head[v]];
			}
			else {
				if (u != v)f(vid[u] + 1, vid[v]);
				break;
			}
		}
	}

};


template<typename Monoid>
struct SegmentTreeFastAry {
	using nd = typename Monoid::type;
	const int ARY_SIZE;
	vector<nd> node;
public:
	SegmentTreeFastAry(int n) : ARY_SIZE(n), node(2 * ARY_SIZE, Monoid::id()) {}
	void set_val(int i, const nd val) {
		i += ARY_SIZE; node[i] = val;
		while (i > 1) { i >>= 1;	node[i] = Monoid::op(node[i << 1], node[(i << 1) + 1]); }
	}
	inline nd query(int l, int r) {
		if (l >= r) return Monoid::id(); nd vl = Monoid::id(), vr = Monoid::id();
		for (l += ARY_SIZE, r += ARY_SIZE; l != r; l >>= 1, r >>= 1) {
			if (l & 1) vl = Monoid::op(vl, node[l++]); if (r & 1) vr = Monoid::op(node[--r], vr);
		}	return Monoid::op(vl, vr);
	}
	nd operator[](int i) { return node[i + ARY_SIZE]; }
	void debugShow() { for (int i = ARY_SIZE; i < ARY_SIZE << 1; ++i) cerr << node[i] << " "; cerr << "\n"; }
};

using PLL = pair<LL, LL>;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	struct Monoid {
		using type = PLL;
		static type id() { return PLL(0, 0); }
		static type op(const type&l, const type&r) {
			PLL ret;
			ret.first = l.first + r.first;
			ret.second = l.second + r.second;
			return ret;
		}
	};
	int N, Q; cin >> N >> Q;
	SegmentTreeFastAry<Monoid> seg(N);
	HLD G(N);
	vector<int>a, b, c, d;
	using edgetp = tuple<int, int, int>;
	vector<vector<edgetp>>Edge(N);
	FOR(i, 0, N - 1) {
		int x, y, z, w; cin >> x >> y >> z >> w;
		x--, y--, z--;
		a.push_back(x), b.push_back(y), c.push_back(z), d.push_back(w);
		Edge[z].push_back(edgetp(x, y, w));
		G.add_edge(x, y);
	}
	G.build();
	FOR(i, 0, N - 1) {
		G.for_each_edge(a[i], b[i], [&](int l, int r) {
			seg.set_val(l, PLL(d[i], 0));
		});
	}
	using querytp = tuple<int, int, int, int>;
	vector<vector<querytp>>Query(N);
	FOR(i, 0, Q) {
		int x, y, u, v; cin >> x >> y >> u >> v;
		u--, v--, x--;
		Query[x].push_back(querytp(u, v, y, i));
	}
	// look color order O(logN*(N+Q))
	vector<LL>ans(Q);
	FOR(col, 0, N) {
		// to zero,one
		for (auto it : Edge[col]) {
			int x, y, w;
			tie(x, y, w) = it;
			G.for_each_edge(x, y, [&](int l, int r) {
				seg.set_val(l, PLL(0, 1));
			});
		}

		// query
		for (auto it : Query[col]) {
			int x, y, chav, id;
			tie(x, y, chav, id) = it;
			PLL sub = PLL(0, 0);
			G.for_each_edge(x, y, [&](int l, int r) {
				sub = Monoid::op(seg.query(l, r + 1), sub);
			});
			ans[id] = sub.first + sub.second*chav;
		}

		// restore
		for (auto it : Edge[col]) {
			int x, y, w;
			tie(x, y, w) = it;
			G.for_each_edge(x, y, [&](int l, int r) {
				seg.set_val(l, PLL(w, 0));
			});
		}
	}
	for (auto it : ans) {
		cout << it << endl;
	}
	return 0;
}

