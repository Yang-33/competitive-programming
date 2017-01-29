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

/* 2017/01/29 ��� ----- ABC035 C /Link http://abc035.contest.atcoder.jp/tasks/abc035_c */
/* -----�����-----
���: ���̖ʂ�0�A���̖ʂ�1�������ꂽ N �̃I�Z���̋�A�ǂ̋�����̖ʂ���������悤�Ɉ��ɕ��ׂ��Ă��܂��B
���̌�A�����Ԃɂ�����S�ė��Ԃ��Ƃ������삪 Q �񂾂��s�Ȃ��܂����B
��̓I�ɂ� i ��ڂ̑���ɂ����ẮA������ li �Ԗڂ̋�� ri �Ԗڂ̋�܂ł̋�S�Ă����Ԃ���܂����B
�ŏI�I�ȔՖʂ����߂Ă��������B

ON/OFF�̂悤�ȑ���ł͂������@�ŋ�Ԃ��Ǘ����A���ǉ���Ђ�����Ԃ��������Ō�ɋ�Ԙa�Ƃ��ĕ\�����Ȃ����΂悢�B



*/

int N, Q;
int x[200001];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> Q;
    FOR(i, 0, Q) {
        int a, b; cin >> a >> b;
        x[--a]--; x[b]++;
    }
    
    int ans = 0;
    FOR(i, 0, N) {
        ans += x[i];
        cout << (abs(ans)) % 2;
    }
    cout << endl;
    return 0;
}