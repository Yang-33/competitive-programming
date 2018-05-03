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

/* -----  2018/05/03  Problem: yukicoder 149  / Link: http://yukicoder.me/problems/no/149  ----- */
/* ------問題------

中身が見えない袋Aと袋Bがある。
袋Aと袋Bにはそれぞれ碁石が入っている。
袋Aには白い碁石がAw個、黒い碁石がAb個入っている。
袋Bには白い碁石がBw個、黒い碁石がBb個入っている。

最初に袋A個から色を見ずにC個の碁石を取り出し袋Bに移す。
次に、袋Bからまた色を見ずにD個の碁石を取り出し袋Aに移す。

最後に袋Aに入っている白い碁石の数を数えるとき、
可能性としてありうる最多の白い碁石の数はいくつか？

-----問題ここまで----- */
/* -----解説等-----

最初になるべく白色を移さないようにして、次にたくさん白色を移動させれば良い。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int Aw, Ab, Bw, Bb, C, D;
	cin >> Aw >> Ab >> Bw >> Bb >> C >> D;
	int decW = max(0,C - Ab);
	Aw -= decW;
	Bw += decW;
	int incW = min(Bw, D);
	ans = Aw + incW;


	cout << ans << "\n";

	return 0;
}
