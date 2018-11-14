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

/* -----  2018/11/12  Problem: ARC 049 B / Link: http://arc049.contest.atcoder.jp/tasks/arc049_b  ----- */
/* ------問題------

高橋ノルム君の可能性は無限大です。高橋ノルムという名前の人物はこの世界にたくさんいます。
2 次元平面上に N 人の高橋ノルム君がいます。i(1≦i≦N) 人目の高橋ノルム君は座標 (xi,yi) にいます。 各高橋ノルム君には正整数定数 ci が割り当てられており、i 人目の高橋ノルム君がある点 (X,Y) に移動するためには ci*max(|xi−X|,|yi−Y|) の時間がかかります。
あなたの仕事は、全ての高橋ノルム君が一点に集まるために必要な最小の時間を求めることです。 ここで、一点に集まるために必要な最小の時間とは最も遅くその点に到着する高橋君の移動にかかった時間とします。
高橋ノルム君は一斉に動き出し、お互いに干渉せず動くものとします。

-----問題ここまで----- */
/* -----解説等-----

ある移動時間が定められたときに、一致する領域があるかを判定するとする。
これは移動時間が広いほうに単調性があるので、二分探索できる。
X,Yは独立なので、直線の共通範囲を考えれば良い。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	vector<double> x(N), y(N), c(N);
	FOR(i, 0, N) {
		cin >> x[i] >> y[i] >> c[i];
	}
	auto commonSegment = [&](double X, const vector<double> &a) {
		double aL = -LINF, aR = LINF;
		FOR(i, 0, N) {
			aL = max(aL, a[i] - X / c[i]);
			aR = min(aR, a[i] + X / c[i]);
		}
		DD(de(X, aL, aR));
		return aR - aL >= 0;
	};
	auto f = [&](double X) {
		bool resX = commonSegment(X, x);
		bool resY = commonSegment(X, y);
		return resX && resY;
	};
	double L = 0, R = INF;
	FOR(i, 0, 100) {
		double mid = (L + R) / 2;
		if (f(mid)) {
			R = mid;
		}
		else {
			L = mid;
		}
	}
	double ans = R;
	cout << fixed << setprecision(10) << ans << endl;

	return 0;
}
