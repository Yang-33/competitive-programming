#include<iostream>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/26 ��� ----- ABC041 D /Link http://abc041.contest.atcoder.jp/tasks/abc041_d */
/* -----�����-----
���: N �C�̂����������܂��B �������� 1 ���� N �܂Ŕԍ����U���Ă��܂��B
����� N �C�̂��������k���������܂����B �����͂��܂���ł����B ���̂Ƃ��A������ N! �ʂ�l�����܂��B
�����N�� M �l�̊ϋq��������W�߂܂����B i �Ԗڂ̊ϋq�ɂ��ƁA������ xi �͂����� yi ������ɃS�[�����������ł��B
���ׂĂ̊ϋq�̏��ɍ��v����悤�Ȓ��������ʂ�l�����邩���߂Ă��������B

N!��10^13���x�ł��邩��S�T���ł�TLE.����Z�[���X�}�����̂Ƃ��̗l�ɏ�Ԃ��i���ŕ\����bitDP�������
O(N*2^N)�Ōv�Z�\�ɂȂ�.X_i��Y_i������ɖK���Ƃ������񂩂猻�݂݂Ă����Ԃł���͐��������𔻒肵�Ă����΂悢�B
���Ԃ��������Ă��܂����̂ł��������Ɖ��������B

*/

int N, M;
int x[121], y[121];
ll dp[1 << 16];
bool can_use[1 << 16];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    FOR(i, 0, M) {
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }

    FOR(i, 0, (1 << N)) { // x��y����
        can_use[i] = true;
        FOR(j, 0, M) {
            if ((!((i >> x[j]) & 1)) && ((i >> y[j]) & 1)) {
                can_use[i] = false;
            }
        }
    }

    dp[0] = 1;

    FOR(i, 0, (1 << N)) {
        FOR(j, 0, N) {
            if ((!((i >> j) & 1)) && can_use[i | (1 << j)]) {
                dp[i | (1 << j)] += dp[i];
            }
        }
    }

    cout << dp[(1 << N) - 1] << endl;

    return 0;
}
