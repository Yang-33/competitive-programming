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
const int INF = 1e9;
typedef long long ll;
int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
int dy[8] = { 1,0,-1,1,-1,1,0,-1 };

/* -----  2017/03/05  Problem: ABC008 D / Link: http://abc008.contest.atcoder.jp/tasks/abc008_4 ----- */
/* ------問題------

盤面のうち (x,y),1≦x≦W, 1≦y≦H(x,y),1≦x≦W, 1≦y≦H の各セルには金塊が置いてある．
金塊回収装置が (xi,yi)に置いてある。そこで回収をはじめると端点あるいは金塊のない場所まで上下左右に回収をする。
H,W≦10^6,N≦30
金塊回収装置を起動する際その上の金塊は回収できるものとして最大でいくつ回収できるか。

-----問題ここまで----- */
/* -----解説等-----

一回回収すると盤面が４分割される。状態遷移であるが良いものを区間を指定して探索していけばよい。
端から折り返す。

 ----解説ここまで---- */

ll N, W, H;
int x[40], y[40];
int dp[40][40][40][40];
ll ans = 0LL;

int rec(int xl, int xr, int yl, int yr) {
    if (dp[xl][xr][yl][yr] != -1)return dp[xl][xr][yl][yr];

    int res = 0; int s = 0;

    FOR(i, 0, N) {
        if (x[xl] < x[i] && x[i] < x[xr] && y[yl] < y[i] && y[i] < y[yr]) {
            s = x[xr] - x[xl] + y[yr] - y[yl] - 4 + 1;
            s += rec(xl, i, yl, i);
            s += rec(xl, i, i, yr);
            s += rec(i, xr, yl, i);
            s += rec(i, xr, i, yr);
            res = max(res, s);
        }
    }

    return dp[xl][xr][yl][yr] = res;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> W >> H;
    cin >> N;

    FOR(i, 0, N) {
        cin >> x[i] >> y[i];
    }

    memset(dp, -1, sizeof(dp));

    x[N] = 0; x[N + 1] = W + 1;
    y[N] = 0; y[N + 1] = H + 1;

    cout << rec(N, N + 1, N, N + 1) << endl;

    return 0;
}