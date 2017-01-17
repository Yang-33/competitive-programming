#include<iostream>
#include<string>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define MOD 1000000007
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

/* 2017/01/17 問題 ----- TDPC_E /Link http://tdpc.contest.atcoder.jp/tasks/tdpc_number */
/* -----解説等-----
問題: N 以下の正整数であって、
十進法表記したときの各桁の数の和が D の倍数であるものの個数を mod 1,000,000,007 で求めよ。

1≦N≦10^10000
1≦D≦100

答えを一行で出力せよ。

64bit整数でも収まりきらない整数あり、明らかに桁ＤＰ。
桁dpには基本となる概念として、現在走査している値の桁における入力可能な値の範囲が制限されているか否か、
現在走査している先頭からの桁数0origin、その他を条件をＤＰの添え字としていくのが基本である。
条件が多くメモリがたくさん必要であれば、i-2文字目はi-1文字目には影響するがi文字目には影響しないことを考慮して
桁管理の配列は２つで足りる。（bit処理になる）

dp[ 決めた桁数 ][ mod D ][ Ｎ未満であることが確定しているか ] := 総数
と設定し、条件から０はこれに当てはまらないとして
dp[N.size][0][0] + dp[N.size][0][1] - 1 が答え。

for d と [k || (d < nowD)] がかなり便利かなあと思った。
ほかの桁fpの問題も解きたい

初期値はdp[0][0][0]=1
テストケースが弱すぎる？

*/

int dp[10010][100][2];
string N;
int D;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> D >> N;
    int Nsize = N.size();
    dp[0][0][0] = 1;

    int nowN;
    //桁、Ｄに対する余り、Ｎ未満確定か、桁の数字
    FOR(i, 0, Nsize)FOR(num, 0, D)FOR(k, 0, 2) {
        nowN = N[i] - '0';
        for (int d = 0; d <= (k ? 9 : nowN); d++) {
            dp[i + 1][(num + d) % D][k || (d < nowN)] = (dp[i + 1][(num + d) % D][k || (d < nowN)] + dp[i][num][k]) % MOD;
        }
    }

    int ans = dp[Nsize][0][0] + dp[Nsize][0][1] - 1;
    ans %= MOD;
    cout << ans << endl;

    return 0;
}