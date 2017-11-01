#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int i = s;i<e;i++)
#define debug(x) cout << #x << " : " << x << endl



/* -----  2017/11/01  Problem: AOJ2233  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2233  ----- */
/* ------問題------

うさぎがある国を旅行している. この国には1 からn の番号がついたn 個の都市があり, うさぎは今都市1にいる. 都市i は座標平面上の1 点(xi, yi) とみなす.
うさぎは以下の条件をみたすように旅をする.

移動経路は折れ線であり, その各部分は異なる2 都市を結ぶ線分でなければならない.
移動経路の全長はr 以下でなければならない. 経路のうち重なった部分も, 通った回数分数える.
移動する方向が変わるとき, 曲がる角度はθ 以下でなければならない. 最初の移動方向に制限はない.
うさぎがある都市から別の都市へ移動をすると, 移動先の都市でニンジンを1 本もらえる. 同じ都市を複数回訪れることは可能であり, 訪れるたびにニンジンをもらえる. うさぎがこの旅で手に入れることのできるニンジンの本数の最大値を求めよ.

-----問題ここまで----- */
/* -----解説等-----

これは移動したときに前の状態が次の状態に依存していると見れる。
したがって拡張ダイクストラの容量で、必要な情報をすべて持っておけばよい。
必要なのは、(総移動距離、前の頂点二つ、何個ニンジンを持っているか)
もしニンジンが各都市一回だけだったら、これもbitmaskでもっておけばよい。

----解説ここまで---- */





const int INF = (1 << 30);
const ll LINF = (1LL << 60);
const double Paidao = 3.14159265359;
int N;
double r, shi;
double x[21];
double y[21];
double d[21][21][10010];
double getshidao[21][21][21];
double kyoritti[21][21];
inline double dist(int now, int bef) {
	return sqrt(pow(x[now] - x[bef], 2) + pow(y[now] - y[bef], 2));
}
inline double getshi(int pos, int bef, int nx) {
	double ax = x[pos] - x[bef];
	double ay = y[pos] - y[bef];
	double bx = x[nx] - x[pos];
	double by = y[nx] - y[pos];

	double naiseki = ax*bx + ay*by;
	double bunbo = sqrt(ax*ax + ay*ay) * sqrt(bx*bx + by*by);
	double shita = 180.0/Paidao * acos(naiseki / bunbo);
	return abs(shita);
}

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	cin >> N;
	FOR(i, 0, N)FOR(j, 0, N)FOR(k, 0, 10010)d[i][j][k] = INF;
	cin >> r >> shi;
	FOR(i, 0, N) {
		cin >> x[i] >> y[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				getshidao[i][j][k] = getshi(i, j, k);
			}
			kyoritti[i][j] = dist(i, j);
		}
	}

	using Ty = tuple<double, int, int, int>;
	priority_queue<Ty, vector<Ty>, greater<Ty>>q;
	FOR(i, 1, N) {
		if (dist(0, i) <= r) {
			d[i][0][1] = dist(0, i);
			q.push(Ty(d[i][0][1], i, 0, 1));
		}
	}

	while (!q.empty()) {

		Ty a = q.top(); q.pop();
		double dist; int pos, bef, cnt;
		tie(dist, pos, bef, cnt) = a;
		if (dist > d[pos][bef][cnt])continue;

		FOR(i, 0, N) {
			if (i == pos)continue;
			if (getshidao[pos][bef][i] <= shi) {//移動していい
				//cout << getshi(pos, bef, i) << "kasaidayo" << endl;
				if ((dist + kyoritti[pos][i] < d[i][pos][cnt + 1]) && (dist + kyoritti[pos][i] <= r)) {
					d[i][pos][cnt + 1] = dist + kyoritti[pos][i];
					q.push(Ty(d[i][pos][cnt + 1], i, pos, cnt + 1));
				}
			}
		}
	}

	
	int ans = -1;

	FOR(i, 0, N) {
		FOR(j, 0, N) {
			for (int k = 10010; k >= 0; k--) {
				if (i == j)continue;
				if (d[i][j][k] > r)continue;
				if (d[i][j][k] <1)continue;
				//cout << i << " " << j << " " << k << " " << d[i][j][k] << endl;
				if (ans < k) {
					ans = max(ans, k);
					//cout << "kousin" << endl;
				}
			}
		}
	}

	cout << ((ans == -1) ? 0 : ans  )<< endl;

}