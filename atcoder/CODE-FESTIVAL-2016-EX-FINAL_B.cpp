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

/* -----  2018/03/03  Problem: code-festival-2016-ex-final_b / Link: https://cf16-exhibition-final.contest.atcoder.jp/tasks/cf16_exhibition_final_b?lang=en  ----- */
/* ------問題------

すぬけ君は、誕生日プレゼントに三角形をもらいました。 三頂点の座標は (x1,y1), (x2,y2), (x3,y3) でした。
すぬけ君は、三角形の内部に半径の等しい二つの円を、重ならないように描きたいです (二円が点で接していてもいいです)。 円の半径の最大値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

S = 1/2 * abs(ay(bx-cx) + by(cx-ax) + cy(ax -bx)) = 1/2 * R * (a + b + c)
内心円の中心からなる円を２つ書くとこれらはある辺に対して平行
相似から、求めるものをXとすると
X = {edge() * R} / (2r + edge())
edge()は当然3つあるので全部やる

----解説ここまで---- */

LL N;

double ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	double ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	double a = hypot(ax - bx, ay - by);
	double b = hypot(bx - cx, by - cy);
	double c = hypot(cx - ax, cy - ay);
	double R = abs(ay*(bx - cx) + by*(cx - ax) + cy*(ax - bx)) / (a + b + c);
	ans = max({ a,b,c }) * R / (2 * R + max({ a,b,c }));
	cout << fixed << setprecision(10) << ans << "\n";

	return 0;
}
