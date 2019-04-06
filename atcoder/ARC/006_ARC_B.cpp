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

/* -----  2019/04/06  Problem: ARC 006 B / Link: http://arc006.contest.atcoder.jp/tasks/arc006_b  ----- */


int main() {
	int N, L; cin >> N >> L;
	cin.ignore();
	vector<string>vs(L + 1);
	FOR(i, 0, L + 1) {
		getline(cin, vs[i]);
	}
	reverse(ALL(vs));
	int pos = vs.front().find('o');
	FOR(i, 1, L + 1) {
		int l = pos - 1;
		int r = pos + 1;
		if (l > 0 && vs[i][l] == '-') {
			pos -= 2;
		}
		else if (r < SZ(vs[i]) && vs[i][r] == '-') {
			pos += 2;
		}

	}

	LL ans = 1 + pos/2;


	cout << (ans) << "\n";

	return 0;
}
