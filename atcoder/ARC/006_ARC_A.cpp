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

/* -----  2019/04/06  Problem: ARC 006 A / Link: http://arc006.contest.atcoder.jp/tasks/arc006_a  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	VI e(6); FOR(i, 0, 6) {
		cin >> e[i];
	}
	int B; cin >> B;
	VI l(6); FOR(i, 0, 6) {
		cin >> l[i];
	}
	bitset<10>E, L;
	FOR(i, 0, 6) {
		E[e[i]] = 1;
		L[l[i]] = 1;
	}
	bitset<10>res = E & L;
	int ans = res.count();
	if (ans == 6) {
		cout << 1 << endl;
	}
	else if (ans == 5) {
		if (!res[B] && L[B]) {
			cout << 2 << endl;
		}
		else {
			cout << 3 << endl;
		}
	}
	else if (ans == 4) {
		cout << 4 << endl;
	}
	else if (ans == 3) {
		cout << 5 << endl;
	}
	else {
		cout << 0 << endl;
	}

	return 0;
}
