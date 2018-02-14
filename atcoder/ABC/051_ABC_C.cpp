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

/* -----  2018/02/14  Problem: 051_abc_c / Link: https://abc051.contest.atcoder.jp/tasks/abc051_c?lang=en  ----- */
/* ------問題------

イルカは x 軸正方向を右、y 軸正方向を上とする 2 次元座標平面にいます。
イルカは現在点 (sx,sy) にいて、1 秒あたり上下左右に距離 1 だけ進むことができます。
このとき、移動前と移動後の x 座標、y 座標はともに整数でなければなりません。
イルカはここから sx<tx と sy<ty を満たす点 (tx,ty) に行き、その後点 (sx,sy) に戻り、また点 (tx,ty) に行き、その後点 (sx,sy) に戻ります。
このとき、イルカは点 (sx,sy) と点 (tx,ty) を除いて、途中で同じ座標を複数回通らないように移動しなければなりません。
このような条件を満たすイルカの最短経路を 1 つ求めてください。

-----問題ここまで----- */
/* -----解説等-----

時計回りに巡回するとすると、
方向も限定されているので二回目のコースは介する点の間に角を入れる感じで
S(↑*,→*)T(↓*←*)S[←↑](↑*,→*)[→↓]T[→↓](↓*←*)[←↑]S
とすればよい。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	int U = ty - sy;
	int D = U;
	int R = tx - sx;
	int L = R;
	string UU = string(U, 'U');
	string DD = string(D, 'D');
	string RR = string(R, 'R');
	string LL = string(L, 'L');
	string ans = "";

	ans = UU + RR + DD + LL + "LU" + UU + RR + "RDRD" + DD + LL + "LU";
	cout << ans << endl;
	return 0;
}
