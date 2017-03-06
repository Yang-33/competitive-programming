#include<iostream>
#include<queue>
#include<string>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
const int INF = 1e9;
typedef long long ll;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

/* -----  2017/03/06  Problem: ABC007 C / Link: http://abc007.contest.atcoder.jp/tasks/abc007_3 ----- */
/* ------問題------

幅優先探索迷路

-----問題ここまで----- */
/* -----解説等-----

幅優先探索を使って迷路を探索する。
この前のマラソンでmake_pairをしこたま書いたのでそろそろライブラリにしたい。

 ----解説ここまで---- */

#define W_MAX 50
#define H_MAX 50
ll N, H, W;
int SY, SX, GY, GX;
string S[H_MAX];
int d[H_MAX][W_MAX];
ll ans = 0LL;

int bfs(int sy, int sx, int ty, int tx) {
    queue<pair<int, int>>Q;
    Q.push(make_pair(sy, sx));
    d[sy][sx] = 0;

    while (!Q.empty()) {
        pair<int, int> q = Q.front();
        int ny = q.first; int nx = q.second;
        Q.pop();
        FOR(i, 0, 4) {
            int yy = ny + dy[i]; int xx = nx + dx[i];
            if (0 <= yy&&yy < H && 0 <= xx&&xx<W)
                if(S[yy][xx]=='.')
                if (d[yy][xx] > d[ny][nx] + 1) {
                    d[yy][xx] = d[ny][nx] + 1;
                    Q.push(make_pair(yy, xx));
                }
        }

    }

    return d[ty][tx];
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> H >> W;
    cin >> SY >> SX >> GY >> GX;
    SY--; SX--; GY--; GX--;
    FOR(i, 0, H)cin >> S[i];

    FOR(i, 0, H)FOR(j, 0, W)d[i][j] = INF;

    ans = bfs(SY, SX, GY, GX);

    cout << ans << endl;

    return 0;
}