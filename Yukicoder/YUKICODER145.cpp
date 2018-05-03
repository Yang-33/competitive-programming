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

/* -----  2018/05/03  Problem: yukicoder 145  / Link: http://yukicoder.me/problems/no/145  ----- */
/* ------問題------

机の上に N 個のパネルが並んでいる。
各パネルには小文字のアルファベットが書かれている。

あなたはパネルを何列かに並べ替え、各列に対応する文字列を作る。
各列ごとに、文字列が辞書順で yuki より大きければ、あなたは幸福度を 1 ずつ得る。

さて、あなたが得られる幸福度の最大値はいくつか？

-----問題ここまで----- */
/* -----解説等-----

最初はy && up_uを優先度を高めにやっていたけど、これをすると後からもそすような操作がしたくなってしまう。
y,u,k,i,よりも小さい文字列は優先度が最も低く、yなどは万能なため、優先度の低い文字列から作成していけば良い。

for文にiを入れている場合じゃあないんだよね

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;  cin >> N;
	string S; cin >> S;
	int y, u, k, i, other;
	int up_u, up_k, up_i;
	y = u = k = i = other = up_u = up_k = up_i = 0;
	FOR(kim, 0, N) {
		if (S[kim] == 'z')ans++;
		else if (S[kim] == 'y')y++;
		else if (S[kim] > 'u')up_u++;
		else if (S[kim] == 'u')u++;
		else if (S[kim] > 'k')up_k++;
		else if (S[kim] == 'k')k++;
		else if (S[kim] > 'i')up_i++;
		else if (S[kim] == 'i')i++;
		else other++;
	}

	int update = 1;
	while (update)
	{
		if (y&&u&&k&&i&&other) {
			y--, u--, k--, i--, other--;
		}
		else if (y&&u&&k&&i > 1) {
			y--, u--, k--, i -= 2;
		}
		else if (y&&u&&k&&up_i) {
			y--, u--, k--, up_i--;
		}
		else if (y&&u&&k > 1) {
			y--, u--, k -= 2;
		}
		else if (y&&u&&up_k) {
			y--, u--, up_k--;
		}
		else if (y&&u > 1) {
			y--, u -= 2;
		}
		else if (y&&up_u) {
			y--, up_u--;
		}
		else if (y > 1) {
			y -= 2;
		}
		else {
			update = 0;
		}
		ans += update;
	}
	cout << ans << "\n";

	return 0;
}
