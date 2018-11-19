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

/* -----  2018/11/19  Problem: ARC 054 B / Link: http://arc054.contest.atcoder.jp/tasks/arc054_b  ----- */
/* ------問題------

高橋君はタカハシマン関数という関数に興味を持ちました。高橋君は T(334) ( T はタカハシマン関数を表す)を計算したいと思いましたが、それは現代のコンピュータでは P 年がかかるため、とても難しいということが分かりました。
半ば計算をあきらめかけていた高橋君でしたが、世の中にはムーアの法則という法則があることを知りました。 ムーアの法則によると、コンピュータの速度は 1.5 年ごとに 2 倍になる速度で、指数関数的に増大することが分かりました。
より正確には、x 年後にはコンピュータの速度は現代の 2x⁄1.5 倍になります。
高橋君は適切なタイミングで計算を始めることで、T(334) の計算をできるだけ早く終わらせたいと思いました。 もちろん計算中にコンピュータを変えることはできないので、計算を終えるまでの時間は (計算を始めるまでの時間)+(計算を始めた時点のコンピュータでT(334)を計算するのにかかる時間) であらわされます。
計算が終わるまでの最短の時間を求めてください。

-----問題ここまで----- */
/* -----解説等-----

三分探索

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	double P; cin >> P;
	auto f = [&P](double X) {
		double val = X + P / pow(2.0, X / 1.5);
		return val;
	};

	double L = 0, R = 334;
	FOR(i, 0, 100) {
		double m1 = (2 * L + R) / 3;
		double m2 = (L + 2 * R) / 3;
		if (f(m1) < f(m2)) {
			R = m2;
		}
		else {
			L = m1;
		}

	}


	double ans = f(R);
	cout<<fixed<<setprecision(10) << ans << "\n";

	return 0;
}
