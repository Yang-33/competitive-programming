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
#define llong long long
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

/* 2017/01/16 問題 -----  AOJ_DPL_3_A /Link http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A&lang=jp */
/* -----解説等-----
問題: 巡回セールスマン問題
重み付き有向グラフ G(V,E) について、以下の条件を満たす最短経路の距離を求めて下さい：

ある頂点から出発し、出発点へ戻る閉路である。
各頂点をちょうど１度通る。

最短経路の距離を1行に出力する。条件を満たす経路がない場合は -1 と出力する。

-- traveling salesman problem -- TSP
NP困難であることは有名
Bit DP を学んだ。
全探索では Ｏ(N!) (N=10まで) 実際は (n-1)!
bit DP では Ｏ( 2^N * N^2 ) (N=16まで)

最小値比較であるから未使用の辺々はINFとしておく。
bit DPたる所以はdpの配列の添え字が状態そのもののbitであらわされており、
bit計算で状態移動や追加を行っているからであると考えられる。
dp[S][v] := 既に訪れたbit頂点集合 S ,現在の頂点vから残りの頂点全てを経由して最初の頂点０に帰るようなパスの重みの最小値
dp[V][0] = 0
dp[S][v] = min dp[S|u][u]+d(v,u) (S?u)

*/
#define MAX_V 15
#define INF 1000000
int V, E;
int d[MAX_V][MAX_V];
int dp[1<<MAX_V][MAX_V];

inline int rec(int S, int v) {
    if (dp[S][v] >= 0) {
        return dp[S][v];
    }

    //一巡してきた
    if (S == (1 << V) - 1 && v == 0) {
        return dp[S][v] = 0;
    }

    //uに移動する際の処理
    int res = INF;
    FOR(u, 0, V) {
        if (!((S >> u) & 1)) {
            res = min(res, rec(S | 1 << u, u) + d[v][u]);
        }
    }
    return dp[S][v] = res;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> V>>E;

    FOR(i, 0, MAX_V) {
        FOR(j, 0, MAX_V) {
            d[i][j] = INF;
        }
    }

    FOR(i, 0, E) {
        int s, t, c; cin >> s >> t >> c;
        d[s][t] = c;
    }

    memset(dp, -1, sizeof(dp));
    int ans = 0;

    ans = rec(0, 0);
    if (ans == INF)ans = -1;
    cout << ans << endl;

    return 0;
}