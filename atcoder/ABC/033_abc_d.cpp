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

#include<cstdlib>
#include<utility>
#include<complex>
#include<functional>
#include<cassert>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/29 ��� ----- ABC033 D /Link http://abc033.contest.atcoder.jp/tasks/abc033_d */
/* -----�����-----
���: 2 �������ʏ�� N �̓_���^�����܂��B
i �Ԗڂ̓_�̍��W�� (xi,yi) �ł��B�������A���̂����̂ǂ� 3 �_�����꒼����ɂ���܂���B

N �_�̂��� 3 �_��I�Ԃ��Ƃɂ���Ă��� 3 �_�𒸓_�Ƃ����O�p�`����邱�Ƃ��l���܂��B
�O�p�`�͑S���� N*(N?1)*(N?2)?6 �ł��܂��B
�����̎O�p�`�̂����A�s�p�O�p�`�̌��A���p�O�p�`�̌��A�݊p�O�p�`�̌������߂Ă��������B

�������A�s�p�O�p�`�Ƃ́A3 �̊p���S�� 90�� ��菬�����O�p�`�ŁA
���p�O�p�`�Ƃ́A���� 1 �̊p�� 90�� �ł���O�p�`�ŁA
�݊p�O�p�`�Ƃ́A���� 1 �̊p�� 90�� ���傫���O�p�`�̂��Ƃ������܂��B


�n( N^3 )�������ɗ��Ƃ����l���Ă�����������Ȃ������B
�Ίp�\�[�g�B
���钸�_�ɑ΂��钸�_�΂��݂āA���̕Ίp��ۑ��������ɕ��ёւ���B
���̂Ƃ����݂݂Ă���Ίp+��/2���傤�ǂ̂��̂����݂���Β��p�O�p�`�����݂��邱�Ƃ��킩��B
�Œ蒸�_��I�Ԃ̂�N, ���_�ƕΊp���݂�̂�N, �\�[�g�ς݂̂��̂���l����������̂�log N
�ŁA�n( N^2 log N )�Ƃ��ĉ�����B
���܂��g�������邽�߂Ɍ��ݒ��ڂ��Ă���l�ɂ���ɒl��������Ƃ�����@���̂��ȁB�Ƃ��������B

����pi/2�ɂ��덷�������邽��eps�Ō덷�ۂߍ��݂��K�v�B
���̊p�ɑ΂��Ă�2�΂������Ă������p���������Ƃ��ł���̂œ�����p�����B
���̗������̂��悭�킩���B15�񓊂�����ʂ����B

*/

ll x[3000], y[3000];
const double eps = 1e-10;
ll cntc = 0, cntd = 0, sum = 0;
const double pi = acos(-1);


int main()
{


    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll N;
    cin >> N;

    for (int a = 0; a < N; a++) {
        cin >> x[a] >> y[a];
    }

    for (int i = 0; i < N; i++) {
        vector<double>argv;

        for (int j = 0; j < N; j++) {
            if (j == i)continue;
            argv.push_back(atan2(y[j] - y[i], x[j] - x[i]));
        }

        sort(argv.begin(), argv.end());

        for (int c = 0; c < (N - 1); c++) {
            argv.push_back(argv[c] + 2 * pi);
        }

        for (int j = 0; j < N - 1; j++) {
            cntc += upper_bound(argv.begin(), argv.end(), argv[j] + pi / 2 + eps) - lower_bound(argv.begin(), argv.end(), argv[j] + pi / 2 - eps);
            cntd += lower_bound(argv.begin(), argv.end(), argv[j] + pi) - upper_bound(argv.begin(), argv.end(), argv[j] + pi / 2 + eps);
        }

    }

    sum = N*(N - 1)*(N - 2) / 6;

    sum = sum - (cntd + cntc);
    printf("%lld %lld %lld\n", sum, cntc, cntd);

    return 0;
}