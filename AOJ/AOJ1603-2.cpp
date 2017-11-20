#include "bits/stdc++.h"
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

/* -----  2017/11/20  Problem: AOJ 1603 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1603  ----- */
/* ------問題------

N店、そこでのお買い物ができる
支払いをうまくして500円玉をたくさんゲットしたい。
最大何枚ゲットできるか、およびその際の最小の支払金額を求めよ。

-----問題ここまで----- */
/* -----解説等-----

DP.最初は dp[ 現在訪れている店 ][ もっている500円玉の枚数 ][ 支払った回数 ] := ( 財布から出した総額 , おつり )
としていたが、これではDPできないので何が必要な情報かわからなかった。支払った回数は邪魔であることが分かっていて、
途中でおつりか支払った総額のどちらも大事であることに気が付いたので、
dp[ 現在訪れている店 ][ もっている500円玉の枚数 ][ 支払った1000円札の枚数 ] := 現時点で支払った総額
として解くことで状態の遷移ができるようになった。
500円玉をもらえない支払いの際には必ず1000円単位で払うのが最適であるから、商品の値段に応じて1000円で切り上げた。
これらの情報があれば、おつりは( 財布から出た1000円の額 - 支払った額 - 持っている500円玉の額 )となるので、
ほしい情報をすべて手に入れることができる。
解の選択から0枚のとき、払わないのがよいというのがコーナーだった(1WA)

もう一回解いても時間がかかった。

----解説ここまで---- */

LL N;

int dp[102][102][502];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	while (cin >> N, N) {
		fill(**dp, **dp + 102 * 102 * 502, INF);
		VI p(N, 0);
		FOR(i, 0, N) {
			cin >> p[i];
		}
		FOR(i, 0, 102)dp[i][0][0] = 0;
		// ishops, j 500 coins, k 1000coins
		FOR(i, 0, N) {
			int cost = ((p[i] + 999) / 1000) * 1000;
			FOR(k, 0, 502) {
				FOR(j, 0, 102) {
					int oturi = 1000 * k - dp[i][j][k] - 500 * j;
					int need1000 = cost / 1000;
					if (cost - p[i] + oturi >= 500) {
						dp[i + 1][j + 1][k + need1000] = min(dp[i + 1][j + 1][k + need1000], dp[i][j][k] + p[i]);
					}
					else {
						dp[i + 1][j][k + need1000] = min(dp[i + 1][j][k + need1000], dp[i][j][k] + p[i]);
					}
					if (dp[i][j][k] != 0) {
						dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
					}
				}
			}
		}
		int coin500;
		int cash = INF;
		FORR(j, 102, 0 - 1) {
			FOR(k, 0, 502) {
				if (dp[N][j][k] == 0)continue;
				if (cash > dp[N][j][k]) {
					cash = dp[N][j][k];
					coin500 = j;
				}
			}
			if (cash != INF)break;

		}

		if (coin500 == 0)cash = 0;
		cout << coin500 << " " << cash << "\n";
	}


	return 0;
}
