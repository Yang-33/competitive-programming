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

/* -----  2018/09/28  Problem: yukicoder 291  / Link: http://yukicoder.me/problems/no/291  ----- */
/* ------問題------

黒いものが好きなので、文字列から部分列(Subsequence)の"KUROI"をたくさん作ることにした。
一度部分列として使った文字は、別の部分列の文字として使わないようにした。

張り切って何個作れるか数えようとすると、いくつかの文字が消えていることがわかった。
消えている箇所はできるだけ部分列"KUROI"の数が多くなるように文字を書いた。

最大で何個の部分列"KUROI"が作れるか求めよ。

※遅い言語だと通らないかもしれません

-----問題ここまで----- */
/* -----解説等-----

dp(i,k,ku,kur,kuro):=i番目の時点で、部分列としてk,ku,kur,kuroとなるものがパラメータ分だけあるときの、kuroiの最大値
としてdpする。オートマトンを考えれば良いかんじになる。
計算量はNに対して/5^4がかかる。なんとか間に合う的な。

----解説ここまで---- */

const int Mx = 22;
int dp[5 * Mx][Mx][Mx][Mx][Mx];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	fill(****dp, ****dp + 5 * Mx*Mx*Mx*Mx*Mx, -1);
	dp[0][0][0][0][0] = 0;
	auto assignMax = [](int &a, int b) {
		if (a < b)a = b;
	};
	int ans = 0;
	FOR(i, 0, SZ(s)) {
		FOR(k, 0, Mx-1)FOR(ku, 0, Mx-1)FOR(kur, 0, Mx-1)FOR(kuro, 0, Mx-1) {
			if (dp[i][k][ku][kur][kuro] == -1)continue;
			assignMax(dp[i + 1][k][ku][kur][kuro], dp[i][k][ku][kur][kuro]);

			if (s[i] == 'K' || s[i] == '?') {
				assignMax(dp[i + 1][k + 1][ku][kur][kuro], dp[i][k][ku][kur][kuro]);
			}
			if ((s[i] == 'U' || s[i] == '?') && k) {
				assignMax(dp[i + 1][k - 1][ku + 1][kur][kuro], dp[i][k][ku][kur][kuro]);
			}
			if ((s[i] == 'R' || s[i] == '?') && ku) {
				assignMax(dp[i + 1][k][ku - 1][kur + 1][kuro], dp[i][k][ku][kur][kuro]);
			}
			if ((s[i] == 'O' || s[i] == '?') && kur) {
				assignMax(dp[i + 1][k][ku][kur - 1][kuro + 1], dp[i][k][ku][kur][kuro]);
			}
			if ((s[i] == 'I' || s[i] == '?') && kuro) {
				assignMax(dp[i + 1][k][ku][kur][kuro - 1], dp[i][k][ku][kur][kuro] + 1);
				assignMax(ans, dp[i][k][ku][kur][kuro]+1);
			}
		}
	}
	cout << ans << "\n";

	return 0;
}
