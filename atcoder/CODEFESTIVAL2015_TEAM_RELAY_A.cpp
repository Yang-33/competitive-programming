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

/* -----  2018/12/21  Problem: codefestival2015_team_relay A / Link: __CONTEST_URL__  ----- */
/* ------問題------

チーム対抗早解きリレーは、10 人のメンバーからなる 20 個のチームに分かれて行うプログラミングコンテストです。
チーム分けは、参加者の本戦の順位を使って以下のような手順で決めます。
1～20 位の人は、順に 1～20 のチームに入る。
21～40 位の人は、逆順に 1～20 のチームに入る。
41～60 位の人は、順に 1～20 のチームに入る。
...
例えばチーム 1 のメンバーの本戦での順位は、それぞれ 1,40,41,80,81,120,121,160,161,200 位となります。
チーム番号が与えられるので、そのチームのメンバーの本戦の順位の和を求めてください。

-----問題ここまで----- */
/* -----解説等-----

和が一定になるのは明らか。
1005になる。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	LL ans = 1005;
	cout << ans << endl;

	return 0;
}