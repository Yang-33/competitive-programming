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

/* -----  2018/06/10  Problem: AOJ 2304 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2304  ----- */
/* ------問題------

有向グラフGがある。
これのs,tからフローを流す。
このとき辺の方向は適当に決めて良い。流量を最大化したとき、反転した辺の数とそのidを出力せよ。

-----問題ここまで----- */
/* -----解説等-----

残余グラフで、cap==2なら逆向きに流れている。これがもとの有向辺とおなじなら、反転したことになる。

----解説ここまで---- */

struct FF {
#define MS  1005
	struct edge {
		int to, cap, rev;
		edge() {}
		edge(int to, int cap, int rev) :to(to), cap(cap), rev(rev) {}
	};
	vector<edge>G[MS];
	bool used[MS];

	void add_edge(int from, int to, int cap) {
		G[from].emplace_back(edge(to, cap, (int)G[to].size()));
		G[to].emplace_back(edge(from, cap, (int)G[from].size() - 1));
	}
	int dfs(int v, int t, int f) {
		if (v == t)return f;
		used[v] = 1;
		FOR(i, 0, SZ(G[v])) {
			edge &e = G[v][i];
			if (!used[e.to] && e.cap > 0) {
				int d = dfs(e.to, t, min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
	int max_flow(int s, int t) {
		const int inf = INT_MAX;
		int flow = 0;
		for (;;) {
			memset(used, 0, sizeof(used));
			int f = dfs(s, t, inf);
			if (f == 0)return flow;
			flow += f;
		}
		return -1;
	}
#undef MS
};
using pll = PLL;
int main() {

	int N, M; int s, t;
	// 1-index
	cin >> N >> M;
	vector<VI> G(N);
	FF F;
	vector<pll>inedge(M);
	FOR(i, 0, M) {
		int x, y;
		cin >> x >> y;
		x--, y--;

		inedge[i] = pll(x, y);
		F.add_edge(x, y, 1);
		G[x].push_back(y);
	}
	cin >> s >> t;
	s--, t--;
	cout << F.max_flow(s, t) << endl;
	set<int> ans;
	FOR(i, 0, M) {
		int x, y; tie(x, y) = inedge[i];
		FOR(j, 0, SZ(F.G[x])) {
			int nv = F.G[x][j].to;
			if (nv == y) { // 本来の有向辺
				if (F.G[x][j].cap == 2) {
					ans.insert(i);
				}
			}
		}
	}

	cout << SZ(ans) << endl;
	for (auto it : ans) {
		cout << it + 1 << endl;
	}

	return 0;
}