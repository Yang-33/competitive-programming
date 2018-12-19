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

/* -----  2018/12/19  Problem: CodeForces457 E div2 / Link: http://codeforces.com/contest/916/problem/E  ----- */
/* ------問題------

根付き木に対して以下のクエリをさばけ。
1. reroot x
2. a,bを両方含む最小サイズの部分木にXを加算
3. Xの部分木の値の総和

-----問題ここまで----- */
/* -----解説等-----

部分木のrerootを学ぶ。
場合分けは3つ：
rerootされたr'と、もとのrがあるとする。

1. r'=rのとき
木全体に操作を行う
2. r'≠r∧r.parentOf(v)=r'.parentOf(v)のとき
要はrerootの影響がvの部分木には関係ないとき。
rを根としたvの部分木に操作を行う
3. r'≠r∧r.parentOf(v)≠r'.parentOf(v)のとき
rerootの影響がvの部分木に関係し、vの現在の親よりも下のrの部分木以外に操作を行う
P=r.parentOf(v)とし、根をrとしたときのPの部分木以外の区間に操作をすれば良い。区間の数は高々2.

あとはHL分解,LCAT等でこれを実現すれば良い。
rerootした後のLCAは、r->r'の辺が反転すると見れば良いので簡単。
rerootした後の親はHL分解が多分必要で、r'を目的の頂点に近づける等する必要がある。

----解説ここまで---- */

template<class T>
struct RaBIT {
	int n; vector<T> bit0, bit1;
	RaBIT(int sz) :n(sz), bit0(n + 1, 0), bit1(n + 1, 0) {}

	T subsum(vector<T>& bit, int i) {
		T s = 0;
		while (i > 0) {
			(s += bit[i]);
			i -= i & -i;
		}
		return s;
	}
	void add(vector<T>& bit, int i, T x) {
		while (i <= n) {
			(bit[i] += x);
			i += i & -i;
		}
	}
	void rangeadd(int a, int b, T x) {
		a++;
		add(bit0, a, -(x * (a - 1)));
		add(bit1, a, x);
		add(bit0, b + 1, x * b);
		add(bit1, b + 1, -x);
	}
	T query(int a, int b) {
		a++;
		return ((subsum(bit1, b) * b + subsum(bit0, b))
			- (subsum(bit1, a - 1) * (a - 1) + subsum(bit0, a - 1)));
	}
};
struct HLD {
	int n, pos;
	vector<vector<int>> G;
	vector<int> vid, head, sub, hvy, par, dep, inv, type, ps, pt;
	HLD(int nn) :
		n(nn), pos(0), G(n),
		vid(n, -1), head(n), sub(n, 1), hvy(n, -1),
		par(n), dep(n), inv(n), type(n), ps(n), pt(n) {}

	void add_edge(int u, int v) {
		G[u].push_back(v);
		G[v].push_back(u);
	}
	void build(int root = 0) {
		int c = 0;
		dfs(root);
		bfs(root, c++);
	}

	void dfs(int rt) {
		using T = pair<int, int>;
		stack<T> st;
		par[rt] = -1;
		dep[rt] = 0;
		st.emplace(rt, 0);
		while (!st.empty()) {
			int v = st.top().first;
			int &i = st.top().second;
			if (i < (int)G[v].size()) {
				int u = G[v][i++];
				if (u == par[v]) continue;
				par[u] = v;
				dep[u] = dep[v] + 1;
				st.emplace(u, 0);
			}
			else {
				st.pop();
				for (int j = 0; j < (int)G[v].size(); j++) {
					int &u = G[v][j];
					if (u == par[v]) swap(u, G[v].back());
					if (u == par[v]) continue;
					sub[v] += sub[u];
					if (sub[u] > sub[G[v].front()]) swap(u, G[v].front());
				}
			}
		}
	}

	void bfs(int r, int c) {
		using T = tuple<int, int, int>;
		stack<T> st;
		st.emplace(r, r, 0);
		while (!st.empty()) {
			int v, h;
			tie(v, h, ignore) = st.top();
			int &i = get<2>(st.top());
			if (!i) {
				type[v] = c;
				ps[v] = vid[v] = pos++;
				inv[vid[v]] = v;
				head[v] = h;
				hvy[v] = (G[v].empty() ? -1 : G[v][0]);
				if (hvy[v] == par[v]) hvy[v] = -1;
			}
			if (i < (int)G[v].size()) {
				int u = G[v][i++];
				if (u == par[v]) continue;
				st.emplace(u, (hvy[v] == u ? h : u), 0);
			}
			else {
				st.pop();
				pt[v] = pos;
			}
		}
	}
	int lca(int u, int v) {
		while (1) {
			if (vid[u] > vid[v])swap(u, v);
			if (head[u] == head[v])return u;
			v = par[head[v]];
		}
	}
	int lca(int a, int b, int c) {
		while (true) {
			if (vid[a] < vid[b]) swap(a, b);
			if (vid[a] < vid[c]) swap(a, c);
			if (vid[b] < vid[c]) swap(b, c);
			if (head[a] == head[b]) return b;
			a = par[head[a]];
		}
	}
	int find_parent(int u, int r) {
		if (u == r) return -1;
		while (vid[u] < vid[r]) {
			if (head[u] == head[r]) return inv[vid[u] + 1];
			if (par[head[r]] == u) return head[r];
			r = par[head[r]];
		}
		return par[u];
	}

	int distance(int u, int v) {
		return dep[u] + dep[v] - 2 * dep[lca(u, v)];
	}
};

int read() { int in; scanf("%d", &in); return in; }

int main() {
	int N = read(), Q = read();
	VI a(N);
	FOR(i, 0, N) {
		a[i] = read();
	}

	HLD G(N);
	FOR(i, 0, N - 1) {
		int a = read() - 1, b = read() - 1;
		G.add_edge(a, b);
	}
	G.build();
	RaBIT<LL>seg(N);
	FOR(i, 0, N) {
		seg.rangeadd(G.ps[i], G.ps[i] + 1, a[i]);
	}
	int root = 0;
	FOR(_, 0, Q) {
		int type = read();
		if (type == 1) {
			root = read() - 1;
		}
		else if (type == 2) {
			int u = read() - 1, v = read() - 1;
			int x = read();
			int Lca = G.lca(u, v, root);
			int LP = G.find_parent(Lca, root);
			if (LP == -1) {
				seg.rangeadd(0, N, x);
			}
			else if (LP == G.par[Lca]) {
				seg.rangeadd(G.ps[Lca], G.pt[Lca], x);
			}
			else {
				seg.rangeadd(G.ps[LP], G.pt[LP], -x);
				seg.rangeadd(0, N, x);
			}
		}
		else {
			int v = read() - 1;
			int vP = G.find_parent(v, root);
			LL ans = 0;
			DD(de(root, v, vP));
			if (vP == -1) {
				ans = seg.query(0, N);
			}
			else if (vP == G.par[v]) {
				ans = seg.query(G.ps[v], G.pt[v]);
			}
			else {
				ans -= seg.query(G.ps[vP], G.pt[vP]);
				ans += seg.query(0, N);
			}
			printf("%lld\n", ans);
		}
	}

	return 0;
}