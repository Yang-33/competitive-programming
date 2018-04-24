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

/* -----  2018/04/24  Problem: yukicoder 114  / Link: http://yukicoder.me/problems/no/114  ----- */
/* ------問題------

簡単に言うと、無向でコスト付きのグラフが与えられる。
グラフの中の点のいくつかは"重要"な点だと考えられている。
そのいくつかの重要な頂点を"全て"連結にするような部分木で木の辺のコストの和が最小となるようなものを考えたい。
その時のコストの和を出力するという問題。

-----問題ここまで----- */
/* -----解説等-----

場合分け解法をね
T≦13のとき、最小シュタイナー木を求める。(http://www.prefield.com/algorithm/dp/steiner_tree.html)
そうでないとき、T個は使用するとして、N-T個の頂点の使用するかどうかを全探索する。
その後その頂点を使用しても良いとして、最小全域木を求める。これのうち条件を満たすもので最小のものが答え。

O(min({シュタイナー木の方}、2^(N-T)*MlogM)) 

----解説ここまで---- */

int OPT[1 << 14][40];

int minimum_steiner_tree(const vector<int>& T, const VVI &g) {
	const int n = g.size();
	const int numT = T.size();
	if (numT <= 1) return 0;
	
	VVI d(g); 
	/// FOR(i, 0, n)d[i][i] = 0;
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);


	for (int p = 0; p < numT; ++p) // trivial case
		for (int q = 0; q < n; ++q)
			OPT[1 << p][q] = d[T[p]][q];

	for (int i = 1; i<1 << numT; i++)if (((i - 1) & i) != 0) {
		for (int j = 0; j<n; j++) {
			OPT[i][j] = INF;
			for (int k = (i - 1)&i; k > 0; k = (k - 1) & i) {
				OPT[i][j] = min(OPT[i][j], OPT[k][j] + OPT[i^k][j]);
			}
		}
		for (int j = 0; j<n; j++) {
			for (int k = 0; k<n; k++) {
				OPT[i][j] = min(OPT[i][j], OPT[i][k] + d[k][j]);
			}
		}
	}

	return OPT[(1 << numT) - 1][T[0]];

}


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

struct edge {
	int f, t, c;
	edge() {}
	edge(int x, int y, int z) :f(x), t(y), c(z) {}
	bool operator < (const edge &e) const { return c < e.c; };
};


LL kruskal(const vector<edge>& es,const VI &use,const VI& Ts ,LL cur) {
	//sort(es.begin(), es.end());
	UnionFind uf(SZ(use));
	LL min_cost = 0;
	FOR(i, 0, SZ(es)) {
		if (use[es[i].f] && use[es[i].t])
			if (!uf.same(es[i].f, es[i].t)) {
				min_cost += es[i].c;
				if (cur < min_cost)return INF;
				uf.unionSet(es[i].f, es[i].t);
			}
	}
	FOR(i, 0, SZ(Ts)) {
		if (!uf.same(Ts[0], Ts[i]))return  INF;
	}

	return min_cost;
}





int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, T; cin >> N >> M >> T;
	VVI G(N, VI(N, INF));
	FOR(i, 0, N)G[i][i] = 0;
	vector<edge>edges(M);
	FOR(i, 0, M) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		G[a][b] = G[b][a] = c;
		edges[i] = edge(a, b, c);
	}

	VI t(T);
	FOR(i, 0, T) {
		cin >> t[i];
		t[i]--;
	}
	LL ans;
	if (T < 14) {
		ans = minimum_steiner_tree(t, G);
	}
	else { // Tに含まれないものを全探索
		VI now_using(N, 0);
		FOR(i, 0, T)now_using[t[i]] = 1;
		int cn = N - T;
		VI candidates;
		FOR(i, 0, N) {
			if (!now_using[i])candidates.push_back(i);
		}
		SORT(edges);

		ans = INF;
		FOR(state, 0, 1 << cn) {
			FOR(i, 0, cn) {
				if (state & 1 << i) {
					now_using[candidates[i]] = 1;
				}
			}
			ans = min(ans, kruskal(edges, now_using,t,ans));
			FOR(i, 0, cn) {
				if (state & 1 << i) {
					now_using[candidates[i]] = 0;
				}
			}

		}

	}

	cout << ans << "\n";

	return 0;
}
