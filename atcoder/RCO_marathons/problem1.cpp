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
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

/* -----  xtimex  Problem:  / Link:  ----- */
/* ------–â‘è------
1

-----–â‘è‚±‚±‚Ü‚Å----- */
/* -----‰ðà“™-----



 ----‰ðà‚±‚±‚Ü‚Å---- */

ll H, W, K;
string S[50];
int s[50][50];
ll ansCount = 0LL;
bool used[50][50];
queue<pair<int, pair<int, int>>>Q;
queue<pair<int, int>>ANSQ;

void bfs(int y, int x) {
    queue<pair<int, int>>q1;
    queue<pair<int, int>>q2;
    q1.push(make_pair(y, x));
   // used[y][x] = true;
    while (!q1.empty() && q2.size() < K) {
        //cout << "a"<< endl;
        pair<int, int> qq = q1.front(); int qy = qq.first; int qx = qq.second; q1.pop();
        if (used[qy][qx] != false)continue;
        used[qy][qx] = true;
        q2.push(make_pair(qy, qx));
        FOR(i, 0, 4) {
             //cout << "push? ‚«‚½" << endl;

            int yy = qy + dy[i];  int xx = qx + dx[i];
            if (0 <= yy&&yy < H && 0 <= xx&&xx < W)
                if (s[yy][xx] != 0 && used[yy][xx] == false) {
                    q1.push(make_pair(yy, xx));
                    //  cout << "‚«‚½"<< endl;
                }
        }
    }

    if (q2.size() >= K) {
         
        FOR(i, 0, K) {
            pair<int, int> qq = q2.front(); int qy = qq.first; int qx = qq.second; q2.pop();

            ANSQ.push(make_pair(qy, qx));
        }
        ansCount++;
    }
    else {
        return;
    }
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> H >> W >> K;
    //in

    FOR(i, 0, H) {
        cin >> S[i];
        //cin >> s[i][j];
        FOR(j, 0, W) {
            s[i][j] = S[i][j] - '0';
            if (s[i][j] == 0)used[i][j] = true;
            used[i][j] = false;
            //        if (s[i][j] > 4)Q.push(make_pair(s[i][j], make_pair(i, j)));
        }
    }


    FOR(i, 0, H)FOR(j, 0, W) {
        if (s[i][j] != 0 && used[i][j] == false) {
            //cout << "bfs" << endl;
            bfs(i, j);
        }
    }


    //out
    cout << ansCount << endl;
    // ansCount*8 times
    FOR(i, 0, ansCount * K) {
        pair<int, int> qq = ANSQ.front(); int qy = qq.first; int qx = qq.second; ANSQ.pop();
        cout << qy+1 <<" "<< qx+1 << endl;
    }
    return 0;
}