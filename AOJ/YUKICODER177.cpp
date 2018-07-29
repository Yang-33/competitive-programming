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

/* -----  2018/07/28  Problem: yukicoder 177  / Link: http://yukicoder.me/problems/no/177  ----- */
/* ------問題------

新人制作進行の宮森あおいは2日間で仕上げなければならないカット(絵のこと)をWカットを抱えていた。
そこで彼女はN人の原画マンとM人の作画監督に次のように依頼することにした。(原画マンはカットを描く人、作画監督はカットを仕上げる人です。)
1日目にN人の原画マンにカットを描いてもらい、2日目にM人の作画監督にそのカットを仕上げてもらう。
i番目の原画マンは1日にJiカット描くことができる。
i番目の作画監督は1日にCiカット仕上げることができる。
しかし、困ったことにi番目の作画監督はQi人(X1, X2, ⋯ ,XQi)の原画マンと絵柄が合わず、そのQi人の原画マンが描いたカットを仕上げることはできない。
新人制作進行宮森あおいが無事Wカットを仕上げることができるか心配になったあなたは、それを判定するプログラムを書くことにした。

-----問題ここまで----- */
/* -----解説等-----

最大流。W以上流せるかを判定すればよい。
原画マンと作画監督への辺は、0orINFで後は最適にやってくれる。

----解説ここまで---- */


typedef LL CapType;
const CapType DINIC_eps = 0; // 整数のときは0
const CapType DINIC_INF = 1e18; // よく考えて
struct DINIC {
#define  MAX_V 120
	struct edge {
		int to, rev; CapType cap;
		edge() {}
		edge(int to, CapType cap, int rev) :to(to), cap(cap), rev(rev) {}
	};

	vector<edge> G[MAX_V];
	LL level[MAX_V], iter[MAX_V];

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


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int W, N; cin >> W >> N;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	int M; cin >> M;
	VI b(M);
	FOR(i, 0, M) {
		cin >> b[i];
	}

	DINIC F;
	int S = N + M;
	int T = S + 1;

	FOR(i, 0, N) {
		F.add_edge(S, i, a[i]);
	}
	FOR(i, 0, M) {
		F.add_edge(N + i, T, b[i]);
	}
	FOR(i, 0, M) {
		int ed[50] = {};
		int Q; cin >> Q;
		FOR(j, 0, Q) {
			int x; cin >> x;
			ed[x - 1] = 1;
		}
		FOR(j, 0, N) {
			if (!ed[j])F.add_edge(j, N + i, INF);
		}
	}
	LL flows = F.max_flow(S, T);


	cout << (W <= flows ? "SHIROBAKO" : "BANSAKUTSUKITA") << "\n";

	return 0;
}