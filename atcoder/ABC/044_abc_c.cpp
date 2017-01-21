#include<iostream>
#include<algorithm>
#include<climits> //INT_MIN/MAX
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/21 ��� ----- ABC044 C /Link http://abc043.contest.atcoder.jp/tasks/arc059_a */
/* -----�����-----
���: N �̐��� a1,a2,..,aN ���^�����܂��B���ьN�͂��������������đS�ē��������ɂ��悤�Ƃ��Ă��܂��B
�eai(1��i��N)�͍��X��񂵂������������܂���(���������Ȃ��Ă��ǂ�)�B
����x�𐮐�y�ɏ���������Ƃ��A�R�X�g��(x?y)^2������܂��B
����ai=aj(i��j)���Ƃ��Ă��A�ЂƂ��̃R�X�g�œ����ɏ��������邱�Ƃ͏o���܂���(���o�͗�2 ���Q��)�B
���ьN���ړI��B������̂ɕK�v�ȃR�X�g�̑��a�̍ŏ��l�����߂Ă��������B

����
1��N��100
?100��ai��100

���ϒl����o���邩�ȂƎv����������̓f�[�^�̎U��΂���ɂ��̂Ō��������Ȃ��Ƃ������ƂőS�T�������B
�ŏ��l�̑S�T���B
���w�I�ɉ������Ƃ��ď������Ԃ��������Ă��܂�������{�͑S�T���ł���Ƃ������ɒ����ł��肽���I

�S�T�����Ȃ��Ă�
avg = sum / N
d = sum % N�Ƃ���
d > N / 2 �Ȃ�avg++�ŋ��߂���B
�܂�f�[�^�̔����ɑ΂��ĂP����������邩�ǂ������݂�B
����؂�邩�ǂ����ł��ꍇ�����ł������B


*/

int N;
int a[100];
ll ans = INT_MAX;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    FOR(i, 0, N) {
        cin >> a[i];
    }

    FOR(i, -100, 101) {
        ll minn = 0;
        FOR(j, 0, N) {
            minn += (a[j] - i)*(a[j] - i);
        }
        ans = min(minn, ans);
    }

    cout << ans << endl;

    return 0;
}