#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/26 問題 ----- ABC040 C /Link http://abc040.contest.atcoder.jp/tasks/abc040_c */
/* -----解説等-----
問題: N 本の木の柱が左から右へ一列に並んだアスレチックがあります。左から i 本目の柱の高さは ai センチメートルです。
高橋君は左から 1 本目の柱からスタートし、右へ柱を渡っていき N 本目の柱まで行こうとしています。
高橋君がある柱にいるとき、次には現在の柱から 1 個もしくは 2 個右にある柱のどちらかへ移動することができます。
移動するときには、現在いる柱の高さと、移動後の柱の高さの差の絶対値のぶんだけコストがかかります。
N 本目の柱まで行くとき、コストの合計の最小値はいくらになるでしょうか。

状態遷移を考える。現状態に到達するためには1つ前あるいは2つ前の情報を持ってこればよい。
初期値はdp[0]=0,dp[1]=|a[0]-a[1]|

*/

int N;
int a[100000];
int dp[100000];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    FOR(i, 0, N) {
        cin >> a[i];
    }
    dp[1] = abs(a[1] - a[0]);
    FOR(i, 0, N - 2) {
        dp[i + 2] = min(dp[i] + abs(a[i] - a[i + 2]), dp[i + 1] + abs(a[i + 1] - a[i + 2]));
    }
    cout << dp[N - 1] << endl;

    return 0;
}