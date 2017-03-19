#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
typedef long long ll;

/* -----  2017/03/20  Problem: ABC029 D / Link: http://abc029.contest.atcoder.jp/tasks/abc029_d ----- */
/* ------問題------

高橋君は 1 以上 N 以下のすべての整数を十進表記で一回ずつ紙に書きました。
この作業で、高橋君は 1 という数字を何個書いたでしょうか。
整数 N (1 ≦ N < 10^9) が与えられる。

-----問題ここまで----- */
/* -----解説等-----

digit dp
桁ｄｐ
通常の検索を行うと同じ部分を何度も検索してしまうのでこれをメモしておくことで高速になる。
1の個数に着目したい のでこれを桁dpの条件に追加する。
dp[ 現在の桁 ][ その数に含まれる1の個数 ][ Ｎ未満という事が確定しているか ] := 数の出現数
N未満であると言い切れない場合には場合分けをしておけばよい。
位の大きい桁から順に数を下していき、
1の出現数を末端まで伝播させておけばすべての数を列挙し終えた際に正確に数えることができる。
出現数のみしか数え上げられないので１の値の数をもう一度考慮して二回目のDPを行えばよい。
各桁についてすべての数を数えるかこれは和となるので計算量はＯ((桁数)*(１の個数)*(はい/いいえ)*(10))
でlogNlogN*10*2ほどで400ループぐらいか？。

 ----解説ここまで---- */

ll dp[12][12][2];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    dp[0][0][0] = 1;

    string N;
    cin >> N;
    ll ans = 0;
    FOR(i, 0, N.size()){
        int D = N[i] - '0';    
            FOR(j, 0, N.size()){
                FOR(k, 0, 2){
                    FOR(d, 0, k ? 10 : D + 1){
                        dp[i + 1][j + (d == 1)][k || d < D] += dp[i][j][k];
                }
            }
        }
    }

    FOR(j, 0, N.size() + 1){
        FOR(k, 0, 2){
            ans += dp[N.size()][j][k] * j;
        }
    }

    cout << ans << endl;

    return 0;
}