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

/* -----  2019/05/19  Problem: ABC 126 D / Link: http://abc126.contest.atcoder.jp/tasks/abc126_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	vector<vector<PLL>> G(N);
	FOR(i, 0, N-1) {
		int a, b; cin >> a >> b;
		LL w; cin >> w;
		a--, b--;
		G[a].push_back(PLL(b, w));
		G[b].push_back(PLL(a, w));
	}
	VI color(N, 0);
	function<void(int, int, LL)>f = [&](int v, int p, LL ws) {

		for (auto it : G[v]) {
			int nx = it.first;
			LL w = it.second;
			if (p == nx)continue;
			if (w % 2 == 1) {
				color[nx] = !color[v];
			}
			else {
				color[nx] = color[v];
			}
			f(nx, v, ws);
		}
	};
	color[0] = 0;
	f(0, -1, 0);
	FOR(i, 0, N) {
		cout << color[i] << endl;
	}

	return 0;
}
