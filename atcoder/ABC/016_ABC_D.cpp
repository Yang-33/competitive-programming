#include<iostream>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* -----  2017/03/01  Problem: ABC016 D / Link: http://abc016.contest.atcoder.jp/tasks/abc016_4 ----- */
/* ------問題------

高橋くんは鍛錬の結果、空手チョップで木の板を切断できるようになりました。
空手チョップの軌道を表す線分と板の形を表す多角形が与えられるので、板がいくつに切断されたか求めてください。

-----問題ここまで----- */
/* -----解説等-----

交錯判定を行えばよい。
f(x,y)>=0を最初調べていたのだけど、判例(傾き∞)が出てきたのであきらめた。
幾何ライブラリ作ろうかなあ。

 ----解説ここまで---- */

ll N;
double ax, ay, bx, by;
double x[101], y[101];
bool p;
ll ans = 0LL;

/* 線分交錯判定 */
bool intersect(double p1x, double p1y, double p2x, double p2y, double p3x, double p3y, double p4x, double p4y) {
    if (((p1x - p2x) * (p3y - p1y) + (p1y - p2y) * (p1x - p3x)) *
        ((p1x - p2x) * (p4y - p1y) + (p1y - p2y) * (p1x - p4x)) < 0) {

        if (((p3x - p4x) * (p1y - p3y) + (p3y - p4y) * (p3x - p1x)) *
            ((p3x - p4x) * (p2y - p3y) + (p3y - p4y) * (p3x - p2x)) < 0) {
            return true;
        }

    }
    return false;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> ax >> ay >> bx >> by;
    cin >> N;
    bool flag;
    FOR(i, 0, N) {
        cin >> x[i] >> y[i];
    }

    FOR(i,0,N){
        int j = (i + 1) % N;
        if (intersect(x[i], y[i], x[j], y[j], ax, ay, bx, by)) ans++;
    }


    cout << ans / 2 + 1 << endl;

    return 0;
}