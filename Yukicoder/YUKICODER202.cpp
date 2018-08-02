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
int DX[9] = { 0,0, 0, 1, -1, 1, 1, -1, -1 };    int DY[9] = { 0,1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/08/02  Problem: yukicoder 202  / Link: http://yukicoder.me/problems/no/202  ----- */
/* ------問題------

ユキさんは、手元にある大量の1円玉を1枚ずつ部屋の床に投げて遊んでいます。

投げた1円玉が床の上で止まったとき、それが既に投げられた床の上の1円玉と
少しでも重なって止まった場合には、次の1円玉を投げる前に、その投げた1円玉を
取り除きます。
そうではない場合、すなわち、投げた1円玉が床の上の1円玉と全く重ならずに
止まった場合には、その投げた1円玉をそのまま床の上に残します。
（この場合、その投げた1円玉はそれ以降ずっと移動しないものとします）。

ユキさんは、すでに1円玉をN回投げ終えました。さて、床の上には何枚の
1円玉があるでしょうか？

なお、
投げた1円玉は、床の上（または床の上の1円玉の上）に、必ず倒れた状態で
止まるものとします。
1円玉は円形とし、半径は10とします。厚みは無視します。
2つの1円玉の円がちょうど互いに外接する状態では、それら2つの1円玉は
重なっていないものとします。
N回投げたそれぞれの1円玉が止まった時の円の中心位置が、
床面上の座標として記録されています。

-----問題ここまで----- */
/* -----解説等-----

領域を適当なサイズに分割する。
平方分割ではないけど、影響する範囲が少ないので適度に分割すればよい。

----解説ここまで---- */

const int SZ = 75;
const int MSZ = 20500;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	// 50*50
	using Circle = tuple<int, int>;
	vector<vector<vector<Circle>>>block(MSZ/SZ, vector<vector<Circle>>(MSZ/SZ));

	auto check = [&block](const Circle& c) {
		int X, Y;
		tie(X, Y) = c;
		X /= SZ, X += 2, Y /= SZ, Y += 2;

		FOR(k, 0, 9) {
			int nx = X + DX[k], ny = Y + DY[k];
			for (const auto& cc : block[nx][ny]) {
				auto circle_intersect = [](const Circle&a, const Circle&b) {
					int ax, ay; tie(ax, ay) = a;
					int bx, by; tie(bx, by) = b;
					ax -= bx, ay -= by;
					if (ax*ax + ay*ay < 400)return 2;
					else return 1;
				};
				int ci = circle_intersect(cc, c);
				if (ci == 2) {
					return false;
				}
			}
		}

		return true;
	};
	auto PUSH = [&block](const Circle& c) {
		int X, Y;
		tie(X, Y) = c;
		X /= SZ, X += 2, Y /= SZ, Y += 2;

		block[X][Y].push_back(c);
	};
	FOR(i, 0, N) {
		int x, y; cin >> x >> y;
		Circle c({ x,y });
		if (check(c)) {
			PUSH(c);
		}
	}
	int ans = 0;
	FOR(i, 0,MSZ/SZ) {
		FOR(j, 0, MSZ/SZ) {
			ans += SZ(block[i][j]);
		}
	}
	cout << ans << "\n";

	return 0;
}
