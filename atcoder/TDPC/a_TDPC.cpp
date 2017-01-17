#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<climits> //INT_MIN/MAX
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
#define MOD 1000000007
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

/* 2010/00/00 問題 ----- TDPC_A /Link http://tdpc.contest.atcoder.jp/tasks/tdpc_contest */
/* -----解説等-----
問題: N 問の問題があるコンテストがあり、i 問目の問題の配点は pi 点である。
コンテスタントは、この問題の中から何問か解き、解いた問題の配点の合計が得点となる。
このコンテストの得点は何通り考えられるか。
1 ? N ? 100
1 ? p_i ? 100

状態遷移が明確なdp.typicalだ。
dp[ 得点 ] := 状態が存在するか
10000点までの可能性が存在し、それをtとしたとき、またP_iの商品があるとき
dp[ t ]  => ( + P_i ) => dp[ t + P_i ] となる状態遷移を考えればよい。:減少ループ
あるいは増加方向であれば得点は各一回しか使えないので二次元に拡張し
dp[ 使える得点の数 ][ 得点 ] := 状態が存在するか　として
dp[i+1][t] = dp[i][t-P_i] とすればよい
答えは dp[N][0=>10000]
どちらも計算量はＯ(N*(SUM_POINTS))≦10^6

*/

#define MAX_N 100
#define MAX_P 100
int N;
int p[MAX_N];
bool dp[MAX_N * MAX_P + 1];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    FOR(i, 0, N) {
        cin >> p[i];
    }
    FOR(i, 0, MAX_N * MAX_P + 1) {
        dp[i] = false;
    }


    dp[0] = 1;

    FOR(i, 0, N) {
        for (int t = MAX_N * MAX_P; t >= 0; t--) {
            if (dp[t] == 1 && t + p[i] <= MAX_N*MAX_P) {
                dp[t + p[i]] = 1;
            }
        }
    }

    int ans = 0;
    FOR(i, 0, MAX_N*MAX_P + 1) {
        ans += dp[i];
    }
    cout << ans << endl;

    return 0;
}