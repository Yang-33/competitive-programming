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

/* -----  2017/11/29  Problem: 070_abc_b / Link: https://abc070.contest.atcoder.jp/tasks/abc071_b  ----- */
/* ------問題------

Alice と Bob は、ロボットを制御するためのスイッチを1つずつ持っており、ロボットを動かしています。 
Alice はロボットを動かし始めて A 秒後にスイッチを押し始め、ロボットを動かし始めて B 秒後にスイッチを離しました。 
Bob はロボットを動かし始めて C 秒後にスイッチを押し始め、ロボットを動かし始めて D 秒後にスイッチを離しました。 
Alice と Bob が、二人ともスイッチを押していた秒数を求めてください。

-----問題ここまで----- */
/* -----解説等-----

区間のテク

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	ans = min(b,d) - max(a,c);
	if (ans < 0)ans = 0;
	cout << ans << "\n";

	return 0;
}
