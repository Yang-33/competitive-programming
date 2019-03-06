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

/* -----  2019/02/27  Problem: ABC 114 C / Link: http://abc114.contest.atcoder.jp/tasks/abc114_c  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	VL a; {
		int S = 1;
		FOR(i, 0, 9) {
			S *= 4;
		}
		VI digit({0, 3, 5, 7});
		FOR(state, 0, S) {
			VI used(4);
			int s = state;
			int num = 0;
			bool th = 1;
			FOR(i, 0, 9) {
				if (th && s%4==0) {
					;
				}
				else {
					used[s % 4] = 1; th = 0;
					num *= 10;
					num += digit[s % 4];
				}
				s /= 4;
			}
			if (!used[0]) {
				bool res = 1;
				FOR(i, 1, 4) {
					res &= used[i];
				}
				if (res) {
					a.push_back(num);
				}
			}
		}
	}

	SORT(a);
	LL N;
	cin >> N;

	ans = upper_bound(ALL(a), N) - a.begin();
	cout << ans << "\n";

	return 0;
}
