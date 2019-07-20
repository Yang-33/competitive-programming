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

/* -----  2019/07/20  Problem: AOJ 0109 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0109  ----- */

struct Parsing {

	Parsing() {}
	// expr1が優先度min
	LL expr1(int &i, string &s) {
		LL ret = expr2(i, s);
		while (i < SZ(s) && (s[i] == '+' || s[i] == '-')) {
			if (s[i] == '+') {
				i++;
				ret += expr2(i, s);
			}
			else if (s[i] == '-') {
				i++;
				ret -= expr2(i, s);
			}
		}
		return ret;
	}

	LL expr2(int &i, string &s) {
		LL ret = expr3(i, s);
		while (i < SZ(s) && (s[i] == '*' || s[i] == '/')) {
			if (s[i] == '*') {
				i++;
				ret *= expr3(i, s);
			}
			else if (s[i] == '/') {
				i++;
				ret /= expr3(i, s);
			}
		}
		return ret;
	}
	LL expr3(int &i, string &s) {
		LL ret;
		if (s[i] == '(') {
			i++; // )
			ret = expr1(i, s); // この区間でアレ
			i++; // )
		}
		else ret = parsenum(i, s);

		return ret;
	}

	LL parsenum(int &i, const string &s) {
		LL res = 0;
		while (i < SZ(s) && isdigit(s[i])) {
			res *= 10;
			res += s[i] - '0';
			i++;
		}
		return res;
	}
};
int main() {
	LL N; cin >> N;
	Parsing sol;
	FOR(_, 0, N) {
		string s; cin >> s;
		int id = 0;
		LL ans = sol.expr1(id,s);
		cout << (ans) << "\n";
	}


	return 0;
}
