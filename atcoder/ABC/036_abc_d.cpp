#include<iostream>
#include<vector>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define MOD 1000000007
typedef long long ll;

/* 2017/01/29 ��� ----- ABC036 D /Link http://abc036.contest.atcoder.jp/tasks/abc036_d */
/* -----�����-----
���: N �̓�������܂��B ���ɂ� 1 ���� N �܂ł̔ԍ������Ă��܂��B
�܂��AN?1 �̋�������܂��B i �Ԗڂ̋��� ai �Ԃ̓��� bi �Ԃ̓����Ȃ��ł��܂��B
�ǂ̓�����ǂ̓��ւ������������o�R���ē��B�ł��邱�Ƃ��킩���Ă��܂��B

���ʂ��N�́A���ꂼ��̓��𔒂܂��͍��ɓh�邱�Ƃɂ��܂����B
�������A���[�̓������œh���Ă���悤�ȋ��������Ă͂����܂���B
�F�̓h��������ʂ肠�邩�A10^9+7 �Ŋ������]������߂Ă��������B


�e�}�X��������p����ԑJ�ڂł��邪�Adp[���_�ԍ�][�F] := ���݃}�X������F�ł��������̐F�̓h���
�Ƃ��č��̖��[���瑀�삵�Ă����B
����}�X�����œh�����Ƃ��͎��̃}�X�͔��łȂ��Ă͂Ȃ�Ȃ��B�����ɂ������ӂ���΃������ċA�őS��Ԃ���񂸂v�Z���ďI���B

int w = x[v][i];�������Y��Ă��Ă���ǂ������B

*/

int N;
ll dp[100010][2];
vector<int>x[100010];
ll ans = 0;
enum { White, Black };

ll dfs(int v, int p, int c) {

    if (dp[v][c] >= 0)return dp[v][c];
    if (x[v].size() == 1 && x[v][0] == p)return 1;

    dp[v][c] = 1;
    FOR(i, 0, x[v].size()) {
        int w = x[v][i];

        if (w == p)continue;
        ll a = 0;
        a = (a + dfs(w, v, White)) % MOD;
        if (c != Black) {
            a = (a + dfs(w, v, Black)) % MOD;
        }
        dp[v][c] = (dp[v][c] * a) % MOD;
    }

    return dp[v][c] ;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    int s, t;
    FOR(i, 0, N - 1) {
        cin >> s >> t;
        s--; t--;
        x[s].push_back(t);
        x[t].push_back(s);
    }

    FOR(i, 0, 100010)FOR(j, 0, 2)dp[i][j] = -1;

    ans = (dfs(0, -1, White) + dfs(0, -1, Black)) % MOD;

    cout << ans << endl;

    return 0;
}