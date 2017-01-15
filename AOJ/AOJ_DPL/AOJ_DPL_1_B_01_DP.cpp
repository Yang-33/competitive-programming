#include<iostream>
#include<algorithm>
#include<climits> //INT_MIN/MAX
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;
ll N;

/* 2016/12/31 問題 ----- AOJ_DPL_1_B /Link http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B&lang=jp ----- */
/* -----解説等-----
問題:0-1 ナップザック問題
価値が vi 重さが wi であるような N 個の品物と、容量が W のナップザックがあります。
次の条件を満たすように、品物を選んでナップザックに入れます

選んだ品物の価値の合計をできるだけ高くする。
選んだ品物の重さの総和は W を超えない。
価値の合計の最大値を求めてください。

求めたい重さのオーダーが低いので Ｏ( N * W )でとける
2^n => N*W
dp[N][W] := Ｎ個までの品物を選択し、重さがＷ以下のときの最大の価値

添え字に注意（笑）

典型メモ化再帰でも解ける
example:
ll func(ll i, ll j){
if exist memo(i,j) => return memo(i,j)
ll res
if i == n res = 0
else if j-w[i]>=0 then  res = func(i+1,j)
else               res =max(func(i+1,j),func(i+1,j-w[i])+v[i])

return memo(i,j) = res
}
*/

#define MAX_N 101//拡張したので注意（下に書いた）
#define MAX_W 10000

ll dp[MAX_N + 1][MAX_W + 1];// ０で初期化されている

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll W;
    cin >> N >> W;
    ll v[MAX_N + 1], w[MAX_N + 1];

    FOR(i, 1, N + 1) {
        cin >> v[i] >> w[i];
    }

    /* 各品は１度しか使えない点に注意！！！
    =>  次状態に影響しないように次元を拡張すればよい！*/
    FOR(i, 1, N + 1) {
        FOR(j, 0, W + 1) {
            if (j - w[i] >= 0)
                dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
            else dp[i + 1][j] = dp[i][j];
        }
    }
    /* 添え字をずらしたので注意（拡張したのを忘れていた） */
    cout << dp[N + 1][W] << endl;

    return 0;
}