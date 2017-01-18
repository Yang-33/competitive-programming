#include<iostream>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define MOD 1000000007
typedef long long ll;

/* 2017/01/018 ��� -----  Name/Link ----- */
/* -----�����-----
���: ����H���ɂ͉w 1 ����w N �܂ł� N �̉w������B���ʂ��N�́A���̘H���ɏ��}�𑖂点�邱�Ƃɂ����B
���}�́A�w 1 �Ɏ~�܂�A{�w 2, ..., �w N-1} �̕����W���Ɏ~�܂�A�w N �Ɏ~�܂�B
�A������ K�ȏ�̉w�Ɏ~�܂�ƁA�q���O���Ă��܂��̂ŁA���̂悤�Ȃ��Ƃ͂��Ȃ��B
���}�̒�ԉw�̑g�ݍ��킹�Ƃ��ĉ��ʂ�l�����邩�Amod 1,000,000,007 �ŋ��߂�B

2��K��N��1000000

dp[���w�ڂ܂ŗ�����][���݉��w�A���Œ�܂��Ă��邩] := �����@�͂��߂������B�i�v�Z�ʁj
��Ԑ�����������̂ō팸����B

����w��i�A���Ŏ~�܂�����ԂɊւ��āA���̉w��i+1�A���ɂȂ�l�͂���Ƃ��Ȃ��B
�~�܂�Ȃ����ƂɊւ��Ă�1~K-1�A���̂��̂Ɏ~�܂�Ȃ����̂�������΂悢�B
n�w�ڂɊւ��� n+1��K�𖞂�����Ԃɂ���K�A����Ԃ̏�Ԃ͑��݂��Ă���菜���˂΂Ȃ�Ȃ��B
���������ĂO�A����Ԃ̂��̂�1~K-1�A����Ԃ̂��̂�g�ݍ��킹��΂悭�A
dp := n�w�ڂɂ�����0�A�����
sum := n�w�ڂɂ�����1~K-1�A����� �Ƃ���
������sum�͕�K-1�̋�ԗݐϘa�Ƃ���=>���ӂꂽK�A���ڂ̒l��dp[n+1-K]
dp[n+1]=dp[n]+sum[n]
sum[n+1]=sum[n]+dp[n]
n+1��K�Ɍ���A�@sum[n+1]=sum[n+1]-dp[n+1-K]�@�Ƃ���΁@
N�w�ڂł͕K����Ԃ��邱�Ƃ��� sum[N]�����߂���̂ƂȂ�

http://shindannin.hatenadiary.com/entry/2015/12/23/223251
�ƂĂ�������₷���B���j�����炩�I

*/

#define MAX_N 1000001
int N, K;
ll dp[MAX_N];
ll sum[MAX_N];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;

    sum[1] = 1;
    dp[0] = 1;
    //�w�P�Œ�Ԃ��Ă���̂�sum[1] = 1 => �w�P�ɂ����ĂP�A�����
    //�܂� ���݂��Ȃ��w0�ɂ��� dp[0] = 1 => sum[1] = 1 , 
    //�܂��A�w�P�ɂ͕K����Ԃ��Ă���̂� dp[1] = 0

    FOR(n, 1, N) {
        dp[n + 1] = (dp[n] + sum[n]) % MOD;
        sum[n + 1] = (sum[n] + dp[n]) % MOD;
        if (n + 1 >= K) {
            sum[n + 1] = (sum[n + 1] - dp[n + 1 - K] + MOD) % MOD;
        }

    }
    int ans = sum[N];
    cout << ans << endl;

    return 0;
}