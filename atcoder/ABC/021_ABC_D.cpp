#include<iostream>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define MOD 1000000007LL
typedef long long ll;

/* -----  2017/02/27  Problem: ABC021 D / Link: http://abc021.contest.atcoder.jp/tasks/abc021_d ----- */
/* ------問題------

いろいろ考えてみたところ、このプログラムの出力する答えは 1≦a1≦a2≦…≦ak≦n であるような整数の組 (a1,a2,…,ak) の個数に等しいということに気づきました。
しかし、彼はそのようなものの個数を数える方法を思いつきませんでした。

彼の同僚であるあなたは、彼の代わりにこの課題をこなすプログラムを作ってあげることにしました。
ただし、答えは非常に大きくなることがあるので、ans の代わりに ans を 1,000,000,007(=10^9+7) で割った余りを出力してください。

-----問題ここまで----- */
/* -----解説等-----

おなじみ逆元問題。
最後桁あふれしやすいのでＭＯＤをよくとること。

 ----解説ここまで---- */

ll N, K;

ll ans = 0LL;

ll mod_pow(ll x, ll p, ll mod) {
    ll a = 1;
    while (p) {
        if (p & 1) a = a * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return a;
}
ll mod_inverse(ll a, ll m) {
    return mod_pow(a, m - 2, m);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    ll x = N - 1 + K;
    ll y = K;
    ll fact[220000];

    fact[0] = 1;

    FOR(i, 1, x + 1) {
        fact[i] = (i*fact[i - 1]) % MOD;
    }

    ans = ((fact[x] * mod_inverse(fact[y], MOD)) % MOD)*mod_inverse(fact[x - y], MOD) % MOD;

    cout << ans << endl;

    return 0;
}