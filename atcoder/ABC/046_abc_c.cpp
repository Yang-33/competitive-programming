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

/* 2017/01/21 ��� ----- ABC046 C /Link http://abc046.contest.atcoder.jp/tasks/arc062_a */
/* -----�����-----
���: �V�J��AtCoDeer����͑I����������Ă��܂��B
�I���ɂ͓�l�̌�⍂������Ɛ؂��񂪏o�Ă��܂��B
����ł́A���݂̓�l�̓��[���̔䂪�\������Ă��܂����A���[�����̂��͕̂\������Ă��܂���B
AtCoDeer����� N ���ʂ����āA i(1��i��N) ��ڂɌ����Ƃ��ɕ\������Ă����� Ti:Ai �ł����B
�����ŁAAtCoDeer���񂪑I������̉�ʂ�1��ڂɌ����i�K�Ŋ��ɂǂ���̌��ɂ����Ȃ��Ƃ���[�͓����Ă������Ƃ��킩���Ă��܂��B
N ��ڂɉ�ʂ������Ƃ��̓��[��(��l�̓��[���̘a)�Ƃ��čl��������̂̂����ŏ��ƂȂ���̂����߂Ă��������B
�������A���[�����r���Ō��邱�Ƃ͂���܂���B

1��N��1000
1��Ti,Ai��1000(1��i��N)
Ti �� Ai �݂͌��ɑf (1��i��N)
������ 10^18 �ȉ��ɂȂ邱�Ƃ͕ۏ؂���Ă���


�^����ꂽ�V���� T, A�ɂ��āA�ȑO�̓��[����Ă��閇�������r�����߂�B
t=T*r
a=A*r
������r��r=max( ceil(t/T) , ceil(a/A) )

*/

int N;
int T[1000], A[1000];
ll ans = 0;
ll nt, na, r;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> N;
    cin >> T[0] >> A[0];
    r = 1; nt = T[0]; na = A[0];

    FOR(i, 1, N) {
        cin >> T[i] >> A[i];
        r = max((nt + T[i] - 1) / T[i], (na + A[i] - 1) / A[i]);
        nt = T[i] * r;
        na = A[i] * r;
    }
    ans = nt + na;
    cout << ans << endl;

    return 0;
}