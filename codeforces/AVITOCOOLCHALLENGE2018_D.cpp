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

/* -----  2018/12/16  Problem: avitoCoolChallenge2018 D / Link: __CONTEST_URL__  ----- */
/* ------問題------

selfloop+multiedgeな無向連結グラフが与えられる。いくつかの頂点は特別な頂点である。
path(u,v)をuからvへの経路のうち、最大の重みの辺、
dist(u,v)をpath(u,v)のうち、最小値
とする。
特別な頂点viから最も遠い特別な頂点vjを選んだときの、それぞれの距離の最大値は?

-----問題ここまで----- */
/* -----解説等-----

最小の辺を見ていく。pathが2つ以上存在する時、最小の辺を通るもので行くことになる。(これはpathが1個しかないときの辺の最大値)
よって木である状態のみを考えれば良い。以上の考察から特別な頂点を全部含むまでufをすれば良い。
結果、最小から見ていったときの最大の辺の大きさが答えになる。

これ言い換えが難しいなあ

----解説ここまで---- */

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
	int query(int x) { return Mdata[root(x)]; }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
	void update(int x, const t val) { x = root(x); Mdata[x] = M::op(Mdata[x], val); }
};
struct info {
	using t = int;
	static t op(const t& a, const t& b) { return a + b; }
	static t id() { return 0; }
};
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, K; cin >> N >> M >> K;
	VI spe(K);
	FOR(i, 0, K) {
		cin >> spe[i]; spe[i]--;
	}
	using tp = tuple<int, int, int>;
	vector<tp>edge(M);
	FOR(i, 0, M) {
		int a, b, c; cin >> a >> b >> c; a--, b--;
		edge[i] = tp(c, a, b);
	}
	SORT(edge);
	UnionFind<info> uf(N);
	FOR(k, 0, K) {
		uf.update(spe[k], 1);
	}
	
	// 必ず連結
	FOR(i, 0, M) {
		int c, a, b; tie(c, a, b) = edge[i];
		uf.unionSet(a, b);
		if (uf.query(a) == K) {
			FOR(k, 0, K) {
				cout << c << " \n"[k == K - 1];
			}
			return 0;
		}

	}

	return 0;
}
