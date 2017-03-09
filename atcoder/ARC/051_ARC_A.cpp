#include<iostream>
using namespace std;

typedef long long ll;

/* -----  2017/03/09  Problem: ARC051 A / Link: http://arc051.contest.atcoder.jp/tasks/arc051_a ----- */
/* ------問題------

白く塗られた二次元平面を考えます。
まず、(x1,y1) からの距離が r 以下の部分を赤く塗ります。
そのあと、 x2≦x≦x3,y2≦y≦y3 を満たす (x,y) を青く塗ります。
なお、赤く塗られた後、更に青く塗られた部分は紫色になるとします。
赤く塗られた部分と青く塗られた部分が存在するかどうかをそれぞれ判定してください。

-----問題ここまで----- */
/* -----解説等-----

片方の図形が片方の図形に対して内包されていなければその色は存在する。従ってそれを判定すればよい。
円が内包されるときは上下左右端が四角形の頂点領域よりも内側、四角形が内包されるときは円の領域判定をすればよい。

 ----解説ここまで---- */


ll ans = 0LL;

int dist(int x, int y) {
    return x*x + y*y;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int x1, y1, r, x2, x3, y2, y3;

    cin >> x1 >> y1 >> r >> x2 >> y2 >> x3 >> y3;
    if (x2 <= x1 - r && x1 + r <= x3 && y2 <= y1 - r && y1 + r <= y3 )cout << "NO" << endl;
    else cout << "YES" << endl;

    if (dist(x2 - x1, y2 - y1) - r*r <= 0 && dist(x2 - x1, y3 - y1) - r*r <= 0 && dist(x3 - x1, y2 - y1) - r*r <= 0 && dist(x3 - x1, y3 - y1) - r*r <= 0)cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}