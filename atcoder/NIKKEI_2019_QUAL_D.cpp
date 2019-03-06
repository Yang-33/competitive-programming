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

/* -----  2019/01/27  Problem: nikkei_2019_qual D / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	VVI G(N);
	VI indeg(N+1, 0);
	FOR(i, 0, N + M - 1) {
		int a, b; cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
		indeg[b]++;
	}

	/*VI di(N + 1, INF);
	priority_queue<PII, vector<PII>,greater<PII>>pq;
	FOR(i, 1, N+1) {
		if (indeg[i] == 0) {
			pq.push(PII(0,i));
			di[i] = 0;
			DD(de(i));
		}
	}
	VI par(N+1, 0);
	while (!pq.empty()) {
		int d, v;
		tie(d, v) = pq.top(); pq.pop();
		if(d!= di[v])continue;
		for (auto nx : G[v]) {
			if (d - 1 < di[nx]) {
				di[nx] = d - 1;
				par[nx] = v;
				DD(de(nx, v));
				pq.push(PII(d - 1, nx));
			}
		}
	}
*/

	auto f = [](const VVI&g) {
		int n = (int)g.size(), k = 0;
		vector<int> ord(n, 0), in(n, 0);
		for (int i = 0; i < (int)g.size(); i++)
			for (int j = 0; j < (int)g[i].size(); j++)
				in[g[i][j]]++;

		queue<int> q;
		for (int i = 0; i < n; ++i)
			if (in[i] == 0) q.push(i);

		while (q.size()) {
			int v = q.front(); q.pop();
			ord[k++] = v;
			for (int i = 0; i < (int)g[v].size(); i++)
				if (--in[g[v][i]] == 0) q.push(g[v][i]);
		}
		return ord;
	};

	auto c = f(G);
	VI par(N, 0);
	VI di(N, 0);
	for (int id : c) {
		for (int nx : G[id]) {
			if (di[nx] < di[id] + 1) {
				di[nx] = di[id] + 1;
				par[nx] = id;
			}
		}
	}

	FOR(i, 1, N+1) {
		if (c[0] == i-1)cout << 0 << endl;
		else cout << par[i-1]+1 << endl;
	}





	return 0;
}
