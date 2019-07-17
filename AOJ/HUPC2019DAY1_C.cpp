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

/* -----  2019/07/14  Problem: HUPC2019day1 C / Link: __CONTEST_URL__  ----- */


using T = tuple<int, int>;
T and_expr(const string&s, int&id);
T term(const string&s, int&id);
T or_expr(const string&s, int &id);
using P = PII;
P formula(const string&s, int &id) {
	int t, f;
	tie(t, f) = or_expr(s, id);
	return P(t, f);
}
T or_expr(const string&s, int &id) {
	T ae = and_expr(s, id);
	vector<T> memo;
	memo.push_back(ae);
	while (id < SZ(s) && s[id] == '|') {
		id++;
		T nae = and_expr(s, id);
		memo.push_back(nae);
	}

	// orで0にする場合は全部0
	int fsum = 0; { // 0
		FOR(i, 0, SZ(memo)) {
			int f, t;
			tie(f, t) = memo[i];
			fsum += f;
		}
	}
	// orで0にする場合は[0*]1
	int tmi = INF; { // 1
		int zerosum = 0;
		FOR(i, 0, SZ(memo)) {
			int f, t;
			tie(f, t) = memo[i];
			tmi = min(tmi, zerosum + t);
			zerosum += f;
		}
	}
	return T(fsum, tmi);
}
T and_expr(const string&s, int&id) {
	T t = term(s, id);
	vector<T> memo;
	memo.push_back(t);
	while (id < SZ(s) && s[id] == '&') {
		id++;
		T nt = term(s, id);
		memo.push_back(nt);
	}
	// andで1にする場合は全部1
	int tsum = 0; {// to 1
		FOR(i, 0, SZ(memo)) {
			int f, t;
			tie(f, t) = memo[i];
			tsum += t;
		}
	}
	// andで0にする場合は[1*]0
	int fmi = INF; { // to 0
		int onesum = 0;
		FOR(i, 0, SZ(memo)) {
			int f, t;
			tie(f, t) = memo[i];
			fmi = min(fmi, onesum + f);
			onesum += t;
		}
	}
	return T(fmi, tsum);
}

T term(const string&s, int&id) {
	if (s[id] == '(') {
		id++;
		T res = or_expr(s, id);
		id++;
		return res;
	}
	else {
		// ?
		assert(s[id] == '?');
		id++;
		// false true
		return T(1, 1);
	}
}
int main()
{
	string s;
	while (cin >> s) {
		int p = 0;
		P ans = formula(s, p);
		assert(SZ(s) == p);
		cout << ans.first << ' ' << ans.second << endl;
	}
	return 0;
}
