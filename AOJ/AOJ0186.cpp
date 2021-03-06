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

/* -----  2019/07/26  Problem: AOJ 0186 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0186  ----- */


int main() {

	int q1, b, c1, c2, q2;
	while (cin >> q1, q1) {
		cin >> b >> c1 >> c2 >> q2;

		int jibard = min(q2, b / c1);
		b -= jibard * c1;

		int nobard = b / c2;
		b -= nobard * c2;

		while (jibard && jibard + nobard < q1) {
			jibard--;
			b += c1;
			int nextnb = b / c2;
			nobard += nextnb;
			b -= nextnb * c2;
		}

		if (jibard) cout << jibard << " " << nobard << "\n";
		else cout << "NA" << "\n";
	}

	return 0;
}