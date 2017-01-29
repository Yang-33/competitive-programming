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

/* 2017/01/29 問題 ----- ABC034 D /Link http://abc034.contest.atcoder.jp/tasks/abc034_d */
/* -----解説等-----
問題: 食塩水が入った容器が N 個あります。 容器には 1 から N までの番号がついています。
i 番の容器には濃度 pi パーセントの食塩水が wi グラム入っています。
高橋君は、K 個の容器を選び、選んだ容器の中に入っている食塩水をすべて混ぜ合わせることにしました。
高橋君の混ぜた食塩水の濃度として考えられる最大値を求めてください。


初めは 各液体について塩と水に値を分けておき、
dp[ 昇順で使用可能な個数 ][ 使用した個数 ] := max濃度 (salt,water)かと思ったが
実装がよくわからなくなってしまった。=> できる
だがこれだと10^4ぐらいでTLEしてしまう。
平均最大化の考えを用いれば 100*NlogN 回ぐらい。
求めたいモノをxとして size[S]=K となる集合Sについて
ΣSomea_i[i∈S]/ΣSomeb_i[i∈S] ≧x となるxがほしいので
これを二分探索すればよい。

今回は Σ(塩)/Σ(水) ≧ X (%) => Σ( 塩 - X*水 ) ≧ 0

*/

int K, N;
int w[1000], p[1000];
double l = 0.0, r = 1.0, mid;
double v[1000];

bool CCC(double x) {
    FOR(i, 0, N) {
        v[i] = (p[i] / 100.0 - x)*w[i];
    }
    sort(v, v + N);
    double sum = 0;
    FOR(i, 0, K) {
        sum += v[N - 1 - i];
    }
    return sum >= 0;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    FOR(i, 0, N) {
        cin >> w[i] >> p[i];
    }
    
    FOR(i,0,100){
        mid = (r+l)/ 2.0;
        if (CCC(mid))l = mid;
        else r = mid;
    }

    printf("%.12lf",mid*100.0);
    return 0;
}