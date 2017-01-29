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

/* 2017/01/29 ��� ----- ABC038 D /Link http://abc038.contest.atcoder.jp/tasks/abc038_d */
/* -----�����-----
���: ��������̓v���[���g��p�ӂ��邱�ƂɂȂ�܂����B
�v���[���g�̒��g�͂��łɌ��܂�A���Ƃ̓v���[���g�����锠��p�ӂ��邾���ł��B
�������񂪎g���锠��N����Ai�Ԗڂ̔��͏chicm�~��wicm�̃T�C�Y�ł��B

�v���[���g����葽���̔��ɓ����Ă����ق����ʔ����ƍl������������́A
�Ȃ�ׂ������̔������q�ɂ��A�ł������̔��Ƀv���[���g�����邱�Ƃɂ��܂����B
���锠�́A�c�E���Ƃ��ɂ��傫���T�C�Y�̔��ɂ̂ݓ���邱�Ƃ��ł��܂��B
�܂��A���锠��1�܂ł������̔������邱�Ƃ͂ł��܂���B
�v���[���g�����锠���ő�ŉ��d�̓���q�ɂł��邩�����Ă��������B


�܂��͕Б��ɂ��ă\�[�g�����āA�������鏇�������肷��B
���̍ہA�����Б��̕ӂɂ��Ă͏�����LIC�ŏ����ł���悤�ɂȂ��Ă��Ăق����A�܂��������̑傫���ł�
���ɓ���邱�Ƃ��ł��Ȃ��Ƃ������񂩂�A�eW�ɂ��č~���ɂ���΂悢�B

INF�̂Ƃ���ň��Ă����̂��ǂ��Ȃ��l�@�������B

http://mayokoex.hatenablog.com/entry/2016/05/28/230000
�Ƃ����悤��segtree��BIT�ŉ����Ƃ������j�����݂���B�\�[�g�������Ƃŋ�Ԃ������Ă��邱�Ƃɒ��ڂ������̂�
log�T�C�Y�Ō�������������̂��~�\�B�������낢�B�d����Ԃ𐔂��グ��FOR i�����炵�Ă����̂��������낢�B

*/

#define MAX_N 100001
#define INF INT_MAX/2
int N;
int h, w;
vector<pair<int, int>> b;
vector<int> a(MAX_N);
int x[MAX_N + 1];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    FOR(i, 0, N) {
        cin >> w >> h;
        b.push_back(make_pair(w, -h));
    }

    sort(b.begin(), b.end());
    FOR(i, 0, N) {
        a[i] = -b[i].second;
    }


    fill(x, x + MAX_N + 1, INF);
    x[0] = -INF;
    
    FOR(i, 0, N) {
        *lower_bound(x, x + MAX_N + 1, a[i]) = a[i];
    }

  /*  FOR(i, 0, N+1) {
        if (x[i] == INF) {
            cout << i-1 << endl;
            return 0;
        }
    }*/


    FORR(i, N, 0) {
        if (x[i] < INF) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}