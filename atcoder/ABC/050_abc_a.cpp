#include<iostream>
#include<string>
using namespace std;

typedef long long ll;

/* 2017/01/19 ��� -----  ABC050 A /Link http://abc050.contest.atcoder.jp/tasks/abc050_a */
/* -----�����-----
���: joisino���o�����́AA op B �Ƃ������̒l���v�Z�������Ǝv���Ă��܂��B �����ŁAA,B �͐����ŁAop �́A+ �܂��� - �̋L���ł��B
���Ȃ��̎d���́Ajoisino���o�����̑���ɂ�������߂�v���O��������邱�Ƃł��B

if���B

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