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

/* -----  2019/04/13  Problem: ABC 124 C / Link: http://abc124.contest.atcoder.jp/tasks/abc124_c  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	string a, b;
	FOR(i, 0, SZ(s)) {
		a += string(1, "01"[i % 2 == 0]);
		b += string(1, "10"[i % 2 == 0]);
	}
	auto diff = [](const string& a,const string &b) {
		int ret = 0;
		FOR(i, 0, SZ(a)) {
			ret += a[i] != b[i];
		}
		return ret;
	};


	LL ans = min(diff(s,a),diff(s,b));


	cout << (ans) << "\n";

	return 0;
}
