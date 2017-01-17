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
#define MOD 1000000007
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

/* 2017/01/18 ��� ----- TDPC_A /Link http://tdpc.contest.atcoder.jp/tasks/tdpc_contest */
/* -----�����-----
���: N ��̖�肪����R���e�X�g������Ai ��ڂ̖��̔z�_�� pi �_�ł���B
�R���e�X�^���g�́A���̖��̒����牽�₩�����A���������̔z�_�̍��v�����_�ƂȂ�B
���̃R���e�X�g�̓��_�͉��ʂ�l�����邩�B
1 ? N ? 100
1 ? p_i ? 100

��ԑJ�ڂ����m��dp.typical���B
dp[ ���_ ] := ��Ԃ����݂��邩
10000�_�܂ł̉\�������݂��A�����t�Ƃ����Ƃ��A�܂�P_i�̏��i������Ƃ�
dp[ t ]  => ( + P_i ) => dp[ t + P_i ] �ƂȂ��ԑJ�ڂ��l����΂悢�B:�������[�v
���邢�͑��������ł���Γ��_�͊e��񂵂��g���Ȃ��̂œ񎟌��Ɋg����
dp[ �g���链�_�̐� ][ ���_ ] := ��Ԃ����݂��邩�@�Ƃ���
dp[i+1][t] = dp[i][t-P_i] �Ƃ���΂悢
������ dp[N][0=>10000]
�ǂ�����v�Z�ʂ͂n(N*(SUM_POINTS))��10^6

*/

#define MAX_N 100
#define MAX_P 100
int N;
int p[MAX_N];
bool dp[MAX_N * MAX_P + 1];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    FOR(i, 0, N) {
        cin >> p[i];
    }
    FOR(i, 0, MAX_N * MAX_P + 1) {
        dp[i] = false;
    }


    dp[0] = 1;

    FOR(i, 0, N) {
        for (int t = MAX_N * MAX_P; t >= 0; t--) {
            if (dp[t] == 1 && t + p[i] <= MAX_N*MAX_P) {
                dp[t + p[i]] = 1;
            }
        }
    }

    int ans = 0;
    FOR(i, 0, MAX_N*MAX_P + 1) {
        ans += dp[i];
    }
    cout << ans << endl;

    return 0;
}