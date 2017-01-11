#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/11 ��� -----  Name DPL_3_A /Link http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_A ----- */
/* -----�����-----
���: �ő吳���`
��ӂ� 1 cm �̃^�C�����AH �~ W ���ׂ��Ă��܂��B�^�C���͉���Ă�����́A�Y��Ȃ��̂̂����ꂩ�ł��B

�Y��ȃ^�C���݂̂��g���Ăł��鐳���`�̖ʐς̍ő�l�����߂Ă��������B
�P�s�ڂɂQ�̐��� H�AW ���󔒋�؂�ŗ^�����܂��B
����H �s�Ń^�C����\�� H �~ W �̐��� ci,j ���^�����܂��B
ci,j ���u1�v�̂Ƃ� "���ꂽ�^�C��" �A�u0�v �̂Ƃ� "�Y��ȃ^�C��" ��\���܂��B


���ォ�瑖�����Ă����Adp[0][0] => dp[i][j] �܂ł̍ő吳���`���쐬����
�������ꂽ�^�C���̏�ł���΂O�A�����łȂ���΍��A����A��̂����ŏ��l�{�P�̐����`���쐬�ł��邱�ƂɂȂ�
�������_�Ƃ��Ċg�����Ă����C���[�W

*/

#define MAX_H 1400
#define MAX_W 1400

ll H, W;
ll dp[MAX_H + 1][MAX_W + 1];
ll m[MAX_H + 1][MAX_W + 1];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> H >> W;
    FOR(i, 1, H + 1) {
        FOR(j, 1, W + 1) {
            cin >> m[i][j]; /* 0 -> clean /  1 -> darty */
        }
    }

    FOR(i, 1, H + 1) {
        FOR(j, 1, W + 1) {
            if (m[i][j] == 1)dp[i][j] = 0; 
            else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    }

    ll ans = 0;
    FOR(i, 1, H + 1) {
        FOR(j, 1, W + 1) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans*ans << endl;

    return 0;
}
