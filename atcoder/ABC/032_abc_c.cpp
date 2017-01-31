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

/* 2017/01/31 ��� ----- ABC032 C /Link http://abc032.contest.atcoder.jp/tasks/abc032_c */
/* -----�����-----
���: ���� N �̔񕉐����� S=s1,s2,�c,sN �Ɛ��� K ������܂��B
���Ȃ��̎d���́A�ȉ��̏����𖞂��� S �� �A������ ������̂����A�ł��������̂̒��������߂邱�Ƃł��B
������̒����� 1 �ȏ�̗�łȂ��Ƃ����܂���B

���̕�����Ɋ܂܂��S�Ă̗v�f�̒l�̐ς́AK �ȉ��ł���B
���������𖞂��������񂪈�����݂��Ȃ��Ƃ��́A0 ���o�͂��Ă��������B


���Ⴍ�Ƃ�@�B�L�΂��ďk�߂�΂悢�B
��0�̋�Ԃŏ����𖞂����Ȃ��Ƃ��͗����̃C���f�b�N�X��i�߂Ă��܂��΂悢�B
�o�O�炸�ɂł����̂͑傫���B
�ΐ����Ƃ�Θa�̖��ɋA���ł���炵���B�܂��K�v�������Ȃ����ǂ����������B�덷���o�����B

*/

ll N, K;
ll s[100000];
int ans;
int l = 0, r = 0;
ll rec = 1;
bool flag = false;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> N >> K;
    FOR(i, 0, N) {
        cin >> s[i];
        if (s[i] == 0)flag = true;
    }

    if (flag) {
        cout << N << endl;
        return 0;
    }

    while (r < N) {
        while (r < N&&rec*s[r] <= K) {
            rec *= s[r];
            r++;
        }
        ans = max(ans, r-l);
        if (l != r) {
            rec /= s[l];
            l++;
        }
        else {
            l++; r++;
        }
    }

    cout << ans << endl;

    return 0;
}