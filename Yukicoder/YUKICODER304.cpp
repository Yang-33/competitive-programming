#include "bits/stdc++.h"
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

/* -----  2018/09/29  Problem: yukicoder 304  / Link: http://yukicoder.me/problems/no/304  ----- */
/* ------問題------

yukiくんは自転車の鍵の暗証番号を忘れてしまいました。 適当にyukiくんに番号を伝えて、なんとか解錠を手伝ってあげてください。

暗証番号は3桁の数字(000 ～ 999)です。 3桁の数字(先頭のゼロを含む)を標準出力に出力すると、 "locked" か "unlocked" のいずれかの文字列がジャッジから標準入力に返されます。
"locked" が返されたとき、鍵はまだ解錠できていません。別の数字を試しましょう。
"unlocked" が返されたとき、鍵は解錠できています。プログラムを終了してください。解錠したクエリより後に余計な出力があるとWAになります。
時間制限内なら何度でも挑戦可能です。

-----問題ここまで----- */
/* -----解説等-----

1000回できる。練習？

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	auto ask = [](int x) {
		cout << setw(3) << setfill('0') << x << endl;
		string s; cin >> s;
		return s == "unlocked";
	};
	FOR(i, 0, 1000) {
		int res = ask(i);
		if (res)break;
	}

	return 0;
}
