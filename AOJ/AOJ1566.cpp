#include <bits/stdc++.h>
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

/* -----  2018/02/05  Problem: AOJ 1566 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1566  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

制約が小さいことを活かしてマッチングできるのでは？となるが、2回目以降は 幸福度50となる制約をフローに表現するのは難しい。
かならず31日間映画を見るとあるので、100の日を重複せずに何日作ることができるかを考えれば良い。
これは簡単な二部マッチングとなり、フローで解くことができる。

priority_queueで解くこともできて、詰まってない順に時系列の問題っぽく解いてもできる。(正当性は明らか)

----解説ここまで---- */

LL N;

LL ans = 0LL;

typedef long long LL;
typedef LL CapType;
const CapType DINIC_eps = 0; // 整数のときは0
const CapType DINIC_INF = 1e18; // 整数のときは0
struct DINIC {
#define  MAX_V 150
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

	cin >> N;
	VI a(N), b(N);
	FOR(i,0,N){
		cin>>a[i]>>b[i];
		a[i]--;b[i]--;
	}
	ans = 1550;
	DINIC F;
	int S = 0;
	int T = 31+N+1;
	FOR(i,1,N+1){
		F.add_edge(S,i,50);
	}
	FOR(i,0,N){
		FOR(to,a[i],b[i]+1)
			F.add_edge(i+1,to+N+1,50);
	}
	FOR(i,N+1,N+32){
		F.add_edge(i,T,50);
	}
	LL res = F.max_flow(S,T);
	ans = res+ ans;

	cout << ans << "\n";

	return 0;
}
