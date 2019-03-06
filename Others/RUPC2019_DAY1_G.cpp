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

/* -----  2019/03/05  Problem: rupc2019_day1 G / Link: __CONTEST_URL__  ----- */

// bip 燃やす埋める
typedef long long LL;
typedef LL CapType;
const CapType DINIC_eps = 0; // 整数のときは0
const CapType DINIC_INF = 1e18; // よく考えて
struct DINIC {
#define  MAX_V 3500
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

	LL H, W, usecost;
	cin >> H >> W >> usecost;
	vector<vector<LL>> a(H, vector<LL>(W));
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> a[i][j];
		}
	}
	auto Bsum = [&](int i, int j) {
		LL sum = 0;
		FOR(y, i, i + 2) {
			FOR(x, j, j + 2) {
				sum += a[y][x];
			}
		}
		return sum;
	};
	auto id = [&](int i, int j) {
		return W * i + j;
	};
	DINIC F;
	LL ans = 0;
	int ON = 3000, OFF = 3001;
	FOR(i, 0, H-1) {
		FOR(j, 0, W-1) {
			if ((i + j) % 2 == 1)continue;
			LL getpoints = Bsum(i, j);
			ans += getpoints;
			if (j % 2 == 0) { // side
				F.add_edge(OFF, id(i, j), usecost);
				F.add_edge(id(i, j), ON, getpoints);
			}
			else { // rev side
				F.add_edge(OFF, id(i, j), getpoints);
				F.add_edge(id(i, j), ON, usecost);

				// ifいらん
				F.add_edge(id(i, j), id(i - 1, j - 1), a[i][j]);
				F.add_edge(id(i, j), id(i - 1, j + 1), a[i][j + 1]);
				F.add_edge(id(i, j), id(i + 1, j - 1), a[i + 1][j]);
				F.add_edge(id(i, j), id(i + 1, j + 1), a[i + 1][j + 1]);
			}
		}
	}
	ans -= F.max_flow(OFF, ON);
	cout << (ans) << "\n";

	return 0;
}
