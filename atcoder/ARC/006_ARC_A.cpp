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

/* -----  2018/12/15  Problem: ARC 006 A / Link: http://arc006.contest.atcoder.jp/tasks/arc006_a  ----- */
/* ------問題------

高橋君は夏の宝くじをこっそり買っていました。今日はその宝くじの当選発表日です。購入者は、0 から 9 までの 10 個の数字から重複せずに 6 つの数字を選び購入します。発表日には 6 つの本数字と 1 つのボーナス数字が発表され、購入した宝くじとその数字がいくつ一致しているかで以下のように当選の等級が決まります。
1 等 : 6 つ数字が一致
2 等 : 5 つ数字が一致し、残りの 1 つの数字がボーナス数字と一致
3 等 : 5 つ数字が一致
4 等 : 4 つ数字が一致
5 等 : 3 つ数字が一致
　上記のどれにも当てはまらない場合ははずれになります。 また、複数の等級を満たす場合は上位の等級（数字が小さい等級）が適用されます。

 　高橋君が購入した宝くじの等級を求めなさい。 なお、与えられる当選番号とボーナス数字の 7 つの数字は互いに異なります。

-----問題ここまで----- */
/* -----解説等-----

場合分けしてやる

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	VI e(6); FOR(i, 0, 6) {
		cin >> e[i];
	}
	int B; cin >> B;
	VI l(6); FOR(i, 0, 6) {
		cin >> l[i];
	}
	bitset<10>E, L;
	FOR(i, 0, 6) {
		E[e[i]] = 1;
		L[l[i]] = 1;
	}
	bitset<10>res = E & L;
	int ans = res.count();
	if (ans == 6) {
		cout << 1 << endl;
	}
	else if (ans == 5) {
		if (!res[B] && L[B]) {
			cout << 2 << endl;
		}
		else {
			cout << 3 << endl;
		}
	}
	else if (ans == 4) {
		cout << 4 << endl;
	}
	else if (ans == 3) {
		cout << 5 << endl;
	}
	else {
		cout << 0 << endl;
	}
	
	
	return 0;
}
