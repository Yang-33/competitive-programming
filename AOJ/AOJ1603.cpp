#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define debug(x) cout << #x << ": " << x << endl
#define ALL(x) (x).begin(),(x).end()

const int INF = 1e9;
const int LINF = 1e9;

int item[105];
int  dp[110][110][515];//item , 500, 1000num

/* -----  2017/10/02  Problem: ICPC国内2015 D / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1603  ----- */
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

----解説ここまで---- */


int main() {


	while (1) {
		int N;
		FOR(i, 0, 105)item[i] = 0;

		//		cin >> N;
		scanf("%d", &N);
		if (N == 0)break;

		FOR(i, 0, 105)FOR(j, 0, 105)FOR(k, 0, 510)dp[i][j][k] = LINF;
		FOR(i, 0, 105)dp[i][0][0] = 0;
		FOR(i, 0, N)scanf("%d", &item[i]);
		//cin >> item[i];
		FOR(i, 0, N) {
			int itm;
			if (item[i] % 1000 == 0)itm = item[i];
			else itm = item[i] + (1000 - item[i] % 1000);
			FOR(k, 0, 509) {
				FOR(j, 0, 104) {
					int oturi = 1000 * k - dp[i][j][k] - 500 * j;
					int nk = itm / 1000;
					if (itm - item[i] + oturi >= 500) {
						dp[i + 1][j + 1][k + nk] = min(dp[i + 1][j + 1][k + nk], dp[i][j][k] + item[i]);

					}
					else {
						dp[i + 1][j][k + nk] = min(dp[i + 1][j][k + nk], dp[i][j][k] + item[i]);
					}
					if (dp[i][j][k] == 0)continue;
					dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);

				}
			}
		}

		int shiharai = LINF;
		int mai;
		for (int j = 105; j >= 0; j--) {
			FOR(k, 0, 510) {
				if (dp[N][j][k] == 0)continue;
				if (shiharai > dp[N][j][k])
					shiharai = dp[N][j][k];
				mai = j;

			}
			if (shiharai != LINF)break;

		}
		if (mai == 0)shiharai = 0;
		printf("%d %d\n", mai, shiharai);
		//cout << mai << " " << shiharai << endl;

	}


	return 0;
}
