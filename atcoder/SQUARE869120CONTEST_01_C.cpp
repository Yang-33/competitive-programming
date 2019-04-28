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

/* -----  2019/04/28  Problem: square869120Contest_01 C / Link: __CONTEST_URL__  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, K; cin >> N >> K;
	vector<LL> D(N);
	for (int i = 0; i < N; ++i) {
		cin >> D[i];
	}
	VVI G(N);
	FOR(i, 0, K) {
		int a, b; cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	LL ans = 0;
	auto f = [&D, &G](int s) {
		LL ret = 0;

		map<LL, LL>memo;
		// 最大値のアをする
		using tp = tuple<LL, LL, LL>;
		queue<tp> q;
		// dist,p,state,
		q.push(tp(D[s], s, 1LL << s));

		while (!q.empty()) {
			LL dist, pre, state;
			tie(dist, pre, state) = q.front(); q.pop();
			ret = max(ret, dist);
			{
				if (memo.find(state) != memo.end()) {
					if (memo[state] < dist)continue;
				}
			}
			for (auto nx : G[pre]) {
				if (state & 1LL << nx)continue;
				LL nstate = state | (1LL << nx);
				if (memo.find(nstate) != memo.end()) {
					if (memo[nstate] <= dist + D[nx]) {
						memo[nstate] = dist + D[nx];
						q.push(tp(memo[nstate], nx, nstate));
					}
				}
				else {
					memo[nstate] = dist + D[nx];
					q.push(tp(memo[nstate], nx, nstate));
				}
			}
		}

		return  ret;


		return ret;
	};
	FOR(i, 0, N) {
		ans = max(ans, f(i));
	}

	cout << ans << "\n";

	return 0;
}