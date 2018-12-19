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

/* -----  2018/12/19  Problem: codefestival2014_team_relay C / Link: __CONTEST_URL__  ----- */
/* ------問題------

kawatea さんは空から降ってくる複数の amylase 伯爵さんを順番に一度ずつ、音楽に合わせて叩くゲームにはまっています。
このゲームにはコンボというシステムが存在し、amylase 伯爵さんを音楽に合わせて叩くことに成功するとコンボの数が 1 増え、叩くことに失敗してしまうとコンボの数が 0 に戻ってしまいます。
合計で n 個の amylase 伯爵さんを叩き終わったとき、最大のコンボの数が m となりました。
このときに考えられる最小の失敗の回数を求めるプログラムを作成してください。

-----問題ここまで----- */
/* -----解説等-----

適当な実数Kが存在して、(M+1)*K=N

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	LL ans = N / (M + 1);
	cout << ans << endl;

	return 0;
}