#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/18 ��� ----- abc051 d /Link http://abc051.contest.atcoder.jp/tasks/abc051_d */
/* -----�����-----
���: ���ȃ��[�v�Ɠ�d�ӂ��܂܂Ȃ� N ���_ M �ӂ̏d�ݕt�������A���O���t���^�����܂��B
i(1��i��M) �Ԗڂ̕ӂ͒��_ ai �ƒ��_ bi ������ ci �Ō��т܂��B 
�����ŁA���ȃ��[�v�� ai=bi(1��i��M) �ƂȂ�ӂ̂��Ƃ�\���܂��B 
�܂��A��d�ӂ� (ai,bi)=(aj,bj) �܂��� (ai,bi)=(bj,aj)(1��i<j��M) �ƂȂ�ӂ̂��Ƃ�\���܂��B 
�A���O���t�́A�ǂ̈قȂ� 2 ���_�Ԃɂ��o�H�����݂���O���t�̂��Ƃ�\���܂��B 
�ǂ̈قȂ� 2 ���_�Ԃ́A�ǂ̍ŒZ�o�H�ɂ��܂܂�Ȃ��ӂ̐������߂Ă��������B


�܂��́A�C�ӂ̓_����C�ӂ̓_�܂ł̍ŒZ�o�H�����߂�B
����͑S�_�Ԃ̍ŒZ���������߂邱�Ƃɑ������A���[�V�����t���C�h�@������ɓK���Ă���B
����ɂ�肠���e���ŒZ�����Ɏg�p����Ă��邩�ǂ����̔�����s�����Ƃ��ł���悤�ɂȂ�B
�ϐ�j,k�ɑ΂��� s-> t �ւ̃R�X�g��c�Ƃ����
d[j][k] == d[j][s] + cost(s -> t) + d[t][k]
�𖞂����Ƃ��ɂ͂��̕ӂ͎g�p����Ă��邱�Ƃ��킩��B
��������ׂĂ̕�*�n�_�I�_�ɑ΂��Ă��ׂă`�F�b�N���邱�ƂŎg�p����Ă��Ȃ��ӂ𔭌����邱�Ƃ��ł���B
�_�C�N�X�g���ł�������B(pq�̓_�����Ȃ��Ǝv��
)

*/

#define INF 10000000
int M; int N;
int d[110][110];
int s[1010];
int t[1010];
int c[1010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    FOR(i, 0, N) { //for Warshall
        FOR(j, 0, N) {
            if (i == j)d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    
   


    FOR(i, 0, M) {
        cin >> s[i] >> t[i] >> c[i];
        s[i]--; t[i]--;
        d[s[i]][t[i]] = c[i];
        d[t[i]][s[i]] = c[i];
    }

    FOR(k, 0, N) { 
        FOR(i, 0, N) {
            if (d[i][k] < INF)
                FOR(j, 0, N) {
                if (d[k][j] == INF)continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    //�g�p�������̃`�F�b�N
    ll ans=0;
    FOR(i, 0, M) {// M�ӂɂ���check
        int yes = 1;
        FOR(j, 0, N) {
            FOR(k, 0, N) {
                if(j!=k)
                //�ŒZ�o�H�ł��邩�ۂ�
                if (d[j][k] == d[j][s[i]] + c[i] + d[t[i]][k])yes = 0;
            }
        }
        ans += yes;
    }
    cout << ans << endl;

    return 0;
}