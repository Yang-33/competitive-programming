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

/* -----  2018/12/06  Problem: ARC 009 A / Link: http://arc009.contest.atcoder.jp/tasks/arc009_a  ----- */
/* ------問題------

ある日高橋君はお母さんに近くのスーパーまでおつかいを頼まれました。
お母さんに手渡されたおつかいメモには、買ってきて欲しい商品の値段と個数がそれぞれ書かれています。
ただしメモに書かれている値段には消費税が含まれていませんが、全ての商品には消費税が 5% かかります。
高橋君のおつかいに必要な金額を答えなさい。
なお、消費税は 1 円未満は切り捨てます。

-----問題ここまで----- */
/* -----解説等-----

計算する。

----解説ここまで---- */



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	LL ans = 0;
	FOR(i, 0, N) {
		int a, b; cin >> a >> b;
		ans += a * b;
	}
	ans = (ans * 105) / 100;
	cout << ans << endl;

	return 0;
}
