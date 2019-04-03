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

/* -----  2019/03/24  Problem: ABC 122 C / Link: http://abc122.contest.atcoder.jp/tasks/abc122_c  ----- */

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

	LL N, Q; cin >> N >> Q;
	string s; cin >> s;
	VL a(N);
	FOR(i, 0, N - 1) {
		if (s[i] == 'A'&&s[i + 1] == 'C') {
			a[i]++;
		}
	}
	DD(De(s,a))
		Cumusum csum(a);
	FOR(_, 0, Q) {
		LL L, R; cin >> L >> R;
		L--, R--;
		LL res = csum.query(L, R + 1);
		if (R != N - 1) {
			if (s[R] == 'A'&&s[R + 1] == 'C')res--;
		}
		cout << res << endl;
	}


	return 0;
}
