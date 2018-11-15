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

/* -----  2018/11/15  Problem: CodeForces520 A div2 / Link: http://codeforces.com/contest/1062/problem/A  ----- */
/* ------問題------

消しても復元可能な最大数

-----問題ここまで----- */
/* -----解説等-----

**区間総和ではない**
問題文に書いてないんだよね…

[上手な実装の仕方]
右と左に0,1001を置く(賢い)

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}

	// 連続区間を取り出す
	int cnt = 0;
	int res = 0;
	FOR(i, 0, N - 1) {
		if (a[i] + 1 == a[i + 1]) {
			cnt++;
		}
		else {
			ans += max(0, cnt - 1);
			res = max(res, cnt - 1);
			cnt = 0;
		}
		DD(de(cnt));
	}
	DD(de(cnt));
	res = max(res, cnt - 1);
	ans += max(0, cnt - 1);
	int f = 0;
	{
		if (N >= 2) {
			if (a[1] == 2)f = 1;
		}
		if (f) {
			cnt = 0;
			FOR(i, 0, N - 1) {
				if (a[i] + 1 == a[i + 1]) {
					cnt++;
				}
				else break;
			}
			res = max(res, cnt);
		}
	}
	int g = 0;
	{
		if (N >= 2) {
			if (a[N - 2] == 999)g = 1;
		}
		if (g) {
			cnt = 0;
			FORR(i, N - 2, 0-1) {
				if (a[i] + 1 == a[i + 1]) {
					cnt++;
				}
				else break;
			}
			res = max(res, cnt);
		}
	}
	ans += f + g;
	DD(de(f, g));
	ans = res;
	cout << ans << "\n";

	return 0;
}
