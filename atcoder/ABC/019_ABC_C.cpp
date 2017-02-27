#include<iostream>
#include<set> 
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* -----  2017/02/28  Problem: ABC019 C / Link: http://abc019.contest.atcoder.jp/tasks/abc019_3 ----- */
/* ------問題------

高橋くんは魔法の箱を持っています。
この箱に整数を入れるとそれに対応した整数が出てきます。
出てくる整数は入れた整数だけによって決まり、同じ整数を入れると毎回同じ結果が得られます。
高橋くんは任意の整数 x について、x を入れた時と 2x を入れた時に出てくる整数が同じであることに気づきました。
高橋くんが入れた整数が N 個与えられるので、最大で何種類の整数が出てくるか答えてください。

-----問題ここまで----- */
/* -----解説等-----

要素aに対して2倍あるいは2で割ったものは同じ結果を吐き出すことから、aを2で割り切れなくなるまで割り、それを集合で管理すればよい。

 ----解説ここまで---- */

ll N;
ll a[100000];
set<ll>s;
ll ans = 0LL;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    FOR(i, 0, N) {
        cin >> a[i];
    }

    FOR(i, 0, N) {
        ll x = a[i];
        while (x % 2 == 0) {
            x /= 2;
        }
        s.insert(x);
    }
    ans = s.size();

    cout << ans << endl;

    return 0;
}