#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/26 ��� ----- ABC040 C /Link http://abc040.contest.atcoder.jp/tasks/abc040_c */
/* -----�����-----
���: N �{�̖؂̒���������E�ֈ��ɕ��񂾃A�X���`�b�N������܂��B������ i �{�ڂ̒��̍����� ai �Z���`���[�g���ł��B
�����N�͍����� 1 �{�ڂ̒�����X�^�[�g���A�E�֒���n���Ă��� N �{�ڂ̒��܂ōs�����Ƃ��Ă��܂��B
�����N�����钌�ɂ���Ƃ��A���ɂ͌��݂̒����� 1 �������� 2 �E�ɂ��钌�̂ǂ��炩�ֈړ����邱�Ƃ��ł��܂��B
�ړ�����Ƃ��ɂ́A���݂��钌�̍����ƁA�ړ���̒��̍����̍��̐�Βl�̂Ԃ񂾂��R�X�g��������܂��B
N �{�ڂ̒��܂ōs���Ƃ��A�R�X�g�̍��v�̍ŏ��l�͂�����ɂȂ�ł��傤���B

��ԑJ�ڂ��l����B����Ԃɓ��B���邽�߂ɂ�1�O���邢��2�O�̏��������Ă���΂悢�B
�����l��dp[0]=0,dp[1]=|a[0]-a[1]|

*/

int N;
int a[100000];
int dp[100000];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    FOR(i, 0, N) {
        cin >> a[i];
    }
    dp[1] = abs(a[1] - a[0]);
    FOR(i, 0, N - 2) {
        dp[i + 2] = min(dp[i] + abs(a[i] - a[i + 2]), dp[i + 1] + abs(a[i + 1] - a[i + 2]));
    }
    cout << dp[N - 1] << endl;

    return 0;
}