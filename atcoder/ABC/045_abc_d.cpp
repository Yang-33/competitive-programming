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

/* -----  2019/04/04  Problem: ABC 045 D / Link: http://abc045.contest.atcoder.jp/tasks/abc045_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL H, W, N; cin >> H >> W >> N;
	map<PLL, LL>m;
	int DY[] = { 1, -1, 0, 0, 1, -1, 1, -1,0 };
	int DX[] = { 0, 0, 1, -1, 1, 1, -1, -1,0 };
	FOR(i, 0, N) {
		int y, x; cin >> y >> x;
		y--, x--;
		auto in = [](int a, int b) {
			return 0 < a && a < b - 1;
		};
		FOR(k, 0, 9) {
			int ny = y + DY[k], nx = x + DX[k];
			if (in(ny, H) && in(nx, W)) {
				m[PLL(ny, nx)]++;
			}
		}
	}
	VL ans(10, 0);
	ans.front() = (W - 2) *(H - 2);
	for (auto it : m) {
		++ans[it.second];
		--ans.front();
	}
	for (auto it : ans) {
		cout << it << endl;
	}

	return 0;
}
