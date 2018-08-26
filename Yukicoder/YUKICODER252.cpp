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

/* -----  2018/08/26  Problem: yukicoder 252  / Link: http://yukicoder.me/problems/no/252  ----- */
/* ------問題------

文字列 S の先頭から検索していったとき、 good という部分文字列と problem という部分文字列が見つかる，かつ，最初に見つかる good の位置が，最初に見つかる problem の位置より前の場合は，文字列 S は良問であるという．
あなたは文字列 S の内の任意の場所の 1 文字を a ～ z のいずれかに書き換えるという操作を繰り返し行う．
文字列 S を良問にするまでに必要な操作の回数の最小値を出力せよ．
（なお，本当の良問を解いたことがあると，この問題は理解がしやすいかもしれません）

-----問題ここまで----- */
/* -----解説等-----

[gの手前までに存在するproblemの個数][ithをgoodにするための最小コスト][promlemにするための最小コスト]
という区間を考える。
i番目を動かす際にそれぞれのコストが求まっていれば線形時間で求めることができる。
先頭は累積和、中央はそのままのコスト、けつはminを後ろから先頭に伝搬しておけば解ける。

実装するだけでメンデイ。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	const string GOOD = "good"; const string PROBLEM = "problem";
	FOR(_, 0, T) {
		string s; cin >> s;
		VI c(SZ(s) + 10, 0);
		VI g(SZ(s) + 10, INF);
		VI p(SZ(s) + 10, INF);
		int N = SZ(s);

		// prefix problem(erase)
		FOR(i, 0, N) {
			if (s.substr(i, SZ(PROBLEM)) == PROBLEM) {
				c[i + SZ(PROBLEM)] = 1;
			}
		}
		FOR(i, 0, N) {
			c[i + 1] += c[i];
		}
		// good(edit)
		FOR(i, 0, N-10) {
			int edit = 0;
			FOR(k, 0, 4) {
				if (s[i + k] != GOOD[k])edit++;
			}
			g[i] = edit;
		}
		// problem(edit) & min
		FOR(i, 0, N - 6) {
			int edit = 0;
			FOR(k, 0, 7) {
				if (s[i + k] != PROBLEM[k])edit++;
			}
			p[i] = edit;
		}
		// <- min
		FORR(i, N - 2, 0-1) {
			p[i] = min(p[i], p[i + 1]);
		}
		

		int ans = INF;
		FOR(i, 0, N-10) {
			ans = min(ans, c[i] + g[i] + p[i + 4]);
		}
		cout << ans << "\n";
	}

	return 0;
}
