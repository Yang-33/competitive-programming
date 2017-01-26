#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
typedef long long ll;

/* 2017/01/26 ��� ----- ABC041 C Name/Link https://abc041.contest.atcoder.jp/tasks/abc041_c */
/* -----�����-----
���: �����w���ɂ� N �l�̐��k�����܂��B ���k�� 1 ���� N �܂ŏo�Ȕԍ����U���Ă��܂��B
i �Ԗڂ̐��k�̐g���� ai �ł��B ai �͂��ׂđ��قȂ�܂��B
�����搶�� N �l�̐��k��w�̍��������珇�ɕ��ׂ܂����B N �l�̐��k�̏o�Ȕԍ���w�̍��������珇�ɏo�͂��Ă��������B

�\�[�g�O�ɂ��̒l�Ƀ����N�����Y�����𕜌����ł���悤�Ƀy�A�\�ŕۑ����Ă����΂悢�B
FORR�ŗ����������B

*/

int N;
vector<pair<int,int>> a;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    FOR(i, 0, N) {
        int x; cin >> x;
        a.push_back(make_pair(x,i+1));
    }
    sort(a.begin(), a.end());
    

    FORR(i, N-1, -1) {
        cout << a[i].second << endl;
    }

    return 0;
}