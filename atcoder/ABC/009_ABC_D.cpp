#include<iostream>
#include<vector>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* -----  2017/03/02  Problem: ABC009 D / Link: https://abc009.contest.atcoder.jp/tasks/abc009_4 ----- */
/* ------問題------

数列 A はすべての要素が 32 ビットの符号なし整数で表現でき、その値は次のようにして決まる。
はじめの K 項 A1,?A2,?…,?AK は入力で与えられる。
A とは別に K 項の数列 C1,?C2,?…,?CK （こちらもすべての要素が 32 ビットの符号なし整数におさまる）が入力で与えられ、
K+1 項目以降の A の値はこの C を用いて次のように計算される。
N≧1 に対し AN+K=(C1?AND?AN+K?1)?XOR?(C2?AND?AN+K?2)?XOR?…? XOR?(CK?AND?AN)
ただし AND はビットごとの論理積、 XOR はビットごとの排他的論理和を表す。
この数列 A の M 番目の値 AM を求めるプログラムを作成せよ。

-----問題ここまで----- */
/* -----解説等-----

線形漸化式は行列の累乗を用いて解ける(プログラミングコンテストチャレンジブック pp.180-185)。
ただし今回は×がandに、+がxorになっている。
しかしこれは、行列累乗の際の計算で、×, +をand, xorにそれぞれ置き換えて計算すれば良い。
実際には、2つの二項演算(和と積)を備えた集合が、半環であればよい。(半環の性質は解説p.97に載っている)
http://www.slideshare.net/chokudai/abc009/97

この性質を実際に確かめる(1bitごとに全ての場合を計算すればよい)と、
xor: 結合法則、交換法則、単位元(0)を持つ
and: 結合法則、単位元(全てのbitが1、ここでは(1<<32)-1)を持つ
andとxorで分配法則が成立
xorの単位元(0)はandの零元
が全て成立するので、and, xorは非負整数の集合で半環をなす。

後は計算するだけ。

まだきびしい。むずかしいわ。

 ----解説ここまで---- */

ll N;

ll ans = 0LL;
typedef vector<vector<ll>> mat;

mat mul_bit(mat &A, mat &B) {
    mat C(A.size(), vector<ll>(B[0].size()));
    FOR(i,0, A.size())FOR(k,0, B.size())FOR(j,0, B[0].size()) {
        C[i][j] = (C[i][j] ^ (A[i][k] & B[k][j]));
    }
    return C;
}

mat pow(mat A, ll n) {
    mat B(A.size(), vector<ll>(A.size()));
    FOR(i,0, A.size()) {
        B[i][i] = -1;
    }
    while (n > 0) {
        if (n & 1) B = mul_bit(B, A);
        A = mul_bit(A, A);
        n >>= 1;
    }
    return B;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll a[101], c[101];
    ll k, m;
    cin >> k >> m;

    mat A;
    FOR(i,0, k) {
        cin >> a[i];
    }
    if (k >= m) {
        cout << a[m - 1] << endl;
        return 0;
    }
    reverse(a, a + k);
    FOR(i,0, k) {
        A.push_back(vector<ll>(1, a[i]));
    }
    /*
    a0
    a1
    a2
    ...

    */
    mat C;
    FOR(i,0, k) {
        cin >> c[i];
    }
    C.push_back(vector<ll>(c, c + k));
    FOR(i,0, k - 1) {
        vector<ll> t(k, 0);
        t[i] = -1;
        C.push_back(t);
    }
    /*
    c0 c1 c2 ... cn-1 cn
    1  0  0 ...  0    0
    0  1  0 ...  0    0
    0  0  1 ...  1    0

    */

    auto mC = pow(C, m - k);
    auto ans = mul_bit(mC, A);
    cout << ans[0][0] << endl;


    return 0;
}