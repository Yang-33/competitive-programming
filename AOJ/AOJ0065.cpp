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

/* -----  2019/07/14  Problem: AOJ 0065 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0065  ----- */

stringstream deletecommma(string line) {
	istringstream ss(line);
	string s;
	stringstream input;
	while (getline(ss, s, ',')) {
		input << s; input << " ";
	}
	return input;
}
int main() {
	map<int, int>mp1, mp2;

	string s;
	while (getline(cin, s), s != "") {
		auto input = deletecommma(s);
		int c; input >> c;
		mp1[c]++;
	}
	while (cin >> s) {
		auto input = deletecommma(s);
		int c; input >> c;
		mp2[c]++;
	}
	for (auto i : mp1) {
		if (mp2[i.first])
			cout << i.first << " " << i.second + mp2[i.first] << "\n";
	}

	return 0;
}
