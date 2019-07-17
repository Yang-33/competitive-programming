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

/* -----  2019/07/15  Problem: HUPC2019day2 E / Link: __CONTEST_URL__  ----- */

inline LL in() { LL in; scanf("%lld", &in); return in; }
inline void outLL(LL out, bool endl = 1) { printf("%lld%c", out, " \n"[endl]); }

// 負辺を解消するためにINF-Pan[i]をする(これは1回しかないので問題ない)
void solve1() {
	LL N = in(), M = in(), K = in();
	VL Pan(N); FOR(i, 0, N)Pan[i] = in();
	VL vType(N); FOR(i, 0, N)vType[i] = in() - 1;
	VL Jam(N); FOR(i, 0, N)Jam[i] = in();

	vector<vector<PLL>>G(N);
	FOR(i, 0, M) {
		int a = in() - 1, b = in() - 1, t = in();
		G[a].emplace_back(b, t);
		G[b].emplace_back(a, t);
	}
	VVL dist(N, VL(2, LINF));
	using tp = tuple<LL, LL, LL>;
	priority_queue <tp, vector<tp>, greater<tp>>pq;
	auto IFPUSH = [&](int v, int f, LL cost) {
		if (dist[v][f] > cost) {
			dist[v][f] = cost;
			pq.push(tp(cost, v, f));
		}
	};
	IFPUSH(0, 0, 0);
	IFPUSH(0, 1, INF - Pan[0]);
	while (!pq.empty()) {
		LL d, v, f; tie(d, v, f) = pq.top(); pq.pop();
		if (dist[v][f] < d)continue;
		if (f == 0)IFPUSH(v, 1, d + (INF - Pan[v]));
		for (auto it : G[v]) {
			LL nx, addc; tie(nx, addc) = it;
			IFPUSH(nx, f, d + addc);
		}
	}
	auto chmax = [](LL &a, const LL b) {
		a = max(a, b);
	};
	VL ans(K, -LINF); {
		FOR(i, 0, N) {
			chmax(ans[vType[i]], Jam[i] - dist[i][0] - (dist[i][1] - INF));
		}
	}

	for (auto it : ans) {
		outLL(it);
	}
}

// Pan[i]-distを最大化
// 最短路を求めた際にPan[i]-optminDist[i]をもつiは候補(Panは固定、distは最小なので全体で最大)
// これを大きい順に広げていく(ただし更新は無限にならないように1回だけ)

// なんかパン屋から降りていくイメージが良い
void solve2() {
	LL N = in(), M = in(), K = in();
	VL Pan(N); FOR(i, 0, N)Pan[i] = in();
	VL vType(N); FOR(i, 0, N)vType[i] = in() - 1;
	VL Jam(N); FOR(i, 0, N)Jam[i] = in();

	vector<vector<PLL>>G(N);
	FOR(i, 0, M) {
		int a = in() - 1, b = in() - 1, t = in();
		G[a].emplace_back(b, t);
		G[b].emplace_back(a, t);
	}
	VL dist(N, LINF);
	using tp = tuple<LL, LL>;
	priority_queue <tp, vector<tp>, greater<tp>>pq;
	auto IFPUSH = [&](int v, LL cost) {
		if (dist[v] > cost) {
			dist[v] = cost;
			pq.push(tp(cost, v));
		}
	};
	IFPUSH(0, 0);
	while (!pq.empty()) {
		LL d, v; tie(d, v) = pq.top(); pq.pop();
		if (dist[v] < d)continue;
		for (auto it : G[v]) {
			LL nx, addc; tie(nx, addc) = it;
			IFPUSH(nx, d + addc);
		}
	}
	auto chmax = [](LL &a, const LL b) {
		a = max(a, b);
	};
	VL ans(K, -LINF); {
		priority_queue<PLL>pq2;
		FOR(i, 0, N) {
			pq2.push(PLL(Pan[i] - dist[i], i));
		}
		VL dist2(N, -LINF);
		while (!pq2.empty()) {
			LL d, v;
			tie(d, v) = pq2.top(); pq2.pop();
			if (dist2[v] > -LINF)continue;
			dist2[v] = d;
			chmax(ans[vType[v]], Jam[v] - dist[v] + d);
			for (auto it : G[v]) {
				LL nx, addc; tie(nx, addc) = it;
				if (dist2[nx] == -LINF) {
					pq2.push(PLL(d - addc, nx));
				}
			}

		}
	}


	for (auto it : ans) {
		outLL(it);
	}

}

int main() {
	//solve1();
	solve2();
	return 0;
}
