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
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

/* 2017/01/21 問題 ----- ABC046 C /Link http://abc046.contest.atcoder.jp/tasks/arc062_a */
/* -----解説等-----
問題: シカのAtCoDeerくんは選挙速報を見ています。
選挙には二人の候補高橋くんと青木くんが出ています。
速報では、現在の二人の得票数の比が表示されていますが、得票数そのものは表示されていません。
AtCoDeerくんは N 回画面を見て、 i(1≦i≦N) 回目に見たときに表示されている比は Ti:Ai でした。
ここで、AtCoDeerくんが選挙速報の画面を1回目に見た段階で既にどちらの候補にも少なくとも一票は入っていたことがわかっています。
N 回目に画面を見たときの投票数(二人の得票数の和)として考えられるもののうち最小となるものを求めてください。
ただし、得票数が途中で減ることはありません。

1≦N≦1000
1≦Ti,Ai≦1000(1≦i≦N)
Ti と Ai は互いに素 (1≦i≦N)
答えが 10^18 以下になることは保証されている


与えられた新しい T, Aについて、以前の投票されている枚数から比rを求める。
t=T*r
a=A*r
ただしrはr=max( ceil(t/T) , ceil(a/A) )

*/

int N;
int T[1000], A[1000];
ll ans = 0;
ll nt, na, r;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> N;
    cin >> T[0] >> A[0];
    r = 1; nt = T[0]; na = A[0];

    FOR(i, 1, N) {
        cin >> T[i] >> A[i];
        r = max((nt + T[i] - 1) / T[i], (na + A[i] - 1) / A[i]);
        nt = T[i] * r;
        na = A[i] * r;
    }
    ans = nt + na;
    cout << ans << endl;

    return 0;
}