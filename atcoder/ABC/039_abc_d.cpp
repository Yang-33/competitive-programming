#include<iostream>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/27 ��� ----- ABC039 D/Link http://abc039.contest.atcoder.jp/tasks/abc039_d */
/* -----�����-----
���: 2 �l�摜�ɑ΂��čs���A���k�Ƃ�������������܂��B
�Ȃ��A2 �l�摜�Ƃ́A��f�̐F������������ 2 ��ނ����Ȃ��摜�̎��ł��B
���k�Ƃ́A���ꂼ��̉�f�ɂ��Ă��̉�f�Ǝ��� 8 �����̉�f�̂����A��ł�������f���������炻�̉�f����������Ƃ��������ł��B
�����ŁA��f�������� H�A�� W �� 2 �l�摜���l���܂��B
���̉摜�͂���摜�Ɉ����k���s�������̂ł��邱�Ƃ��킩���Ă��܂��B
���̉摜�Ƃ��čl��������̂����邩�𔻒肵�A��������Ȃ�΂��̂����ǂꂩ 1 �𕜌����Ă��������B
�摜�́AH �́AW �����̕����� Si �ŗ^�����܂��BSi �� j �����ڂ�
�A�ォ�� i �ځA������ j �ڂ̉�f�̐F��\���Ă���A. �Ȃ甒�A# �Ȃ獕�ł��B

���F�̃}�X�����݂���΂��̎���̃}�X�ɍ����}�X�͂Ȃ��B
����ɂ���ĕ��������}�X�ɑ΂��ĐF�h���������x�s���A���ꂪ���̃}�X�ƈ�v����Ε����\�A��v���Ȃ���Ε����s�\�ƂȂ�B

*/

int N, M;
char f[105][105];

int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
int dy[8] = { 1,0,-1,1,-1,1,0,-1 };

bool u[105][105];
char G[105][105];
char F[105][105];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    FOR(i, 0, N)FOR(j, 0, M)cin >> f[i][j];

    FOR(i, 0, N)FOR(j, 0, M) {
        if (f[i][j] == '.') {
            u[i][j] = 1;
            FOR(k, 0, 8) {
                int nx = i + dx[k], ny = j + dy[k];
                if (0 <= nx&&nx < N && 0 <= ny&&ny < M) {
                    u[nx][ny] = 1;
                }
            }
        }
    }

    FOR(i, 0, N)FOR(j, 0, M) {
        if (u[i][j]) F[i][j] = '.'; 
        else F[i][j] = '#';
    }

    FOR(i, 0, N)FOR(j, 0, M) {
        G[i][j] = F[i][j];
        for (int k = 0; k < 8; k++) {
            int nx = i + dx[k], ny = j + dy[k];
            if (0 <= nx&&nx < N && 0 <= ny&&ny < M&&F[nx][ny] == '#') {
                G[i][j] = '#';
            }
        }
    }
    FOR(i, 0, N)FOR(j, 0, M) {
        if (G[i][j] != f[i][j]) {
            cout << "impossible" << endl; 
            return 0;
        }
    }

    cout << "possible" << endl;

    FOR(i, 0, N)FOR(j, 0, M) {
        cout << F[i][j];
        if (j == M - 1)cout << endl;
    }

    return 0;
}