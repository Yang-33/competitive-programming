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

/* -----  2019/07/26  Problem: AOJ 0183 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0183  ----- */



int main() {
	string in;
	while (cin >> in, in != "0") {
		VS s(3); s.front() = in;
		FOR(i, 1, 3)cin >> in, s[i] = in;
		int ans = 0;
		const int B = 1, W = 2;
		auto f = [&](const char c) {
			bool res = 0;
			FOR(i, 0, 3) {
				bool ff = 1;
				FOR(j, 0, 3) {
					ff &= s[i][j] == c;
				}
				res |= ff;
			}
			FOR(j, 0, 3) {
				bool ff = 1;
				FOR(i, 0, 3) {
					ff &= s[i][j] == c;
				}
				res |= ff;
			}
			{
				bool ff = 1;
				FOR(i, 0, 3) {
					ff &= s[i][i] == c;
				}
				res |= ff;
			}
			{
				bool ff = 1;
				FOR(i, 0, 3) {
					ff &= s[i][2 - i] == c;
				}
				res |= ff;
			}
			return res;
		};
		if (f('b'))ans = B;
		if (f('w'))ans = W;
		if (ans == 0)puts("NA");
		if (ans == B)puts("b");
		if (ans == W)puts("w");
	}
}