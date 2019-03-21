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

/* -----  2019/03/21  Problem: ABC 059 D / Link: http://abc059.contest.atcoder.jp/tasks/abc059_d  ----- */

const int WIN = 1, LOSE = 2;
int memo[102][102][2];

int f(int a, int b, bool p) {
	if (memo[a][b][p])return memo[a][b][p];

	bool gotolose = 0;
	for (int i = 1; 2 * i <= a; i ++) {
		int res = f(a - 2 * i, b + i, !p);
		if (res == LOSE)gotolose = 1;
	}
	for (int i = 1; 2 * i <= b; i ++) {
		int res = f(a + i, b - 2 * i, !p);
		if (res == LOSE)gotolose = 1;
	}
	return memo[a][b][p] = (gotolose ? WIN : LOSE);
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL X, Y; cin >> X >> Y;
	if (abs(X - Y) > 1) {
		cout << "Alice" << endl;
	}
	else {
		cout << "Brown" << endl;
	}
	if (0) {
		FOR(i, 0, 51) {
			FOR(j, 0, 51) {
				int res = f(i, j, 0);
				cout << "WL"[res == LOSE];
			}cout << endl;
		}
	}


	return 0;
}
