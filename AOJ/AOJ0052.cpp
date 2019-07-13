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

/* -----  2019/07/14  Problem: AOJ 0052 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0052  ----- */
map<LL, LL> make_factor(long long  n) {
	map<LL, LL>ans;
	for (long long i = 2; i * i <= n; i++) {
		while (n%i == 0) {
			ans[i]++;
			n /= i;
		}
	}
	if (n != 1)ans[n]++;
	return ans;
}

int main() {
	LL N;
	while (cin >> N, N) {
		LL two = 0, five = 0;
		FOR(i, 1, N + 1) {
			auto it = make_factor(i);
			two += it[2];
			five += it[5];
		}
		LL ans = min(two,five);

		cout << (ans) << "\n";
	}

	return 0;
}
