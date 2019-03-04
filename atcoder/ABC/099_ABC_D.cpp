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

/* -----  2019/03/04  Problem: ABC 099 D / Link: http://abc099.contest.atcoder.jp/tasks/abc099_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, C; cin >> N >> C;
	vector<vector<LL>> cost(C, vector<LL>(C));
	for (int i = 0; i < C; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> cost[i][j];
		}
	}

	vector<vector<LL>> a(N, vector<LL>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> a[i][j];
			a[i][j]--;
		}
	}

	VVL b(3);
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			b[(i + j) % 3].push_back(a[i][j]);
		}
	}

	// pre
	VVL bcost(3, VL(C));
	{
		FOR(bb, 0, 3) {
			FOR(c, 0, C) {
				for (auto it : b[bb]) {
					bcost[bb][c] += cost[it][c];
				}
			}
		}
	}
	// 各bに対して重複無いCを割り振って，そのコスト
	LL ans = LINF;
	FOR(i, 0, C) {
		FOR(j, 0, C) {
			FOR(k, 0, C) {
				if (i == k || i == j || j == k)continue;
				ans = min(ans, bcost[0][i] + bcost[1][j] + bcost[2][k]);
			}
		}
	}

	cout << (ans) << "\n";

	return 0;
}
