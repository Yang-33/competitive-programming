#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define debug(x) cout << #x << ": " << x << endl
#define ALL(x) (x).begin(),(x).end()

const int INF = 1e9;
const ll LINF = 1e16;

/* -----  2017/10/28  Problem: ICPC2013国内予選 E / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1190  ----- */
/* ------問題------

つながれた風船
地面上に風船があり，地面上の１つ以上の杭とロープでつながれている． 各ロープは，風船と杭をつなぐのに十分な長さがある．
ロープ同士は交差していない． 図 E-1 は，そのような状況を示したものである．
今，風船が飛びはじめた． あなたの仕事は，風船がロープの接続を維持したまま， どこまで高く飛ぶことができるか答えることである．
杭の位置は，固定されている． ロープの長さと，杭の位置は与えられる．
また，ロープに重さはなく，どの方向に引っ張られたとしても， 一直線になりうると考えてよい． 
図E-2は，図E-1の状態から風船が飛びはじめた時に， 風船が一番高くあがった位置を表している．

-----問題ここまで----- */
/* -----解説等-----

いろいろな解法があって面白い。
位置についての三分探索を行う。
あるｙについての最適なｘがあるときに、もう一方のｙについての最適なｘがある。
これらについてf(x,y):=風船の平面座標が(x,y)のときの、ひもの足りない長さ（+は足りている、-は足りていない）を
用いて最小値をもとめ、その最小値が最大になるような点を探索すればよい。
イメージしたらほんとに凸でハッピーになった。

角度で二分探索してもいけそう。（めんどくさそう）＝＞ひもの長さが余る可能性があるので不可。

----解説ここまで---- */


vector<int> vx, vy;
vector<int> L;
double Y = 0;
double X = 0;

/* 上に凸? */
double len_f(double _x, double _y, int n) {
	double sum = 1e9;

	for (int i = 0; i < n; i++) {
		double  l = (_x - vx[i])*(_x - vx[i]) + pow(_y - vy[i], 2);

		//if (L[i] - l >= 0) {
		sum = min(sum, L[i] - l);
		//}
		//sum +=(l - L[i]);
		//sum += pow(L[i], 2) - l;
	}
	return sum;
}

double fy(double x,int n) {

	double yl = -100, yr = 100;
	for (int i = 0; i < 200; i++) {
		double mid1 = yl + (yr - yl) / 3;
		double mid2 = yl + (yr - yl) * 2 / 3;

		if (len_f(x, mid1, n) > len_f(x, mid2, n)) {
			yr = mid2;
		}
		else {
			yl = mid1;
		}
	}
	Y = yl;
	return len_f(x, Y, n);
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (1) {
		int n; cin >> n; if (!n) break;

		vx.resize(n); vy.resize(n); L.resize(n);
		double ans = 0;

		for (int i = 0; i < n; i++) {
			cin >> vx[i] >> vy[i] >> L[i];
			L[i] *= L[i];
		}

		Y = 0;
		X = 0;
		double xl = -100, xr = 100;
		for (int i = 0; i < 200; i++) {
			double mid1 = xl + (xr - xl) / 3;
			double mid2 = xl + (xr - xl) * 2 / 3;

			if (fy(mid1, n) > fy(mid2, n)) {
				xr = mid2;
			}
			else {
				xl = mid1;
			}
		}
		X = xl;

		//out << x << " " << y << endl;
		printf("%.15lf\n", sqrt(len_f(X, Y, n)));
		//cout << sqrt(L[0] - (pow(vx[0] - x, 2) + pow(vy[0] - y, 2))) << endl;
	}

	return 0;
}