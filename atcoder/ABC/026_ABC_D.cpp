#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* -----  2017/02/25  Problem: ABC026 D / Link: http://abc026.contest.atcoder.jp/tasks/abc026_d ----- */
/* ------問題------

高橋君は野球が得意です。高橋君は、高橋君ボール 1 号という変化球を投げることが出来ます。
このボールは、投げてから t 秒後のボールの位置を f(t) とすると、
f(t)=A×t+B×sin(C×t×π) と表すことが出来ます。
あなたは、t≧0 かつ f(t)=100 となるタイミングで、ボールを打たなければいけません。
この時の t を求めたいです。

-----問題ここまで----- */
/* -----解説等-----

二分探索。
グラフを書くと連続で増加傾向にある関数であることがわかり、
中間値の定理から求めるtは必ず一つ以上存在する。
もし最小のtがほしいときには先に総当たりで範囲を決定し、その後二分探索をすればよい。

 ----解説ここまで---- */

int a, b, c;
ll ans = 0LL;
double pi = acos(-1.0);

bool f(double t) {
    return a*t + b*sin(c*pi*t) >= 100.0;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> a >> b >> c;

    double l = 0.0, r = 100000.0, mid;

    FOR (i, 0, 100000) {
        mid = (l + r) / 2.0;
        if (f(mid)) r = mid;
        else l = mid;
    }

    printf("%.12f¥n", l);

    return 0;
}