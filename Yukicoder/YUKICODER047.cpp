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

/* -----  2018/04/11  Problem: yukicoder 047  / Link: http://yukicoder.me/problems/no/047  ----- */
/* ------問題------

Saraは、「ふしぎなポケット」を手に入れた。
「ふしぎなポケット」は、いくつかビスケットを入れて叩くと、入れたビスケットの数が２倍になる。
Saraは最初1枚のビスケットを持っていて、「ふしぎなポケット」を使ってちょうどN枚のビスケットにして、全部食べたいと思っている。
（食べきれないので枚数をオーバーしてはいけない）
この時、ちょうどN枚にするには、Saraは最低何回ポケットを叩く必要があるか求めてください。

-----問題ここまで----- */
/* -----解説等-----

2^k+aのようにして、任意の数を作れるので、N≦2^xとなるような最小のxを出力すれば良い。


----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	int s = 1;
	while(N > s) {
		s *= 2;
		ans++;
	}
	cout << ans << "\n";

	return 0;
}
