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

/* -----  2018/02/23  Problem: 074_arc_a / Link: https://abc062.contest.atcoder.jp/tasks/arc074_a?lang=en  ----- */
/* ------問題------

縦 H ブロック、横 W ブロックの板チョコがあります。 すぬけ君は、この板チョコをちょうど 3 つのピースに分割しようとしています。 ただし、各ピースはブロックの境目に沿った長方形でなければなりません。

すぬけ君は、3 つのピースの面積 (ブロック数) をできるだけ均等にしようとしています。 具体的には、3 つのピースの面積の最大値を Smax、最小値を Smin としたとき、Smax−Smin を最小化しようとしています。 Smax−Smin の最小値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

一つ決めるとあとは全部決まるので、分割の仕方を全探索

----解説ここまで---- */

LL H, W;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> H >> W;

	ans = LINF;
	FOR(k, 0, 2) {
		swap(H, W);
		FOR(i, 1, W) {
			LL a = i;
			LL b = (W - i) / 2;
			LL c = W - a - b;

			LL Sx = a*H;
			LL Sy = b*H;
			LL Sz = c*H;
			ans = min(ans, max({ Sx, Sy, Sz }) - min({ Sx, Sy, Sz }));

			LL w = W - a;
			LL bb = H / 2;
			LL cc = H - bb;
			Sy = bb*w;
			Sz = cc*w;
			ans = min(ans, max({ Sx, Sy, Sz }) - min({ Sx, Sy, Sz }));

		}
	}
	cout << ans << "\n";

	return 0;
}
