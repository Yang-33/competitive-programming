#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)

/* -----  2017/03/09  Problem: ARC056 A / Link: http://arc056.contest.atcoder.jp/tasks/arc056_a ----- */
/* ------問題------

高橋くん一家では今シーズンの果物がみかんに決まり、K個のみかんを買うことが決まりました。
みかんは1個A円、さらにL個のセットでB円で売っています。 1個のみかんとL個のセットをそれぞれいくつか買い、
合計でK個以上のみかんを買うとき、払うお金の最小値を求めるプログラムを書いてください。

-----問題ここまで----- */
/* -----解説等-----

考察せず全探索したらダメだった。
制約からk/l * b個はセットで買うので余りをセットがバラで買えばよい。

 ----解説ここまで---- */

ll N, a, b, k, l;

ll ans = 0LL;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> a >> b >> k >> l;

    ans = min(k / l*b + k%l*a, (k / l + 1)*b);

    cout << ans << endl;

    return 0;
}