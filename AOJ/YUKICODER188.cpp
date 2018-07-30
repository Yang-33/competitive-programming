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
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/07/30  Problem: yukicoder 188  / Link: http://yukicoder.me/problems/no/188  ----- */
/* ------問題------

今日は4月22日であり、kamipeipaa君の誕生日です。kamipeipaa君はこの日が4=2+2と表せることに気づきました。
kamipeipaa君はX月Y日についてYの数字和がXと等しいとき、この日を"HAPPY DAY"であると呼ぶことにしました。ここで数字和とは与えられた整数の各桁の数字が表す数の総和です。
例えば、4月4日や10月19日は4=0+4、10=1+9となり、HAPPY DAYですが、12月3日や11月28日は12≠0+3、11≠2+8となりHAPPY DAYではありません。
グレゴリオ暦の2015年においてHAPPY DAYがどれだけあるかkamipeipaa君に教えてあげてください。

ヒント:グレゴリオ暦とは通常のカレンダーのことである。2015年のカレンダーを参照しても良い。
365日それぞれの日が成り立つか確認してカウントしても十分速い。

-----問題ここまで----- */
/* -----解説等-----

実際に調べる。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	VI days({ 31,28,31,30,31,30,31,31,30,31,30,31 });
	int ans = 0;
	FOR(month, 0, 12) {
		FOR(day, 0, days[month]) {
			auto digit = [](int x) {
				int ret = 0;
				while (x) {
					ret += x % 10;
					x /= 10;
				}
				return ret;
			};

			ans += (month + 1 == digit(day + 1));
		}
	}
	cout << ans << "\n";

	return 0;
}
