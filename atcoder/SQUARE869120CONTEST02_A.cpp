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

/* -----  2019/07/02  Problem: square869120Contest02 A / Link: https://atcoder.jp/contests/s8pc-2/tasks/  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL ans = 0LL;
	string s; cin >> s;
	char pre = 'O';
	ans = 0;
	for (auto c : s) {
		if (c == pre)continue;
		pre = c;
		ans ++;
	}
	
	if (ans % 2 == 0&&ans)ans--;
	cout << (ans) << "\n";

	return 0;
}
