#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,s,e) for(int (i) = (s); (i) < (e); (i)++)
#define debug(x) cout  << #x << ": " << x << endl
#define ALL(x) (x).begin(),(x).end()
const ll LINF = 1e16;

/* -----  2017/06/27  Problem: ICPC国内予選2009E / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1163&lang=jp  ----- */
/* ------問題------

最大二部マッチング

-----問題ここまで----- */
/* -----解説等-----

最大流でOK。始点と終点、およびgcd()≧2の点に辺を張ればよい。

----解説ここまで---- */

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
#define INF 100000
#define MAXV 1050

struct edge {
	int to, cap, rev;
	edge() {}
	edge(int to,int cap,int rev) :to(to),cap(cap),rev(rev){}
};
vector<edge> G[MAXV];
bool used[MAXV];

void add_edge(int from, int to, int cap) {
	G[from].emplace_back(edge(to, cap, (int)G[to].size()));
	G[to].emplace_back(edge(from, 0, (int)G[from].size() - 1));
}

int dfs(int v, int t, int f) {
	if (v == t)return f;
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++) {
		edge&e = G[v][i];
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
		if (f == 0) return flow;
		flow += f;
	}
	return -1;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	int m, n;
	int b[550];
	int r[550];
	while (cin >> m >> n, m) {
		for (int i = 0; i < 550; i++) {
			b[i] = r[i] = 0;
		}

		for (int i = 0; i < MAXV; i++) {
			G[i].clear();
		}

		for (int i = 1; i <= m; i++) cin >> b[i];
		for (int i = 1; i <= n; i++) cin >> r[i];

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (gcd(b[i], r[j]) >= 2) {
					add_edge(i, m + j, 1);
				}
			}
		}


		for (int i = 1; i <= m; i++) {
			add_edge(0, i, 1);
		}
		for (int i = m + 1; i <= m + n; i++) {
			add_edge(i,m+n+1, 1);
		}

		cout << max_flow(0, m+n+1) << endl;

	}
	return 0;
}