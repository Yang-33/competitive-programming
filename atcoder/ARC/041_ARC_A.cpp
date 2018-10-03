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

/* -----  2018/10/03  Problem: ARC 041 A / Link: http://arc041.contest.atcoder.jp/tasks/arc041_a  ----- */
/* ------問題------

表向きのコインが x 枚、裏向きのコインが y 枚ある。 高橋君はちょうど k 枚のコインを選び、それらすべてをひっくり返す。 その結果、表向きのコインは最大で何枚になるか？

-----問題ここまで----- */
/* -----解説等-----

裏のものを全部表にする以上にひっくり返さないといけないかで場合分け

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL x, y; cin >> x >> y;
	LL k; cin >> k;

	LL ans = 0;
	LL gsum = y - k;
	if (gsum < 0) {
		ans = x + y + gsum;
	}
	else {
		ans = x + k;
	}


	cout << ans << "\n";

	return 0;
}