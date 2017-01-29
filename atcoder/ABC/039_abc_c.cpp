#include<iostream>
#include<string>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/27 問題 ----- ABC039 C /Link http://abc039.contest.atcoder.jp/tasks/abc039_c */
/* -----解説等-----
問題:　高橋君は青木君に突然魔法で小さくされ、ピアノの上に乗せられてしまいました。
高橋君は、今ピアノのある鍵盤の上に立っていますが、どの鍵盤の上にいるのかを知りたいです。
高橋君は、自分の今いる鍵盤から右 20 個の鍵盤の色を調べました。高橋君のいる鍵盤の音階を調べてください。
調べた鍵盤の色は、W、B からなる文字列 S として与えられ、W は白色、B は黒色を表します。
そして、高橋くんのいる鍵盤の色は文字列の先頭に対応します。
なお、ピアノの鍵盤は下図のように、色は"白黒白黒白白黒白黒白黒白"、
音階は "ド ド# レ レ# ミ ファ ファ# ソ ソ# ラ ラ# シ" を繰り返しています。

WBWBWWBWBWBWWBWBWWBW do
WWBWBWWBWBWBWWBWBWWB si
WBWWBWBWWBWBWBWWBWBW ra
WBWBWWBWBWWBWBWBWWBW so
WBWBWBWWBWBWWBWBWBWW fa
WWBWBWBWWBWBWWBWBWBW mi
WBWWBWBWBWWBWBWWBWBW re

らしい。WBWBWWBWBWBWが1セットであるからこれを発見しようと思ったがそれが含まれないところもあるので
部分極大のWBWBWBWに着目する。これを発見し先頭付近の要素までWを数え上げ、適切な位置を返せばよい。

*/

string S;
string ans[7] = { "Do","Re","Mi","Fa","So","La","Si" };
int X = 0, cnt = 3;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> S;
    X = S.find("WBWBWBW");
    FOR(i, 0, X) {
        if (S[i] == 'W')cnt--;
    }

    cout << ans[(7+cnt)%7] << endl;

    return 0;
}