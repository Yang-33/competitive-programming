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

/* 2017/01/29 ��� ----- ABC036 C /Link http://abc036.contest.atcoder.jp/tasks/abc036_c */
/* -----�����-----
���: N �l�̐l�������Ă��܂��B i �Ԗڂ̐l�̍����� ai �ł��B ���ʂ��N�́A�召�֌W��ۑ������܂܍����̃f�[�^�����k���ĕۑ����邱�Ƃɂ��܂����B �ȉ��̏����𖞂������� b1,�c,bN �����߂Ă��������B
bi �͂��ׂĔ񕉐����ł���B
ai<aj �Ȃ�� bi<bj �ł���B
ai=aj �Ȃ�� bi=bj �ł���B
��̏����𖞂����z��̂����Abi �̍ő�l���ŏ��ƂȂ�B
���̂悤�ȏ������݂��� b �͈�ӂɒ�܂邱�Ƃ��m���Ă��܂��B

����
1?N?10^5
0?ai?10^9
ai �͐����ł���B

���W���k���I�����I
�ʔz��ɂ��̈��k���W���������ނ�����͂�����o�͂��Ă��܂��΂悢�B

*/

int N;
int a[100000];
vector<int>x;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    FOR(i, 0, N) {
        cin >> a[i];
        x.push_back(a[i]);
    }

    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());

    int p;
    FOR(i, 0, N) {
        p = lower_bound(x.begin(), x.end(), a[i]) - x.begin();
        cout << p << endl;
    }

    return 0;
}