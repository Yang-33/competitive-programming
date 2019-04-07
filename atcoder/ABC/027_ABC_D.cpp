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

/* -----  2019/04/07  Problem: ABC 027 D / Link: http://abc027.contest.atcoder.jp/tasks/abc027_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	int p = 0, m = 0;
	VL a;
	for (int i = SZ(s) - 1; i >= 0; i--) {
		if (s[i] == '+') {
			p++;
		}
		else if (s[i] == '-') {
			m++;
		}
		else {
			a.push_back(p - m);
		}
	}

	int n = SZ(a);
	RSORT(a);
	LL a1 = accumulate(a.begin(), a.begin() + n / 2, 0LL);
	LL b1 = -accumulate(a.begin() + n / 2, a.end(), 0LL);
	DD(de(a1,b1))
	LL ans =  a1+b1;
	cout << (ans) << "\n";

	return 0;
}
