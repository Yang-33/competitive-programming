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
#define llong long long
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

/* 2017/01/16 ��� -----  AOJ_DPL_3_A /Link http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A&lang=jp */
/* -----�����-----
���: ����Z�[���X�}�����
�d�ݕt���L���O���t G(V,E) �ɂ��āA�ȉ��̏����𖞂����ŒZ�o�H�̋��������߂ĉ������F

���钸�_����o�����A�o���_�֖߂�H�ł���B
�e���_�����傤�ǂP�x�ʂ�B

�ŒZ�o�H�̋�����1�s�ɏo�͂���B�����𖞂����o�H���Ȃ��ꍇ�� -1 �Əo�͂���B

-- traveling salesman problem -- TSP
NP����ł��邱�Ƃ͗L��
Bit DP ���w�񂾁B
�S�T���ł� �n(N!) (N=10�܂�) ���ۂ� (n-1)!
bit DP �ł� �n( 2^N * N^2 ) (N=16�܂�)

�ŏ��l��r�ł��邩�疢�g�p�̕ӁX��INF�Ƃ��Ă����B
bit DP���鏊�Ȃ�dp�̔z��̓Y��������Ԃ��̂��̂�bit�ł���킳��Ă���A
bit�v�Z�ŏ�Ԉړ���ǉ����s���Ă��邩��ł���ƍl������B
dp[S][v] := ���ɖK�ꂽbit���_�W�� S ,���݂̒��_v����c��̒��_�S�Ă��o�R���čŏ��̒��_�O�ɋA��悤�ȃp�X�̏d�݂̍ŏ��l
dp[V][0] = 0
dp[S][v] = min dp[S|u][u]+d(v,u) (S?u)

*/
#define MAX_V 15
#define INF 1000000
int V, E;
int d[MAX_V][MAX_V];
int dp[1<<MAX_V][MAX_V];

inline int rec(int S, int v) {
    if (dp[S][v] >= 0) {
        return dp[S][v];
    }

    //�ꏄ���Ă���
    if (S == (1 << V) - 1 && v == 0) {
        return dp[S][v] = 0;
    }

    //u�Ɉړ�����ۂ̏���
    int res = INF;
    FOR(u, 0, V) {
        if (!((S >> u) & 1)) {
            res = min(res, rec(S | 1 << u, u) + d[v][u]);
        }
    }
    return dp[S][v] = res;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> V>>E;

    FOR(i, 0, MAX_V) {
        FOR(j, 0, MAX_V) {
            d[i][j] = INF;
        }
    }

    FOR(i, 0, E) {
        int s, t, c; cin >> s >> t >> c;
        d[s][t] = c;
    }

    memset(dp, -1, sizeof(dp));
    int ans = 0;

    ans = rec(0, 0);
    if (ans == INF)ans = -1;
    cout << ans << endl;

    return 0;
}