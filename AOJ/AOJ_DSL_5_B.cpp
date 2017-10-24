#include "bits/stdc++.h"
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/10/24  Problem: AOJ_DSL_5_B  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B&lang=jp  ----- */
/* ------問題------

The Maximum Number of Overlaps
平面上にN 枚の長方形のシールが貼られています。各シールの辺は、x 軸または y 軸に平行で、
i 個目のシールの左上の座標は(x1i,y1i)、右下の座標は(x2i,y2i) です。
重なっているシールの枚数が最も多い部分の、重なっているシールの枚数を求めてください。

-----問題ここまで----- */
/* -----解説等-----

二次元累積和を作りたいが、愚直に作るとTLEなので、imos法的なノリで値を作成すればよい。

----解説ここまで---- */



LL N;

int ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VVI data(1003, VI(1003, 0));
	FOR(i, 0, N) {
		int ax, ay, bx, by; cin >> ax >> ay >> bx >> by;
		ax++; ay++; bx++; by++;
		data[ax][ay]++;
		data[ax][by]--;
		data[bx][ay]--;
		data[bx][by]++;
	}


	FOR(i, 0, 1002)FOR(j, 0, 1002)data[i + 1][j + 1] += data[i + 1][j];
	FOR(i, 0, 1002)FOR(j, 0, 1002)data[i + 1][j + 1] += data[i][j + 1];
	FOR(i, 0, 1003)FOR(j, 0, 1003)ans = max(ans, data[i][j]);
	cout << ans << "\n";

	return 0;
}
