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

/* -----  2019/04/04  Problem: ABC 042 A / Link: http://abc042.contest.atcoder.jp/tasks/abc042_a  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	multiset<int>se;
	FOR(i, 0, 3) {
		int a; cin >> a;
		se.insert(a);
	}
	LL ans = (se.count(5) == 2) && (se.count(7) == 1);
	auto print_yesno = [](LL yes, int mode = 0) {
		if (mode == 0) {
			cout << (yes ? "yes" : "no") << endl;
		}
		else if (mode == 1) {
			cout << (yes ? "Yes" : "No") << endl;
		}
		else if (mode == 2) {
			cout << (yes ? "YES" : "NO") << endl;
		}
		else assert(0);
	};
	print_yesno(ans, 2);

	return 0;
}
