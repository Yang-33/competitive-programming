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

/* -----  2019/07/21  Problem: AOJ 0139 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0139  ----- */


int main() {
	auto isa = [](const string&s) {
		bool ok = 0;
		FOR(i, 1, 100) {
			string a = ">'" + string(i, '=') + "#" + string(i, '=') + "~";
			ok |= s == a;
		}
		return ok;
	};
	auto isb = [](const string&s) {
		bool ok = 0;
		string qe = "Q=";
		FOR(i, 1, 100) {
			string b = ">^" + qe + "~~";
			ok |= s == b;
			qe += "Q=";
		}
		return ok;
	};

	LL N; cin >> N;
	FOR(_, 0, N) {
		string s; cin >> s;
		if (isa(s))cout << "A\n";
		else if (isb(s))cout << "B\n";
		else cout << "NA\n";
	}

	return 0;
}
