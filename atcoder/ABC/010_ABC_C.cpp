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

/* -----  2019/04/12  Problem: ABC 010 C / Link: http://abc010.contest.atcoder.jp/tasks/abc010_c  ----- */

using PDL = pair<double, LL>;

vector<double> Dijkstra(vector<vector<PDL>>& G, int s) {
	vector<double> dist(SZ(G), LINF);
	dist[s] = 0;
	priority_queue<PDL, vector<PDL>, greater<PDL>> que;
	que.push(PDL(0LL, s));

	while (!que.empty()) {
		PDL p = que.top(); que.pop();
		int v; /* 頂点*/ double d; /* 頂点vまでの距離 */
		tie(d, v) = p;
		DD(de(d, v));
		if (d > dist[v]) continue;

		FOR(i, 0, (int)G[v].size()) {
			int nv = G[v][i].second;
			if (dist[nv] > dist[v] + G[v][i].first) {
				dist[nv] = dist[v] + G[v][i].first;
				que.push(PDL(dist[nv], nv));
			}
		}
	}
	return dist;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	PLL sp, tp;
	cin >> sp.second >> sp.first;
	cin >> tp.second >> tp.first;
	int Ti, V; cin >> Ti >> V;
	int N; cin >> N;
	vector<double> x(N), y(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i] >> y[i];
	}
	x.push_back(sp.second);
	y.push_back(sp.first);
	x.push_back(tp.second);
	y.push_back(tp.first);
	auto dist = [&](int a, int b) {
		return sqrt((x[a] - x[b])*(x[a] - x[b]) + (y[a] - y[b])*(y[a] - y[b]));
	};

	vector<vector<PDL>>G(N + 2);
	int S = N, T = N + 1;
	FOR(i, 0, N) {
		G[S].push_back(PDL(dist(S, i), i));
		G[i].push_back(PDL(dist(S, i), S));
		G[T].push_back(PDL(dist(T, i), i));
		G[i].push_back(PDL(dist(T, i), T));
	}
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			if (i == j)continue;
			G[i].push_back(PDL(dist(i, j), j));
		}
	}
	auto dists = Dijkstra(G, S);
	DD(de(dists[T], V*Ti));
	bool UWAKI = (dists[T] <= 1.0*V * Ti);
	auto print_yesno = [](LL yes, int mode = 0) {
		if (mode == 0) {
			cout << (yes ? "yes" : "no") << endl;
		}
		else if (mode == 1) {
			cout << (yes ? "Yes" : "No") << endl;
		}
		else if (mode == 2) {
			cout << (yes ? "YES" : "NO") << endl;
		}
		else assert(0);
	};
	print_yesno(UWAKI, 2);
	return 0;
}
