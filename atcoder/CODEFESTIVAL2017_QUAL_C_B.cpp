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

/* -----  2017/10/22  Problem: codefestival2017_qual_b B  / Link: https://beta.atcoder.jp/contests/code-festival-2017-qualc  ----- */
/* ------問題------

2 つの長さ N の整数列 x1,x2,…,xN と y1,y2,…,yN が「似ている」とは、 任意の i (1≤i≤N) に対して |xi−yi|≤1 が成り立つことをいうものとします。
とくに、どの整数列もその数列自身と似ていると考えます。
整数 N および長さ N の整数列 A1,A2,…,AN が与えられます。
A と似ている整数列 b1,b2,…,bN であって、すべての項の積 b1b2…bN が偶数となるものはいくつあるか求めてください。

-----問題ここまで----- */
/* -----解説等-----

偶奇で場合分け
全部奇数だとだめじゃーんってなるので、これをのぞく。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	LL x = 1;
	ans = 1;
	FOR(i, 0, N) {
		if (a[i] % 2 == 0)x *= 2;
		ans *= 3;
	}
	ans -= x;
	cout << ans << "\n";

	return 0;
}