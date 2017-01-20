#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<climits> //INT_MIN/MAX
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

/* 2017/01/20 ��� ----- ABC047 D /Link http://abc047.contest.atcoder.jp/tasks/arc063_b */
/* -----�����-----
���: N �̒����꒼����ɕ���ł��܂��B�s���l�̍����N�͒� 1 ����o�����A�����S�̔��������Ȃ��璬 N �ւƌ������܂��B

�͂��ߍ����N�͒� 1 �ɂ���A�����S�� 1 �������Ă��܂���B�����N�͎��̂����ꂩ�̍s�����J��Ԃ��s���܂��B

�ړ�: �� i (i<N) �ɂ���Ƃ��A�� i+1 �ֈړ�����B
�����S�̔���: �����S���D���Ȍ�������������B
�����ŁA�� i (1��i��N) �ł̓����S�̔��l�����l���Ƃ��� Ai �~�Ƃ���B������ Ai �͑��قȂ鐮���ł��B
1 �̒��Ŕ������郊���S�̌��ɐ����͂���܂��񂪁A���̒��Ŕ������郊���S�̌��͍��v�� (�������Ɣ���������킹��) T �ȉ��ɂ��Ȃ��Ă͂Ȃ�܂���B

�����N�͗��̗��v�A���Ȃ킿�����S�𔄂���������甃����������������l���ő�ɂ���悤�ɗ�������Ƃ��܂��B
�����I������Ƃ��Ɏ����Ă��������S�̉��l�͍l�����A���̒��Ŕ����������z�������l���܂��B

���̗��ɐ旧���āA�،N�͔C�ӂ̒� i �ɑ΂��� Ai ���D���Ȕ񕉐��� Ai' �ɕς���Ƃ���������D���Ȃ����s�����Ƃ��ł��܂��B
�������A���̑���͍s�����Ƃ� |Ai?Ai'| �̃R�X�g��������܂��B
�����ɂ͈قȂ钬�̊ԂŃ����S�̒l�i�������ɂȂ��Ă��Ă��\���܂���B

�،N�̖ړI�͂ł��邾�����Ȃ����v�R�X�g�̑���ō����N�̗��v�����Ȃ��Ƃ� 1 �~�����邱�Ƃł��B
���v�R�X�g�̍ŏ��l�����߂Ă��������B

�������A���̏�Ԃō����N�� 1 �~�ȏ�̗��v���グ���邱�Ƃ͉��肵�č\���܂���B

����
1��N��105
1��Ai��109 (1��i��N)
Ai �͑��قȂ�
2��T��109
���͂̏�Ԃł͍����N�� 1 �~�ȏ�̗��v���グ���邱�Ƃ��ۏ؂����


�ŏ��l���X�V����邲�Ƃɕʂ̋�Ԃł���Ƃ���B
�����̋�Ԃɂ��Ă̍ő�l�ƍŏ��l�̍���ێ����A���̍��̍ő�l������o�ꂷ�邩���J�E���g����B
�ŏ��l���X�V���ꂽ�ꍇ�ɂ͂���܂ł̍ő�l��p���邱�Ƃ��ł��Ȃ��̂ōŏ��l�ȉ��̐��ɂ���Ζ��Ȃ��B

*/

#define INF INT_MAX/2
int N, T, a[100000];
int minn = INF, maxn = -INF;
int nowmax = -1;
int cnt = 0;
int ans = 0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> T;
    FOR(i, 0, N) {
        cin >> a[i];
    }

    minn = a[0];
    FOR(i, 0, N) {
        
        if (minn > a[i]) {
            maxn = -INF;
            minn = a[i];
        }

        if (nowmax == a[i]- minn)cnt++;
        else if (nowmax < a[i] - minn) {
            nowmax = a[i] - minn;
            cnt = 1;
        }
    }

    ans = cnt;
    cout << ans << endl;

    return 0;
}