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

/* -----  2019/03/08  Problem: ABC 092 D / Link: http://abc092.contest.atcoder.jp/tasks/abc092_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL A, B; cin >> A >> B;
	LL H, W; H = W = 100;
	VS a(H, string(W, '!'));
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (i < H / 2) {
				a[i][j] = '.';
			}
			else {
				a[i][j] = '#';
			}
		}
	}
	A--, B--;
	for (int i = 1; i < H / 2; i += 2) {
		for (int j = 1; j < W-1; j += 2) {
			if (B) {
				a[i][j] = '#';
				B--;
			}
		}
	}
	for (int i = H / 2 + 1; i < H; i += 2) {
		for (int j = 1; j < W-1; j += 2) {
			if (A) {
				a[i][j] = '.';
				A--;
			}
		}
	}


	cout << H << " " << W << endl;
	FOR(i, 0, H) {
		cout << a[i] << endl;
	}

	return 0;
}
