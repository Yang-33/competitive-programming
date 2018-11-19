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

/* -----  2018/11/19  Problem: ARC 053 C / Link: http://arc053.contest.atcoder.jp/tasks/arc053_c  ----- */
/* ------問題------

高橋君は N 個の魔法を覚えています。魔法は 1 から N まで番号が振られています。
最初、気温は 0 度です。高橋君が i 番目の魔法を唱えると、気温が ai 度だけ上がった後 bi 度だけ下がります。
高橋君はすべての魔法をちょうど 1 回ずつ唱えます。この間の気温の最大値を X 度とします。高橋君は魔法を唱える順番を工夫して、X をできるだけ小さくしようとしています。X の最小値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

証明ちゃんとできてないけどこれしか無いと思って出してしまった...本当に良くない
まず下がる方が大きい方を最初に行うのが良い。
下がる中でもなるべく浅くしたいので、a[i]が小さい方が良い。
次に、上がる方を考える。これはなるべく下がってくれたほうが嬉しい。(わりと下がるものを最後に持ってくるのは無駄)
これを順に貪欲にやると最適。(ホンマかいな…)

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VL a(N), b(N);
	VI minus, plus;
	FOR(i, 0, N) {
		cin >> a[i] >> b[i];
		if (a[i] > b[i])plus.push_back(i);
		else minus.push_back(i);
	}
	sort(ALL(plus), [&](int ai, int bi) {
		if (b[ai] == b[bi]) {
			return a[ai] < a[bi];
		}
		else {
			return b[ai] > b[bi];
		}
	});
	sort(ALL(minus), [&](int ai, int bi) {
		if (a[ai] == a[bi]) {
			return b[ai] > b[bi];
		}
		else {
			return a[ai] < a[bi];
		}
	});

	LL cur = 0;
	for (int i : minus) {
		cur += a[i];
		ans = max(ans, cur);
		cur -= b[i];
	}
	for (int i : plus) {
		cur += a[i];
		ans = max(ans, cur);
		cur -= b[i];
	}

	cout << ans << "\n";

	return 0;
}
