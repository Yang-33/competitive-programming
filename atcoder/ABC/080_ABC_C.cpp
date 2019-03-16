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

/* -----  2019/03/12  Problem: ABC 080 C / Link: http://abc080.contest.atcoder.jp/tasks/abc080_c  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; 
	cin >> N;
	vector<vector<LL>> a(N, vector<LL>(10));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 10; ++j) {
			cin >> a[i][j];
		}
	}
	vector<vector<LL>> P(N, vector<LL>(11));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 11; ++j) {
			cin >> P[i][j];
		}
	}



	LL ans = -LINF;
	FOR(state, 1, 1 << 10) {
		LL ret = 0;

		FOR(i, 0, N) {
			LL cnt = 0;
			FOR(j, 0, 10) {
				if ((state & 1 << j) && (a[i][j])) {
					cnt++;
				}
			}
			ret += P[i][cnt];
		}

		ans = max(ans, ret);
	}
	
	
	cout << (ans) << "\n";

	return 0;
}
