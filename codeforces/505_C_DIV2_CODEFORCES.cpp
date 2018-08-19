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

/* -----  2018/08/19  Problem: CodeForces505 C div2 / Link: http://codeforces.com/contest/1025/problem/C  ----- */
/* ------問題------

バイナリ列を一箇所で分断して左右を反転させてからくっつける、を繰り返す。
最長の01列は?

-----問題ここまで----- */
/* -----解説等-----

wbwb=4って書いてくれ
やるだけ

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	int N = SZ(s);
	s += s;
	int ans = 1;
	{
		int ret = 0;
		char bef = 0;
		char fir = 0;
		FOR(i, 0, SZ(s)) {
			if (bef == 0) {
				bef = s[i];
				fir = s[i];
				ret = 1;
			}
			else if (bef != s[i]) {
				ret++;
				bef = s[i];
			}
			else {
				bef = s[i];
				ans = max(ans, ret);
				ret = 1;
				fir = bef;
			}
		}
		ans = max(ans, ret);
	}
	ans = min(ans, N);
	cout << ans << "\n";

	return 0;
}
