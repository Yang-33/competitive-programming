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

/* -----  2018/04/26  Problem: yukicoder 126  / Link: http://yukicoder.me/problems/no/126  ----- */
/* ------問題------

Wilsonはショッピングセンターに来ている。
ショッピングセンターは、地上100階と地下1階の合計101階存在する。
そのショッピングセンターにはエレベータが2基（それぞれ、エレベータA,エレベータBとする。）並んで存在している。
しかし、エレベータAのみ地下1階に行けるようになっている。
（エレベータBでは地下1階にはいけない）

各階には、上下のボタンが有り、それぞれのボタンを押した際に、その階に近い方のエレベータのかごが移動しきてドアが開き、客を乗せようとする。
どちらも距離が同じであればエレベータAが優先される。
すでにその階にエレベータがいると、どちらとものエレベータの移動はなく、ドアが開くだけになる。
ただし、1階で下ボタンを押すと、エレベータBは移動できないのでエレベータAのみが来てドアが開くことになる。
（エレベータBがすでに1階にいても、エレベータAが来ることになる。）

エレベータのかご内は、そのエレベータが行くことができれば任意の階のボタンを押して移動することができる。

これらのエレベータのみを使って地下一階に行きたいと思っている。
初期状態のそれぞれのエレベータの位置は把握できる。

このとき、これらのエレベータのそれぞれの現在の位置(A,B階)と、Wilsonの位置(S階)が与えられるので、エレベータの階間の最小の移動数の合計を求めてください。
客を乗せてない移動も移動数に含め、他に客がいないとする。
（与えられる値について、地下一階のことを0で表すことにする。）
エレベータに乗って、中のボタンを押してすぐに出るなどは、出来ないとする。

-----問題ここまで----- */
/* -----解説等-----

上行けるんかい…

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int A, B, S; cin >> A >> B >> S;
	LL ans = 0;
	if (abs(A - S) <= abs(B - S) || S == 1) {
		ans = abs(A - S) + S;
	}
	else {
		if (A == 0) {
			ans++;
			A = 1;
		}
		ans += abs(B - S) + A + min(S - 1, abs(A - S));
	}
	cout << ans << "\n";

	return 0;
}
