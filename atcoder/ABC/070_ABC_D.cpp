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

/* -----  2018/02/15  Problem: 070_abc_d / Link: https://abc070.contest.atcoder.jp/tasks/abc070_d?lang=en  ----- */
/* ------問題------

N 頂点の木が与えられます。
木とはグラフの一種であり、頂点の数を N とすると、辺の数が N−1 本である閉路のない連結グラフです。
i(1≦i≦N−1) 番目の辺は 頂点 ai と 頂点 bi を距離 ci で結びます。

また、Q 個の質問クエリと整数 K が与えられます。
j(1≦j≦Q) 番目の質問クエリでは、頂点 xj から 頂点 K を経由しつつ、頂点 yj まで移動する場合の最短経路の距離を求めてください。

-----問題ここまで----- */
/* -----解説等-----

要はKからの距離を求めてと書いてあるので、d[K->x] + d[K->y]がわかれば良い。
一回ダイクストラすればいいよね

----解説ここまで---- */
void D(vector<vector<PLL>>& G, VL&dist, int s, int t) {

	const int INF = INT_MAX;
	const long long INIT_NUM = LLONG_MAX / 10;// dist の型
#define DijkV 200020

	priority_queue<PLL, vector<PLL>, greater<PLL>> que; //優先度付きqueue 降順(距離、頂点)
	que.push(PLL(0LL, s)); // push(距離,頂点)

	while (!que.empty()) {
		PLL p = que.top(); que.pop(); //queueのデータ構造
		int v; /* 頂点*/ long long d; /* 頂点vまでの距離 */
		tie(d, v) = p;

		if (d > dist[v]) continue; //最適でないならば考慮しない

		FOR(i, 0, (int)G[v].size()) { //頂点vからはi本の辺が存在
			int nv = G[v][i].first; // v->nv
			if (dist[nv] > dist[v] + G[v][i].second) {
				dist[nv] = dist[v] + G[v][i].second;
				que.push(PLL(dist[nv], nv)); //push(距離,頂点) 
			}
		}
	}

#undef DijkV
}

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	vector<vector<PLL>> G(N);
	FOR(i, 0, N-1) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		G[a].push_back(PLL(b, c));
		G[b].push_back(PLL(a, c));
	}

	int Q, K; cin >> Q >> K;
	K--;
	VL dist(N, LINF);
	dist[K] = 0;

	D(G, dist, K,N);
	FOR(i, 0, Q) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		ans = dist[x] + dist[y];
		cout << ans << "\n";
	}

	return 0;
}
