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

/* -----  2019/03/05  Problem: rupc2019_day1 C / Link: __CONTEST_URL__  ----- */

// 実験

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL Q; cin >> Q;
	VVI s(8, VI(8, 1));
	for (int i = 0; i < 8; i += 2) {
		for (int j = 1; j < 8; j += 2) {
			s[i][j] = 0;
		}
	}

	FOR(_, 0, Q) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--, b--;
		int ans = 0;
		DD(de(a,b,c,d))
		FOR(i, a, c) {
			FOR(j, b, d) {
				ans += s[i][j];
			}
		}
		cout << (ans) << "\n";
	}


	return 0;
}
