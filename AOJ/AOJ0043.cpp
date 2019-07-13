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

/* -----  2019/07/13  Problem: AOJ 0043 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0043  ----- */

// 麻雀

int main() {
	string s;
	while (cin >> s) {
		VI a(14);
		VI cnt(11, 0);
		{
			FOR(i, 0, SZ(s)) {
				a[i] = s[i] - '0';
				cnt[a[i]]++;
			}
		}

		auto check = [&]() {
			VI data = cnt;
			for (int i = 1; i < 10; i++) {
				if (data[i] >= 2) {
					vector<int> vc(data);
					bool flag = true;
					vc[i] -= 2;
					for (int j = 1; j < 10; j++) {
						while (vc[j] % 3 != 0) {
							for (int k = 0; k < 3; k++) {
								vc[k + j]--;
								if (vc[k + j] < 0) flag = false;
							}
						}
					}
					if (flag) return true;
				}
			}
			return false;
		};

		VI ans;
		FOR(i, 1, 10) {
			if (cnt[i] >= 4)continue;
			a.back() = i;
			cnt[i]++;
			if (check()) {
				ans.push_back(i);
			}
			cnt[i]--;
		}
		FOR(i, 0, SZ(ans)) {
			cout << ans[i] << " \n"[i + 1 == SZ(ans)];
		}
		if (SZ(ans) == 0)cout << 0 << endl;
	}

	return 0;
}
