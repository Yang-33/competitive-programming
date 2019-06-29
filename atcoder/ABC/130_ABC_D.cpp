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

/* -----  2019/06/16  Problem: ABC 130 D / Link: http://abc130.contest.atcoder.jp/tasks/abc130_d  ----- */


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
	LL N, K;
	cin >> N >> K;
	vector<LL> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	Cumusum c(a);
	LL ans = 0;
	FOR(i, 0, N) {
		int L = i, R = N;
		while (R - L > 1) {
			int mid = (L + R) / 2;
			if (c.query(i, mid) >= K) {
				R = mid;
			}
			else {
				L = mid;
			}
		}
		if (c.query(i, R) >= K)
			ans += N - R + 1;
	}


	cout << ans << endl;

	return 0;
}
