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

/* -----  2019/03/12  Problem: ABC 080 D / Link: http://abc080.contest.atcoder.jp/tasks/abc080_d  ----- */


struct Cumusum {
	vector<LL>csum;
	Cumusum() {}
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

	LL N, C; cin >> N >> C;
	vector<LL>s(N), t(N), c(N);
	for (int i = 0; i < N; ++i) {
		cin >> s[i] >> t[i] >> c[i];
		c[i]--;
	}
	VVL vc(C, VL(2e5 + 10));
	FOR(i, 0, N) {
		vc[c[i]][2 * s[i] - 1]++;
		vc[c[i]][2 * t[i]]--;
	}
	vector<Cumusum>vcsum(C);
	FOR(i, 0, C) {
		vcsum[i] = Cumusum(vc[i]);
	}
	VL a(2e5 + 30);
	FOR(c, 0, C) {
		FOR(i, 0, 2e5 + 10) {
			if (vcsum[c].csum[i])
				a[i]++;
		}
	}

	LL ans = *max_element(ALL(a));


	cout << (ans) << "\n";

	return 0;
}
