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

/* -----  2018/06/10  Problem: AOJ 2776 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2776  ----- */
/* ------問題------

スクールアイドル時代から、国民的人気を誇ってきた女性アイドルグループArai's。今では、たくさんの「あらい」さんが所属する大規模なグループとして、世界レベルで活躍している。そして今日、新たなるプロジェクトの始動が決定した。彼女たちは、小さなユニットをいくつか結成することで、さらなる売上の向上を試みることになったのである。
Arai'sには「荒井」さんがA人，「新井」さんがB人在籍しており、合計でA+B人の「あらい」さんからなる。新ユニットは、「荒井」さん一人と「新井」さん一人のペアで構成する。（ここで、同じ「あらい」さんが複数のユニットに所属していはいけない。）ただし、ある「荒井」さんが一部の「新井」さんのことを良く思っていないうえに、同様にある「新井」さんが一部の「荒井」さんのことを良く思っていない。「あらい」さんたちはユニットを組む際に、良く思っていない「あらい」さんをペアとして認めてくれず、一方でも認めてくれなければユニットを組むことはできない。
Arai'sのマネージャーであるあなたは、なるべくたくさんのユニットを作りたいと考えているが、メンバーの交友関係からその限界を感じていた。そこであなたは、「あらい」さんたちと個別に面談し、ユニットを組ませたい「あらい」さんについての、良い噂を聞かせることを考えた。面談をした「あらい」さんは、噂に聞いた「あらい」さんを見直し、ユニットのペアとして認めるようになる。
しかし、あなたはそれほど時間をとることができないため、最大K回までしか噂を聞かせることができない。あなたは限られた時間の中で、結成できるユニットの数を最大化しようと試みた。あなたが結成できるユニットの数の最大値を求めよ。

-----問題ここまで----- */
/* -----解説等-----

ぱっと見割当問題である。
なんかコストをかけて辺をはれるみたいな問題文に見える。
最小費用流をすればよい。
辺の方向があるように見えるけど、実際は変形しても良くて、双方向ならcost:0,単一ならcost:1,なければcost:2で左から右にはれば良い。
愚直に流したけど、間に合わないならK->logKとするために二分探索ができる。

----解説ここまで---- */


using ll = LL;
using pll = PLL;
struct Primal_Dual {
	struct edge {
		int to, rev;
		ll cap, cost;
		edge() {}
		edge(int to, ll cap, ll cost, int rev) :to(to), cap(cap), cost(cost), rev(rev) {}
	};
	vector<vector<edge>> graph;
	vector<int> prevv, preve;
	vector<ll> potential, min_cost;
	Primal_Dual(int V) :graph(V) {}

	void add_edge(int from, int to, ll cap, ll cost) {
		graph[from].emplace_back(to, cap, cost, graph[to].size());
		graph[to].emplace_back(from, 0, -cost, graph[from].size() - 1);
	}

	ll min_cost_flow(int s, int t, int f) {
		int V = graph.size();
		ll ret = 0;
		priority_queue<pll, vector<pll>, greater<pll>> que;
		potential.assign(V, 0);
		preve.assign(V, -1);
		prevv.assign(V, -1);

		while (f > 0) {
			min_cost.assign(V, LINF);
			que.push({ 0,s });
			min_cost[s] = 0;

			while (que.size()) {
				pll p = que.top();
				que.pop();
				if (min_cost[p.second] < p.first) continue;
				for (int i = 0; i < graph[p.second].size(); i++) {
					edge& e = graph[p.second][i];
					ll nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];
					if (e.cap > 0 && min_cost[e.to] > nextCost) {
						min_cost[e.to] = nextCost;
						prevv[e.to] = p.second; preve[e.to] = i;
						que.push(pll(min_cost[e.to], e.to));
					}
				}
			}
			if (min_cost[t] == LINF) return -1;
			for (int v = 0; v < V; v++) potential[v] += min_cost[v];
			ll add = f;
			for (int v = t; v != s; v = prevv[v]) {
				add = min(add, graph[prevv[v]][preve[v]].cap);
			}
			f -= add;
			ret += add * potential[t];
			for (int v = t; v != s; v = prevv[v]) {
				edge& e = graph[prevv[v]][preve[v]];
				e.cap -= add;
				graph[v][e.rev].cap += add;
			}
		}
		return ret;
	}
};

void solve() {
	ll A, B, K; cin >> A >> B >> K;
	vector<string> a(A), b(B);
	for (auto& in : a) cin >> in;
	for (auto& in : b) cin >> in;

	ll S = A + B, T = A + B + 1;
	Primal_Dual clojure(A + B + 2);
	for (int i = 0; i < A; i++) clojure.add_edge(S, i, 1, 0);
	for (int i = 0; i < B; i++) clojure.add_edge(A + i, T, 1, 0);

	for (int i = 0; i < A; i++) {
		for (int j = 0; j < B; j++) {
			ll cost = 0;
			if (a[i][j] == '1') cost++;
			if (b[j][i] == '1') cost++;

			clojure.add_edge(i, A + j, 1, cost);
		}
	}

	ll ans = 0;
	while (true) {
		ll ret = clojure.min_cost_flow(S, T, 1);
		//		cout << ret << endl;
		if (ret == -1) break;
		if (ret > K) break;
		K -= ret;
		ans++;
	}
	cout << ans << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}