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

/* -----  2018/11/10  Problem: ARC 025 A / Link: http://arc025.contest.atcoder.jp/tasks/arc025_a  ----- */
/* ------問題------

stove 君はとある平面世界の住人である。
ある日 stove 君は多くの金が取れる鉱山を砂漠とジャングルに発見した。
stove 君は 7 日間かけて鉱山採掘に取り組むことにした。
砂漠とジャングルは遠い位置関係にあるので、それぞれの日にはどちらか一方の鉱山でしか採掘できない。
その日の天候、気分に応じて採掘量が鉱山ごとに変化してしまうので、どちらの鉱山を選ぶべきかがその日毎に異なる場合がある。
それぞれの日においての採掘量が分かっているとき、最適に鉱山を選んだ場合に得られる金の量がいくらかを求めるプログラムを作成せよ。

-----問題ここまで----- */
/* -----解説等-----

maxをとる。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N = 7;
	VI a(N), b(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	FOR(i, 0, N) {
		cin >> b[i];
	}
	FOR(i, 0, N) {
		int ret = max(a[i], b[i]);
		ans += ret;
	}

	cout << ans << "\n";

	return 0;
}