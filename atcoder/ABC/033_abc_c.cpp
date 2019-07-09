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

/* -----  2019/04/06  Problem: ABC 033 C / Link: http://abc033.contest.atcoder.jp/tasks/abc033_c  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	// +で切る
	vector<string>a;
	string kou;
	FOR(i, 0, SZ(s)) {
		if (s[i] == '+') {
			a.push_back(kou);
			kou.clear();
		}
		else {
			kou += string(1, s[i]);
		}
	}
	if (SZ(kou))a.push_back(kou);
	// *内に0のみがあればそれを使用，そうでなければ1
	LL ans = 0LL;
	for (auto it : a) {
		ans += !(count(ALL(it), '0') > 0);
	}



	cout << (ans) << "\n";

	return 0;
}
