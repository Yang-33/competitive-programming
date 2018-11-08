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

/* -----  2018/11/10  Problem: ARC 024 A / Link: http://arc024.contest.atcoder.jp/tasks/arc024_a  ----- */
/* ------問題------

ARCマートは土曜日だけに営業する靴屋さんです。扱う靴は1種類だけで、サイズ以外の見分けはつきません。 残念なことに、 1 週間ぶりに店を開けると空き巣に入られてしまったらしく、靴がめちゃくちゃに散乱していました。
残っている靴を全部かき集めると、左足の靴が L 足、右足の靴が R 足みつかりました。 ただ、靴を売るには同じサイズを両足分そろえてペアにしなければなりません。 靴の種類はすべて同じなので、ペアを作るときはサイズだけを気にすれば良さそうです。
もう開店まで時間がないので、店長のために、最大で何組のペアを作ることができるか求めてください。

-----問題ここまで----- */
/* -----解説等-----

あるサイズについて存在するかを見れば良い。mapやcntでもいいけどmultisetが楽。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL A, B; cin >> A >> B;
	VI a(A), b(B);
	FOR(i, 0, A) {
		cin >> a[i];
	}
	FOR(i, 0, B) {
		cin >> b[i];
	}
	SORT(a), SORT(b);
	multiset<int>bb(ALL(b));
	for (int i : a) {
		auto it = bb.find(i);
		if (it != bb.end()) {
			ans++;
			bb.erase(it);
		}
	}

	cout << ans << "\n";

	return 0;
}