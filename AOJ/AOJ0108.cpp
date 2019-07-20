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

/* -----  2019/07/20  Problem: AOJ 0108 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0108  ----- */


int main() {
	LL N;
	while (cin >> N,N) {
		vector<LL> s(N);
		for (int i = 0; i < N; ++i) {
			cin >> s[i];
		}
		LL ans = 0LL;
		while (1) {
			map<LL, LL>m; {
				FOR(i, 0, N) {
					m[s[i]]++;
				}
			}
			VL nx(N, 0); {
				FOR(i, 0, N) {
					nx[i] = m[s[i]];
				}
			}

			if (nx == s)break;
			ans++;
			s.swap(nx);
		}
		cout << (ans) << "\n";
		FOR(i, 0, N) {
			cout << s[i] << " \n"[i + 1 == N];
		}
	}


	return 0;
}
