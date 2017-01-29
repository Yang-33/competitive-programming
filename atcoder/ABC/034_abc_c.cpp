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
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
#define MOD 1000000007
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

/* 2017/01/29 問題 ----- ABC034 C /Link http://abc034.contest.atcoder.jp/tasks/abc034_c */
/* -----解説等-----
問題: 横 W x 縦 H のグリッドがあります。左から i 番目、下から j 番目のマス目には (i,j) という番号がついています。 

高橋君は、マス目 (i,j) から (i+1,j) または (i,j+1) に進むことができます。
高橋君が (1,1) から (W,H) まで行く経路の個数を 1,000,000,007 で割ったあまりを求めてください。


逆元を求める。1/a ≡ a^(p-2) (mod p)はフェルマーの定理から求めることができる。
これを用いて nCr= n!/(r!*(n-r)!)を nCr≡n!*(r!)^(p^2)*(n-r)!^(p-2) (mod p)
とあらわせばよい。
1回答えればよいのでこれで終了。

*/

#define MAX 230000
int W, H;
ll ans = 0;
ll fact[MAX], rfact[MAX];

ll mod_pow(ll x, ll p, ll mod) {
    ll a = 1;
    while (p) {
        if (p % 2) a = a * x % mod;
        x = x * x % mod;
        p /= 2;
    }
    return a;
}

//逆元
ll mod_inverse(ll a, ll m) {
    return mod_pow(a, m - 2, m);
}

ll nCr(int n, int r) {
    return fact[n] * rfact[r] % MOD * rfact[n - r] % MOD;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> H >> W;

    fact[0] = rfact[0] = 1;

    for (int i = 1; i < MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        rfact[i] = mod_inverse(fact[i], MOD);
    }
    H--; W--;
    ans = nCr(H+W, W);

    cout << ans << endl;

    return 0;
}