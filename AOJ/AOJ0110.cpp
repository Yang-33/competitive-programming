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

/* -----  2019/07/20  Problem: AOJ 0110 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0110  ----- */

LL getnum(int &i, string &s, int x) {
	LL num = 0;
	int ii = i;
	while (isdigit(s[i]) || s[i] == 'X') {
		if (ii - i == 0 && s[i] == 'X'&&x == 0)return LINF;
		char c = s[i];
		if (s[i] == 'X')c = '0' + x;
		num *= 10;
		num += c - '0';
		i++;
	}

	return num;
}

int main() {
	string s;
	auto f = [](string&s) {
		string ans = "";
		FOR(i, 0, 10) {
			int p = 0;
			LL x1 = getnum(p, s, i);
			p++;
			LL x2 = getnum(p, s, i);
			p++;
			LL x3 = getnum(p, s, i);
			if (x1 + x2 == x3) {
				ans = to_string(i);
				break;
			}
		}
		if (ans == "")ans = "NA";
		return ans;
	};
	while (getline(cin, s)) {
		string ans = f(s);
		cout << (ans) << "\n";
	}

	return 0;
}
