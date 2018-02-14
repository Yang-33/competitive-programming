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

/* -----  2018/02/14  Problem: 064_abc_c / Link: https://abc064.contest.atcoder.jp/tasks/abc064_c?lang=en  ----- */
/* ------問題------

AtCoderでは、コンテストに参加すると「色」が付き、これはレートによって次のように変化します：
•レート 1-399：灰色
•レート 400-799：茶色
•レート 800-1199：緑色
•レート 1200-1599：水色
•レート 1600-1999：青色
•レート 2000-2399：黄色
•レート 2400-2799：橙色
•レート 2800-3199：赤色
また、レートが 3200 以上になると色を自由に変えることができます。
現在 N 人の人がAtCoderのコンテストに参加したことがあり、i 人目の人のレートは ai です。
そのとき、色の種類数の最小値と最大値を求めなさい。


-----問題ここまで----- */
/* -----解説等-----

言われたとおりに書く。
上手に書けた。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI a(N);
	VI c(8,0);
	int god = 0;
	FOR(i, 0, N) {
		cin >> a[i];
		if (a[i] >= 3200)god++;
	}
	FOR(i, 0, 8) {
		FOR(k, 0, N) {
			if (i * 400 <= a[k] && a[k] < (i + 1) * 400) {
				c[i]++;
			}
		}
	}
	int m = 0;
	int M = 0;
	FOR(i, 0, 8) {
		if (c[i])m++;
	}
	if (m == 0 && god)m = 1,M=god;
	else M = m + god;
	cout << m << " " << M << endl;
	return 0;
}
