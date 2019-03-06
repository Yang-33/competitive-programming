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

/* -----  2019/02/28  Problem: ABC 109 D / Link: http://abc109.contest.atcoder.jp/tasks/abc109_d  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

初期状態から偶数の個数を最終的に減らすことはないので，奇数を動かす．
奇数を1箇所or0箇所に集めることになるので，
ぐいーんって動かしていけば良い

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL H, W; cin >> H >> W;
	vector<vector<LL>> a(H, vector<LL>(W));
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> a[i][j];
		}
	}
	using tp = tuple<int, int, int, int>;
	vector<tp>ans;
	FOR(i, 0, H) {
		if (i % 2 == 0) {
			FOR(j, 0, W) {
				if (j == W - 1) {
					if (i == H - 1)continue;
					if (a[i][j] % 2) {
						a[i + 1][j]++;
						ans.push_back(tp(i, j, i + 1, j));
					}
				}
				else {
					if (a[i][j] % 2) {
						a[i][j + 1]++;
						ans.push_back(tp(i, j, i, j + 1));
					}

				}
			}
		}
		else {
			FORR(j, W - 1, 0 - 1) {
				if (j == 0) {
					if (i == H - 1)continue;
					if (a[i][j] % 2) {
						a[i + 1][j]++;
						ans.push_back(tp(i, j, i + 1, j));
					}
				}
				else {
					if (a[i][j] % 2) {
						a[i][j - 1]++;
						ans.push_back(tp(i, j, i, j - 1));
					}

				}
			}

		}
	}
	cout << SZ(ans) << endl;
	for (auto it : ans) {
		int b, c, d, e;
		tie(b, c, d, e) = it;
		b++, c++, d++, e++;
		cout << b << " " << c << " " << d << " " << e << endl;
	}

	return 0;
}
