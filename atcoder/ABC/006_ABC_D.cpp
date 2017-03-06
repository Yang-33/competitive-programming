#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
const int INF = 1e9;

/* -----  2017/03/06  Problem: ABC006 D / Link: http://abc006.contest.atcoder.jp/tasks/abc006_4 ----- */
/* ------問題------

数字が書かれたカードが N 枚あります。このカードの束（山札）に対して以下の操作が可能です。
山札からカードを 1 枚抜き取り、任意の場所に挿入する。
山札の上から下に向けて、カードを昇順に並べ替えるために必要な、最小の操作回数を求めてください。

-----問題ここまで----- */
/* -----解説等-----

最初のカードの並びに対して、カードを抜いた後の並びがなるべく一致しているものを求めたい。
最長増加部分列。

----解説ここまで---- */

ll N;
int a[30000];
int dp[32000];
ll ans = 0LL;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    FOR(i, 0, N) {
        cin >> a[i];
    }
    FOR(i, 0, 32000)dp[i] = INF;

    int res = -1;
    FOR(i, 0, N) {
        int id = lower_bound(dp, dp + i, a[i]) - dp;
        dp[id] = a[i];
        res = max(res, id);
    }
    cout << N-res-1 << endl;

    return 0;
}