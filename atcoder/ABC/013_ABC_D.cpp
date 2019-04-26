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

/* -----  2019/04/11  Problem: ABC 013 D / Link: http://abc013.contest.atcoder.jp/tasks/abc013_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M, D; cin >> N >> M >> D;
	vector<LL> a(M);
	for (int i = 0; i < M; ++i) {
		cin >> a[i];
		a[i]--;
	}
	reverse(ALL(a));
	// doubling !!
	VI next_p(N);
	iota(ALL(next_p), 0);
	FOR(i, 0, M) {
		int p = a[i];
		swap(next_p[p], next_p[p + 1]);
	}
	VVI doubling(32, VI(N, -1));
	FOR(i, 0, N) {
		doubling[0][i] = next_p[i];
	}
	FOR(i, 0, 31) {
		FOR(j, 0, N) {
			doubling[i + 1][j] = doubling[i][doubling[i][j]];
		}
	}
	FOR(i, 0, N) {
		// D回移動する
		// 上から二分探索っぽく
		int p = i;
		FORR(t, 30, 0 - 1) {
			if (D & 1 << t)
				p = doubling[t][p];
		}
		cout << p + 1 << endl;
	}

	return 0;
}
