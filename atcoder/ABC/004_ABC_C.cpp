#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)

/* -----  2017/03/07  Problem:  / Link: http://abc004.contest.atcoder.jp/tasks/abc004_3 ----- */
/* ------問題------

ここにカードが 6 枚あり、それぞれ 1 から 6 までの整数が書かれています。
最初、左から右へ 1 のカードから 6 のカードまでがソートされた状態で並んでいます。
高橋君には整数 N が与えられます。高橋君は以下の操作を i=0,1,2, … ,N?1 に対して i=0 から 順番に行います。
左から (i mod 5)+1 番目にあるカードと、左から (i mod 5)+2 番目にあるカードの位置を入れ替える。
最終状態の盤面は。

-----問題ここまで----- */
/* -----解説等-----

３０回動かすと元に戻るという性質から３０の剰余だけかんがえればよい。

 ----解説ここまで---- */

ll N;
int num[7];
ll ans = 0LL;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    FOR(i, 0, 7)num[i] = i;

    cin >> N;
    int s = N % 30;
    FOR(i, 0, s) {
        int x = i % 5;
        swap(num[x + 1], num[x + 2]);
    }

    FOR(i, 1, 7)
        cout << num[i];
    cout << endl;

    return 0;
}