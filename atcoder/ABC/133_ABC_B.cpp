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

/* -----  2019/07/07  Problem: ABC 133 B / Link: http://abc133.contest.atcoder.jp/tasks/abc133_b  ----- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, D;
	cin >> N >> D;
	vector<vector<int>> a(N, vector<int>(D));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < D; ++j) {
			cin >> a[i][j];
		}
	}
	auto isSquare=[](LL n) {
		LL d = (LL)sqrt(n) - 1;
		while (d*d < n) ++d;
		return d * d == n;
	};
	int ans = 0;
	FOR(i, 0, N) {
		FOR(j, i + 1, N) {
			int sum = 0;
			FOR(d, 0, D) {
				int b = (a[i][d] - a[j][d]);
				sum += b * b;
			}
			if (isSquare(sum))ans++;
		}
	}
	cout << ans << endl;


	return 0;
}


