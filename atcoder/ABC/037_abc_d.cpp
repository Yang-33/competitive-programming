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
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
typedef long long ll;

/* 2017/01/29 ��� ----- ABC037 D /Link http://abc037.contest.atcoder.jp/tasks/abc037_d */
/* -----�����-----
���: H*W �̃}�X�ڂ�����A���ꂼ��̃}�X�ɂ͐�����������Ă��܂��B
i �s j ��ɏ�����Ă��鐔�� aij �ł��B
���Ȃ��͂��̃O���b�h�̒��̍D���ȃ}�X����D���Ȃ��������܂�(�ŏ��̃}�X���瓮���Ȃ��Ă����܂��܂���)�B
������}�X�̏㉺���E�ɗאڂ��Ă���}�X�̂����A������}�X���傫�Ȑ����������ꂽ�}�X�Ɉړ����邱�Ƃ��ł��܂��B
���肤��ړ��o�H�̌���10^9+7�Ŋ������]������߂Ă��������B

��������ł����^�C�v�̏�ԑJ�ځB
dp[y][x] :=  (x,y) �Ŏn�܂�ړ��o�H
���낻��o�H�T���p��dxdy���e���v�������悤�B

*/

int H, W;
int num[1000][1000];
ll dp[1000][1000];
ll ans = 0;

ll dfs(int y, int x) {

    ll rec = dp[y][x];
    if (rec != -1)return rec;

    rec = 1;

    FOR(i, 0, 4) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (0 <= ny&&ny < H && 0 <= nx&&nx < W) {
            if (num[y][x] < num[ny][nx]) {
                rec = ((rec + dfs(ny, nx)) % MOD);
            }
        }
    }

    return  dp[y][x] = rec;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> H >> W;
    FOR(i, 0, H)
        FOR(j, 0, W)
        cin >> num[i][j];

    memset(dp, -1, sizeof(dp));
    FOR(i, 0, H)
        FOR(j, 0, W) {
        ans = ((ans + dfs(i, j)) % MOD);
    }

    cout << ans << endl;

    return 0;
}