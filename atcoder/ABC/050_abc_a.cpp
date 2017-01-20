#include<iostream>
#include<string>
using namespace std;

typedef long long ll;

/* 2017/01/19 問題 -----  ABC050 A /Link http://abc050.contest.atcoder.jp/tasks/abc050_a */
/* -----解説等-----
問題: joisinoお姉ちゃんは、A op B という式の値を計算したいと思っています。 ここで、A,B は整数で、op は、+ または - の記号です。
あなたの仕事は、joisinoお姉ちゃんの代わりにこれを求めるプログラムを作ることです。

if文。

*/

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll a, b, ans;
    string s;
    cin >> a >> s >> b;
    if (s == "+")ans = a + b;
    else ans = a - b;
        cout << ans<< endl;

    return 0;
}