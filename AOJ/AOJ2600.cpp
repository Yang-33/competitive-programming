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

/* -----  2018/06/10  Problem: AOJ 2600 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2600  ----- */
/* ------問題------

Koto は言わずと知れた碁盤の目の街である． この街は東西方向に W メートル，南北方向に H メートルに伸びる長方形の領域によってできている． この街の西端から x メートル，南端から y メートルの点は (x, y) と記される． ここの街に住む人は古くから伝わる独自の文化を重んじており，その一つにKoto距離という変わった距離尺度がある． 2つの点 (x1,y1)，(x2,y2) の Koto 距離は，min(|x1−x2|, |y1−y2|) によって定義される．
最近この街全体に Wifi を使えるようにする計画が立ち上がった． 現在の計画では，親機を N 個作ることになっている． i 番目の親機は点 (xi, yi) に設置され，Koto距離が wi 以下の領域に対して Wifi を提供する．
親機を計画どおり建てた場合に，街の内部及び境界上に Wifi を提供できるかどうかを判定せよ．
なお，Koto距離は一般に三角不等式を満たさないため，距離の公理を満たさないということはここだけの秘密である．

-----問題ここまで----- */
/* -----解説等-----

街の周囲の辺について、たしかめればよい

----解説ここまで---- */

template<class T> using V = vector<T>; template<class T> using VV = V<V<T>>;

void solve() {
	int N, W, H;
	cin >> N >> W >> H;
	int flag = 0;
	V<int> xs(W + 10, 0), ys(H + 10, 0);
	FOR(i, 0, N) {
		int x, y, w;
		cin >> x >> y >> w;
		xs[max(0, x - w)]++;
		xs[min(W + 5, x + w)]--;
		ys[max(0, y - w)]++;
		ys[min(H + 5, y + w)]--;
	}
	int xinfo = 1;
	FOR(i, 0, W) {
		xs[i + 1] += xs[i];
		if (xs[i] == 0)xinfo = 0;// 適用できなさそう
	}

	int yinfo = 1;
	FOR(i, 0, H) {
		ys[i + 1] += ys[i];
		if (ys[i] == 0)yinfo = 0; // 適用できなさそう
	}
	//	cout << xinfo << "," << yinfo << endl;
	if (xinfo || yinfo) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}
