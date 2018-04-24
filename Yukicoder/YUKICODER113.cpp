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

/* -----  2018/04/24  Problem: yukicoder 113  / Link: http://yukicoder.me/problems/no/113  ----- */
/* ------問題------

A君は宝の地図を手に入れました。
地図には公園があり公園の中心に目印が書いてありました。
そして、そこからの移動方法が書いてありました。
書いてある文字に対応する移動方法は次のようになります。

・「N」は北に1メートル移動する。
・「E」は東に1メートル移動する。
・「W」は西に1メートル移動する｡
・「S」は南に1メートル移動する。

例えば、「NE」と書いてあるなら北に1メートル歩いたのち東に1メートル歩きます。
その地点を掘れば宝が出てくるようです。
しかし、A君は移動方法の無駄に気づきました。
「NE」であれば北東の方向に12+12−−−−−−√=2–√メートルだけ移動すれば良さそうです。
A君は公園の中心から最短の距離で宝が埋まっている位置に移動したいです。
障害物にぶつかる可能性は無いとして、A君は何メートル移動する必要があるでしょうか？

-----問題ここまで----- */
/* -----解説等-----

やっていけばよい。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s;  cin >> s;
	int x = 0, y = 0;
	FOR(i, 0, SZ(s)) {
		if (s[i] == 'N')x++;
		else if (s[i] == 'S')x--;
		else if (s[i] == 'E')y++;
		else y--;
	}

	double ans = sqrt(x*x+y*y);
	cout <<fixed<<setprecision(10)<< ans << "\n";

	return 0;
}
