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
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

/* 2010/00/00 ��� -----  AOJ_DPL_2_B /Link http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_B&lang=jp */
/* -----�����-----
���: �����l�X�֔z�B���
�d�ݕt�������O���t G(V,E) �ɂ��āA�ȉ��̏����𖞂����ŒZ�o�H�̋��������߂ĉ������F

���钸�_����o�����A�o���_�֖߂�H�ł���B
�e�ӂ����Ȃ��Ƃ��P�x�͒ʂ�B
�ŒZ�o�H�̋�����1�s�ɏo�͂���B

�I�C���[�H�ł���Ή��͎����ƂȂ邪�A�����łȂ��ꍇ�̓I�C���[�H�ɂȂ�悤�ȕӂ������ŉ�����΂悢�i�I�C���[��ԁj
�ӂ̎����ɒ��ڂ��A���ꂪ�����ɂȂ���݂̂̂ł���Έ�M�����̍ŊȂȂ��̂���邱�Ƃ��ł���̂�
��̂��̂����Ƃ��ĕێ����A������S�ėp�������ōł��Z�������ƂȂ���̂����߂�΂悢�B
���Ȃ݂Ɏ�������ƂȂ钸�_�͋����ł���B����͈����肩������炩

���d�ӂ����݂��邱�Ƃ��l���ɓ����ׂ��B�i���߁j
*/

#define MAX_V 15
#define INF INT_MAX/10
int V, E;
int G[MAX_V][MAX_V];
int dp[1 << MAX_V];
int cnt[MAX_V];

vector<int>degodd;
ll W = 0;
ll plusnum=0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> V >> E;
    FOR(i, 0, V) { //for Warshall
        FOR(j, 0, V) {
            if (i == j)G[i][j] = 0;
            else G[i][j] = INF;
        }
    }

    FOR(i, 0, E) {
        int s, t, d, p; cin >> s >> t >> d;
        p = min(d, G[s][t]);
        G[s][t] = p;
        G[t][s] = p;
        W += d;
        cnt[s]++;//conut edge's deg
        cnt[t]++;
    }

    FOR(i, 0, V) {// check whether deg num is odd
        if (cnt[i] % 2 == 1)degodd.push_back(i);
    }

    FOR(k, 0, V) { //for Warshall
        FOR(i, 0, V) {
            if(G[i][k]<INF)
            FOR(j, 0, V) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    int CNT = degodd.size();

    //dp init
    FOR(i, 0, (1 << CNT)) {
        dp[i] = INF;
    }
    dp[0] = 0;


    // i : all states  j,k : combination
    FOR(i, 0, (1 << CNT)) {
        FOR(j, 0, CNT) {
            if (!(i&(1 << j))) {
                FOR(k, j + 1, CNT) {
                    if (!(i&(1 << k))) {
                        dp[i | (1 << j) | (1 << k)] = min(dp[i | (1 << j) | (1 << k)], dp[i]+G[degodd[j]][degodd[k]]);
                    }
                }
            }
        }
    }

    plusnum = dp[(1<<CNT)-1];
    
    //all edge + cost to make eular path 
    cout << W+plusnum<< endl;

    return 0;
}