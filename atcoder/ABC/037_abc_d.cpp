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
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
typedef long long ll;

/* 2017/01/29 問題 ----- ABC037 D /Link http://abc037.contest.atcoder.jp/tasks/abc037_d */
/* -----解説等-----
問題: H*W のマス目があり、それぞれのマスには整数が書かれています。
i 行 j 列に書かれている数は aij です。
あなたはこのグリッドの中の好きなマスから好きなだけ動きます(最初のマスから動かなくてもかまいません)。
今いるマスの上下左右に隣接しているマスのうち、今いるマスより大きな整数が書かれたマスに移動することができます。
ありうる移動経路の個数を10^9+7で割った余りを求めてください。

足しこんでいくタイプの状態遷移。
dp[y][x] :=  (x,y) で始まる移動経路
そろそろ経路探測用のdxdyをテンプレ化しよう。

*/

int H, W;
int num[1000][1000];
ll dp[1000][1000];
ll ans = 0;

ll dfs(int y, int x) {

    ll rec = dp[y][x];
    if (rec != -1)return rec;

    rec = 1;

    FOR(i, 0, 4) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (0 <= ny&&ny < H && 0 <= nx&&nx < W) {
            if (num[y][x] < num[ny][nx]) {
                rec = ((rec + dfs(ny, nx)) % MOD);
            }
        }
    }

    return  dp[y][x] = rec;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> H >> W;
    FOR(i, 0, H)
        FOR(j, 0, W)
        cin >> num[i][j];

    memset(dp, -1, sizeof(dp));
    FOR(i, 0, H)
        FOR(j, 0, W) {
        ans = ((ans + dfs(i, j)) % MOD);
    }

    cout << ans << endl;

    return 0;
}