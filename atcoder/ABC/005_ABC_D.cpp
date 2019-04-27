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

/* -----  2019/04/19  Problem: ABC 005 D / Link: http://abc005.contest.atcoder.jp/tasks/abc005_d  ----- */

template<typename T>
struct CumulativeSum2D {
	int H, W;
	vector< vector< T > >data;
	CumulativeSum2D(int H_, int W_) : data(H_ + 1, vector< T >(W_ + 1, 0)) { H = H_, W = W_; };
	inline void add(int y, int x, T val) {
		if (y > (int)data.size() || x > (int)data[0].size()) return;
		data[y + 1][x + 1] += val;
	}
	inline void build() {
		FOR(i, 0, H)FOR(j, 0, W)data[i + 1][j + 1] += data[i + 1][j];
		FOR(i, 0, H)FOR(j, 0, W)data[i + 1][j + 1] += data[i][j + 1];
	}
	inline T query(int y, int x) {
		return (data[y + 1][x + 1]);
	}

	inline T querysumhei(int sy, int sx, int ty, int tx) {
		return query(ty, tx) - query(sy - 1, tx) - query(ty, sx - 1) + query(sy - 1, sx - 1);
	}
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	vector<vector<LL>> a(N, vector<LL>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> a[i][j];
		}
	}

	CumulativeSum2D<LL>cum(N, N);
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			cum.add(i, j, a[i][j]);
		}
	}
	cum.build();
	VL dp(N*N + 1, 0);
	FOR(sy, 0, N) {
		FOR(sx, 0, N) {
			FOR(ty, sy, N) {
				FOR(tx, sx, N) {
					int sz = (ty - sy + 1)*(tx - sx + 1);
					dp[sz] = max(dp[sz], cum.querysumhei(sy, sx, ty, tx));
				}
			}
		}
	}
	FOR(i, 0, N*N) {
		dp[i + 1] = max(dp[i + 1], dp[i]);
	}

	int Q; cin >> Q;
	FOR(_, 0, Q) {
		int a; cin >> a;
		LL ans = dp[a];
		cout << ans << "\n";
	}


	return 0;
}
