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

/* -----  2018/09/23  Problem: yukicoder 273  / Link: http://yukicoder.me/problems/no/273  ----- */
/* ------問題------

ある文字列Sが与えられる。
文字列Sを文字と文字の間で自由に切って2つ以上の回文に分解する。
必ず1箇所を間を切る
このときできる最も文字数の長い回文の文字列の長さを答えよ。

-----問題ここまで----- */
/* -----解説等-----

適当な列に分解した場合、
実際に部分文字列を作って回分かをチェックすれば良い。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;

	int ans = 1;
	FOR(i, 0, SZ(s) + 1)FOR(j, 0, i) {
		if (i - j < SZ(s)) {
			string ss = s.substr(j, i - j);
			string tt = ss;
			reverse(ALL(tt));
			if (ss == tt) {
				ans = max(ans, i - j);
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
