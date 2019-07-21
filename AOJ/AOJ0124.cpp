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

/* -----  2019/07/21  Problem: AOJ 0124 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0124  ----- */


int main() {
	LL N;
	int ca=0;
	while (cin >> N, N) {
		if (ca)cout << endl;
		ca++;
		using tp = tuple<int, int, string>;
		vector<tp>a;
		FOR(i, 0, N) {
			string s; cin >> s;
			int w, l, t; cin >> w >> l >> t;
			a.emplace_back(3 * w + t, -i, s);
		}
		RSORT(a);
		for (auto it : a) {
			int sc; string s;
			tie(sc, ignore, s) = it;
			cout << s << "," << sc << "\n";
		}
	}

	return 0;
}
