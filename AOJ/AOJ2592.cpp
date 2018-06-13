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

/* -----  2018/06/14  Problem: AOJ 2592 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2592  ----- */
/* ------問題------

N個の植物を育てたい。これらはみんな花が咲く。
それぞれの植物の華が咲くためにth[i]だけ栄養が必要である。
次の選択によってすべての花が咲くための最小コストを求めよ。

1:任意のWに対して費用W*pwをかけてそれぞれの植物にW*v[i]だけの栄養を与える。
2:任意のF[i]に対して費用F[i]*pf[i]をかけてi番目の植物にF[i]*vf[i]だけの栄養を与える。


-----問題ここまで----- */
/* -----解説等-----

雰囲気が三分探索。
投げると通る
正当性はわからない。イメージのみ
凸であることをちゃんと確認したい。

----解説ここまで---- */

using cvd = const vector<double>;
double pw;
double f(double W, cvd& vw, cvd& pf, cvd& vf, cvd& th) {
	// 全体にWを与えたときの最小コスト
	double cost = W * pw;
	FOR(i, 0, SZ(vw)) {
		// 条件を満たすようにやる
		double left = th[i] - W * vw[i];
		double ret = 0;
		if (left >= 0) {
			double F = left / vf[i];
			ret = F*pf[i];
		}
		cost += ret;
	}
	return cost;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;

	while (cin >> N, N) {
		cin >> pw;
		vector<double>vw(N), pf(N), vf(N), th(N);

		FOR(i, 0, N) {
			cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
		}
		double x1 = 0, x2 = 1e9;
		double L, R;
		FOR(i, 0, 100) {
			L = (2 * x1 + x2) / 3, R = (x1 + 2 * x2) / 3;
			if (f(L, vw, pf, vf, th) <= f(R, vw, pf, vf, th)) {
				x2 = R;
			}
			else {
				x1 = L;
			}
		}
		double ans = min({ f(x1, vw, pf, vf, th) ,f((x1 + x2) / 2, vw, pf, vf, th) ,f(x2, vw, pf, vf, th) });
		cout << ans << endl;
	}



	return 0;
}
