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

/* -----  2019/03/04  Problem: ARC 001 B / Link: http://arc001.contest.atcoder.jp/tasks/arc001_b  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL A, B; cin >> A >> B;
	VL a({ -1,-5,-10,1,5,10 });
	map<LL, LL>dist;
	queue<PLL>q;
	q.push(PLL(0,A));
	dist[A] = 0;
	while (!q.empty()) {
		auto now = q.front(); q.pop();
		if (abs(now.second) > 100)continue;
		for (auto it : a) {
			LL nx = now.second + it;
			if (dist.count(nx)) {
				if (dist[nx] > now.first + 1) {
					dist[nx] = now.first + 1;
					q.push(PLL(dist[nx], nx));
				}
			}
			else {
				dist[nx] = now.first + 1;
				q.push(PLL(dist[nx], nx));

			}
		}
	}
	LL ans = dist[B];
	
	
	cout << (ans) << "\n";

	return 0;
}
