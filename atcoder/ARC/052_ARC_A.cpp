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

/* -----  2018/11/18  Problem: ARC 052 A / Link: http://arc052.contest.atcoder.jp/tasks/arc052_a  ----- */
/* ------問題------

高橋くんの通う学校では、創立された年に入学した生徒を 1 期生、その次の年に入学した生徒を 2 期生、といったように呼びます。
つまり、(入学した年−創立された年)+1=n の時に n 期生と呼ばれることとなります。
また、高橋くんの学校内では生徒がみな ID を持っており、それぞれの ID には必ず自分の期の数字が含まれることがわかっています。

ある生徒の ID が文字列 S として与えられるとき、その生徒が何期生であるかを回答してください。
また、数字が 2 つ連続して並んでいる場合は 2 桁の数字を意味するものとします。

-----問題ここまで----- */
/* -----解説等-----

番号は連続しているらしいので適当にできる。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	FOR(i, 0, SZ(s)) {
		if (isdigit(s[i])) {
			ans *= 10;
			ans += s[i] - '0';
		}
	}
	
	cout << ans << "\n";

	return 0;
}
