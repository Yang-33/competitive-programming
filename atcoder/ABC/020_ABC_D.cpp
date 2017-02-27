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
const int INF = 1e9;
typedef long long ll;
int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
int dy[8] = { 1,0,-1,1,-1,1,0,-1 };

/* -----  2017/02/27  Problem: ABC020 D / Link: http://abc020.contest.atcoder.jp/tasks/abc020_d ----- */
/* ------問題------


-----問題ここまで----- */
/* -----解説等-----

100点解法
lcm(a,b)=a*b/gcd(a,b)
gcd(a,b)=gcd(a%b,b)を利用する
するとΣ(n->N) lcm(n,K) はKの余剰で考えることができる
K種の値についてlcm(x%K,K)=gc,(x%K,K)*x*K,
about N/Kぐらいの項をgcm(x%K,K)でまとめることができるので
公差Kの等差数列の和として考えることができる -> О(1)
О(K log K)で計算可能

101点解法
gcd(i,k)はk種類しか存在しない。
ｋの約数を求め、各約数についてのlcmを求めればよい。その際重複して数え上げないように注意する。
http://abc020.contest.atcoder.jp/submissions/663276

----解説ここまで---- */

ll N, K;
ll ans = 0LL;

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    ll r = a%b;
    while (r > 0) {
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    if (K > 100)return 0;

    FOR(i, 1, K + 1) {
        if (i > N)
            break;
        ll n = N / K;
        if (N%K >= i)
            n++;
        ans += n*(2 * i + (n - 1)*K) / 2 / gcd(i, K)*K;
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}