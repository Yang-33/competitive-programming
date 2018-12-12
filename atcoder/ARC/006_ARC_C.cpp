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

/* -----  2018/12/15  Problem: ARC 006 C / Link: http://arc006.contest.atcoder.jp/tasks/arc006_c  ----- */
/* ------問題------

高橋君はもう大人なので、親元を離れて一人暮らしをすることにしました。トラックから引越し先の部屋へと荷物のダンボールを運びたいのですが、部屋の床がダンボールで埋まってしまうと、今日高橋君が寝るための布団がひけません。
　そこで、1 箱ずつ広げて置くのではなく、ある程度ダンボールを積み重ねた山を作ることにしました。しかし、ダンボールには重さが決まっており、下にあるダンボールよりも重いダンボールを上に積み重ねると下のダンボールが潰れてしまいます。

 図：下にあるダンボールは上にあるダンボール以上の重さでなければならない

 　トラックから運ぶ順にダンボールの重さが与えられるので、ダンボールを潰さないような積み重ね方を考えなさい。そして、その積み重ねた山の個数が最小となる場合の山の個数を求めなさい。


-----問題ここまで----- */
/* -----解説等-----

DAGの最小パス被覆で解ける。
貪欲でも解ける。(ア)

----解説ここまで---- */


struct FordFulkerson {
#define max_flow_MAX 1005

	struct edge {
		int to, cap, rev;
		edge() {}
		edge(int to, int cap, int rev) :to(to), cap(cap), rev(rev) {}
	};
	vector<edge> G[max_flow_MAX];
	bool used[max_flow_MAX];

	void add_edge(int from, int to, int cap) {
		G[from].emplace_back(edge(to, cap, (int)G[to].size()));
		G[to].emplace_back(edge(from, 0, (int)G[from].size() - 1));
	}
	void undir_add_edge(int from, int to, int cap) {
		G[from].emplace_back(edge(to, cap, (int)G[to].size()));
		G[to].emplace_back(edge(from, cap, (int)G[from].size() - 1));
	}

	int dfs(int v, int t, int f) {
		if (v == t)return f;
		used[v] = true;
		FOR(i, 0, (int)G[v].size()) {
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
		const int INF = INT_MAX;
		int flow = 0;
		for (;;) {
			memset(used, 0, sizeof(used));
			int f = dfs(s, t, INF);
			if (f == 0)return flow;
			flow += f;
		}
		return -1;
	}
#undef max_flow_MAX
};



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	FordFulkerson F;
	int S = 2 * N, T = 2 * N + 1;
	FOR(i, 0, N) {
		F.add_edge(S, i, 1);
		F.add_edge(N + i, T, 1);
	}
	FOR(i, 0, N) {
		FOR(j, i + 1, N) {
			if (a[i] >= a[j]) {
				F.add_edge(i, N + j, 1);
			}
		}
	}


	LL ans = N - F.max_flow(S, T);
	cout << ans << endl;

	return 0;
}