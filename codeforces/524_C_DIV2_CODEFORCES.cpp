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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/11/24  Problem: CodeForces524 C div2 / Link: http://codeforces.com/contest/1080/problem/C  ----- */
/* ------問題------

H*Wのチェスの碁盤がある。今から指定領域を塗りつぶす。最終的な白と黒の数は?
1. h*wを白で塗りつぶす。
2. その後h*wを黒で塗りつぶす。
3. その後集計

-----問題ここまで----- */
/* -----解説等-----

領域が交錯しないときは、領域内の他の色の個数をカウントすれば良い。
交錯するときは、黒が白になって再度黒になるとき、これは変化しなかったとして扱えば良い。

----解説ここまで---- */

LL ans = 0LL;

LL read() { LL in; scanf("%lld", &in); return in; }
int main() {
	LL cas = read();

	auto areas = [](LL sx, LL sy, LL tx, LL ty) {
		LL black = 0;
		LL white = 0;
		LL h = ty - sy + 1;
		LL w = tx - sx + 1;
		DD(de(h, w));
		if (h % 2 == 1 && w % 2 == 1) {
			LL p = sx + sy;
			if (p % 2 == 1) {
				black = (h * w + 1) / 2;
				white = (h * w) / 2;
			}
			else {
				black = (h * w) / 2;
				white = (h * w + 1) / 2;
			}
		}
		else {
			black = (h * w) / 2;
			white = (h * w) / 2;
		}

		return PLL(black, white);
	};
	FOR(_, 0, cas) {
		LL H = read(), W = read();
		LL black = 0;
		LL white = 0;
		if (H % 2 == 1 && W % 2 == 1) {
			black = (H*W) / 2;
			white = (H*W+1) / 2;
		}
		else {
			black = (H * W) / 2;
			white = (H * W) / 2;
		}
		PLL q1, q2, com;
		LL wx1 = read(), wy1 = read(), wx2 = read(), wy2 = read();
		LL bx1 = read(), by1 = read(), bx2 = read(), by2 = read();
		auto coms = [&]() {
			LL cx1 = max(wx1, bx1);
			LL cy1 = max(wy1, by1);
			LL cx2 = min(wx2, bx2);
			LL cy2 = min(wy2, by2);
			if (cy1 <= cy2 && cx1 <= cx2) {
				return areas(cx1, cy1, cx2, cy2);
			}
			return PLL(0, 0);
		};

		q1 = areas(wx1, wy1, wx2, wy2);
		q2 = areas(bx1, by1, bx2, by2);
		com = coms();
		DD(de(black, white));
		DD(de(q1.first, q1.second));
		DD(de(com.first, com.second));
		DD(de(q2.first,q2.second));
		{// to white
			black -= q1.first;
			white += q1.first;
			DD(de(black, white));
		}
		{
			black += com.first;
			white -= com.first;
			DD(de(black, white));
		}
		{// to black
			black += q2.second;
			white -= q2.second;
			DD(de(black, white));
		}
		cout << white << " " << black << endl;
	}

	return 0;
}
