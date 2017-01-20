#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/20 ��� -----  ABC048 C /Link  */
/* -----�����-----
���: N �̔��������ɕ���ł��܂��B �ŏ��A������ i �Ԗڂ̔��ɂ� ai �̃L�����f�B�������Ă��܂��B

���ʂ��N�͎��̑�����D���ȉ񐔂����s�����Ƃ��ł��܂��B

�L�����f�B�� 1 �ȏ�����Ă��锠���ЂƂI�сA���̔��̃L�����f�B�� 1 �H�ׂ�B
���ʂ��N�̖ڕW�͎��̒ʂ�ł��B

�ǂׂ̗荇�� 2 �̔������Ă��A�����̔��ɓ����Ă���L�����f�B�̌��̑��a�� x �ȉ��ł���B
�ڕW��B�����邽�߂ɕK�v�ȑ���񐔂̍ŏ��l�����߂Ă��������B


���o���v���Ƃ��Ē[���珇�ɂ��𒴂��Ă��܂����̂��팸���Ă����΂悢�B
�V�����������v�f�ɑ΂��č팸����ɍs���悤�ɂ���Ύ���ɍ팸���Ȃ��Ă��悢�\�������݂���̂�
���̒T�������ŏ��������߂��i�ł���B�n(N)

*/

int N, x;
int a[100000];
ll ans = 0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> x;
    FOR(i, 0, N) {
        cin >> a[i];
    }
    FOR(i, 0, N - 1) {
        ll sum = a[i] + a[i + 1];
        if (sum <= x)continue;
        
        ll sub = sum - x;
        if (sub <= a[i + 1]) a[i + 1] -= sub;
        else {
            ll subsub = sub;
            subsub -= a[i + 1];
            a[i + 1] = 0;
            a[i] -= subsub;
        }
        ans += sub;
    }


    cout << ans << endl;

    return 0;
}