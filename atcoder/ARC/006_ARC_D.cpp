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

/* -----  2019/04/06  Problem: ARC 006 D / Link: http://arc006.contest.atcoder.jp/tasks/arc006_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL H, W; cin >> H >> W;
	VS vs(H); FOR(i, 0, H) {
		cin >> vs[i];
	}

	const int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
	const int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
	auto is_in = [](int a, int b, int c) { return a <= b && b < c; };
	VVI used(H, VI(W, 0));
	auto f = [&](int Y, int X) {
		int res = 1;
		queue<PII>q;
		used[Y][X] = 1;
		q.push(PII(Y, X));
		while (!q.empty()) {
			int y, x; tie(y, x) = q.front(); q.pop();
			FOR(k, 0, 8) {
				int ny = y + DY[k], nx = x + DX[k];
				if (is_in(0, ny, H) && is_in(0, nx, W)) {
					if (!used[ny][nx] && vs[ny][nx] == 'o') {
						used[ny][nx] = 1;
						res++;
						q.push(PII(ny, nx));
					}
				}
			}
		}

		return res;
	};
	auto g = [](int n) {
		for (int i = 2; i*i <= n; i++) {
			int p2 = i * i;
			while (n%p2 == 0) {
				n /= p2;
			}
		}
		if (n == 3)return 0;
		if (n == 1)return 1;
		if (n == 11)return 2;
		assert(0);
	};
	VI ans(3, 0);
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (used[i][j] || vs[i][j] == '.')continue;
			int sz = f(i, j);
			int id = g(sz);
			ans[id]++;
		}
	}
	FOR(i, 0, 3) {
		cout << ans[i] << " \n"[i == 2];
	}


	return 0;
}
