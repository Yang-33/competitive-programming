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

/* -----  2017/11/22  Problem: 073_arc_a / Link: https://arc073.contest.atcoder.jp/tasks/arc073_a?lang=en  ----- */
/* ------問題------

とある銭湯には、スイッチを押すと T 秒間お湯が出るシャワーがあります。
なお、お湯が出ているときにスイッチを押すと、そのタイミングから T 秒間お湯が出つづけます。 お湯の出る時間が T 秒間延長されるわけではないことに注意してください。
このシャワーの前を、N 人の人がスイッチを押して通り過ぎていきます。 i 人目の人は、1 人目の人がスイッチを押した ti 秒後にスイッチを押します。
お湯が出る時間の総和は何秒かを求めてください。

-----問題ここまで----- */
/* -----解説等-----

最大はTであることに注意していきながら、区間の最小をとればよい。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL T; cin >> N >> T;
	VL t(N + 1, 0);
	t[N] = LINF;
	FOR(i, 0, N)cin >> t[i];
	FOR(i, 0, N) {
		ans += min(t[i + 1] - t[i], T);
	}
	cout << ans << "\n";

	return 0;
}
