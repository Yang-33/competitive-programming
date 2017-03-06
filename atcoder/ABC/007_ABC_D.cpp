#include<iostream>
#include<string>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* -----  2017/03/06  Problem: ABC007 D / Link: http://abc007.contest.atcoder.jp/tasks/abc007_4 ----- */
/* ------問題------

たかはし王国の国王であるたかはし君主は数字の 4 と 9 が大嫌いです。
それらの数字を国内で目にするだけで気分が悪いので、それらを使ってはいけないという法律を定めました。
この法律を破ってしまうと罰せられます。数字が禁止されているので、ある数の10進表現を考えたとき、いずれかの桁に禁止された数字が1つでも含まれている場合、その数を使うことはできません。
今まで使っていた数字を使えなくなったあなたは、うっかり使ってしまって罰せられては困るので、
使う可能性がある数の区間 [A,B]={A,A+1,A+2,…,B} に、いくつ禁止された数が含まれているかを確かめることにしました。そのためのプログラムを作ってください。

-----問題ここまで----- */
/* -----解説等-----

桁ｄｐの条件に含まれるものを伝播させればよい。ABC029 の1の個数そのものではなく１を含む数を求めるイメージでよい。
used=1であるものは各桁以下の数字について4または9を含む個数となっている。
dp[ 上位何桁目か ][ ４または９が含まれているか ][ 現在の数字に対してN未満で確定か ] := 現在注目桁までの数字に4または9が含まれる数字が何回登場したか

ちょっとメモ化と桁dp理解してきた。

----解説ここまで---- */

ll a, b;
ll dp[20][2][2];
string s;
ll ans = 0LL;

/* 埋め込んだ */
ll rec2(int x, bool used, bool ok) {
    ll tmp = 0;

    if (dp[x][used][ok] != -1)return dp[x][used][ok];
    if (x == s.size())return dp[x][used][ok] = used;
    else {
        int upper = (ok ? 9 : s[x] - '0');
        for (int d = 0; d <= upper; d++) {
            tmp += rec(x + 1, used || (d == 4 || d == 9), ok || (d < upper));
        }
    }
    return dp[x][used][ok] = tmp;
}


ll rec(int x, bool used, bool ok) {
    ll tmp = 0;

    if (dp[x][used][ok] != -1)return dp[x][used][ok];
    if (x == s.size())return dp[x][used][ok] = used;
    else {
        if (ok == false) {
            for (int i = 0; i < s[x] - '0'; i++) {
                tmp += rec(x + 1, used || (i == 4 || i == 9), true);
            }
            tmp += rec(x + 1, used || ((s[x] - '0') == 4 || (s[x] - '0') == 9), false);
        }
        else {
            for (int i = 0; i <= 9; i++) {
                tmp += rec(x + 1, used || (i == 4 || i == 9), true);
            }
        }
    }
    return dp[x][used][ok] = tmp;
}

ll cal(ll num) {
    memset(dp, -1, sizeof(dp));
    s = to_string(num);
    return rec(0, false, false);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> a >> b;

    cout << cal(b) - cal(a - 1) << endl;

    return 0;
}

