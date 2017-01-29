#include<iostream>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/29 問題 ----- ABC037 C /Link http://abc037.contest.atcoder.jp/tasks/abc037_c */
/* -----解説等-----
問題: 長さ N の数列 {ai} と1 以上 N 以下の整数 K が与えられます。
この数列には長さ K の連続する部分列が N?K+1 個あります。
これらのそれぞれ部分列に含まれる値の合計の総和を求めてください。

累積和をとって区間和を出せばよい。
区間和といえばsegtreeもできたなあと思ったが今回はこっちのほうが実装が簡単。

*/

#define MAX_N 100000
int N, K;
ll sum[MAX_N + 1];
ll ans = 0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> N >> K;

    int x;
    sum[0] = 0;
    FOR(i, 1, N + 1) {
        cin >> x;
        sum[i] = sum[i - 1] + x;
    }

    FOR(i, K, N + 1) {
        ans += (sum[i] - sum[i - K]);
    }

    cout << ans << endl;

    return 0;
}