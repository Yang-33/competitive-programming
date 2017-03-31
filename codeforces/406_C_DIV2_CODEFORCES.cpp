#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int INF = 1e9;
typedef long long ll;
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define debug(x) cout<<#x<<": "<<x<<endl

/* -----  2017/03/30  Problem: CodeForces406 C div2 / Link: http://codeforces.com/contest/786/problem/A ----- */
/* ------問題------

円上に n 個のマスがある．それぞれ 0 から n-1 まで番号が振られている．
0 番目はブラックホールである．
また，どこかのマスに一匹のモンスターがいる．
これらを使って2人でゲームをする．2人はそれぞれ集合S1, S2を持っていて，要素はいくつかの自然数である．
順番に，自分の集合の中から好きな数字をえらんで，モンスターを今いる位置から時計回りに選んだ数字分移動させる．
この時，ちょうどブラックホールにモンスターを移動させたほうが勝ちである．
モンスターの初期位置が 1, 2, …, n-1 番目のマスだった場合，2人のプレイヤーが最善を尽くした時に先手（プレイヤーは二人いるので2通り）は「勝ち」「ループ」「負け」のいずれになるかをすべて答えよ．

-----問題ここまで----- */
/* -----解説等-----

ゲームは最終状態からたどっていくのが定石らしい。
勝ちが決まるのは、相手が負けると決まっているマスに到達可能であるとき、負けが決まるのはすべての手を使っても相手が勝つと確定するマスに到達してしまうときである。
状態数は最大でもn*kであるから O(N*K)

----解説ここまで---- */

ll N;
int dp[2][7010];
int vis[2][7010];
int L[2];
int S[2][7010];

void pre() {

    queue<int> que;
    dp[0][0] = -1; que.push(0 * 101010 + 0);
    dp[1][0] = -1; que.push(1 * 101010 + 0);

    while (!que.empty()) {
        int q = que.front(); que.pop();

        int p = q / 101010;
        int x = q % 101010;

        int pp = 1 - p;
        FOR(i, 0, L[pp]) {
            int xx = (x - S[pp][i] + N) % N;
            if (dp[p][x] < 0) {
                if (dp[pp][xx] == 0) {
                    dp[pp][xx] = 1;
                    que.push(pp * 101010 + xx);
                }
            }
            else {
                if (dp[p][x] == 0) continue;
                vis[pp][xx]++;
                if (vis[pp][xx] == L[pp]) {
                    dp[pp][xx] = -1;
                    que.push(pp * 101010 + xx);
                }
            }
        }
    }
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    FOR(i, 0, 2) {
        cin >> L[i];
        FOR(j, 0, L[i]) cin >> S[i][j];
    }

    pre();

    FOR(p, 0, 2) {
        FOR(x, 1, N) {
            int d = dp[p][x];
            if (d < 0) printf("Lose");
            else if (d == 0) printf("Loop");
            else printf("Win");
            if (x != N - 1) printf(" ");
        }
        printf("\n");
    }


    return 0;
}