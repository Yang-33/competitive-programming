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

/* -----  2018/11/12  Problem: EDU054 A / Link: __CONTEST_URL__  ----- */
/* ------問題------

文字列から1文字抜いて辞書順最小になるものは？

-----問題ここまで----- */
/* -----解説等-----

s[i]>s[i+1]となるiを最初に抜くのが最適。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	string s; cin >> s;

	string t;
	int f = 0;
	s += string(1, 'a');
	s.back()--;
	FOR(i, 0, N) {
		if (!f&&s[i] > s[i + 1]) {
			f = 1;
		}
		else {
			t += string(1, s[i]);
		}
	}
	DD(de(t, SZ(t)));
	cout << t << endl;

	return 0;
}
