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
#define debug(x) cout<<#x<<": "<<x<<endl
const int INF = 1e9;
typedef long long ll;
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };

/* -----  xtimex  Problem:  / Link:  ----- */
/* ------ñ‚ëË------
2

-----ñ‚ëËÇ±Ç±Ç‹Ç≈----- */
/* -----âê‡ìô-----



----âê‡Ç±Ç±Ç‹Ç≈---- */
int sr, sc, N;
ll H, W, K;
string S[50];
int d[50][50];
ll ansCount = 0LL;
queue<pair<int, pair<int, int>>>Q;
queue<pair<int, int>>ANSQ;
int fr[3000], fc[3000], F[3000], D[3000];
pair<int,int> parent[50][50];
int STRnum = 0;


void scstring(int ny, int nx, int gy, int gx) {
    // g => s ÇÇÕÇÒÇƒÇÒÇ∑ÇÍÇŒÇÊÇ¢ÅB
    int X = gx;
    int Y = gy;
    stack<string> STR;

    while (1) {
        pair<int, int>P = parent[Y][X];
        int py = P.first; int px = P.second;
        if (py == Y) {
            if (X > px)STR.push("R");
            else STR.push("L");
        }
        else {
            if (Y > py)STR.push("D");
            else STR.push("U");
        }
        STRnum++;

        if (py == ny&&px == nx) {
            printf("break string\n");
            break;
        }
        Y = py; X = px;
    }
    cout << "out mode" << endl;

    FOR(i, 0, STR.size()) {
        cout << STR.top();
        STR.pop();
    }

}

void bfs(int ny, int nx, int gy, int gx, int turn) {

    FOR(i, 0, H)FOR(j, 0, W) {
        d[i][j] = INF;
    }
    FOR(i, 0, H)FOR(j, 0, W) {
        parent[i][j] = make_pair(-1, -1);
    }
    queue<pair<int, int>>q1; //((x,y),num)

    q1.push(make_pair(ny, nx));
    d[ny][nx] = 0;

    int nowY = ny; int nowX = nx;

    while (!q1.empty()) {
        
        pair<int, int> qq = q1.front(); 
        nowY = qq.first; nowX = qq.second;
        q1.pop();
        
        if (nowY == gy && nowX == gx) {
            cout << "find root" << endl;
            break;
        }

        FOR(i, 0, 4) {
            int yy = nowY + dy[i];  int xx = nowX + dx[i];
            if (0 <= yy&&yy < H && 0 <= xx&&xx < W) {
                if (S[yy][xx] == '#')continue;
                if (d[yy][xx] > d[nowY][nowX] + 1) {

                    d[yy][xx] = d[nowY][nowX] + 1;

                    parent[yy][xx] = make_pair(nowY, nowX);

                    q1.push(make_pair(yy, xx));
                      cout << "Ç´ÇΩ"<< endl;
                }
            }
        }
    }

    scstring( ny, nx, gy, gx);

}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> H >> W >> K >> sr >> sc;
    //in
    sr--; sc--;

    FOR(i, 0, H) {
        cin >> S[i];
        //cin >> s[i][j];
    }
    cin >> N;
    FOR(i, 1, N + 1) {
        cin >> fr[i] >> fc[i] >> F[i] >> D[i];
        fr[i]--; fc[i]--;
    }

    fr[0] = sr; fc[0] = sc;
    int t = 0;
    FOR(i, 0, N) {
        debug(i);
        cout << "fri " << fr[i] << "fci " << fc[i];
        cout << "fri " << fr[i + 1] << "fci " << fc[i + 1] << endl;
        bfs(fr[i], fc[i], fr[i + 1], fc[i + 1], 0);
    }

    //out
    // ansCount*8 times
    //Çjï∂éö

    FOR(i, 0, K - STRnum) {
        cout << "-";
    }
    cout << endl;

    return 0;
}