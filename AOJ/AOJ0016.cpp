#include "bits/stdc++.h"
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

/* -----  2017/10/03  Problem: AOJ 0016  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0016&lang=jp ----- */
/* ------問題------

北を向いており、(x,sh)で次の行動が指定される
今向いている向きからx進み、sh回転する(右向きが正)

-----問題ここまで----- */
/* -----解説等-----

数学で頑張る
誤差はいいのだろうか。

----解説ここまで---- */

LL N;

LL ans = 0LL;
double x, y;

int main() {
	int kaku = 90;
	while (2) {
		int a, b;
		scanf("%d,%d", &a, &b);
		if (a == 0 && b == 0)break;
		double sh = PI * 2 * kaku / 360;
		x += (double)a*cos(sh);
		y += (double)a*sin(sh);
		kaku = (kaku - b + 720) % 360;
	}
	printf("%d\n", (int)x);
	printf("%d\n", (int)y);

	return 0;
}
