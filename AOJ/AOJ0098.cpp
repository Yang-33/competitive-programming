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

/* -----  2019/07/20  Problem: AOJ 0098 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0098  ----- */

// aの長さ1以上の連続列の和の最大値を求める
LL rowmaxsegsum(const VL&a) {
	int N = (int)a.size();
	LL s = 0;
	LL mx = -LINF;
	FOR(i, 0, N) {
		if (s >= 0) {
			s += a[i];
		}
		else {
			s = a[i];
		}
		mx = max(mx, s);
	}
	return mx;
}
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
	LL N; cin >> N;
	vector<vector<LL>> a(N, vector<LL>(N));
	vector<Cumusum>cs;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> a[i][j];
		}
		cs.emplace_back(Cumusum(a[i]));
	}
	LL ans = -LINF;
	FOR(L, 0, N) {
		FOR(R, L + 1, N + 1) {
			VL b;
			FOR(i, 0, N) {
				b.emplace_back(cs[i].query(L, R));
			}
			ans = max(ans, rowmaxsegsum(b));
		}
	}


	cout << (ans) << "\n";

	return 0;
}
