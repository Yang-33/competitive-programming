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

/* -----  2018/12/15  Problem: EDU056 B / Link: __CONTEST_URL__  ----- */
/* ------問題------

与えられた文字列を並び替えて、回文にならないようにできるか？

-----問題ここまで----- */
/* -----解説等-----

ソートしても前と後ろが一致するなら回文。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	FOR(_, 0, T) {
		string s; cin >> s;
		SORT(s);
		VI cnt(26, 0);
		FOR(i, 0, SZ(s)) {
			cnt[s[i] - 'a']++;
		}
		int f = 1;
		FOR(i, 0, SZ(s)/2) {
			int j = SZ(s) - i - 1;
			if (s[i] == s[j]) {

			}
			else {
				f = 0;
			}
		}
		if (f) {
			cout << -1 << endl;
		}
		else {
			cout << s << endl;
		}

	}

	return 0;
}
