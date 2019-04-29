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

/* -----  2019/04/29  Problem: AOJ 2565 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2565  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	while (cin >> N, N) {
		bool no = 0;
		VL a(N);
		FOR(i, 0, N) {
			string num;
			cin >> num;
			if (num == "x")a[i] = -LINF;
			else a[i] = stoll(num);
		}

		PLL range;
		range.first = -LINF, range.second = LINF;
		FOR(i, 0, N - 1) {
			if (i % 2 == 0) {
				if (a[i] == -LINF) {
					if (a[i + 1] == -LINF)no = 1;
					else range.second = min(range.second,a[i + 1] - 1);
				}
				else {
					if (a[i + 1] == -LINF)range.first = max(range.first,a[i] + 1);
					else {
						if (a[i] >= a[i + 1])no = 1;
					}
				}
			}
			else {
				if (a[i] == -LINF) {
					if (a[i + 1] == -LINF)no = 1;
					else range.first = max(range.first, a[i + 1] + 1);
				}
				else {
					if (a[i + 1] == -LINF)range.second = min(range.second,a[i] - 1);
					else {
						if (a[i] <= a[i + 1])no = 1;
					}
				}
			}
		}
		// check
		if (range.first > range.second)no = 1;

		if (no)cout << "none" << endl;
		else {
			if (range.first == range.second)cout << range.first << endl;
			else cout << "ambiguous" << endl;
		}

	}

	return 0;
}
