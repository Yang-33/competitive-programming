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

/* -----  2019/03/12  Problem: ABC 083 D / Link: http://abc083.contest.atcoder.jp/tasks/abc083_d  ----- */

struct Cumusum {
	vector<LL>csum;
	Cumusum(vector<LL>&a) {
		csum.assign((int)a.size() + 1, 0);
		for (int i = 0; i < (int)a.size(); i++) {
			csum[i + 1] = csum[i] + a[i];
		}
	}
	LL query(int l, int r) {
		return csum[r] - csum[l];
	}
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	VL z(SZ(s));
	FOR(i, 0, SZ(s)) {
		z[i] = s[i] == '0';
	}
	Cumusum zeros(z);

	LL ans = (SZ(s) + 1) / 2;

	int L = SZ(s) / 2 - 1;
	int R = (SZ(s) & 1 ? SZ(s) / 2 + 1 : SZ(s) / 2);
	while (10) {
		if (L < 0 || R >= SZ(s))break;
		int W = R - L + 1;
		LL sum = zeros.query(L, R + 1);
		if (W == sum || !sum) {
			// ok
			ans = max(ans, (LL)SZ(s) - L);
		}
		else break;

		L--, R++;
	}

	cout << (ans) << "\n";

	return 0;
}
