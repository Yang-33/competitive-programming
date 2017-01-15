#include<iostream>
#include<algorithm>
#include<climits> //INT_MIN/MAX
using namespace std;
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define MOD 1000000007
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;
ll N;

/* 2016/12/31 問題 -----  DPL_1_C_DP /Link http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_C&lang=jp ----- */
/* -----解説等-----
問題:価値が vi 重さが wi であるような N 種類の品物と、容量が W のナップザックがあります。

次の条件を満たすように、品物を選んでナップザックに入れます：

選んだ品物の価値の合計をできるだけ高くする。
選んだ品物の重さの総和は W を超えない。
同じ種類の品物はいくつでも選ぶことができる。
価値の合計の最大値を求めてください。

dp[i][j] := i個選択した際に重さがj以下での価値の最大値
初期値: dp[0][x]=0 :　０個選択化な時にどの重さに対しても価値は０



*/

#define MAX_N 100
#define MAX_W 10000
ll dp[MAX_N + 1][MAX_W + 1], v[MAX_N], w[MAX_N];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll W;
    cin >> N >> W;

    FOR(i, 0, N) {
        cin >> v[i] >> w[i];
    }

    /*次状態は繰り返し遷移することを考慮するとiに関する一回のループで
    複数個の選択が可能！
    */

    FOR(i, 0, N) {
        FOR(j, 0, W + 1) {
            if (j - w[i] >= 0) {
                dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
            }//↑生成した状態からも遷移する
            else {
                dp[i + 1][j] = dp[i][j];
            }
        }
    }

    cout << dp[N][W] << endl;

    return 0;
}