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

/* 2017/01/29 ��� ----- ABC034 D /Link http://abc034.contest.atcoder.jp/tasks/abc034_d */
/* -----�����-----
���: �H�������������e�킪 N ����܂��B �e��ɂ� 1 ���� N �܂ł̔ԍ������Ă��܂��B
i �Ԃ̗e��ɂ͔Z�x pi �p�[�Z���g�̐H������ wi �O���������Ă��܂��B
�����N�́AK �̗e���I�сA�I�񂾗e��̒��ɓ����Ă���H���������ׂč������킹�邱�Ƃɂ��܂����B
�����N�̍������H�����̔Z�x�Ƃ��čl������ő�l�����߂Ă��������B


���߂� �e�t�̂ɂ��ĉ��Ɛ��ɒl�𕪂��Ă����A
dp[ �����Ŏg�p�\�Ȍ� ][ �g�p������ ] := max�Z�x (salt,water)���Ǝv������
�������悭�킩��Ȃ��Ȃ��Ă��܂����B=> �ł���
�������ꂾ��10^4���炢��TLE���Ă��܂��B
���ύő剻�̍l����p����� 100*NlogN �񂮂炢�B
���߂������m��x�Ƃ��� size[S]=K �ƂȂ�W��S�ɂ���
��Somea_i[i��S]/��Someb_i[i��S] ��x �ƂȂ�x���ق����̂�
�����񕪒T������΂悢�B

����� ��(��)/��(��) �� X (%) => ��( �� - X*�� ) �� 0

*/

int K, N;
int w[1000], p[1000];
double l = 0.0, r = 1.0, mid;
double v[1000];

bool CCC(double x) {
    FOR(i, 0, N) {
        v[i] = (p[i] / 100.0 - x)*w[i];
    }
    sort(v, v + N);
    double sum = 0;
    FOR(i, 0, K) {
        sum += v[N - 1 - i];
    }
    return sum >= 0;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    FOR(i, 0, N) {
        cin >> w[i] >> p[i];
    }
    
    FOR(i,0,100){
        mid = (r+l)/ 2.0;
        if (CCC(mid))l = mid;
        else r = mid;
    }

    printf("%.12lf",mid*100.0);
    return 0;
}