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

/* -----  2018/12/15  Problem: ARC 007 C / Link: http://arc007.contest.atcoder.jp/tasks/arc007_c  ----- */
/* ------問題------

高橋君は有料の衛星放送を見ようとしています。有料衛星放送はお金を払わないと見ることが出来ませんが、高橋君はその契約を行なっていません。
　しかし、有料衛星放送はどのような内容を放送しているか視聴者がわかるように、無料でも視聴可能な時間が定期的に存在し、視聴可能な時間とできない時間が交互に繰り返されます。このような視聴可能な時間とそうでない時間を視聴パターンと呼ぶことにします。
　視聴パターンは o と x から成り立っており、図 1 で示すように視聴可能な時間を o の個数、視聴できない時間を x の個数で表しています。

図 1:視聴パターンの例(入力は10文字以下なので、この入力はテストに存在しません)
　一度テレビを点けると途切れることなくこの視聴パターンが繰り返される。また、テレビは一度点けると消すことはできません。
　高橋君は複数のテレビを点けるタイミングをずらして並行して利用することで、無料でも常にいずれかのテレビで視聴ができる方法を思いつきました。
　例えば図 1 の視聴パターンの場合は図 2 で示すように 5 分後にもう 1 台テレビを点ければ常に視聴ができます。

図 2:2 台のテレビで常に視聴する例
　その場合高橋君が用意しなければいけない最低限のテレビの台数を答えなさい。
　なお、必要なテレビを全て点け終えるまでの間には視聴できない時間があっても構いませんが、全てのテレビを点けてからは常にいずれかのテレビで視聴ができないといけません。


-----問題ここまで----- */
/* -----解説等-----

2^N個列挙しても問題ない。Nの環で同値なものへと変換すれば良い。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	int N = SZ(s);
	VI b(N);
	FOR(i, 0, N) {
		b[i] = (s[i] == 'o');
	}
	int ans = INF;
	FOR(state, 0, 1 << N) {
		int sub = 0;
		VI check(N, 0);
		FOR(j, 0, N) {
			if (state & 1 << j) {
				sub++;
				FOR(k, 0, N) {
					if (!b[k]) continue;
					int nx = (j + k) % N;
					check[nx] = true;
				}
			}
		}
		bool f = 1;
		FOR(j, 0, N) {
			if (!check[j])f = false;
		}
		if (f) ans = min(ans, sub);
	}
	cout << ans << endl;

	return 0;
}