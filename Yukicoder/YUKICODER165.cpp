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
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/07/26  Problem: yukicoder 165  / Link: http://yukicoder.me/problems/no/165  ----- */
/* ------問題------

XY座標上に異なるN個の整数座標上の点が与えられる。
各点にはそれぞれ得点が定められている。
A君はX軸、Y軸に辺が平行な四角形で点と重ならないように多くの点を囲いたい。
ただし、条件として囲った点の得点の合計がB以下でないといけない。
囲える点の最大の数はいくつだろうか？

-----問題ここまで----- */
/* -----解説等-----

Yの組を全探索し、累積和+しゃくとりをした。

最初はN^2もできる気がしたけどそんなことはなかった。
yの範囲を決めると累積和上の配列で一次元しゃくとりをする問題に落とせる。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int N,B; cin >> N>>B;
	VI x(N), y(N), p(N);
	FOR(i, 0, N) {
		cin >> x[i] >> y[i] >> p[i];
	}
	VI xs = x, ys = y;
	SORT(xs), UNIQ(xs);
	SORT(ys), UNIQ(ys);
	int W = SZ(xs), H = SZ(ys);
	VVI cnt(H, VI(W, 0));
	VVI psum = cnt;
	FOR(i, 0, N) {
		int xid = lower_bound(ALL(xs), x[i]) - xs.begin();
		int yid = lower_bound(ALL(ys), y[i]) - ys.begin();
		cnt[yid][xid] ++;
		psum[yid][xid] += p[i];
	}
	int ans = 0;
	FOR(ys, 0, H) {
		VI cntToH(W, 0), psumToH(W, 0);
		FOR(ye, ys, H) {
			FOR(i, 0, W) {
				cntToH[i] += cnt[ye][i];
				psumToH[i] += psum[ye][i];
			}
			int SktrCnt = 0;
			int SktrSum = 0;
			for (int l = 0, r = 0; l < W; l++) {
				 //[l, r)
				while (r < W && SktrSum+psumToH[r]<=B) {
					SktrCnt += cntToH[r];
					SktrSum += psumToH[r];
					r++;
				}
				debug(SktrCnt);
				debug(SktrSum);
				ans = max(ans, SktrCnt);
				SktrCnt -= cntToH[l];
				SktrSum -= psumToH[l];

			}
		}
	}


	cout << ans << "\n";

	return 0;
}

