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

/* -----  2019/03/12  Problem: ABC 079 C / Link: http://abc079.contest.atcoder.jp/tasks/abc079_c  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	VI a(4);
	FOR(i, 0, 4) {
		a[i] = s[i] - '0';
	}
	FOR(state, 0, 1 << 3) {
		int ret = a.front();
		FOR(i, 0, 3) {
			if (state & 1 << i) {
				ret -= a[i + 1];
			}
			else {
				ret += a[i + 1];
			}
		}


		if (ret == 7) {
			FOR(i, 0, 4) {
				cout << a[i];
				if (i < 3) {
					cout << "+-"[state >> i & 1];
				}
			}
			cout << "=7" << endl;
			return 0;
		}
	}
	
	return 0;
}
