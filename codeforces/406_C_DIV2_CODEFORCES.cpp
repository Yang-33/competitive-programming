#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int INF = 1e9;
typedef long long ll;
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define debug(x) cout<<#x<<": "<<x<<endl

/* -----  2017/03/30  Problem: CodeForces406 C div2 / Link: http://codeforces.com/contest/786/problem/A ----- */
/* ------���------

�~��� n �̃}�X������D���ꂼ�� 0 ���� n-1 �܂Ŕԍ����U���Ă���D
0 �Ԗڂ̓u���b�N�z�[���ł���D
�܂��C�ǂ����̃}�X�Ɉ�C�̃����X�^�[������D
�������g����2�l�ŃQ�[��������D2�l�͂��ꂼ��W��S1, S2�������Ă��āC�v�f�͂������̎��R���ł���D
���ԂɁC�����̏W���̒�����D���Ȑ����������ŁC�����X�^�[��������ʒu���玞�v���ɑI�񂾐������ړ�������D
���̎��C���傤�ǃu���b�N�z�[���Ƀ����X�^�[���ړ��������ق��������ł���D
�����X�^�[�̏����ʒu�� 1, 2, �c, n-1 �Ԗڂ̃}�X�������ꍇ�C2�l�̃v���C���[���őP��s���������ɐ��i�v���C���[�͓�l����̂�2�ʂ�j�́u�����v�u���[�v�v�u�����v�̂�����ɂȂ邩�����ׂē�����D

-----��肱���܂�----- */
/* -----�����-----

�Q�[���͍ŏI��Ԃ��炽�ǂ��Ă����̂���΂炵���B
���������܂�̂́A���肪������ƌ��܂��Ă���}�X�ɓ��B�\�ł���Ƃ��A���������܂�̂͂��ׂĂ̎���g���Ă����肪���Ɗm�肷��}�X�ɓ��B���Ă��܂��Ƃ��ł���B
��Ԑ��͍ő�ł�n*k�ł��邩�� O(N*K)

----��������܂�---- */

ll N;
int dp[2][7010];
int vis[2][7010];
int L[2];
int S[2][7010];

void pre() {

    queue<int> que;
    dp[0][0] = -1; que.push(0 * 101010 + 0);
    dp[1][0] = -1; que.push(1 * 101010 + 0);

    while (!que.empty()) {
        int q = que.front(); que.pop();

        int p = q / 101010;
        int x = q % 101010;

        int pp = 1 - p;
        FOR(i, 0, L[pp]) {
            int xx = (x - S[pp][i] + N) % N;
            if (dp[p][x] < 0) {
                if (dp[pp][xx] == 0) {
                    dp[pp][xx] = 1;
                    que.push(pp * 101010 + xx);
                }
            }
            else {
                if (dp[p][x] == 0) continue;
                vis[pp][xx]++;
                if (vis[pp][xx] == L[pp]) {
                    dp[pp][xx] = -1;
                    que.push(pp * 101010 + xx);
                }
            }
        }
    }
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    FOR(i, 0, 2) {
        cin >> L[i];
        FOR(j, 0, L[i]) cin >> S[i][j];
    }

    pre();

    FOR(p, 0, 2) {
        FOR(x, 1, N) {
            int d = dp[p][x];
            if (d < 0) printf("Lose");
            else if (d == 0) printf("Loop");
            else printf("Win");
            if (x != N - 1) printf(" ");
        }
        printf("\n");
    }


    return 0;
}