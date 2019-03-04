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

/* -----  2019/02/28  Problem: ABC 110 C / Link: http://abc110.contest.atcoder.jp/tasks/abc110_c  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s, t; cin >> s >> t;
	VVI table(26, VI(26, 0));
	FOR(i, 0, SZ(s)) {
		int a = s[i] - 'a';
		int b = t[i] - 'a';
		table[a][b]=1;
	}

	int ok = 1;
	FOR(i, 0, 26) {
		int cnt = 0;
		FOR(k, 0, 26) {
			if (table[i][k])cnt++;
		}
		ok &= cnt < 2;
		cnt = 0;
		FOR(k, 0, 26) {
			if (table[k][i])cnt++;
		}
		ok &= cnt < 2;
	}




	cout << (ok ? "Yes" : "No") << "\n";

	return 0;
}
