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

/* -----  2018/04/12  Problem: yukicoder 055  / Link: http://yukicoder.me/problems/no/055  ----- */
/* ------問題------

異なる4点の整数座標を渡されました。
方眼紙に4点を頂点とする正方形を描くのが仕事です。
しかし、4点のうち1点だけがわからなくなってしましました。
わかっているのは残りの3点の座標です。
もし、1点を推測して正方形が描けるのであれば、
正方形を描けるその1点の座標を答えなさい。
正方形が描けない場合は-1を答えとします。

-----問題ここまで----- */
/* -----解説等-----

辺の長さが等しくて、角度が90度であったときは正方形で、
補完する点はベクトルっぽく考えると簡単に求められる。

----解説ここまで---- */

LL N;

LL ans = 0LL;
void rotate(VL& a) {
	LL tmp = a[0];
	a[0] = a[1];
	a[1] = a[2];
	a[2] = tmp;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	VL X(3), Y(3);
	FOR(i, 0, 3) {
		cin >> X[i] >> Y[i];
	}
	FOR(k, 0, 3) {
		rotate(X); rotate(Y);
		LL x1 = X[1] - X[0], y1 = Y[1] - Y[0];
		LL x2 = X[2] - X[0], y2 = Y[2] - Y[0];
		if (x1 * x1 + y1 * y1 != x2 * x2 + y2 * y2) continue;
		if (x1 * x2 + y1 * y2 != 0) continue;
		cout << X[0] + x1 + x2 << " " << Y[0] + y1 + y2 << endl;
		return 0;
	}
	cout << -1 << endl;

	return 0;
}
