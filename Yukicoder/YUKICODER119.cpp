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

/* -----  2018/04/24  Problem: yukicoder 119  / Link: http://yukicoder.me/problems/no/119  ----- */
/* ------問題------

N個の国があります。
国は０番目からN-1番目と数えます。
A君はN個の国から旅行に行きたい国を選びました。
A君は必ず小さい番目の国から順に旅行に出かけます。

旅行会社に行くと各国にはそれぞれ１つのツアーがあるようでした。
ただし、旅行会社のツアーというものは良いものもあれば、
返って自由度が減って嫌なものもあります。
ツアーに行くか行かないかで満足度が設定されています。

また、旅行会社の人が言うには、あるツアーに行ったら別の国のツアーにも参加しないといけない。
という条件がいくつかあるようでした。
例えば、

・x番目の国のツアーに行ったらy番目の国のツアーに行かなければならない(x<y)

というような条件です。
もし、x番目の国とy番目の国の両方に行くならこの条件が発生します。
A君は理由はよくわからないけど条件を呑むことにしました。
旅行の全行程を通して満足度は加算されていきます。
A君はより多くの満足度を得たいです。
最大の満足度を答えなさい。

すなわち、それぞれ条件をみたすのなら、
・x番目の国に行かない。
・x番目の国に行くけど、ツアーには参加しない。
・x番目の国に行き、ツアーにも参加する。
のどれかの選択ができるということである。

-----問題ここまで----- */
/* -----解説等-----

両方選択しないのをpspっぽく表現するのがミソ。
sample3から、そもそも行かない場合を考えたい。これは利得を0にするとみれるので、両側をカットしたい気持ちになる。
頂点を倍化して同じ頂点にINFを貼っておけば良さそうで、実際よい。

----解説ここまで---- */

typedef LL CapType;
const CapType DINIC_eps = 0;
const CapType DINIC_INF = 1e18;
struct DINIC {
#define  MAX_V 100
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
};

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	DINIC F;
	int S = 2 * N;
	int T = S + 1;
	FOR(i, 0, N) {
		int tour, rej; cin >> tour >> rej;
		ans += tour + rej;
		F.add_edge(S, i, tour);
		F.add_edge(i, i + N, INF);
		F.add_edge(N + i, T, rej);
	}
	int M; cin >> M;
	FOR(i, 0, M) {
		int u, v;
		cin >> u >> v;
		F.add_edge(u, N+v, INF);
	}
	LL ret = F.max_flow(S, T);
	ans -= ret;

	cout << ans << "\n";

	return 0;
}
