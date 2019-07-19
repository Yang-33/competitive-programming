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

/* -----  2019/07/19  Problem: AOJ 0082 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0082  ----- */


int main() {

	const int N = 8;
	VI p(N);
	while (cin >> p[0]) {
		string m = "41412121";
		FOR(i, 1, N)cin >> p[i];
		string k;
		int M = INT_MAX;
		FOR(i, 0, N) {
			rotate(m.begin(), m.begin() + 1, m.end());
			int s = 0;
			FOR(j, 0, N)s += max(0, p[j] + '0' - m[j]);
			if (s < M) { M = s; k = m; }
			if (s == M && m < k)k = m;
		}
		FOR(i, 0, N)cout << k[i] << (i == 7 ? "\n" : " ");
	}

	return 0;
}
