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
#define DEBUG(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/19  Problem: ARC 037 A / Link: http://arc037.contest.atcoder.jp/tasks/arc037_a  ----- */
/* ------問題------

高橋君には「未来視」という能力がある。
彼は大学で N 個の科目を履修しており、全ての科目の試験で 80 点以上を取ることが目標である。
たった今見た「未来視」によると、各科目 i について、勉強せずにその科目の試験を受けると mi 点を取ることが予測される。
高橋君は 1 つの科目を 1 分間勉強するごとに、その科目の試験で取ることが予測される点数を 1 点上げることができる。
「未来視」が正しいとして、高橋君が目標を達成するために必要な最短の合計勉強時間を求めよ。

-----問題ここまで----- */
/* -----解説等-----

実際に見ればよい。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
		ans += max(0LL, 80 - a[i]);
	}

	cout << ans << "\n";

	return 0;
}