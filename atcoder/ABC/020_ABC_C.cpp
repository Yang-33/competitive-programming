#include<iostream>
#include<queue>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
const long long int INF = 1e12;
typedef long long ll;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

/* -----  2017/02/27  Problem: ABC020 C / Link: http://abc020.contest.atcoder.jp/tasks/abc020_c ----- */
/* ------問題------

正方形のマスが縦 H 行、横 W 列に並んでいます。
各マスは白または黒で塗られており、白マスのうち 2 つがそれぞれスタート地点とゴール地点として指定されています。
高橋君はスタート地点から出発して T 秒以内にゴール地点に到着したいです。
高橋君は、各マスから上下左右に隣接する別のマスに移動することができます。
このとき、移動先が白マスであれば 1 秒、黒マスであれば x 秒の時間がかかります（移動前のマスの色は移動時間に影響しません）。
ここで、 x の値は高橋君がスタート地点から出発する前にあなたに選んでもらいます。
x の値は正整数でなければならず、高橋君の出発後に値を変更することはできません。
高橋君が T 秒以内にゴール地点に到着することが可能であるような正整数 x の最大値を求めてください。

-----問題ここまで----- */
/* -----解説等-----

純粋な探索では計算量がＯ(HWT)となり答えを求められない。
境界を求めるので二分探索で解けそう。
ならＯＫ.半開区間[l,r)で探索するので答えはl
INFの値設定で1WA。気を付けたい

 ----解説ここまで---- */

ll H, W, T;
char m[10][10];
ll sx, sy, gx, gy;
ll ans = 0LL;

bool f(ll a) {
    ll d[10][10];
    
    FOR(i, 0, 10)
        FOR(j, 0, 10)
        d[i][j] = INF;

    d[sy][sx] = 0;

    queue<pair<int, int>>Q;
    Q.push(make_pair(sy, sx));
    while (!Q.empty()) {
        auto p = Q.front();
        int y = p.first; int x = p.second;
        Q.pop();
        FOR(i, 0, 4) {
            int yy = y + dy[i]; int xx = x + dx[i];
            if (!(0 <= xx&&xx < W && 0 <= yy&&yy < H))continue;

            if (m[yy][xx] == '#') {
                if (d[yy][xx] <= d[y][x] + a) continue;
                d[yy][xx] = d[y][x] + a;
            }
            else {
                if (d[yy][xx] <= d[y][x] + 1)continue;
                d[yy][xx] = d[y][x] + 1;
            }
            Q.push(make_pair(yy, xx));
        }
    }
    return d[gy][gx] <= T;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> H >> W >> T;
    FOR(i, 0, H)
        FOR(j, 0, W) {
        cin >> m[i][j];
        if (m[i][j] == 'S') {
            sx = j; sy = i;
        }
        else if (m[i][j] == 'G') {
            gx = j; gy = i;
        }
    }

    ll l = 1, r = 1e9 + 1;
    ll mid;
    while (r - l > 1) {
        mid = (l + r) / 2;
        if (f(mid))
            l = mid;
        else r = mid;
    }

    ans = l;
    cout << ans << endl;

    return 0;
}