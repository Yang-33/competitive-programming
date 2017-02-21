#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* -----  2017/02/22  Problem: ABC029 D / Link: http://abc029.contest.atcoder.jp/tasks/abc029_d ----- */
/* ------問題------

高橋君は 1 以上 N 以下のすべての整数を十進表記で一回ずつ紙に書きました。
この作業で、高橋君は 1 という数字を何個書いたでしょうか。
整数 N (1 ≦ N < 10^9) が与えられる。

-----問題ここまで----- */
/* -----解説等-----

digit dp
通常の検索を行うと同じ部分を何度も検索してしまうのでこれをメモしておくことで高速になる。
1の個数に着目したい のでこれを桁dpの条件に追加する。
dp[ 現在の桁 ][ 1の個数 ][ Ｎ未満という事が確定しているか ] := 総数
N未満であると言い切れない場合には場合分けをしておけばよい。
位の大きい桁から順に数を下していき、
1の出現数を末端まで伝播させておけばすべての数を列挙し終えた際に正確に数えることができる。
10*桁数*(はい/いいえ)　ぐらいの計算量

 ----解説ここまで---- */

string N;
ll dp[30][20][2];

ll rec(int x,int cnt,int ok) {
    if (dp[x][cnt][ok] != -1)return dp[x][cnt][ok];
    if (x == N.size())return cnt;

    if (ok == 0) {
        ll tmp = 0;
        for (int i = 0; i < N[x] - '0'; i++) {
            tmp += rec(x + 1, cnt + (i == 1), 1);
        }
        tmp += rec(x + 1, cnt + (N[x] == '1'), 0);
        return dp[x][cnt][ok] = tmp;
    }
    else {
        ll tmp = 0;
        for (int i = 0; i < 10; i++) {
            tmp += rec(x + 1, cnt + (i == 1), 1);
        }
        return dp[x][cnt][ok] = tmp;
    }
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    memset(dp, -1, sizeof(dp));

    cin >> N;

    cout << rec(0,0,0) << endl;

    return 0;
}