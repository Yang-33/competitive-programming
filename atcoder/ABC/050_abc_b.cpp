#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2010/00/00 ��� -----  ABC 050 B /Link http://abc050.contest.atcoder.jp/tasks/abc050_b */
/* -----�����-----
���:oisino���o�����́A����v���O���~���O�R���e�X�g�̌������T���Ă��܂��B
���̃R���e�X�g�ł́AN ��̖�肪�p�ӂ���Ă���A�����ɂ� 1~N �̔ԍ������Ă��܂��B
joisino���o�����́A��� i(1��i��N) �������̂ɂ����鎞�Ԃ� Ti �b�ł��邱�Ƃ�m���Ă��܂��B

�܂��A���̃R���e�X�g�ł́AM ��ނ̃h�����N���񋟂���Ă���A1~M �̔ԍ������Ă��܂��B
�����āA�h�����N i(1��i��M) �����ނƁA�]���h������A��� Pi �������̂ɂ����鎞�Ԃ� Xi �b�ɂȂ�܂��B
���̖��������̂ɂ����鎞�Ԃɕω��͂���܂���B

�R���e�X�^���g�́A�R���e�X�g�J�n�O�ɂ����ꂩ�̃h�����N�� 1 �{�������ނ��Ƃ��ł��܂��B
joisino���o�����́A���ꂼ��̃h�����N�ɂ��āA��������񂾍ۂɁA�S�Ă̖��������̂ɉ��b�K�v�Ȃ̂���m�肽���Ȃ�܂����B �S�Ă̖��������̂ɕK�v�Ȏ��ԂƂ́A���ꂼ��̖��������̂ɂ����鎞�Ԃ̍��v�ł��B ���Ȃ��̎d���́Ajoisino���o�����̑���ɂ�������߂�v���O�������쐬���邱�Ƃł��B

ans:
���̐��񂩂�Y�����������Ⴒ���Ⴕ�Ă��邪
���a���Ƃ��ăh�����N�̕����������Ƃ��Ē������邾���B

*/

int N;
int T[100000];
int M;
int P[100000], X[100000];
ll sum = 0, ans = 0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    FOR(i, 0, N) {
        cin >> T[i];
        sum += T[i];
    }

    cin >> M;
    FOR(i, 0, M) {
        cin >> P[i] >> X[i];
        ans = sum-T[P[i]-1]+X[i];
        cout << ans << endl;
    }

    return 0;
}