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

/* -----  2019/07/07  Problem: AOJ 2520 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2520  ----- */



typedef int CapType;
const CapType DINIC_eps = 0; // 整数のときは0
const CapType DINIC_INF = 1e8; // よく考えて

struct DINIC {
#define  MAX_V 250
	struct edge {
		int to, rev; CapType cap;
		edge() {}
		edge(int to, CapType cap, int rev) :to(to), cap(cap), rev(rev) {}
	};

	vector<edge> G[MAX_V];
	int level[MAX_V], iter[MAX_V];

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
		for (int &i = iter[v]; i < (int)G[v].size(); ++i) {
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
inline int readint() { int in; scanf("%d", &in); return in; }
inline void outint(int out, bool endl = 1) { printf("%d%c", out, " \n"[endl]); }

int main() {
	int N = readint(), M = readint();
	vector<int>a(M), b(M);
	FOR(i, 0, M) {
		a[i] = readint() - 1, b[i] = readint() - 1;
	}
	FOR(i, 0, M) {
		DINIC F;
		auto in = [&](int x) {return x; };
		auto out = [&](int x) {return N + x; };
		const int S = out(0);
		const int T = N * 2;

		FOR(j, 0, N) {
			F.add_edge(in(j), out(j), 1);
		}
		FOR(j, 0, i) {
			F.add_edge(out(a[j]), in(b[j]), 1);
			F.add_edge(out(b[j]), in(a[j]), 1);
		}
		F.add_edge(out(a[i]), T, 1);
		F.add_edge(out(b[i]), T, 1);
		int res = F.max_flow(S, T);
		cout << (res == 2 ? "Yes" : "No") << "\n";
	}
}
