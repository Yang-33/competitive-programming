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

/* -----  2018/06/24  Problem: AOJ 1615 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1615  ----- */
/* ------問題------

プレゼント交換会

-----問題ここまで----- */
/* -----解説等-----

上限と下限について、超適当に範囲を大きくすると流せる。
範囲を狭めたり下限を大きくするとダメなので、単調性が存在する。
あとは上限下限付きでしゃくとりをする。

----解説ここまで---- */


typedef long long LL;
typedef LL CapType;
const CapType DINIC_eps = 0; // 整数のときは0
const CapType DINIC_INF = 1e18; // よく考えて
struct DINIC_LIMIT {
#define  MAX_V 6000
	struct edge {
		int to, rev; CapType cap;
		edge() {}
		edge(int to, CapType cap, int rev) :to(to), cap(cap), rev(rev) {}
	};

	vector<edge> G[MAX_V];
	LL level[MAX_V], iter[MAX_V];


	int S; int T;
	CapType sum_L;
	DINIC_LIMIT(int n) :S(n), T(n + 1) { /*cout << "need to N+2 vertexes" << endl; assert(0);*/ }
	// !! attention ->[L,R]
	void add_edge_limit(int from, int to, CapType L, CapType R) {
		add_edge(from, to, R - L);
		// Three lines below should have no effect if lb == 0.
		add_edge(S, to, L);
		add_edge(from, T, L);
		sum_L += L;
	}

	// -1:cant flow under limit : L
	CapType max_flow_limit(int s, int t) {
		CapType A = max_flow(S, T);
		CapType B = max_flow(s, T);
		CapType C = max_flow(S, t);
		CapType D = max_flow(s, t);
		return (A + C == sum_L && A + B == sum_L) ? B + D : -1;

	}

	void add_edge(int from, int to, CapType cap) {
		G[from].push_back(edge(to, cap, G[to].size()));
		G[to].push_back(edge(from, 0, G[from].size() - 1));
	}

	void bfs(int s) {
		memset(level, -1, sizeof(level));
		queue<int> q;
		level[s] = 0;
		q.push(s);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			FOR(i, 0, (int)G[v].size()) {
				edge &e = G[v][i];
				if (e.cap > DINIC_eps && level[e.to] < 0) {
					level[e.to] = level[v] + 1;
					q.push(e.to);
				}
			}
		}
	}

	CapType dfs(int v, int t, CapType f) {
		if (v == t) return f;
		for (LL &i = iter[v]; i < (int)G[v].size(); ++i) {
			edge &e = G[v][i];
			if (e.cap > DINIC_eps && level[v] < level[e.to]) {
				CapType d = dfs(e.to, t, min(f, e.cap));
				if (d > DINIC_eps) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	CapType max_flow(int s, int t) {
		CapType flow = 0;
		while (true) {
			bfs(s);
			if (level[t] < 0) return flow;
			memset(iter, 0, sizeof(iter));
			CapType f;
			while ((f = dfs(s, t, DINIC_INF)) > 0)
				flow += f;
		}
	}
	bool used[MAX_V];
	int countdfs(int v) {
		int ret = 0;
		used[v] = 1;
		ret++;
		FOR(i, 0, (int)G[v].size()) {
			int u = G[v][i].to;
			if (G[v][i].cap > DINIC_eps && !used[u])ret += countdfs(u);
		}
		return ret;
	}
};

bool ok(int L, int R, DINIC_LIMIT F, int S,int N ,int M) {
	// Sからはる
	int T = S + 1;
	FOR(i, 0, N) {
		F.add_edge_limit(S, i, L, R);
	}

	int FLOW = F.max_flow_limit(S, T);
	return FLOW == M;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M;
	while (cin >> N >> M, N) {
		DINIC_LIMIT F(N + M + 2);
		int S = N + M, T = S + 1;
		FOR(i, 0, M)F.add_edge_limit(N + i, T, 0, 1);
		FOR(i, 0, M) {
			int a, b;
			cin >> a >> b;
			a--, b--;
			F.add_edge_limit(a, N + i, 0, 1);
			F.add_edge_limit(b, N + i, 0, 1);
		}
		int ansL = 0;
		int ansR = N;

		for (int l = 0, r = 0; l <N; l++) {
			while (r <= N && !ok(l, r, F, S, N, M))r++;
			if (r > N)break;
			if (r - l <= ansR - ansL) {
				ansR = r; ansL = l;
			}
		}
		cout << ansL << " " << ansR << endl;
	}


	return 0;
}
