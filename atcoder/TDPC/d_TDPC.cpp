#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/18 問題 -----  TDPC_D /Linkhttp://tdpc.contest.atcoder.jp/tasks/tdpc_dice */
/* -----解説等-----
問題: サイコロを N 回振ったとき、出た目の積が D の倍数となる確率を求めよ。
1≦N≦100
1≦D≦10^18

Dの約数を考えたときに2,3,5のいずれかの組み合わせで表すことができないときはサイコロの出目ではこれを表すことはできない。
2^n1,3^n2,5^n3と現わすことができたとすると、
dp[ サイコロの個数 ][ ２の倍数の個数p1 ][ ３の倍数の個数p2 ][ ５の倍数の個数p3 ] := n個のサイコロで 2^p1,3^p2,5^p3 となる確率
と設定することで dp[N][n1≦2*N][n2≦N][n3≦N]を求めればよい。
状態数はN*2N*N*Nとなり全状態の推移で求められる。
dp[n][][][]に対してこれらを足し合わせたものは１
したがってやはりdp[N]での値を答えとして用いねばならない。

紙に状態遷移を書いたらよくわかった。
初期値は dp[0][0][0][0] = 1

atcoder上ではメモリ足りないらしいので配列の再利用をした。
*/

int N;
ll D, d;
double dp[2][202][101][101];
int c1 = 0, c2 = 0, c3 = 0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> d;
    D = d;

    for (;;) {
        while (D % 2 == 0) {
            D /= 2;
            c1++;
        }
        while (D % 3 == 0) {
            D /= 3;
            c2++;
        }
        while (D % 5 == 0) {
            D /= 5;
            c3++;
        }
        if (D == 1)break;
        else {
            cout << 0.000000 << endl;
            return 0;
        }
    }

    dp[0][0][0][0] = 1.0;

    int cur = 0, temp = 1;

    FOR(n, 0, N) {
        memset(dp[temp], 0, sizeof(dp[temp]));//いる
        FOR(i, 0, 2 * n + 1)FOR(j, 0, n + 1)FOR(k, 0, n + 1) {
            if (dp[cur][i][j][k] != 0) {
                dp[temp][i][j][k] += (dp[cur][i][j][k] / 6.0);
                dp[temp][i + 1][j][k] += (dp[cur][i][j][k] / 6.0);
                dp[temp][i][j + 1][k] += (dp[cur][i][j][k] / 6.0);
                dp[temp][i + 2][j][k] += (dp[cur][i][j][k] / 6.0);
                dp[temp][i][j][k+1] += (dp[cur][i][j][k] / 6.0);
                dp[temp][i + 1][j + 1][k] += (dp[cur][i][j][k] / 6.0);

            }
        }
        swap(cur, temp);

    }
    double ans = 0;
    FOR(i, c1, 202)FOR(j, c2, 101)FOR(k, c3, 101) {
        ans += dp[cur][i][j][k];
    }

    printf("%.12f\n", ans);

    return 0;
}