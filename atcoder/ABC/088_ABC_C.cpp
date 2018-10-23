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

/* -----  2018/10/23  Problem: ABC 088 C / Link: http://abc088.contest.atcoder.jp/tasks/abc088_c  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	VVI c(3, VI(3));
	FOR(i, 0, 3) {
		FOR(j, 0, 3) {
			cin >> c[i][j];
		}
	}

	FOR(a1, -400, 401) {
		VI b(3);
		FOR(i, 0, 3) {
			b[i] = c[0][i] - a1;
		}
		VI a(3);
		FOR(i, 0, 3) {
			a[i] = c[i][0] - b[0];
		}
		bool ok = 1;
		FOR(i, 0, 3) {
			FOR(j, 0, 3) {
				ok &= (a[i] + b[j] == c[i][j]);
			}
		}
		if (ok) {
			cout << "Yes" << endl; return 0;
		}
	}
	cout << "No" << endl;

	return 0;
}
