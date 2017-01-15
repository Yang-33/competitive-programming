#include<iostream>
#include<algorithm>
#include<climits> //INT_MIN/MAX
using namespace std;
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;
ll N;

/* 2016/12/31 問題 -----  APJ_DPL_1_F /Link http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_F----- */
/* -----解説等-----
問題: 0-1 ナップザック問題 II
価値が vi 重さが wi であるような N 個の品物と、容量が W のナップザックがあります。次の条件を満たすように、品物を選んでナップザックに入れます：

選んだ品物の価値の合計をできるだけ高くする。
選んだ品物の重さの総和は W を超えない。
価値の合計の最大値を求めてください。

W <= 10^9
 => N*W はオーバー
ここで、いつものdp[N][W]ではN個の品物を任意に選択し重さW以下での価値の最大値を求めていたが
価値における重さの最小値を記録していく
　=> dp[N][V] := N番までの品物で価値が V になるときの重さ総和の最小値
 を定義し、その配列の中でＷ以下となる最大のvを求めればよい。

 初期条件: dp[0][0] : ゼロ個の品物を選択してその価値はゼロ
           dp[0][x] : ゼロ個選択して価値がx∈Vとなるのには重さが∞より重いものが必要（無理）{1<=x<=V}
*/


#define MAX_N 100
#define MAX_V 100
#define INF 100000000000 // 10^11
ll dp[MAX_N + 1][MAX_N*MAX_V + 1];
ll v[MAX_N], w[MAX_N];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll W;
    cin >> N >> W;
    
    FOR(i, 0, N) {
        cin >> v[i] >> w[i];
    }

    //init
    FOR(i, 0, MAX_V*MAX_N + 1) {
        dp[0][i] = INF;
    }//最小値がほしいのでINFに。
    dp[0][0] = 0;


    FOR(i, 0, N) {//品物
        FOR(j, 0, MAX_N*MAX_V + 1) {//価値
            if (j - v[i] >= 0) {
                //生成した状態が同じループで影響を与えないようにするので次元拡張=>次の状態にのみ影響させる
                dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
            }
            else {
                dp[i + 1][j] = dp[i][j]; //何もできないので前の状態を引き継ぐ
            }
        }
    }

    ll ans=0;
    FOR(j, 0, MAX_N*MAX_V + 1) {
        if (dp[N][j] <= W)
            ans = j; //大きぃのがほしぃの♡

    }

    cout << ans << endl;

    return 0;
}