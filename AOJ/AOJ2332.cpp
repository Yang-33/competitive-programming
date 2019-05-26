#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = int;
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
//const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);

/* -----  2019/05/26  Problem: AOJ 2332 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2332  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	vector<LL> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	// p >= a.back()がゴール
	// それぞれのマスはほぼ1度しか訪れない
	queue<int>q;
	const int INF = 1e9;
	VL visit(N, INF);
	auto IFPUSH = [&](int nx, int c) {
		if (visit[nx] > c) {
			visit[nx] = c;
			q.push(nx);
		}
	};
	IFPUSH(0, 0);
	// PIIだと4.03s, intだと0.03なんだけど　何

	LL ans = INF;
	while (!q.empty()) {
		auto it = q.front(); q.pop();
		//if (it.second == N - 1)continue;
		if (a[it]) {
			LL nx = it + a[it];
			nx = min(nx, N - 1);
			IFPUSH(nx, visit[it]);
		}
		else {
			FOR(add, 1, 6 + 1) {
				LL nx = it + add;
				nx = min(nx, N - 1);
				IFPUSH(nx, visit[it] + 1);
			}
		}

	}
	DD(De(visit));
	ans = visit[N - 1];
	cout << (ans) << "\n";

	return 0;
}
