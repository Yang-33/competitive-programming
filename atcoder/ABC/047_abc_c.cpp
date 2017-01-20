#include<iostream>
#include<string>
#include<stack>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/20 ��� -----  ABC047 C /Link http://abc047.contest.atcoder.jp/tasks/arc063_a */
/* -----�����-----
���: ���˂̎��Y�ƎO�Y���ꎟ�����o�[�V�ŗV��ł��܂��B
�ꎟ�����o�[�V�ł́A�Ֆʂɂ͔������̐΂����ɕ��񂾏�ԂƂȂ��Ă���A��̉E�[�����[�ɐV���ɐ΂�ł��Ă����܂��B
�ʏ�̃��o�[�V�Ɠ����悤�ɁA���Ƃ��Δ��̐΂�ł��Ƃō��̐΂����ނƁA���܂ꂽ���̐΂͔����΂ɕς��܂��B

�Q�[���̓r���ŎO�Y�ɋ}�p���ł��ċA���Ă��܂����ƂɂȂ�܂����B
���̂Ƃ��A�Ֆʂ̏�Ԃ͕����� S �ŕ\����܂��B�΂� |S| (������̒���) ����ł���A
������ i (1��i��|S|) �ڂ̐΂̐F�́AS �� i �����ڂ� B �̂Ƃ����AW �̂Ƃ����ł��B

���Y�͌��݂̔Ֆʂɑ΂��āA�ł��邾�����Ȃ����̐΂�V���ɑł��ƂőS�Ă̐΂𓯂��F�ɂ��悤�ƍl���܂����B
�ŏ��ŉ��̐΂�łĂ΂悢�������߂Ă��������B


���E�ǂ��炩��u���Ɋւ�炸�A�X�V�񐔂͕Е�����A������I�Z���̐F������
�����������񐔂ł���B
WWWWWW => 0
WWWBBB => 1
BWBWWW => 3
�X�^�b�N�ɐς񂾂画�肪�y�ɂȂ������A���O�̐F�����ł���������ۑ��ł���Ή��ł��悢�B


*/

string S;
stack<int>sta;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> S;
    sta.push(S[0]);
    FOR(i, 0, S.size()) {
        if (sta.top() != S[i]) {
            sta.push(S[i]);
        }
    }

    cout << sta.size()-1 << endl;

    return 0;
}