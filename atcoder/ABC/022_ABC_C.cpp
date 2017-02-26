#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
const int INF = 1e9;
typedef long long ll;

/* -----  2017/02/27  Problem: ABC022 C / Link: http://abc022.contest.atcoder.jp/tasks/abc022_c ----- */
/* ------問題------
高橋君の住む街には N 個の家と M 個の道があります。 家は 1 〜 N の整数によって番号付けされています。
高橋君は家 1 に住んでいます。 道も 1 〜 M の整数によって番号付けされています。
i 番目の道は家 ui と 家 vi を双方向につなぐ長さ li メートルの道です。
高橋君は街のどこかの家に居るという「幸せの青い鳥」を探しています。
実は、「幸せの青い鳥」は高橋くんの家にいて、高橋君もそのことを知っています。 
しかし、形だけでも探す旅に出ないと盛り上がりに欠けて面白くないので、仕方なく旅の計画をたてることにしました。
高橋君は自分の家から開始して、同じ道を二度以上通らないようにいくつかの家に訪れ、最後に自分の家に戻ってくる、という旅の計画をたてる予定です。
このとき盛り上がりを作るために、旅の途中で自分の家以外の家を少なくとも 1 軒訪れる予定です。 
高橋君はこの茶番をできるだけ早く終わらせたいので、通る道の長さの総和が最も小さくなるような計画が最適だと考えています。
高橋君の住む街の家と道の情報が与えられるので、高橋君が上の条件のもとで最適な計画をたてることができるかどうかを求めてください。 
もし最適な計画をたてることができるならば、そのとき通る道の長さの総和を求めてください。


-----問題ここまで----- */
/* -----解説等-----

無向グラフで一筆書きの最短閉路を作りたい。
愚直な解法はないので、出発地点に隣接した辺を取り除いてみると最短経路を導出してから出発地点からの辺を二本選べばよいことになる。
従って 1->x,1->y x->y への最短距離がわかればよく、これの最小値を求めればよい。
選択にN^2かかるのでその際の ダイクストラでは計算量が N^3logN
ワーシャルフロイドでは一度で全点の最短距離がN^3でわかるので
N^3 + N^2 で厳しくても間に合う。
考察楽しい。ほんとにC問題か？

 ----解説ここまで---- */

ll N, M;
vector<pair<int, int>>x;
ll d[300][300];
ll ans = 0LL;

void warshall_floyd(ll n) {
    FOR(k, 0, n) {
        FOR(i, 0, n) {
            if (d[i][k] == INF)continue;
            FOR(j, 0, n) {
                if (d[k][j] == INF)continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    FOR(i, 0, N)FOR(j, 0, N) {
        if (i == j)d[i][j] = 0;
        else d[i][j] = INF;
    }

    FOR(i, 0, M) {
        ll u, v, l;
        cin >> u >> v >> l;
        u--; v--;
        if (u != 0) {
            d[u][v] = l;
            d[v][u] = l;
        }
        else {
            x.push_back(make_pair(v, l));
        }
    }
    warshall_floyd(N);
    ans = INF * 100;
    FOR(i, 0, x.size()) {
        for (int j = i + 1; j < x.size(); j++) {
            ans = min(ans, x[i].second + x[j].second + d[x[i].first][x[j].first]);
        }
    }
    if (ans > INF)ans = -1;
    cout << ans << endl;

    return 0;
}