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
#define llong long long
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

/* 2017/01/25 問題 ----- ABC042 D /Link http://abc042.contest.atcoder.jp/tasks/arc058_b */
/* -----解説等-----
問題: 縦 H マス、横 W マスのマス目があります。
いろはちゃんは、今一番左上のマス目にいます。
そして、右か下に1マス移動することを繰り返し、一番右下のマス目へと移動します。
ただし、下から A 個以内、かつ左から B 個以内のマス目へは移動することは出来ません。

移動する方法は何通りあるか求めてください。

なお、答えは非常に大きくなることがあるので、答えは 10^9+7 で割ったあまりを出力してください。

組み合わせ・逆元の問題
既に類似した問題を解いたことがあるのですぐにＡＣ
割り算のMODは取ることができないのでフェルマーの定理から逆元を用いて組み合わせを求める。

nCk=n!/((n-k)!*(k!))
nCkの計算をしていく際にmodをとると割り算に対してはその計算ができないので、
p:素数としてフェルマーの小定理とaとpが互いに素でることを考慮して、変形して逆元を考えれば
a^(p-1)≡1 (mod p)　->  a^(p-2)*a≡1 (mod p)
-> a^(p-2)≡1/a (mod p) ->b/a (mod p) = b*a^(p-2) (mod p)
となる

単一の逆元は、
Int inv[1000010];
inv[1] = 1;
for (int i = 2; i <= N; ++i)
inv[i] = P - (P / i) * inv[P % i] % P;　(mod P)

として求めることができる。これを用いて階乗とその逆元は
I
nt fac[1000010], facInv[1000010];
fac[0] = facInv[0] = 1;
for (int i = 1; i <= N; ++i) {
fac[i] = (fac[i - 1] * i) % P;
facInv[i] = (facInv[i - 1] * inv[i]) % P;
}
pow_mod(a,mod-2,mod)を用いなくてもこのように求めることもできる。

invers前準備O(N+N+N) 使用O(1) <単一逆元の利用>
powmod前準備O(N+N*log(MOD)) 使用O(1) <フェルマーの小定理から>

*/

#define MAX 230000
int H, W, A, B;
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

    int H, W, A, B;
    cin >> H >> W >> A >> B;
    ll ans = 0;


    fact[0] = rfact[0] = 1;

    for (int i = 1; i < MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        rfact[i] = mod_inverse(fact[i], MOD);
    }

    for (int i = B + 1; i <= W; i++) {
        int h = H - A - 1, w = i - 1;
        ll tmp = nCr(h + w, h);
        h = A - 1, w = W - i;
        tmp *= nCr(h + w, w);
        ans += tmp % MOD;
    }

    cout << ans%MOD << endl;

    return 0;
}