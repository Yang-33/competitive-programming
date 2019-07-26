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

/* -----  2019/07/24  Problem: AOJ 0176 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0176  ----- */


int main() {
	const vector<string> color
		= { "black","blue","lime","aqua",
		"red","fuchsia","yellow","white" };

	string s;
	while (cin >> s, s != "0") {
		s = s.substr(1);
		pair<LL, string>ans = { LINF,"!" };
		VI a(3);
		auto trans = [](char c) {
			if (isdigit(c))return c - '0';
			else return c - 'a' + 10;
		};
		FOR(i, 0, 3) {
			a[i] = 16 * trans(s[2 * i]) + trans(s[2 * i + 1]);
		}
		auto update = [&]() {
			FOR(st, 0, 1 << 3) {
				LL sum = 0;
				FOR(i, 0, 3) {
					LL b = a[i];
					LL c = (st & 1 << (2 - i) ? 255 : 0);
					sum += (b - c)*(b - c);
				}
				if (sum <= ans.first) {
					ans.first = sum;
					ans.second = color[st];
				}
			}
		};
		update();
		cout << ans.second << "\n";
	}

	return 0;
}
