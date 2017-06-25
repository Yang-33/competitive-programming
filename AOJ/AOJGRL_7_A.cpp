#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/06/25  Problem: AOJ GRL_7_A  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A  ----- */
/* ------問題------

2部マッチングの基本

-----問題ここまで----- */
/* -----解説等-----

実はAOJのコースの問題解いてなかったのでやった。（あ）
各ノードをつなぎ、
片側のノードを始点に、もう片側のノードは終点にそれぞれ流量1で流すだけ。

----解説ここまで---- */


ll ans = 0LL;

#define MAX_V 1005
#define INF 100000

struct edge {
	int to, cap, rev;
	edge() {}
	edge(int to, int cap, int rev) :to(to), cap(cap), rev(rev) {}
};
vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from, int to, int cap) {
	G[from].emplace_back(edge(to, cap, (int)G[to].size()));
	G[to].emplace_back(edge(from, 0, (int)G[from].size() - 1));
}

int dfs(int v, int t, int f) {
	if (v == t)return f;
	used[v] = true;
	FOR(i, 0, G[v].size()) {
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
	int flow = 0;
	for (;;) {
		memset(used, 0, sizeof(used));
		int f = dfs(s, t, INF);
		if (f == 0)return flow;
		flow += f;
	}
	return -1;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll N, M, E;
	cin >> N >> M >> E;
	FOR(i, 0, E) {
		int x, y;
		cin >> x >> y;
		x++; y++;
		y += N;
		add_edge(x,y,1);
	}
	FOR(i, 0, N) {
		add_edge(0, i + 1, 1);
	}
	FOR(i, 0, M) {
		add_edge(i+1+N,N+M+2, 1);
	}

	ans = max_flow(0, N + M + 2);
	cout << ans << endl;

	return 0;
}
