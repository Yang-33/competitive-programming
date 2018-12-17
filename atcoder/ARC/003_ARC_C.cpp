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

/* -----  2018/12/15  Problem: ARC 003 C / Link: http://arc003.contest.atcoder.jp/tasks/arc003_c  ----- */
/* ------問題------

高橋君は、夜道を通って学校から自宅へと 1 人で帰ろうとしています。
彼の住む街は長方形の形をしており、格子状の区画に区切られています。彼は東西南北に 1 秒に 1 区画ずつ移動することができます。
各区画には日当たりの良さが与えられ、経過時間 t 秒(出発時間は 0 秒)を用いて「“各区画の明るさ” = 日当たりの良さ ×0.99t」と表すことが出来ます。
学校から自宅まで帰る途中に通る経路上の区画における“区画の明るさ”の最小値を、その経路における“経路の明るさ”とします。
高橋君は暗所恐怖症なので、“経路の明るさ”がなるべく大きい経路を選択したいと考えています。
そのような経路を選択した場合の、“経路の明るさ”を求めなさい。

-----問題ここまで----- */
/* -----解説等-----

すぐ二分探索と気づくことができたので良かった。
ある閾値X以上の経路しか通ってはいけないとする。
このとき、Xに対する結果：f(X):=X以上の経路のみを通過してTに到達可能か？
とすると、0-X,X-INFでok,noとなる。
したがって二分探索可能。あとは-1の判定を最後にすれば良い。

----解説ここまで---- */

double POW(double a, long long b) {
	if (b == 0) return 1;
	return POW(a * a, b / 2) * (b & 1 ? a : 1);
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int H, W; cin >> H >> W;
	PII S, T;
	VS vs(H); {
		FOR(i, 0, H) {
			cin >> vs[i];
			FOR(j, 0, W) {
				if (vs[i][j] == 's')S = PII(i, j);
				if (vs[i][j] == 'g')T = PII(i, j);
			}
		}
	}
	auto cost = [&](int t, int i, int j) {
		return (vs[i][j] - '0')*POW(0.99, t);
	};
	auto f = [&](double X) {
		// X以上の経路のみを使用して到達可能か?
		VVI dist(H, VI(W, INF));
		using tp = tuple<int, int, int>;
		queue<tp>q;
		dist[S.first][S.second] = 1;
		q.push(tp(1, S.first, S.second));
		while (!q.empty()) {
			int d, y, x; tie(d, y, x) = q.front(); q.pop();
			FOR(k, 0, 4) {
				int ny = y + DY[k], nx = x + DX[k];
#define IN(a,A) (0<=a&&a<A)
				if (IN(ny, H) && IN(nx, W)) {
					if (vs[ny][nx] != '#') {
						if (isdigit(vs[ny][nx])) {
							double C = cost(d, ny, nx);
							if (C >= X) {
								if (dist[ny][nx] > d + 1) {
									dist[ny][nx] = d + 1;
									q.push(tp(d + 1, ny, nx));
								}
							}
						}
						else {
							if (dist[ny][nx] > d + 1) {
								dist[ny][nx] = d + 1;
								q.push(tp(d + 1, ny, nx));
							}
						}
					}
				}
			}
		}

		return dist[T.first][T.second] < INF;
	};
	double L = 0, R = 10;
	FOR(_, 0, 50) {
		double mid = (L + R) / 2;
		if (f(mid)) {
			L = mid;
		}
		else {
			R = mid;
		}
	}
	double ans = L;
	if (!f(-1)) {
		cout << -1 << endl;
	}
	else {
		cout << fixed << setprecision(10) << ans << "\n";
	}

	return 0;
}
