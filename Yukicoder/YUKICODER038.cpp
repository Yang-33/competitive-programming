#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
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

/* -----  2018/04/10  Problem: yukicoder 038  / Link: http://yukicoder.me/problems/no/038  ----- */
/* ------問題------

赤と青と白のブロックが各１０個ずつある。
ブロックは左から右に一列に並べられている。
並べるときには次のような決まりがある。

赤いブロックよりちょうどKr個左に赤いブロックがあってはならない。
赤いブロックよりちょうどKr個右に赤いブロックがあってはならない。
青いブロックよりちょうどKb個左に青いブロックがあってはならない。
青いブロックよりちょうどKb個右に青いブロックがあってはならない。
白いブロックについては特に制限は無い。

最初にKr、Kbの数値とブロックの並びが与えられる。
赤のブロックをR、青のブロックをB、白のブロックをWとする。
最初の状態は上記に示した条件を満たしていないかもしれない。
よって、操作として次のような操作が許される。

・赤か青のブロックをいくつか抜いて列の間を詰める。

例えば、「RWBRWWB」であれば、
左端のRだけ抜いて「WBRWWB」という列を作ることができる。
左から4つめのRと右端のBを抜いて「RWBWW」という列も作れる。
RとBはいくつでも選んで抜くことができる。
ただし、Wのブロックを抜くことはできない。
このような操作を行うことで条件を満たす最長の列を残したい。
どのようにRとBのブロックを抜くかは自由である。
残すことが可能な最長の列の長さはどれだけか？

-----問題ここまで----- */
/* -----解説等-----

R,Bについて、これらそれぞれについて使うかどうかを2^20通り全部試せば良い。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int Kr, Kb; cin >> Kr >> Kb;
	string s; cin >> s;

	int ans = 0;
	FOR(r, 0, 1 << 10) {
		FOR(b, 0, 1 << 10) {

			string t;
			int rmask = 0, bmask = 0;
			int rc = 0, bc = 0;
			FOR(i, 0, 10) {
				if (r&(1 << i)) {
					rmask |= 1 << i;
				}
				if (b&(1 << i)) {
					bmask |= 1 << i;
				}
			}
			FOR(i, 0, SZ(s)) {
				if (s[i] == 'R') {
					if (rmask & (1 << rc))t += s[i];
					rc++;
				}
				else if (s[i] == 'B') {
					if (bmask & (1 << bc))t += s[i];
					bc++;
				}
				else {
					t += s[i];
				}
			}
			int ok = 1;
			FOR(i, 0, SZ(t)) {
				if (t[i] == 'R') {
					if (i - Kr >= 0 && t[i - Kr] == 'R')ok = 0;
					if (i + Kr < SZ(t) && t[i + Kr] == 'R')ok = 0;
				}
				else if (t[i] == 'B') {
					if (i - Kb >= 0 && t[i - Kb] == 'B')ok = 0;
					if (i + Kb < SZ(t) && t[i + Kb] == 'B')ok = 0;
				}
			}
			if (ok) {
				ans = max(ans, SZ(t));
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
