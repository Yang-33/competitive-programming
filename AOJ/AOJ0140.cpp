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

/* -----  2019/07/21  Problem: AOJ 0140 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0140  ----- */


int main() {
	string a = "6 7 8 9 5 4 3 2 1 0 1 2 3 4 5 6 7 8 9 5 4 3 2";
	int N; cin >> N;
	FOR(_, 0, N) {
		int s, t; cin >> s >> t;
		int i, j;
		for (i = 0; s != a[i] - '0'; i++);
		for (j = i; t != a[j] - '0'; j++)if (a[j] - '0' == s)i = j;
		cout << a.substr(i, j - i + 1) << endl;

	}
	return 0;

}