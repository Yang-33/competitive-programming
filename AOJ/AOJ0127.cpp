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

/* -----  2019/07/21  Problem: AOJ 0127 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0127  ----- */


int main() {

	const string M = "abcdefghijklmnopqrstuvwxyz.?! ";
	string s;
	while (cin >> s) {
		bool f = 1;
		string ans = "";
		if (SZ(s) % 2)f = 0;
		else {
			FOR(i, 0, SZ(s) / 2) {
				int y = s[2 * i] - '0';
				int x = s[2 * i + 1] - '0';
				x--, y--;
				if (5 * y + x >= 30 || y >= 6 || x >= 5||y<0||x<0)f = 0;
				else ans += string(1, M[5 * y + x]);
			}
		}
		if (!f)cout << "NA" << "\n";
		else cout << (ans) << "\n";
	}

	return 0;
}
