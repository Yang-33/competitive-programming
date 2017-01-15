#include<iostream>
#include<algorithm>
#include<climits> //INT_MIN/MAX
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;
ll N;

/* 2016/12/31 問題 -----  AOJ_DPL_1_A / http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_A ----- */
/* -----解説等-----
問題:額面がc1, c2,..., cm　円の　m　種類のコインを使って、 n 円を支払うときの、
コインの最小の枚数を求めて下さい。各額面のコインは何度でも使用することができます。

枚数：無制限 / m種類 / N円支払う最小の枚数を求める

DAG経路を考えて、dp[x] => (+) => min(dp[x-value[i]]+1,dp[x]) 
グラフ問題に帰着できるので、
結局各ノードについて全走査する　=> Ｏ(NM) =10^6 < 10^8

dp[x] := x円払う際の最小枚数　
初期条件 : dp[0] = 0 <=　これにつないでいく
答え : dp[N] := N円払う際の最小枚数
*/

#define INF 10000000
#define MAX_M 20
#define MAX_N 50010
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll M;
    cin >> N >> M;
    ll cost[MAX_M];
    FOR(i, 0, M) {
        cin >> cost[i];
    }

    ll dp[MAX_N];
    FOR(i, 0, N + 1) {
        dp[i] = INF;
    }
    //初期条件
    dp[0] = 0;

    FOR(i, 0, M) {
        FOR(j, 0, N+1) {
            if (j - cost[i] >= 0) {
                dp[j] = min(dp[j], dp[j - cost[i]] + 1);
                //cost[i]=5 j=6 ではもとのｄｐが採用されるので当然考慮しない
            }
        }
    }

    cout << dp[N] << endl;

    return 0;
}