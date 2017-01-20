#include<iostream>

using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define MOD 1000000007
typedef long long ll;

/* 2017 01/19 ��� ----- ABC 050 C /Link http://abc050.contest.atcoder.jp/tasks/arc066_a */
/* -----�����-----
���: 1~N �܂ł̔ԍ��������AN �l�̐l�����܂��B
�ނ�͍���A���鏇�Ԃō��E���ɕ���ł��܂������A�����ɂȂ��Ă��̕��ѕ���������Ȃ��Ȃ��Ă��܂��܂����B
�������A�ނ�͑S���A�u�����̍��ɕ���ł����l���Ǝ����̉E�ɕ���ł����l���̍��̐�Βl�v���o���Ă��܂��B
�ނ�̕񍐂ɂ��ƁA�l i �́A�u�����̍��ɕ���ł����l���Ǝ����̉E�ɕ���ł����l���̍��̐�Βl�v�� Ai �ł��B

�ނ�̕񍐂����ɁA���̕��ѕ������ʂ肠�蓾�邩�����߂Ă��������B �������A�����͔��ɑ傫���Ȃ邱�Ƃ�����̂ŁA109+7 �Ŋ������]����o�͂��Ă��������B
�܂��A�ނ�̕񍐂��Ԉ���Ă���A���肤����ѕ����Ȃ����Ƃ����肦�܂��B ���̍ۂ� 0 ���o�͂��Ă��������B

����
1��N��10^5
0��A_i��N?1

���̕��я��Ƃ��Ă��肤����̂����ʂ肠�邩���߁A109+7 �Ŋ������]����o�͂���B

���m�ȏ��Ԃ𕜌������ہA��ʂ����Ȃ��u�����͈�ӂɒ�܂�B
�ȉ��̏����𖞂����˂΂Ȃ�Ȃ�
N:��̂Ƃ��@���̋����� N/2 ���(2��) + 0
N:�����̂Ƃ��@���̊�� N/2 ���(2��) +
�g�ݍ��킹��2^(2/N).
�ꍇ�����ƃ`�F�b�N���J��Ԃ��B

*/

int N;
ll ans = 1;
bool flag = true;
int cnt[100000 / 2];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    if (N % 2 == 0) {
        FOR(i, 0, N) {
            int a; cin >> a;

            if (a % 2 == 0 || a > N)flag = false;

            cnt[a / 2]++;
        }
        
        FOR(i, 0, N / 2) {
            if (cnt[i] != 2)flag = false;
        }
        FOR(i, 0, N / 2) {
            ans = (ans * 2) % MOD;
        }

    }
    else {
        int zero = 0;
        FOR(i, 0, N) {
            int a; cin >> a;

            if (a % 2 == 1 || a > N)flag = false;
            if (a != 0) {
                cnt[a / 2]++;
            }
            else zero++;
        }
        FOR(i, 1, N / 2+1) {
            if (cnt[i] != 2)flag = false;
        }
        if (zero != 1)flag = false;
        FOR(i, 0, N / 2) {
            ans = (ans * 2) % MOD;
        }

    }


    if (flag == false)ans = 0;
    cout << ans << endl;

    return 0;
}