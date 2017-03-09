#include<iostream>
using namespace std;

typedef long long ll;
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)

/* -----  2017/03/09  Problem: ARC057 A / Link: https://arc057.contest.atcoder.jp/tasks/arc057_a ----- */
/* ------問題------

高橋君は 2 兆 (=2×1012) 円が欲しいです。高橋君の現在の所持金は A 円であり、ある日に高橋君が t 円を持っているならその翌日には 高橋君の所持金は 1+Kt 円増加します。
高橋君の所持金がはじめて 2 兆円以上になるのは何日後でしょうか。

-----問題ここまで----- */
/* -----解説等-----

K≠0で指数的に増加するが0は1加算に他ならないので例外処理をする。
二兆円欲しい。

 ----解説ここまで---- */

ll A, K;

ll ans = 0LL;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> A >> K;
    if (K == 0) {
        cout << 2000000000000 - A << endl;
        return 0;
    }
    ll money = A;
    ll cnt = 0;
    while (money < 2000000000000) {
        money += 1 + K*money;
        cnt++;
    }

    ans = cnt;
    cout << ans << endl;

    return 0;
}