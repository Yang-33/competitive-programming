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

/* -----  2018/12/19  Problem: codefestival2014_team_relay A / Link: __CONTEST_URL__  ----- */
/* ------問題------

ある日、haruki さんは学校で素数について習いました。素数とは、1 とその数自身でしか割り切れない 1 より大きい整数のことです。
とても好奇心旺盛な haruki さんは以下のような疑問を持ちました。
「n 以下の素数の中に偶数はいくつ存在するんだろう。haruki、気になります！」
そこで、haruki さんのために、n 以下の素数の中に偶数がいくつあるかを求めるプログラムを作成してください。

-----問題ここまで----- */
/* -----解説等-----

偶数の素数は2のみなので、2を含むか含まないかで場合分け

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	LL ans = 0;
	if (N == 1) {
		ans = 0;
	}
	else {
		ans = 1;
	}

	cout << ans << endl;

	return 0;
}