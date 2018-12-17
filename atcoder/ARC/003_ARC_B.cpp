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

/* -----  2018/12/15  Problem: ARC 003 B / Link: http://arc003.contest.atcoder.jp/tasks/arc003_b  ----- */
/* ------問題------

高橋君は友達とチャットで逆さしりとりをすることにしました。
逆さしりとりとは、前の人が言った単語の頭文字で終わる単語を答えるしりとりです。
しかし、高橋君は英単語に自信がないのでこっそり「さかさま辞書」を使うことにしました。

普通の辞書は単語の先頭の文字がABC順になるように並べられており、同じ文字同士の場合はその次の文字がABC順になるように並べられます。
先頭から見ていく普通の辞書順に対して、「さかさま辞書」は後ろの文字から見ていきます。
例えば apple, bee, card は、普通の辞書なら apple → bee → card の順になります。
しかし、「さかさま辞書」では d で終わる card が 1 番、apple とbee は同じ e で終わるのでその 1 つ前が e である bee が 2 番、l であるapple が 3 番の順になります。

図(a)：普通の辞書順に並べた例　　図(b)：さかさま辞書順に並べた例

高橋君の代わりに「さかさま辞書」を作成し、与えられた単語を「さかさま辞書」順に並べてください。

-----問題ここまで----- */
/* -----解説等-----

自分でソートするやつ。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VS vs(N); {
		FOR(i, 0, N) {
			cin >> vs[i];
		}
	}
	sort(ALL(vs), [](const string& L,const string& R) {
		int Li = SZ(L) - 1; int Ri = SZ(R) - 1;
		while (Li >= 0 && Ri >= 0) {
			if (L[Li] != R[Ri]) {
				return L[Li] < R[Ri];
			}
			else {
				Li--, Ri--;
			}
		}
		if (Ri >= 0)return true;
		else return false;
	});
	FOR(i, 0, N) {
		cout << vs[i] << endl;
	}

	return 0;
}
