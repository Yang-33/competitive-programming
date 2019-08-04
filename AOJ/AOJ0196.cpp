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

/* -----  2019/07/27  Problem: AOJ 0196 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0196  ----- */


int main() {
	int N;
	while (cin >> N, N) {
		VS s(N);
		map<int, string>m;
		vector<pair<PII, int> >a(N);
		FOR(i, 0, N) {
			cin >> s[i];
			m[i] = s[i];
			a[i].second = i;
			FOR(j, 0, N - 1) {
				int p; cin >> p;
				if (!p)a[i].first.second--;
				if (p == 1)a[i].first.first++;
			}
		}
		SORT(a);
		FOR(i, 0, N)swap(a[i].first.second, a[i].first.first);
		SORT(a);
		FOR(i, 0, N) {
			cout << m[a[i].second] << "\n";
		}
	}

	return 0;
}
