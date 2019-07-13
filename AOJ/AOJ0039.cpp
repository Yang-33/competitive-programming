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

/* -----  2019/07/13  Problem: AOJ 0039 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0039  ----- */


class Roman {
	void toRomanNumber1(char i, char v, char x, int n, string &s) {
		switch (n) {
		case 0: break;
		case 1: s += i; break;
		case 2: s += i, s += i; break;
		case 3: s += i, s += i, s += i; break;
		case 4: s += i, s += v; break;
		case 5: s += v; break;
		case 6: s += v, s += i; break;
		case 7: s += v, s += i, s += i; break;
		case 8: s += v, s += i, s += i, s += i; break;
		case 9: s += i, s += x; break;
		default: break;
		}
	}
public:
	string toRomanNumber(int n) {
		string s(n / 1000, 'M');
		toRomanNumber1('C', 'D', 'M', n / 100 % 10, s);
		toRomanNumber1('X', 'L', 'C', n / 10 % 10, s);
		toRomanNumber1('I', 'V', 'X', n % 10, s);
		return s;
	}
	Roman() {}
	int roma_to_arabic(string s) {
		auto number = [](char c) -> int {
			if (c == 'I')
				return 1;
			if (c == 'V')
				return 5;
			if (c == 'X')
				return 10;
			if (c == 'L')
				return 50;
			if (c == 'C')
				return 100;
			if (c == 'D')
				return 500;
			if (c == 'M')
				return 1000;
		};
		int ans = number(s[0]);
		int pre = number(s[0]);
		for (int i = 1; i < (int)s.size(); i++) {
			int now = number(s[i]);
			now <= pre ? ans += now : ans += now - 2 * pre;
			pre = now;
		}
		return ans;
	}
};


int main() {

	string s;
	Roman trans;
	while (cin >> s) {
		cout << trans.roma_to_arabic(s) << "\n";
	}
	return 0;
}
