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

/* -----  2018/09/29  Problem: yukicoder 296  / Link: http://yukicoder.me/problems/no/296  ----- */
/* ------問題------

ユキさんは朝が苦手です。目覚まし時計のアラームが鳴っても、ついついアラームを止めて、2度寝をしてしまいます。目覚まし時計はアラームを繰り返しますが、ユキさんはやはりアラームを止めて、最終的に起床するまでに、3度寝、4度寝、…、n度寝と繰り返してしまいます。

目覚まし時計のアラームが最初に鳴る時刻と、それ以降にアラームが鳴る間隔が与えられたとき、ユキさんがn度寝するとして、ユキさんが最終的に起床する時刻を求めてください。

以下の点に注意してください。

n度寝とは、最初に目覚めた後、最終的に起床するまでn−1回目覚めることを言います。
ユキさんはアラームが鳴ると必ず目覚めます。
目覚まし時計は、最初にアラームを鳴らした後、ユキさんが最終的に起床するまで、一定間隔でアラームを繰り返します。
最終的に起床する場合以外、ユキさんは目覚めるとアラームを止め再び眠ります。この動作は一瞬で終わるものとします。
サマータイムは考慮しません。

-----問題ここまで----- */
/* -----解説等-----

分に直すと簡単！

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, H, M, T; cin >> N >> H >> M >> T;
	LL ans = 60 * H + M + (N - 1)*T;
	ans %= 1440;
	cout << ans / 60 << endl;
	cout << ans % 60 << endl;

	return 0;
}
