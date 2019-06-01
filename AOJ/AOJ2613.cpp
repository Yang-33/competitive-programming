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

/* -----  2019/05/30  Problem: AOJ 2613 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2613  ----- */


LL expr1(const string&s, int &id, vector<set<char>>&op);
LL expr2(const string&s, int &id, vector<set<char>>&op);
LL expr3(const string&s, int &id, vector<set<char>>&op);
LL expr4(const string&s, int &id, vector<set<char>>&op);

// 優先度低い
LL expr1(const string&s, int &id, vector<set<char>>&op) {
	LL ret = expr2(s, id, op);
	while (id < SZ(s) && op[0].find(s[id]) != op[0].end()) {
		char c = s[id];
		id++;
		if (c == '+') {
			ret += expr2(s, id, op);
		}
		if (c == '-') {
			ret -= expr2(s, id, op);
		}
		if (c == '*') {
			ret *= expr2(s, id, op);
		}
	}
	return ret;
}
LL expr2(const string&s, int &id, vector<set<char>>&op) {
	LL ret = expr3(s, id, op);
	while (id < SZ(s) && op[1].find(s[id]) != op[1].end()) {
		char c = s[id];
		id++;
		if (c == '+') {
			ret += expr3(s, id, op);
		}
		if (c == '-') {
			ret -= expr3(s, id, op);
		}
		if (c == '*') {
			ret *= expr3(s, id, op);
		}
	}
	return ret;
}
LL expr3(const string&s, int &id, vector<set<char>>&op) {
	LL ret = expr4(s, id, op);
	while (id < SZ(s) && op[2].find(s[id]) != op[2].end()) {
		char c = s[id];
		id++;
		if (c == '+') {
			ret += expr4(s, id, op);
		}
		if (c == '-') {
			ret -= expr4(s, id, op);
		}
		if (c == '*') {
			ret *= expr4(s, id, op);
		}
	}
	return ret;
}
LL expr4(const string&s, int &id, vector<set<char>>&op) {
	if (s[id] == '(') {
		id++;
		LL ret = expr1(s, id, op);
		id++;
		return ret;
	}
	LL ret = 0;
	while (id < SZ(s) && isdigit(s[id])) {
		ret *= 10;
		ret += s[id] - '0';
		id++;
	}

	return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL ans = LLONG_MIN;
	string s; cin >> s;
	FOR(i, 0, 3) {
		FOR(j, 0, 3) {
			FOR(k, 0, 3) {
				vector<set<char>>op(3);
				op[i].insert('+');
				op[j].insert('-');
				op[k].insert('*');
				int id = 0;
				ans = max(ans, expr1(s, id, op));
			}
		}
	}

	cout << ans << endl;

	return 0;
}
