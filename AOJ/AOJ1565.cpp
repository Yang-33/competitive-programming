#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/02/05  Problem: AOJ 1565 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1565  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

塗る動作は3辺をはるみたいな感じでダイクストラ

----解説ここまで---- */
 
bool is_in(int y, int x, int H, int W){
    return (0 <= x && x < W && 0 <= y && y < H);
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
    int H, W;
    int sx, sy, gx, gy;
     
    cin >> H >> W;
    vector<string> a(H);
    FOR(i,0,H){
        cin>>a[i];
        FOR(j,0,W){
            if(a[i][j] == 'S'){
                sy = i;sx= j;
                a[i][j] = '.';
            }else if (a[i][j] == 'G') {
                gx = j; gy = i;
                a[i][j] = '.';
            }
        }
    }
    typedef pair<int,PII> TP;
    priority_queue<TP,vector<TP>,greater<TP>> pq;
    pq.push(TP(0,PII(sx,sy)));
    VVI d(H, VI(W, INF));
    d[sy][sx] = 0;
     
    while (!pq.empty()) {
        TP s = pq.top(); pq.pop();
        int x = s.second.first, y = s.second.second;
                
        if (d[y][x] < s.first) { continue; }
         
        if (x == gx && y == gy) { break; }
 
        FOR(i,0,4){
            int nx, ny, ncost;
            FOR(j,1,4){
                nx = x + DX[i] * j, ny = y + DY[i] * j;
                 
                if (!is_in(ny, nx, H, W) || a[ny][nx] == '#') {
                    break;
                }
                 
                ncost = d[y][x] + j + 2;
                if (ncost < d[ny][nx]) {
                    d[ny][nx] = ncost;
                    pq.push(TP(d[ny][nx],PII(nx,ny)));
                }
            }
             
            nx = x + DX[i], ny = y + DY[i];
            if (!is_in(ny, nx, H, W) || a[ny][nx] == '#' ||
                a[ny][nx] == 'x') {
                continue;
            }
             
            ncost = d[y][x] + (a[ny][nx] == 'o' ? 1 : 2);
            if (ncost < d[ny][nx]) {
                d[ny][nx] = ncost;
                pq.push(TP(d[ny][nx],PII(nx,ny)));
            }
        }
    }
     
    cout << d[gy][gx] << endl;
     
    return 0;
}
