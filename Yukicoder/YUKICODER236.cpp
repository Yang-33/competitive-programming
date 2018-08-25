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

/* -----  2018/08/25  Problem: yukicoder 236  / Link: http://yukicoder.me/problems/no/236  ----- */
/* ------問題------

コーヒーと紅茶を A:B の割合で混ぜて鴛鴦茶を作ります。
X ミリリットルのコーヒーと Y ミリリットルの紅茶があるとき、
最大で何ミリリットルの鴛鴦茶を作ることができますか。

（2015/07/06 23:27追記）
注意：出力関数によっては有効桁数の問題がありますので注意してください。

-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	double A, B, X, Y; cin >> A >> B >> X >> Y;

	double ans = (A + B)*min(X/A,Y/B);
	cout << fixed << setprecision(10) << ans << "\n";

	return 0;
}
