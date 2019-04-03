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

/* -----  2019/03/24  Problem: ABC 122 B / Link: http://abc122.contest.atcoder.jp/tasks/abc122_b  ----- */


int main() {
	cin.tie(0);

	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	LL ans = 0LL;
	FOR(i, 0, SZ(s)) {
		FOR(j, 1, SZ(s) + 1) {
			string t = s.substr(i, j);
			DD(de(t));
			LL ret = 0;
			for (auto c : t) {
				if (c == 'A' || c == 'T' || c == 'G' || c == 'C')ret++;
				else break;
			}
			ans = max(ans, ret);
		}
	}


	cout << (ans) << "\n";

	return 0;
}
