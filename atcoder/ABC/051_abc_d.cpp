#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/18 問題 ----- abc051 d /Link http://abc051.contest.atcoder.jp/tasks/abc051_d */
/* -----解説等-----
問題: 自己ループと二重辺を含まない N 頂点 M 辺の重み付き無向連結グラフが与えられます。
i(1≦i≦M) 番目の辺は頂点 ai と頂点 bi を距離 ci で結びます。 
ここで、自己ループは ai=bi(1≦i≦M) となる辺のことを表します。 
また、二重辺は (ai,bi)=(aj,bj) または (ai,bi)=(bj,aj)(1≦i<j≦M) となる辺のことを表します。 
連結グラフは、どの異なる 2 頂点間にも経路が存在するグラフのことを表します。 
どの異なる 2 頂点間の、どの最短経路にも含まれない辺の数を求めてください。


まずは、任意の点から任意の点までの最短経路を求める。
これは全点間の最短距離を求めることに相当し、ワーシャルフロイド法がこれに適している。
これによりある辺eが最短距離に使用されているかどうかの判定を行うことができるようになる。
変数j,kに対して s-> t へのコストをcとすれば
d[j][k] == d[j][s] + cost(s -> t) + d[t][k]
を満たすときにはこの辺は使用されていることがわかる。
これをすべての辺*始点終点に対してすべてチェックすることで使用されていない辺を発見することができる。
ダイクストラでも解ける。(pqはダメかなあと思う
)

*/

#define INF 10000000
int M; int N;
int d[110][110];
int s[1010];
int t[1010];
int c[1010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    FOR(i, 0, N) { //for Warshall
        FOR(j, 0, N) {
            if (i == j)d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    
   


    FOR(i, 0, M) {
        cin >> s[i] >> t[i] >> c[i];
        s[i]--; t[i]--;
        d[s[i]][t[i]] = c[i];
        d[t[i]][s[i]] = c[i];
    }

    FOR(k, 0, N) { 
        FOR(i, 0, N) {
            if (d[i][k] < INF)
                FOR(j, 0, N) {
                if (d[k][j] == INF)continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    //使用したかのチェック
    ll ans=0;
    FOR(i, 0, M) {// M辺についてcheck
        int yes = 1;
        FOR(j, 0, N) {
            FOR(k, 0, N) {
                if(j!=k)
                //最短経路であるか否か
                if (d[j][k] == d[j][s[i]] + c[i] + d[t[i]][k])yes = 0;
            }
        }
        ans += yes;
    }
    cout << ans << endl;

    return 0;
}