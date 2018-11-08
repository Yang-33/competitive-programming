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

/* -----  2018/11/10  Problem: ARC 024 B / Link: http://arc024.contest.atcoder.jp/tasks/arc024_b  ----- */
/* ------問題------

レッドブラックアイランドには特殊な性質を持った木が生えています。この木は赤色になったり黒色になったりする変わった木です。 この木には複数の個体が 1 箇所に集まって、ある円の円周上に 1 列に並ぶように生えるという特徴があります。
また、この木は同じ色が 1 箇所に集中しないように1日ごとに「バランスをとる」という性質があります。具体的には、自分とその両隣の木の色がすべて同じ色だったら、その木は次の日は異なる色に変わるという性質です。 より形式的に言うと、ある3つの木 A,B,C がこの順に並んでいて、それぞれの色が CA,CB,CC であるとします。このとき CA=CB=CC= 赤だったならば次の日 CB は黒になります。黒と赤が反対の場合も同様です。
しかし、この木は隣の木が次の日どうなるかに関わらず、その日の自分の状況だけを見て「バランスをとる」ことをします。そのため 1 日たっても同じ色の木が 3 つ連続で並ぶという事もあり得ます(下の入力例を参照してください)。そのときは次の日も同様に「バランスをとる」ことをします。
研究者であるあなたは N 個の木からなるある群れの 1 日目の色の状況を観測しました。何日目に全ての木の色が変わらなくなるか求めてください。

-----問題ここまで----- */
/* -----解説等-----

連続していない部分が互いに影響を与えることはないため、最長部分だけ見れば良い。
1日経過すると端に対応する要素が2減るので、これを計算すれば良い。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	{
		int f = 1;
		int fir = a.front();
		FOR(i, 0, N) {
			f &= fir == a[i];
		}
		if (f) {
			cout << -1 << endl;
			return 0;
		}
	}
	// どっかで終わるはずのとき
	// 最大を出せばよい
	VI b = a;
	FOR(i, 0, N)b.push_back(a[i]);
	// 2*N

	int maxlen = 0;
	int sub = 0;
	int pre = -1;
	FOR(i, 0, 2 * N) {
		if (pre == -1) {
			pre = b[i];
			sub = 1;
			maxlen = 1;
		}
		else if (pre == b[i]) {
			sub++;
			maxlen = max(maxlen, sub);
		}
		else {
			sub = 1;
			pre = b[i];
		}
	}
	DD(de(maxlen));
	ans = (maxlen + 1) / 2;
	cout << ans << "\n";

	return 0;
}