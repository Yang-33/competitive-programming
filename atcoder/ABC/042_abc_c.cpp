#include<iostream>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/25 ��� ----- ABC042 C/Link http://abc042.contest.atcoder.jp/tasks/arc058_a */
/* -----�����-----
���: ����͂����͂��������̂ŁA�����Ȑ����� K ����A���ꂼ�� D1,D2,�c,DK �ł��B

����͂����͂��X�ł������������Ă��āA N �~�̕i���𔃂����Ƃ��Ă��܂��B
�������A���̕i���� N �~�ȏ�̂������x�����Δ������Ƃ��ł��܂��B
�������A��قǏq�ׂ��悤�ɂ���͂����͋���������肪����̂ŁA
���������X�Ɏx�������z�� 10 �i�\�L�ɂ���͂����̌����Ȑ������o�����Ȃ��悤�ȍł����Ȃ����z���x�������Ƃ��܂��B

����͂���񂪎x�������z�����߂Ă��������B

�S�T��������B
�e�����ɂ��Ďg�p�\�����`�F�b�N���A�_���Ȃ�+1���čēx�`�F�b�N�������Ă���
�̓�����J��Ԃ��s���΂悢�B


*/

int N, K;
bool d[10];
int ans = 0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    FOR(i, 0, K) {
        int s;
        cin >> s;
        d[s] = true;
    }
    int x = N;
    for (;;) {
        bool flag = true;
        int t = x;
        while (t) {
            if (d[t % 10])flag = false;
            t /= 10;
        }
        if (flag) {
            cout << x << endl;
            return 0;
        }
            x++;
    }


    return 0;
}