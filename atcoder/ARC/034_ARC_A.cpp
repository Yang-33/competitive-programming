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

/* -----  2018/10/27  Problem: ARC 034 A / Link: http://arc034.contest.atcoder.jp/tasks/arc034_a  ----- */
/* ------問題------

N 人の人が高橋大学の入学試験を受けた。試験には「国語」「数学」「理科」「英語」「塗り絵」の 5 科目がある。各受験生について、その人の「国語」「数学」「理科」「英語」の 4 科目の得点の合計に、「塗り絵」の得点の 110⁄900 倍を加えたものがその人の最終得点となる。
各受験生の各試験の得点が与えられる。N 人のうち最も最終得点が高い受験生の最終得点を求めよ。

-----問題ここまで----- */
/* -----解説等-----

やっていこう

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	double ans = 0;
	FOR(i, 0, N) {
		double a, b, c, d, e; cin >> a >> b >> c >> d >> e;
		double sum = a + b + c + d + e*(110.0/900);
		ans = max(ans, sum);

	}

	cout << fixed << setprecision(10) << ans << "\n";

	return 0;
}
