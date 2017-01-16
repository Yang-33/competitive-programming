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
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

/* 2010/00/00 問題 -----  AOJ_DPL_2_B /Link http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_B&lang=jp */
/* -----解説等-----
問題: 中国人郵便配達問題
重み付き無向グラフ G(V,E) について、以下の条件を満たす最短経路の距離を求めて下さい：

ある頂点から出発し、出発点へ戻る閉路である。
各辺を少なくとも１度は通る。
最短経路の距離を1行に出力する。

オイラー閉路であれば解は自明となるが、そうでない場合はオイラー閉路になるような辺を自分で加えればよい（オイラー補間）
辺の次数に着目し、これが偶数になるもののみであれば一筆書きの最簡なものを作ることができるので
奇数のものを候補として保持し、それらを全て用いた中で最も短い距離となるものを求めればよい。
ちなみに次数が奇数となる頂点は偶数個である。これは握手補題からも明らか

多重辺が存在することも考慮に入れるべき。（戒め）
*/

#define MAX_V 15
#define INF INT_MAX/10
int V, E;
int G[MAX_V][MAX_V];
int dp[1 << MAX_V];
int cnt[MAX_V];

vector<int>degodd;
ll W = 0;
ll plusnum=0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> V >> E;
    FOR(i, 0, V) { //for Warshall
        FOR(j, 0, V) {
            if (i == j)G[i][j] = 0;
            else G[i][j] = INF;
        }
    }

    FOR(i, 0, E) {
        int s, t, d, p; cin >> s >> t >> d;
        p = min(d, G[s][t]);
        G[s][t] = p;
        G[t][s] = p;
        W += d;
        cnt[s]++;//conut edge's deg
        cnt[t]++;
    }

    FOR(i, 0, V) {// check whether deg num is odd
        if (cnt[i] % 2 == 1)degodd.push_back(i);
    }

    FOR(k, 0, V) { //for Warshall
        FOR(i, 0, V) {
            if(G[i][k]<INF)
            FOR(j, 0, V) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    int CNT = degodd.size();

    //dp init
    FOR(i, 0, (1 << CNT)) {
        dp[i] = INF;
    }
    dp[0] = 0;


    // i : all states  j,k : combination
    FOR(i, 0, (1 << CNT)) {
        FOR(j, 0, CNT) {
            if (!(i&(1 << j))) {
                FOR(k, j + 1, CNT) {
                    if (!(i&(1 << k))) {
                        dp[i | (1 << j) | (1 << k)] = min(dp[i | (1 << j) | (1 << k)], dp[i]+G[degodd[j]][degodd[k]]);
                    }
                }
            }
        }
    }

    plusnum = dp[(1<<CNT)-1];
    
    //all edge + cost to make eular path 
    cout << W+plusnum<< endl;

    return 0;
}