#include<iostream>
#include<string>
#include<queue>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
const int INF = 1e9;
typedef long long ll;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

/* -----  2017/02/28  Problem: ABC019 C / Link: http://abc018.contest.atcoder.jp/tasks/abc018_3 ----- */
/* ------問題------

縦 R 行、横 C 列の長方形領域がある。上から i(1≦i≦R) 行目、左から j(1≦j≦C) 列目にあるマスをマス (i, j) と呼ぶことにする。
これらのマスのうちいくつかのマスは黒く、他のマスは白く塗られている。
また、ある整数 K が定められている。
ここで、以下の条件を満たすように新たに緑色を塗ることを考える。この操作は1 回だけ行う。
ある整数 の組 x(K≦x≦R?K+1), y(K≦y≦C?K+1) に対して、|i?x|+|j?y|≦K?1 を満たすすべてのマス (i,j) について、
マス (i,j) は元々白いマスで、かつ、この操作で緑色に塗られる。さらに、|i?x|+|j?y|≧K を満たすすべてのマスについて、そのマスは緑色に塗らない。
このような色の塗り方の総数はいくらか。ただし、ここでいう塗り方とは、どのマスがどの色になったかという組み合わせのことで、色の塗る順番は考慮しないものとする。

-----問題ここまで----- */
/* -----解説等-----

各マスのマンハッタン距離がＫ以上でないと塗れない。Ｏ(R*C)

 ----解説ここまで---- */

ll R, C, K;
string m[500];
ll d[500][500];
queue<pair<int, int>>Q;
ll ans = 0LL;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    FOR(i, 0, 500)FOR(j, 0, 500)d[i][j] = INF;

    cin >> R >> C >> K;
    FOR(i, 0, R) {
        cin >> m[i];
        FOR(j, 0, C) {
            if (m[i][j] == 'x') {
                d[i][j] = 0;
                Q.push(make_pair(i, j));
            }
        }
    }

    while (!Q.empty()) {
        auto q = Q.front();
        int x = q.second; int y = q.first;
        Q.pop();
        FOR(i, 0, 4) {
            int xx = x + dx[i]; int yy = y + dy[i];
            if (!(0 <= xx&&xx < C && 0 <= yy&&yy < R))continue;
            if (d[yy][xx] > d[y][x] + 1) {
                d[yy][xx] = d[y][x] + 1;
                Q.push(make_pair(yy, xx));
            }
        }
    }

    FOR(i, 0, R) {
        FOR(j, 0, C) {
            if (d[i][j] >= K)
                if (K - 1 <= j&&j <= C - K&&K - 1 <= i&&i <= R - K)ans++;
        }
    }

    cout << ans << endl;

    return 0;
}