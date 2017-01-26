#include<iostream>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/26 問題 ----- ABC041 D /Link http://abc041.contest.atcoder.jp/tasks/abc041_d */
/* -----解説等-----
問題: N 匹のうさぎがいます。 うさぎは 1 から N まで番号が振られています。
これら N 匹のうさぎが徒競走をしました。 同着はいませんでした。 このとき、着順は N! 通り考えられます。
高橋君は M 人の観客から情報を集めました。 i 番目の観客によると、うさぎ xi はうさぎ yi よりも先にゴールしたそうです。
すべての観客の情報に合致するような着順が何通り考えられるか求めてください。

N!は10^13程度であるから全探索ではTLE.巡回セールスマン問題のときの様に状態を二進数で表してbitDPをすれば
O(2^N)で計算可能になる.X_iはY_iよりも先に訪れるという制約から現在みている状態でそれは正しいかを判定していけばよい。
時間がかかってしまったのでちゃっちゃと解きたい。

*/

int N, M;
int x[121], y[121];
ll dp[1 << 16];
bool can_use[1 << 16];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    FOR(i, 0, M) {
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }

    FOR(i, 0, (1 << N)) { // xがyより先
        can_use[i] = true;
        FOR(j, 0, M) {
            if ((!((i >> x[j]) & 1)) && ((i >> y[j]) & 1)) {
                can_use[i] = false;
            }
        }
    }

    dp[0] = 1;

    FOR(i, 0, (1 << N)) {
        FOR(j, 0, N) {
            if ((!((i >> j) & 1)) && can_use[i | (1 << j)]) {
                dp[i | (1 << j)] += dp[i];
            }
        }
    }

    cout << dp[(1 << N) - 1] << endl;

    return 0;
}