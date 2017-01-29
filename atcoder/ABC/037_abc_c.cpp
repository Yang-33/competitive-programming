#include<iostream>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/29 ��� ----- ABC037 C /Link http://abc037.contest.atcoder.jp/tasks/abc037_c */
/* -----�����-----
���: ���� N �̐��� {ai} ��1 �ȏ� N �ȉ��̐��� K ���^�����܂��B
���̐���ɂ͒��� K �̘A�����镔���� N?K+1 ����܂��B
�����̂��ꂼ�ꕔ����Ɋ܂܂��l�̍��v�̑��a�����߂Ă��������B

�ݐϘa���Ƃ��ċ�Ԙa���o���΂悢�B
��Ԙa�Ƃ�����segtree���ł����Ȃ��Ǝv����������͂������̂ق����������ȒP�B

*/

#define MAX_N 100000
int N, K;
ll sum[MAX_N + 1];
ll ans = 0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> N >> K;

    int x;
    sum[0] = 0;
    FOR(i, 1, N + 1) {
        cin >> x;
        sum[i] = sum[i - 1] + x;
    }

    FOR(i, K, N + 1) {
        ans += (sum[i] - sum[i - K]);
    }

    cout << ans << endl;

    return 0;
}