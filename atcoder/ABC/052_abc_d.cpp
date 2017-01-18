#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define llong long long
typedef long long ll;
ll N;
/* 2017/01/18 問題 -----  abc052 d Link http://abc052.contest.atcoder.jp/tasks/arc067_b */
/* -----解説等-----
問題:
クラスカル?と思ったが間に合わない。
頂点移動の順序によらない
ex:1=>2===>3
テレポ1->2+歩く2->3

ex:1=>3===>2
テレポ1->3+歩く3->2

テレポのコストが同じため、
以上のコストは同じ。
よって帰納的に順序に依存しない(略)
すなわち隣り合う頂点の最小の疲労をとっていけばよい。

*/

ll ans = 0;
ll x[100001];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll A, B;
    cin >> N >> A >> B;
    FOR(i, 1, N + 1)
        cin >> x[i];
    FOR(i, 1, N ) {
        ans += min(A*(x[i + 1] - x[i]), B);
    }
    cout << ans << endl;

    return 0;
}