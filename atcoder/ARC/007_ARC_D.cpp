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
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2019/04/08  Problem: ARC 007 D / Link: http://arc007.contest.atcoder.jp/tasks/arc007_d  ----- */

#ifdef YANG33
using bigint = long long;
#else
#include <boost/multiprecision/cpp_int.hpp>
using bigint = boost::multiprecision::cpp_int;
#endif
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	//初項
	int idx = 0;
	bigint a = 1;
	string T;
	if (s.front() == '0') {
		while (idx < SZ(s) && s[idx] == '0') {
			a *= 10;
			T += s[idx];
			idx++;
		}
	}
	else {
		a = s[idx] - '0';
		T += s[idx];
		idx++;
		while (idx < SZ(s) && s[idx] == '0') {
			a *= 10;
			T += s[idx];
			idx++;
		}
	}

	// [idx,...)

	if (idx == SZ(s)) {
		cout << a << " " << 1 << endl;
		return 0;
	}

	bigint d1 = 0;
	while (1) {
		d1 *= 10;
		if (idx < SZ(s)) {
			d1 += s[idx] - '0';
		}
		DD(de(d1))
			idx++;
		bigint rd = d1 - a;
		if (rd >= 0) {
			if (rd <= 0)rd = 1;
			string X = T;
			bigint a2 = a + rd;//koko
			while (X.size() < s.size()) {
#ifdef YANG33
				X += to_string(a2);
#else
				X += a2.str();
#endif
				a2 += rd;
			}
			DD(de(X))
				X = X.substr(0, SZ(s));
			if (X == s) {
				cout << a << " " << rd << endl;
				return 0;
			}
		}
	}

	assert(0);

	return 0;
}
