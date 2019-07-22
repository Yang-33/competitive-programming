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

/* -----  2019/07/21  Problem: AOJ 0137 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0137  ----- */


int main() {
	int N; cin >> N;
	FOR(i, 0, N) {
		cout << "Case " << i + 1 << ":\n";
		const int d = 4;
		int S; cin >> S;
		FOR(k, 0, 10) {
			int S2 = S * S;
			string s = to_string(S2);
			s = string(max(0, 8 - SZ(s)), '0') + s;
			S = stoi(s.substr(2, d));
			cout << S << "\n";
		}
	}

	return 0;
}
