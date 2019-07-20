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

/* -----  2019/07/20  Problem: AOJ 0105 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0105  ----- */


int main() {
	string in;
	map<string, VI>m;
	while (getline(cin, in)) {
		stringstream ss(in);
		string s; int id;
		ss >> s >> id;
		m[s].push_back(id);
	}
	for (auto it : m) {
		cout << it.first << endl;
		SORT(it.second);
		FOR(i, 0, SZ(it.second)) {
			cout << it.second[i] << " \n"[i + 1 == SZ(it.second)];
		}
	}

	return 0;
}
