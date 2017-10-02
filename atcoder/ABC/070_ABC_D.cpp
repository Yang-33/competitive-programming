#include "bits/stdc++.h"
using namespace std;

typedef long long LL;

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

/* -----  2017/10/02  Problem: Nagoya_univ_contest16_d  / Link: http://abc070.contest.atcoder.jp/tasks/abc070_d  ----- */
/* ------問題------

N 頂点の木が与えられます。
木とはグラフの一種であり、頂点の数を N とすると、辺の数が N−1 本である閉路のない連結グラフです。
i(1≦i≦N−1) 番目の辺は 頂点 ai と 頂点 bi を距離 ci で結びます。

また、Q 個の質問クエリと整数 K が与えられます。

j(1≦j≦Q) 番目の質問クエリでは、頂点 xj から 頂点 K を経由しつつ、頂点 yj まで移動する場合の最短経路の距離を求めてください。

-----問題ここまで----- */
/* -----解説等-----

木の上でKを経由するのは、Kから移動するのと変わらない。
したがってダイクストラ or dfsを頂点Kからやって、dist[x]+dist[y]をすればよい。

----解説ここまで---- */

LL N, Q, K;
typedef pair<long long, long long >PLL;
LL ans = 0LL;
vector<vector<PLL>> G;

#define DijkV 100005
long long dist[DijkV];
void Dijkstra(int s, int t) {
	const long long INIT_NUM = LLONG_MAX / 10;
	FOR(i, 0, DijkV)dist[i] = INIT_NUM;

	dist[s] = 0;
	priority_queue<PLL, vector<PLL>, greater<PLL>> que;
	que.push(PLL(0LL, s));

	while (!que.empty()) {
		PLL p = que.top(); que.pop();
		LL v;  LL d;
		tie(d, v) = p;

		if (d > dist[v]) continue;

		FOR(i, 0, (int)G[v].size()) {
			int nv = G[v][i].first;
			if (dist[nv] > dist[v] + G[v][i].second) {
				dist[nv] = dist[v] + G[v][i].second;
				que.push(PLL(dist[nv], nv));
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	G = vector<vector<PLL>>(N+1);
	int a, b, c;

	FOR(i, 0, N - 1) {
		cin >> a >> b >> c;
		G[a].push_back(PLL(b, c));
		G[b].push_back(PLL(a, c));
	}
	cin >> Q >> K;
	Dijkstra(K, 0);

	int x, y;
	FOR(i, 0, Q) {
		cin >> x >> y;
		cout << dist[x] + dist[y] << endl;
	}


	return 0;
}