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
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2019/03/02  Problem: ABC 101 D / Link: http://abc101.contest.atcoder.jp/tasks/abc101_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	auto digitsum = [](LL a) {
		LL ret = 0;
		while (a) {
			ret += a % 10;
			a /= 10;
		}
		return ret;
	};

	if (0) {
		VL ret;
		FOR(i, 1, 100000) {
			bool ok = 1;
			FOR(j, i + 1, 100000) {
				ok &= (i*digitsum(j) <= j * digitsum(i));
			}
			if (ok) {
				ret.push_back(i);
			}
		}
		for (auto it : ret) {
			cout << it << ", ";
		}cout << endl;
		return 0;
	}

	if (0) {
		FOR(i, 1, 1000 + 1) {
			cout << i << " " << 1.0*i / (1.0*digitsum(i)) << (i % 10 == 9 ? " Suf9" : "") << endl;
		}

		return 0;
	}

	LL N;
	cin >> N;
	VL ans;
	LL ten = 1;
	FOR(i, 0, 15) {
		FOR(j, 1, 135 + 1) {
			ans.push_back(ten*(j + 1) - 1);
		}
		ten *= 10;
	}
	SORT(ans);
	UNIQ(ans);
	DD(de(SZ(ans)));
	set<LL>prohibit(ALL(ans));
	FOR(i, 0, SZ(ans)) {
		FOR(j, i + 1, SZ(ans)) {
			LL a = ans[i], b = ans[j];
			if (prohibit.count(a) && prohibit.count(b) && a*digitsum(b) > b*digitsum(a)) {
				prohibit.erase(a);
				break;
			}
		}
	}
	DD(de(SZ(prohibit)));
	FOR(k, 0, N) {
		auto it = prohibit.begin();
		cout << *it << endl;
		prohibit.erase(it);
	}

	return 0;
}
