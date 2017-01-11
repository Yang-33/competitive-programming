#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/11 問題 -----  Name DPL_3_A /Link http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_A ----- */
/* -----解説等-----
問題: 最大正方形
一辺が 1 cm のタイルが、H × W 個並べられています。タイルは汚れているもの、綺麗なもののいずれかです。

綺麗なタイルのみを使ってできる正方形の面積の最大値を求めてください。
１行目に２つの整数 H、W が空白区切りで与えられます。
続くH 行でタイルを表す H × W 個の整数 ci,j が与えられます。
ci,j が「1」のとき "汚れたタイル" 、「0」 のとき "綺麗なタイル" を表します。


左上から走査していき、dp[0][0] => dp[i][j] までの最大正方形を作成する
もし汚れたタイルの上であれば０、そうでなければ左、左上、上のうち最小値＋１の正方形が作成できることになる
左上を基点として拡張していくイメージ

*/

#define MAX_H 1400
#define MAX_W 1400

ll H, W;
ll dp[MAX_H + 1][MAX_W + 1];
ll m[MAX_H + 1][MAX_W + 1];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> H >> W;
    FOR(i, 1, H + 1) {
        FOR(j, 1, W + 1) {
            cin >> m[i][j]; /* 0 -> clean /  1 -> darty */
        }
    }

    FOR(i, 1, H + 1) {
        FOR(j, 1, W + 1) {
            if (m[i][j] == 1)dp[i][j] = 0; 
            else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    }

    ll ans = 0;
    FOR(i, 1, H + 1) {
        FOR(j, 1, W + 1) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans*ans << endl;

    return 0;
}
