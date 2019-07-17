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

/* -----  2019/07/14  Problem: AOJ 0067 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0067  ----- */

int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
inline bool IN(int y, int x, int H, int W) { return (0 <= y && y < H && 0 <= x && x < W); }

int main() {
	int N = 12;
	VVI d(N, VI(N, 0));
	VS m(N);
	auto f = [&](PII s) {
		queue<PII>q;
		q.push(s);

		while (!q.empty()) {
			PII a = q.front(); q.pop();
			pair<int, int> pos = a;
			if (d[pos.first][pos.second])continue;
			d[pos.first][pos.second] = 1;
			FOR(k, 0, 4) {
				int ny = pos.first + DY[k]; int nx = pos.second + DX[k];
				if (IN(ny, nx, N, N)) {
					if (m[ny][nx] == '1' && d[ny][nx] == 0) {
						q.push({ ny,nx });
					}
				}
			}
		}
	};
	string s;
	while (cin >> s) {
		m[0] = s;
		FOR(i, 1, N)cin >> m[i];
		d = VVI(N, VI(N, 0));
		int ans = 0;
		FOR(i, 0, N) {
			FOR(j, 0, N) {
				if (!d[i][j] && m[i][j] == '1') {
					f(PII(i, j)), ans++;
				}
			}
		}

		cout << ans << "\n";
	}


	return 0;
}
