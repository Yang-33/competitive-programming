#include<iostream>
#include<string>
using namespace std;


/* 2017/01/20 ��� ----- ABC048 D /Link http://abc048.contest.atcoder.jp/tasks/arc064_b */
/* -----�����-----
���: ���� 3 �ȏ�̕����� s ������܂��B s �̒��ɓ���̕������ׂ荇���ӏ��͂���܂���B

�����N�Ɛ،N���Q�[���ŏ������܂��B ��l�͌��݂Ɏ��̑�����s���܂��B �����N�����ł��B

s ���痼�[�ȊO�̕������ЂƂ�菜���B �������A���̕�������菜�����ƂŁAs �̒��ɓ���̕������ׂ荇���ӏ����ł���ꍇ�A���̕�������菜�����Ƃ͂ł��Ȃ��B
��ɑ�����s���Ȃ��Ȃ����l�������ł��B ��l���œK�ɍs�������Ƃ��A�ǂ��炪�����𔻒肵�Ă��������B

����
3��|s|��105
s �͉p�������݂̂���Ȃ�B
s �̒��ɓ���̕������ׂ荇���ӏ��͂Ȃ��B

�P����Ԃ�ababab�̂悤�ȓ񕶎��̌J��Ԃ��ƂȂ����
abababcabababa�ł����aca�܂ō팸�\(11��)=>�Q�l�ڂ̕���
ababcabcabababa�ł����acaca�܂ō팸�\(10��)=>1�l�ڂ̕���
ababxyabab=>ab(8)=>1
ababxyaba=>aya(6)=>1

ababxabab=>ab(7)=>2
ababxaba=>axa(5)=>2
������̗��[���ꏏ �@=> {�����A�} => {2�����A1����}
������̗��[���قȂ� => {�����A�} => {1�����A2����}

����\�ł��邪�������������Ȃ�...�I


*/

string S; int slen;
int p;
string ans;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> S;
    slen = S.size();
    if (S[0] == S[slen - 1] && slen % 2 == 1 || S[0] != S[slen - 1] && slen % 2 == 0)p = 2;
    else p = 1;

    if (p == 1)ans = "First";
    else ans = "Second";
    cout << ans << endl;

    return 0;
}