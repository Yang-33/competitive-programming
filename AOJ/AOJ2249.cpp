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

/* -----  2018/04/27  Problem: AOJ 2249 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2249  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

最短路上で、d[j] < d[i]となるiが存在するとき、1本だけ辺があればよい。
したがって頂点に関して一本のみ頂点を選択すればよく、これを貪欲にやれば良い。
頂点をうまく見れば、O(M)

----解説ここまで---- */


VL Dijkstra(vector<vector<PLL>>& G, int s) {
	VL dist(SZ(G), LINF);
	dist[s] = 0;
	priority_queue<PLL, vector<PLL>, greater<PLL>> que;
	que.push(PLL(0LL, s));

	while (!que.empty()) {
		PLL p = que.top(); que.pop();
		int v; /* 頂点*/ long long d; /* 頂点vまでの距離 */
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
	return dist;
}



LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M;
	while (cin >> N >> M, N) {
		using tp = tuple<int, int, int>;
		vector<vector<tp>>edge(N);
		vector<vector<PLL>>normalG(N);
		VI u(M), v(M), d(M), c(M);
		FOR(i, 0, M) {
			cin >> u[i] >> v[i] >> d[i] >> c[i];
			u[i]--, v[i]--;
			normalG[u[i]].push_back(PLL(v[i], d[i]));
			normalG[v[i]].push_back(PLL(u[i], d[i]));
			edge[u[i]].push_back(tp(v[i], d[i], c[i]));
			edge[v[i]].push_back(tp(u[i], d[i], c[i]));
		}


		ans = 0;//つかうやつだけ足す
		VL dist = Dijkstra(normalG, 0);

		FOR(i, 1, N) {// 始点以外
			// d[i] > d[j]について edge(j,i)がちょうどいいアレなら候補、最小を選択すれば良いO(M)
			int distmin = INF;
			FOR(j, 0, SZ(edge[i])) {
				int v, di, ci;
				tie(v, di, ci) = edge[i][j];
				if (dist[i] > dist[v] && dist[v] + di == dist[i]) {
					distmin = min(distmin, ci);
				}
			}
			
			ans += distmin;
		}

		//FOR(i, 0, SZ(editedge)) {
		//	int a, b, d, c;
		//	tie(a, b, d, c) = editedge[i];
		//	if (dist[a] + d == dist[b]) {
		//		ans += c;
		//	}
		//	else if (dist[b] + d == dist[a]) {
		//		ans += c;
		//	}
		//	else {
		//	}
		//}

		cout << ans << "\n";

	}

	return 0;
}
