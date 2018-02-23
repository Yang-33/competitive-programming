#include <bits/stdc++.h>
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

/* -----  2018/02/15  Problem: 075_abc_d / Link: https://abc075.contest.atcoder.jp/tasks/abc075_d?lang=en  ----- */
/* ------問題------

2次元座標上に N 個の点があります。
i(1≦i≦N) 番目の点の座標は (xi,yi) です。
長方形の内部に N 点のうち K 個以上の点を含みつつ、それぞれの辺がX軸かY軸に平行な長方形を考えます。
このとき、長方形の辺上の点は長方形の内部に含みます。
それらの長方形の中で、最小の面積となるような長方形の面積を求めてください。

-----問題ここまで----- */
/* -----解説等-----

O(N^5)、すき
適当にやって通ってしまったけど範囲内にある点の数は毎回計算する余裕がないのなら、
これは事前に計算可能で、二次元累積和でできる。

----解説ここまで---- */

LL N,K;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>K;
	VL x(N), y(N);
	VL xc(N), yc(N);
	FOR(i, 0, N) {
		cin >> x[i] >> y[i];
		xc[i] = x[i];
		yc[i] = y[i];
	}

	SORT(xc);
	SORT(yc);
	ans = (xc[N-1]- xc[0])*(yc[N - 1] - yc[0]);
	FOR(u1, 0, N) {
		FOR(u2, u1+1, N) {
			FOR(d1, 0, N) {
				FOR(d2, d1+1, N) {
					LL X = xc[u2] - xc[u1];
					LL Y = yc[d2] - yc[d1];
					int cnt = 0;
					FOR(i, 0, N) {
						if (xc[u1] <= x[i]
							&& x[i] <= xc[u2]
							&&yc[d1] <= y[i]
							&& y[i] <= yc[d2]
							)
							cnt++;
					}

					if (cnt >= K) {
						ans = min(ans, X*Y);
					}



				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
