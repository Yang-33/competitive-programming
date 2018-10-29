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

/* -----  2018/10/29  Problem: CodeForces519 C div2 / Link: http://codeforces.com/contest/1043/problem/C  ----- */
/* ------問題------

a,bのみの文字列が与えられ、前からprefixを反転できる。
最小の文字列を構成する反転をつくれ。

-----問題ここまで----- */
/* -----解説等-----

aaaabbbbみたいなのがつくれるとわかる。
aaaaabbbbb"X"としておけば、bならそのまま、aなら手前で反転してそこでも反転すれば良い。
頭が壊れて困った。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
		int n = SZ(s);
		VI a(n, 0);
		char pre = 0;
		int lastApos = -1;
		int lastBpos = -1;
		FOR(i, 0, n) {
			if (s[i] == 'a')lastApos = i;
			if (s[i] == 'b')lastBpos = i;
		}
		string t = s;
		if (lastApos != -1) {

			FOR(i, 0, lastApos) {
				if (t[i] == 'a'&&t[i + 1] == 'b') {
					a[i + 1] += 1;
					a[i] += 1;
					t[i + 1] = 'a';
				}
			}
			a[lastApos] = 1;
			if (lastApos != n - 1) {
				a[lastApos + 1] = 0;
			}
		}
		FOR(i, 0, n) {
			cout << a[i]%2 << " \n"[i == n - 1];
		}
		//string tt = s;
		//FOR(i, 0, n) {
		//	if (a[i] % 2) {
		//		reverse(tt.begin(), tt.begin() + i + 1);
		//	}
		//	cout << tt << endl;
		//}
		//cout << tt << endl;
	return 0;
}
