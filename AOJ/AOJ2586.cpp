#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/07/07  Problem: AOJ 2586 jag domestic 2014 (NU contest 14 A)  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2586  ----- */
/* ------問題------

流れ星に願いを
空間におけるN個の流れ星の初期位置と、移動速度、半径、消滅速度が与えられる。

二つの流れ星がぶつかるとこれらは同時に消滅する。
全ての星について消滅する時刻を求めよ。

-----問題ここまで----- */
/* -----解説等-----

ある星が自然消滅する時刻、全ての組の星が衝突する時刻を求め、これを時間順にソートし順に消滅させていけばよい。

自然消滅の時刻は簡単に求めることができる。
一方で組となっている流れ星についてはこれらについての時刻Tについての衝突時刻についての二次方程式を解けばよい。
具体的には二点間の中心の距離はベクトルを用いて、A=(x2-x1+vx2T-vx1T,y2-y1+vy2T-vy1T,z2-z1+vz2T-vz1T)とあらわせる。
半径については衝突時に一直線になるからR=(r1-vr1T)+(r2-vr2T)である。
|A|^2=R^2となる時刻が衝突時刻なのでこれを解けばよい。

よくわからないけど計算では時刻0で消滅する場合もあるが問題ではこれは存在しないとしているので最後に0がでてきたらとばせばよい。(1WA)
衝突時刻は三分探索でもできる。(okadukiさん)

----解説ここまで---- */

ll N;

double  x[202], y[202], z[202];
double  vx[202], vy[202], vz[202];
double  r[202], vr[202];
using Ty = tuple<double, int, int>;
bool dead[202];
double  ans[202]; 	  // t max

void init() {
	//happens.clear();
	FOR(i, 0, 202)dead[i] = 0;
}

double vsa(int i, int j, double a[]) { return a[j] - a[i]; }
double vp(int i, int j, double a[]) { return pow(vsa(i, j, a), 2); }

double f(int i, int j) {
	double a = vp(i, j, vx) + vp(i, j, vy) + vp(i, j, vz) - pow(vr[i] + vr[j], 2);
	double b = 2 * (vsa(i, j, vx) * vsa(i, j, x) + vsa(i, j, vy) * vsa(i, j, y) + vsa(i, j, vz) * vsa(i, j, z) + (r[i] + r[j])*(vr[i] + vr[j]));
	double c = vp(i, j, x) + vp(i, j, y) + vp(i, j, z) - pow(r[i] + r[j], 2);
	if (!(b*b - 4 * a*c > 0))return -1;
	else {
		double tt = (-b - sqrt(b*b - 4 * a*c)) / (2 * a);
		if (tt < 0) tt = (-b + sqrt(b*b - 4 * a*c)) / (2 * a);
		if (tt < 0) tt = -1;
		return tt;
	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (1) {
		init();
		cin >> N;
		if (N == 0)break;
		vector<Ty>happens;

		FOR(i, 0, N) {
			cin >> x[i] >> y[i] >> z[i] >> vx[i] >> vy[i] >> vz[i] >> r[i] >> vr[i];
		}

		//ぶつかる
		FOR(i, 0, N) {
			FOR(j, 0, i) {
				double coltime = f(i, j);
				happens.push_back(Ty(coltime, i, j));
			}
		}


		//消滅
		FOR(i, 0, N) {
			double destime = r[i] / vr[i];
			happens.push_back(Ty(destime, i, i));
		}

		sort(happens.begin(), happens.end());


		// 消してく 消えたら0->1に
		FOR(i, 0, happens.size()) {
			double dtime; int a, b;
			tie(dtime, a, b) = happens[i];
			if (dtime <= 0)continue;//ここで落ちてた
			if (dead[a] == 0 && dead[b] == 0) {

				ans[b] = ans[a] = dtime;
				dead[a] = dead[b] = 1;
			}
		}

		FOR(i, 0, N) {
			printf("%.10lf\n", ans[i]);
			//	cout << fixed << setprecision(15) << ans[i] << endl;
		}
	}
	return 0;

}
