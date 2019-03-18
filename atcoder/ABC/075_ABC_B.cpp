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

/* -----  2019/03/16  Problem: ABC 075 B / Link: http://abc075.contest.atcoder.jp/tasks/abc075_b  ----- */


inline bool IN(int y, int x, int H, int W) { return (0 <= y && y < H && 0 <= x && x < W); }

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL H, W; cin >> H >> W;
	vector<string> s(H);
	for (int i = 0; i < H; ++i) {
		cin >> s[i];
		FOR(j, 0, W) {
			if (s[i][j] == '.') {
				s[i][j] = '0';
			}
		}
	}
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (s[i][j] == '#') {
				FOR(k, 0, 8) { 
					int ny = i + DY[k]; int nx = j + DX[k];
					if (IN(ny, nx, H, W) && s[ny][nx] != '#') {
						s[ny][nx]++;
					}
				}
			}
		}
	}
	FOR(i, 0, H) {
		cout << s[i] << endl;
	}

	return 0;
}
