#include<iostream>
#include<string>
#include<stack>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/21 ��� -----  ABC046 D /Link http://abc046.contest.atcoder.jp/tasks/arc062_b */
/* -----�����-----
���: �V�J��AtCoDeer����͗F�B��TopCoDeer����Ƃ���Q�[�������đΐ킵�Ă��܂��B
���̃Q�[���� N �^�[������Ȃ�܂��B�e�^�[���ł͂��ꂼ��̃v���C���[�͂���񂯂�̃O�[���p�[���o���܂��B
�������A�e�v���C���[�͎��̏����𖞂����K�v������܂��B

(��) �e�^�[���̌�ŁA(���܂łɃp�[���o������)��(���܂łɃO�[���o������)�@�𖞂���

���̃Q�[���ł̊e�v���C���[�̓��_�́A(�������^�[���̐�) ? (�������^�[���̐�) �ł��B 
AtCoDeer����͓���\�͂������Ă���̂ŁA�Q�[�����n�܂�O��TopCoDeer����̏o�� N �^�[���̎��S�Ēm�邱�Ƃ��o���܂����B 
AtCoDeer����̊e�^�[���ł̎�����߂āAAtCoDeer����̓��_���ő剻���Ă��������B
TopCoDeer����̏o����̏��͕����� s �ŗ^�����܂��B 
s �� i(1��i��N) �����ڂ� g�̂Ƃ��� i �^�[���ڂ�TopCoDeer���񂪃O�[���o�����Ƃ��A p�̂Ƃ��̓p�[���o�����Ƃ�\���܂��B

����
1��N��10^5
N=|s|
s �̊e������g��p
s �ŕ\������́A����(��)�𖞂����Ă���

AtCoDeer����̓��_�̍ő�l���o�͂���B


�������B���Ԃɏ��Ă�Ƃ��ɏ����A�����Ȃ��Ƃ����I�����ł���Ε����Ȃ��悤�ɂ���B
�����B

*/

string S;
stack<int> sta;
int ans = 0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> S;
    FOR(i, 0, S.size()) {
        if (!sta.empty()) {
            if (S[i] == 'g') {
                sta.pop();
                ans++;
            }
            else {
                sta.pop();
            }
        }
        else {
            if (S[i] == 'g') {
                sta.push(1);
            }
            else {
                sta.push(1);
                ans--;
            }
        }
    }

    cout << ans << endl;

    return 0;
}