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

/* -----  2019/04/29  Problem: AOJ 2905 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2905  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	map<string, VL>m;
	FOR(i, 0, N) {
		string s; cin >> s;
		LL d; cin >> d;
		m[s].push_back(d);
	}
	for (auto &it : m) {
		SORT(it.second);
	}
	map<string, int>mid;
	LL Q; cin >> Q;
	bool ok = 1;
	LL w = -1;
	FOR(_, 0, Q) {
		string s; cin >> s;
		if (mid[s] < SZ(m[s])) {
			while (mid[s] < SZ(m[s]) && m[s][mid[s]] <= w) {
				mid[s]++;
			}
			if (mid[s] < SZ(m[s])) {
				w = m[s][mid[s]];
			}
			else {
				ok = 0;
			}
			mid[s]++;

		}
		else ok = 0;
	}

	cout << (ok ? "Yes" : "No") << "\n";

	return 0;
}
