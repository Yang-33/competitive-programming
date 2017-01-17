#include<iostream>
#include<string>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define MOD 1000000007
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

/* 2017/01/17 ��� ----- TDPC_E /Link http://tdpc.contest.atcoder.jp/tasks/tdpc_number */
/* -----�����-----
���: N �ȉ��̐������ł����āA
�\�i�@�\�L�����Ƃ��̊e���̐��̘a�� D �̔{���ł�����̂̌��� mod 1,000,000,007 �ŋ��߂�B

1��N��10^10000
1��D��100

��������s�ŏo�͂���B

64bit�����ł����܂肫��Ȃ���������A���炩�Ɍ��c�o�B
��dp�ɂ͊�{�ƂȂ�T�O�Ƃ��āA���ݑ������Ă���l�̌��ɂ�������͉\�Ȓl�͈̔͂���������Ă��邩�ۂ��A
���ݑ������Ă���擪����̌���0origin�A���̑����������c�o�̓Y�����Ƃ��Ă����̂���{�ł���B
��������������������������K�v�ł���΁Ai-2�����ڂ�i-1�����ڂɂ͉e�����邪i�����ڂɂ͉e�����Ȃ����Ƃ��l������
���Ǘ��̔z��͂Q�ő����B�ibit�����ɂȂ�j

dp[ ���߂����� ][ mod D ][ �m�����ł��邱�Ƃ��m�肵�Ă��邩 ] := ����
�Ɛݒ肵�A��������O�͂���ɓ��Ă͂܂�Ȃ��Ƃ���
dp[N.size][0][0] + dp[N.size][0][1] - 1 �������B

for d �� [k || (d < nowD)] �����Ȃ�֗����Ȃ��Ǝv�����B
�ق��̌�fp�̖�����������

�����l��dp[0][0][0]=1
�e�X�g�P�[�X���シ����H

*/

int dp[10010][100][2];
string N;
int D;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> D >> N;
    int Nsize = N.size();
    dp[0][0][0] = 1;

    int nowN;
    //���A�c�ɑ΂���]��A�m�����m�肩�A���̐���
    FOR(i, 0, Nsize)FOR(num, 0, D)FOR(k, 0, 2) {
        nowN = N[i] - '0';
        for (int d = 0; d <= (k ? 9 : nowN); d++) {
            dp[i + 1][(num + d) % D][k || (d < nowN)] = (dp[i + 1][(num + d) % D][k || (d < nowN)] + dp[i][num][k]) % MOD;
        }
    }

    int ans = dp[Nsize][0][0] + dp[Nsize][0][1] - 1;
    ans %= MOD;
    cout << ans << endl;

    return 0;
}