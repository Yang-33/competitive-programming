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

/* -----  2019/03/04  Problem: ARC 001 C / Link: http://arc001.contest.atcoder.jp/tasks/arc001_c  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N = 8;
	VS s(N);
	FOR(i, 0, N) {
		cin >> s[i];
	}

	VVI table(N, VI(N, 0));
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			table[i][j] = s[i][j]=='Q';
		}
	}
	auto check = [&]() {
		FOR(i, 0, N) {
			FOR(j, 0, N) {
				if (!table[i][j])continue;
				int cnt = 0;
				FOR(k, 0, 8) {
					int ny = i + DY[k], nx = j + DX[k];
					while (0 <= ny && ny < N && 0 <= nx && nx < N) {
						cnt += table[ny][nx];
						ny += DY[k], nx += DX[k];
					}
				}
				if (cnt)return false;

			}
		}
		return true;
	};
	function<bool(int)> dfs = [&](int h) {
		if (h == N)return check();
		FOR(j, 0, 8)if (table[h][j])return dfs(h + 1);
		FOR(j, 0, 8) {
			table[h][j] = true;
			if (dfs(h + 1))return true;
			table[h][j] = false;
		}
		return false;
	};
	if (dfs(0)) {
		FOR(i, 0, N) {
			FOR(j, 0, N) {
				cout << (table[i][j] ? "Q" : ".");
			}cout << endl;
		}
	}
	else {
		cout << "No Answer" << endl;
	}

	return 0;
}
