#include<iostream>
#include<string>
using namespace std;

typedef long long ll;
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)

/* -----  2017/03/09  Problem:  / Link: http://arc055.contest.atcoder.jp/tasks/arc055_a ----- */
/* ------問題------

シカのAtCoDeerくんは数え上げ問題が大好きです。数え上げ問題のmodの値としてよく出てくるものに10N+7 の形のものがあります。
Nが与えられるので、整数10^N+7を計算してください。

-----問題ここまで----- */
/* -----解説等-----

桁数が非常に大きくなる可能性があり、単調なので文字列として10^N+7をつくる。

 ----解説ここまで---- */

ll N;
string S;
ll ans = 0LL;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    S = '1';
    FOR(i, 0, N - 1)S += '0';
    S += '7';
    cout << S << endl;
    
    return 0;
}