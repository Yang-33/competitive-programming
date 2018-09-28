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

/* -----  2018/09/28  Problem: yukicoder 292  / Link: http://yukicoder.me/problems/no/292  ----- */
/* ------問題------

お笑い芸人のA君は芸名Sを考えました。
最初にB師匠に意見をもらうと最初からt文字目(0-index)を1文字消せと言われました。
次にC師匠に意見をもらうと最初からu文字目(0-index)を1文字消せと言われました。
A君はB師匠とC師匠に言われた通りに文字を消すように決めました。
B師匠とC師匠の意見が同じであれば消す文字は1文字です。
B師匠とC師匠の意見が異なれば消す文字は2文字です。
S、t、uが与えられるのでB師匠とC師匠に意見をもらってできた名前を答えよ。

-----問題ここまで----- */
/* -----解説等-----

やっていく

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	string s; cin >> s;
	int a, b; cin >> a >> b;

	FOR(i, 0, SZ(s)) {
		if(i!=a&&i!=b)cout << s[i];
	}cout << endl;

	return 0;
}
