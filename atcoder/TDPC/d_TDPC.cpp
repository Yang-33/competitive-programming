#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/18 ��� -----  TDPC_D /Linkhttp://tdpc.contest.atcoder.jp/tasks/tdpc_dice */
/* -----�����-----
���: �T�C�R���� N ��U�����Ƃ��A�o���ڂ̐ς� D �̔{���ƂȂ�m�������߂�B
1��N��100
1��D��10^18

D�̖񐔂��l�����Ƃ���2,3,5�̂����ꂩ�̑g�ݍ��킹�ŕ\�����Ƃ��ł��Ȃ��Ƃ��̓T�C�R���̏o�ڂł͂����\�����Ƃ͂ł��Ȃ��B
2^n1,3^n2,5^n3�ƌ��킷���Ƃ��ł����Ƃ���ƁA
dp[ �T�C�R���̌� ][ �Q�̔{���̌�p1 ][ �R�̔{���̌�p2 ][ �T�̔{���̌�p3 ] := n�̃T�C�R���� 2^p1,3^p2,5^p3 �ƂȂ�m��
�Ɛݒ肷�邱�Ƃ� dp[N][n1��2*N][n2��N][n3��N]�����߂�΂悢�B
��Ԑ���N*2N*N*N�ƂȂ�S��Ԃ̐��ڂŋ��߂���B
dp[n][][][]�ɑ΂��Ă����𑫂����킹�����̂͂P
���������Ă�͂�dp[N]�ł̒l�𓚂��Ƃ��ėp���˂΂Ȃ�Ȃ��B

���ɏ�ԑJ�ڂ���������悭�킩�����B
�����l�� dp[0][0][0][0] = 1

atcoder��ł̓���������Ȃ��炵���̂Ŕz��̍ė��p�������B
*/

int N;
ll D, d;
double dp[2][202][101][101];
int c1 = 0, c2 = 0, c3 = 0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> d;
    D = d;

    for (;;) {
        while (D % 2 == 0) {
            D /= 2;
            c1++;
        }
        while (D % 3 == 0) {
            D /= 3;
            c2++;
        }
        while (D % 5 == 0) {
            D /= 5;
            c3++;
        }
        if (D == 1)break;
        else {
            cout << 0.000000 << endl;
            return 0;
        }
    }

    dp[0][0][0][0] = 1.0;

    int cur = 0, temp = 1;

    FOR(n, 0, N) {
        memset(dp[temp], 0, sizeof(dp[temp]));//����
        FOR(i, 0, 2 * n + 1)FOR(j, 0, n + 1)FOR(k, 0, n + 1) {
            if (dp[cur][i][j][k] != 0) {
                dp[temp][i][j][k] += (dp[cur][i][j][k] / 6.0);
                dp[temp][i + 1][j][k] += (dp[cur][i][j][k] / 6.0);
                dp[temp][i][j + 1][k] += (dp[cur][i][j][k] / 6.0);
                dp[temp][i + 2][j][k] += (dp[cur][i][j][k] / 6.0);
                dp[temp][i][j][k+1] += (dp[cur][i][j][k] / 6.0);
                dp[temp][i + 1][j + 1][k] += (dp[cur][i][j][k] / 6.0);

            }
        }
        swap(cur, temp);

    }
    double ans = 0;
    FOR(i, c1, 202)FOR(j, c2, 101)FOR(k, c3, 101) {
        ans += dp[cur][i][j][k];
    }

    printf("%.12f\n", ans);

    return 0;
}