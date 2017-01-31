#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<climits> //INT_MIN/MAX
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

/* 2017/01/31 ��� ----- ABC032 D /Link http://abc032.contest.atcoder.jp/tasks/abc032_d */
/* -----�����-----
���: 0/1�i�b�v�T�b�N���������Ă��������B0/1�i�b�v�T�b�N���Ƃ͈ȉ��̂悤�Ȗ��̂��Ƃł��B

N �̉ו�������Ai(1��i��N) �Ԗڂ̉ו��ɂ͉��l vi �Əd�� wi �����蓖�Ă��Ă���B
���e�d�� W �̃i�b�v�T�b�N��1����B
�d���̘a�� W �ȉ��ƂȂ�悤�ɉו��̏W����I�уi�b�v�T�b�N�ɋl�ߍ��ނƂ��A���l�̘a�̍ő�l�����߂�B
�������A�����ו��͈�x�����I�Ԃ��Ƃ��ł��Ȃ��B
1 �s�ڂɂ́A�ו��̐���\������ N(1��N��200) �ƃi�b�v�T�b�N�̋��e�d�ʂ�\������ W(1��W��109) ���󔒋�؂�ŗ^������B
2 �s�ڂ���� N �s�ɂ́A�e�ו��̏�񂪗^������B
���̂��� i(1��i��N) �s�ڂɂ́Ai �Ԗڂ̉ו��̉��l��\������ vi(1��vi��109) �Əd����\������ wi(1��wi��109) ���󔒋�؂�ŗ^������B
�uN��30�v�A�u�S�Ă�i(1��i��N) �ɂ��� 1��wi��1000�v�A�u�S�Ă�i(1��i��N) �ɂ��� 1��vi��1000�v�Ƃ��� 3 �̏����̂������Ȃ��Ƃ�1�̏��������藧�B
�����_
���̖��ɂ͕����_���ݒ肳��Ă���B���_�� 100 �_�ł���B

N��30 �𖞂����f�[�^�Z�b�g 1 �ɐ��������ꍇ�́A34 �_���^������B
N��200 ���S�Ă� i(1��i��N) �ɂ��� 1��wi��1000 �𖞂����f�[�^�Z�b�g 2 �ɐ��������ꍇ�́A��L�̓_���Ƃ͕ʂ� 33 �_���^������B
N��200 ���S�Ă� i(1��i��N) �ɂ��� 1��vi��1000 �𖞂����f�[�^�Z�b�g 3 �ɐ��������ꍇ�́A��L�̓_���Ƃ͕ʂ� 33 �_���^������B


��@
�f�[�^�Z�b�g�ɂ���āA�ȉ��̂��̂�I��������

�����S�� => �ŏ����Ƃ���DP => ���Ȃ���DP

�œK�Ȃ��̂����ꂼ��̃f�[�^�Z�b�g�ɑ΂��đI��ł�����΂悢�B
�ŏ����Ƃ��� �n( N*MAX_V_SUM )     dp[ N�܂ŏ��i��I���ł��� ][ ���l���u ]:= �d���̍ŏ��l

inf �ȉ����� W�ȉ��ōő�� dp[N][j]��j��I��
���Ȃ��� �n( N*W )    dp[ �m�܂ł̏��i��I���ł��� ][ �d����W�ȉ� ]:= �ő�̉��l

*/

#define INF (LLONG_MAX/10)
ll N;
ll W; ll v[200], w[200];
ll dp[210][210 * 1000];
pair<ll, ll>ps[1 << (32 / 2)];
bool flag = false;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> N >> W;
    FOR(i, 0, N) {
        cin >> v[i] >> w[i];
        if (w[i] > 1000)flag = true;
    }

    if (N < 31) { //meet in the middle
                  /* solve */
        ll fn = N / 2; /* first half N */

        for (ll i = 0; i < (1 << fn); i++) {
            ll sw1 = 0, sv1 = 0; /* part source w and source v */
            FOR(j, 0, fn) {
                if ((i >> j) & 1) {
                    sw1 += w[j];
                    sv1 += v[j];
                }
            }
            ps[i] = make_pair(sw1, sv1);
        }

        // Optimisation
        sort(ps, ps + (1 << fn));
        ll m = 1; /* new ps point => m */
        for (ll i = 0; i < (1 << fn); i++) {
            if (ps[m - 1].second < ps[i].second) {
                ps[m++] = ps[i];
            }
        }

        ll ans = 0;
        ll sn = N - fn; /*second half N */
        FOR(i, 0, (1 << sn)) {
            ll sw2 = 0, sv2 = 0;
            FOR(j, 0, sn) {
                if ((i >> j) & 1) {
                    sw2 += w[fn + j];
                    sv2 += v[fn + j];
                }
            }

            if (sw2 <= W) {
                ll tv; /* part target v */
                tv = (lower_bound(ps, ps + m, make_pair(W - sw2, INF)) - 1)->second;
                ans = max(ans, sv2 + tv);
            }
        }

        /* out */
        cout << ans << endl;
    }
    else if (flag) { // min dp case 3
        FOR(i, 0, 1000 * 200 + 1) {
            dp[0][i] = INF;
        }//�ŏ��l���ق����̂�INF�ɁB
        dp[0][0] = 0;


        FOR(i, 0, N) {//�i��
            FOR(j, 0, 200 * 1000 + 1) {//���l
                if (j - v[i] >= 0) {
                    //����������Ԃ��������[�v�ŉe����^���Ȃ��悤�ɂ���̂Ŏ����g��=>���̏�Ԃɂ̂݉e��������
                    dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
                }
                else {
                    dp[i + 1][j] = dp[i][j]; //�����ł��Ȃ��̂őO�̏�Ԃ������p��
                }
            }
        }

        ll ans = 0;
        FOR(j, 0, 200 * 1000 + 1) {
            if (dp[N][j] <= W)
                ans = j; //�傫���̂��ق�����?

        }

        cout << ans << endl;
    }
    else { // typical dp case2
        FOR(i, 0, N) {
            FOR(j, 0, W + 1) {
                if (j - w[i] >= 0)
                    dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
                else dp[i + 1][j] = dp[i][j];
            }
        }
        /* �Y���������炵���̂Œ��Ӂi�g�������̂�Y��Ă����j */
        cout << dp[N][W] << endl;
    }


    return 0;
}