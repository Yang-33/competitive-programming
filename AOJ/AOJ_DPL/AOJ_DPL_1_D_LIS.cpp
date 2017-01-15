#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;
ll N;

/* 2016/12/31 問題 -----  AOJ_DPL_1_D /Link http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=jp */
/* -----解説等-----
問題:最長増加部分列
数列 A=a0,a1,…,an−1 の最長増加部分列 (LIS: Longest Increasing Subsequence) の長さを求めてください。
数列 A の増加部分列は 0≤i0<i1<…<ik<n かつ　ai0<ai1<…<aik を満たす部分列 ai0,ai1,…,aik です。
最長増加部分列はその中で最も k　が大きいものです。


１．lower_boundで部分列の値をを更新していけばよい.
=>　О(Nlog N).

２．ある点までの増加列を更新していく.
dpっぽい解答になる（最適であるものを部分問題として解いていく)
=>　О(N^2) (だがおそい・・・)

*/
#define INF 1000000000+5 //最大値より大きい
#define MAX_N 100000

ll dp[MAX_N];
ll a[MAX_N];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> N;
    FOR(i, 0, N) {
        cin >> a[i];
    }
    fill(dp, dp + MAX_N, INF);
    FOR(i, 0, N) {
        *lower_bound(dp, dp + N, a[i]) = a[i];
    }// dp[N-1]までの中でa[i]以上の値の位置を返すので書き換え

    ll ans = (lower_bound(dp, dp + N, INF) -lower_bound(dp,dp+N,0));
    // dp[N-1]までのなかでINFよりも大きい場所から初期位置の差分をとれば
    //そこが長さに相当する
    cout << ans << endl;

    return 0;
}