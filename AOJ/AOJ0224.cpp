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

/* -----  2019/08/14  Problem: AOJ 0224 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0224  ----- */


int main() {

	// bitmask + dijkstra
	// if mask of v? -> get cake.
	int M, N, K, D;
	// 2^M状態ある
	while (cin >> M >> N >> K >> D, K) {
		VI calorie(M); {
			FOR(i, 0, M) {
				cin >> calorie[i];
			}
		}
		vector<vector<PII>>G(N + M + 2);
		int S = N + M;
		int T = S + 1;
		FOR(i, 0, D) {
			string a, b;
			int c; cin >> a >> b >> c;
			int x = -1, y = -1;
			{
				if (a == "H")x = S;
				if (b == "H")y = S;
			}
			{
				if (a == "D")x = T;
				if (b == "D")y = T;
			}
			if (a.front() == 'L') {
				x = stoi(a.substr(1)) - 1;
			}
			if (b.front() == 'L') {
				y = stoi(b.substr(1)) - 1;
			}
			if (a.front() == 'C') {
				x = stoi(a.substr(1)) - 1 + N;
			}
			if (b.front() == 'C') {
				y = stoi(b.substr(1)) - 1 + N;
			}
			assert(x != -1);
			assert(y != -1);
			G[x].emplace_back(y, K*c);
			G[y].emplace_back(x, K*c);
		}
		VVI dist(N + M + 2, VI(1 << M, INF));
		using tp = tuple<int, int, int>;
		priority_queue<tp, vector<tp>, greater<tp>>pq;
		// 本当にIFPUSH式，良い
		auto IFPUSH = [&](int nv, int prestate, int d) {
			if (nv >= N && nv < N + M && ((prestate&(1 << (nv - N))) != 0))return;
			if (nv >= N && nv < N + M && ((prestate&(1 << (nv - N))) == 0)) {
				prestate |= 1 << (nv - N);
				d -= calorie[nv - N];
			}
			if (dist[nv][prestate] > d) {
				dist[nv][prestate] = d;
				pq.emplace(d, nv, prestate);
			}
		};
		IFPUSH(S, 0, 0);
		while (!pq.empty()) {
			int d, v, state;
			tie(d, v, state) = pq.top(); pq.pop();
			if (d > dist[v][state])continue;
			for (auto it : G[v]) {
				int nx, cost;
				tie(nx, cost) = it;
				IFPUSH(nx, state, d + cost);
			}
		}
		int ans = INF;
		FOR(state, 0, 1 << M) {
			ans = min(ans, dist[T][state]);
		}
		cout << ans << "\n";

	}

	return 0;
}
