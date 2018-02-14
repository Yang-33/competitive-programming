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

/* -----  2018/02/14  Problem: 063_arc_a / Link: https://abc047.contest.atcoder.jp/tasks/arc063_a?lang=en  ----- */
/* ------問題------

きつねの次郎と三郎が一次元リバーシで遊んでいます。一次元リバーシでは、盤面には白か黒の石が一列に並んだ状態となっており、列の右端か左端に新たに石を打っていきます。通常のリバーシと同じように、たとえば白の石を打つことで黒の石を挟むと、挟まれた黒の石は白い石に変わります。
ゲームの途中で三郎に急用ができて帰ってしまうことになりました。このとき、盤面の状態は文字列 S で表されます。石は |S| (文字列の長さ) 個並んでおり、左から i (1≦i≦|S|) 個目の石の色は、S の i 文字目が B のとき黒、W のとき白です。
次郎は現在の盤面に対して、できるだけ少ない個数の石を新たに打つことで全ての石を同じ色にしようと考えました。最小で何個の石を打てばよいかを求めてください。

-----問題ここまで----- */
/* -----解説等-----

区間が切り替わるだけ石を置かないと行けない。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	char t = s[0];
	FOR(i, 1, SZ(s)) {
		if (t != s[i]) {
			t = s[i];
			ans++;
		}
	}
	cout << ans << "\n";

	return 0;
}
