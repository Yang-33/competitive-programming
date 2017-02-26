#include<iostream>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define MOD 1000000007
typedef long long ll;

/* -----  2017/02/26  Problem: ABC024 D / Link: http://abc024.contest.atcoder.jp/tasks/abc024_d ----- */
/* ------問題------
高橋君はタテ、ヨコともに 108 マスずつある方眼紙を使って以下の問題を解くことにしました。

「一番左下のマスから開始して、右もしくは上に1マス移動するという操作を繰り返して、
各マスにたどり着く方法の個数を 1,000,000,007 で割った余りを求めよ。」
しかし書き込み終わったあと、達成感のために舞い上がってしまい、方眼紙の一部を破いてしまいました。

高橋君の手元には、あるマスと、その上のマスと右のマスの部分のみが書かれている方眼紙の欠片があります。
高橋君はこの欠片を元の位置に戻そうと思ったのですが、方眼紙が大きすぎるので、どこに置けばいいのかわかりません。
欠片の情報から、この欠片が元々の方眼紙の左から何マス、下から何マスの位置にあったのか求めてください。
つまり、左からxマス、下からyマスのマスのことを (x,y) と書くとして、
(r,c)、(r,c+1)、(r+1,c)のマスに書かれている整数が与えられるので、 r と c を求めてください。
なお、一番左下のマスは (0,0) です。

-----問題ここまで----- */
/* -----解説等-----

探索はサイズ的に不可能。

A=(r+c)comb(c)
B=(r+c+1)comb(c+1)
C=(r+c+1)comb(c)
であることからr,cの式はABCを使って解くことができる。
その式はmodの除算を含むので逆元を用いて積に変換する。
いつものやつだが差の式がある場合には負にならないように気を付けなければならないので
+MODを各式に入れておけば安心。

 ----解説ここまで---- */


ll mod_pow(ll x, ll p, ll mod) {
    ll a = 1;
    while (p) {
        if (p & 1) a = a * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return a;
}

//逆元　1/a (mod m) => a^(m-2) (mod m)
ll mod_inverse(ll a, ll m) {
    return mod_pow(a, m - 2, m);
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll a, b, c;

    cin >> a >> b >> c;
    ll d = (b*c%MOD - a*b%MOD - a*c%MOD + MOD + MOD) % MOD;
    ll r = ((a*c%MOD - b*c%MOD+MOD) % MOD)*mod_inverse(d, MOD)%MOD;
    ll x = ((a*b%MOD - b*c%MOD+MOD) % MOD)*mod_inverse(d, MOD)%MOD;

    cout << r << " " << x << endl;

    return 0;
}