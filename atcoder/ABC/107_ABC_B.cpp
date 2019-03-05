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

/* -----  2019/02/28  Problem: ABC 107 B / Link: http://abc107.contest.atcoder.jp/tasks/abc107_b  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL H, W; cin >> H >> W;
	vector<string> a(H);
	for (int i = 0; i < H; ++i) {
		cin >> a[i];
	}
	VI pr(H, 1), pc(W,1);
	FOR(i, 0, H) {
		bool allwhite = 1;
		FOR(j, 0, W) {
			allwhite &= a[i][j] == '.';
		}
		pr[i] = !allwhite;
	}
	FOR(j, 0, W) {
		bool allwhite = 1;
		FOR(i, 0, H) {
			allwhite &= a[i][j] == '.';
		}
		pc[j] = !allwhite;
	}
	FOR(i, 0, H) {
		int prc = 0;
		FOR(j, 0, W) {
			if (pr[i] && pc[j]) {
				cout << a[i][j];
				prc++;
			}
		}
		if (prc) {
			cout << endl;
		}
	}

	return 0;
}
