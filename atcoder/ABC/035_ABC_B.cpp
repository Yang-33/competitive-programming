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

/* -----  2019/04/06  Problem: ABC 035 B / Link: http://abc035.contest.atcoder.jp/tasks/abc035_b  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	int t; cin >> t;
	LL ans = 0LL;
	const int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
	const int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
	string dir = "UDLR";
	map<char, int>dirmap;
	FOR(i, 0, 4) {
		dirmap[dir[i]] = i;
	}
	int qcnt = 0;
	int Y = 0, X = 0;
	for (auto c : s) {
		if (c == '?')qcnt++;
		else {
			Y += DY[dirmap[c]];
			X += DX[dirmap[c]];
		}
	}
	if (t == 1) { // max
		ans = abs(X) + abs(Y) + qcnt;
	}
	else { // min
		LL sum = abs(X) + abs(Y);
		if (sum >= qcnt) {
			ans = sum - qcnt;
		}
		else {
			if (sum % 2 == qcnt%2)ans = 0;
			else ans = 1;
		}
	}



	cout << (ans) << "\n";

	return 0;
}
