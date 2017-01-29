#include<iostream>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

/* 2017/01/28 ��� ----- ABC038 C Link http://abc038.contest.atcoder.jp/tasks/abc038_c */
/* -----�����-----
���: N�̐�����Ȃ鐔�񂪗^�����܂��Bi�Ԗڂ̐���ai�ƌĂт܂��傤�B
al,al+1,�c,ar ���P�������A���Ȃ킿 l��r �ł����� ai<ai+1 ��l��i<r �𖞂����S�Ă�i�ɑ΂��Đ��藧�悤��(l,r)�̐������߂Ă��������B

�P��������Ԃ�ێ����A�����łȂ���΋�Ԃɑ΂���g�𐔂���B1+2+3+4+...+k=k*(k+1)/2
ans��int�^�ɂ��Ă�����Ă����B���v���ɂ�����ll�͍ŋ��I

*/

#define MAX_N 100000
int N;
int a[MAX_N + 1];
ll cnt = 0, ans = 0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    FOR(i, 0, N) {
        cin >> a[i];
    }
    a[N] = -1;

    FOR(i, 0, N) {
        cnt++;
        if (a[i] >= a[i + 1]) {
            ans += (cnt*(cnt + 1) / 2);
            cnt = 0;        
        }
    }

    cout << ans << endl;

    return 0;
}