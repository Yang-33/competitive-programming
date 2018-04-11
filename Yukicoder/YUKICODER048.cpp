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

/* -----  2018/04/11  Problem: yukicoder 048  / Link: http://yukicoder.me/problems/no/048  ----- */
/* ------問題------

太郎君はロボットを遠隔で操縦している。

このロボットは現在(0,0)の座標に立っていて北の方向を向いている。
太郎君はいまこのロボットを(X,Y)の座標に移動させたいと思っている。

ロボットに出来る命令は、1回につき以下のうちいずれかの命令を選んで指示することができる。
・時計回りに、90∘ その場で向き(進行方向)を変える。
・反時計回りに、90∘ その場で向き(進行方向)を変える。
・向いている方向に K距離だけ前進する。Kは、(1≤K≤L) の範囲で、命令のたびに指定することができる。

-----問題ここまで----- */
/* -----解説等-----

北側を向いているので、Y≧0としてY軸上のときは、0回の方向転換、そうでないときは1回の方向転換で移動できる。
Y<0のときは、2回で移動できる。
したがって軸上のみ場合分けすれば良い。

----解説ここまで---- */

LL X, Y, L;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> X >> Y >> L;
	int rot = 0;
	if (X != 0) {
		rot++;
	}
	if (Y < 0) {
		rot++;
		if (X == 0)rot++;
	}
	ans = (abs(X) + L - 1) / L + (abs(Y) + L - 1) / L + rot;
	cout << ans << "\n";

	return 0;
}
