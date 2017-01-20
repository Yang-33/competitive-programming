#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<climits> //INT_MIN/MAX
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

/* 2017/01/20 問題 ----- ABC047 D /Link http://abc047.contest.atcoder.jp/tasks/arc063_b */
/* -----解説等-----
問題: N 個の町が一直線上に並んでいます。行商人の高橋君は町 1 から出発し、リンゴの売買をしながら町 N へと向かいます。

はじめ高橋君は町 1 におり、リンゴを 1 つも持っていません。高橋君は次のいずれかの行動を繰り返し行います。

移動: 町 i (i<N) にいるとき、町 i+1 へ移動する。
リンゴの売買: リンゴを好きな個数だけ売買する。
ここで、町 i (1≦i≦N) ではリンゴの買値も売値もともに Ai 円とする。ここで Ai は相異なる整数です。
1 つの町で売買するリンゴの個数に制限はありませんが、旅の中で売買するリンゴの個数は合計で (買う個数と売る個数を合わせて) T 個以下にしなくてはなりません。

高橋君は旅の利益、すなわちリンゴを売った代金から買った代金を引いた値を最大にするように旅をするとします。
旅が終わったときに持っていたリンゴの価値は考えず、旅の中で売買した金額だけを考えます。

この旅に先立って、青木君は任意の町 i に対して Ai を好きな非負整数 Ai' に変えるという操作を好きなだけ行うことができます。
ただし、この操作は行うごとに |Ai?Ai'| のコストがかかります。
操作後には異なる町の間でリンゴの値段が同じになっていても構いません。

青木君の目的はできるだけ少ない合計コストの操作で高橋君の利益を少なくとも 1 円下げることです。
合計コストの最小値を求めてください。

ただし、元の状態で高橋君が 1 円以上の利益を上げられることは仮定して構いません。

制約
1≦N≦105
1≦Ai≦109 (1≦i≦N)
Ai は相異なる
2≦T≦109
入力の状態では高橋君は 1 円以上の利益を上げられることが保証される


最小値が更新されるごとに別の区間であるとする。
それらの区間についての最大値と最小値の差を保持し、その差の最大値が何回登場するかをカウントする。
最小値が更新された場合にはそれまでの最大値を用いることができないので最小値以下の数にすれば問題ない。

*/

#define INF INT_MAX/2
int N, T, a[100000];
int minn = INF, maxn = -INF;
int nowmax = -1;
int cnt = 0;
int ans = 0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> T;
    FOR(i, 0, N) {
        cin >> a[i];
    }

    minn = a[0];
    FOR(i, 0, N) {
        
        if (minn > a[i]) {
            maxn = -INF;
            minn = a[i];
        }

        if (nowmax == a[i]- minn)cnt++;
        else if (nowmax < a[i] - minn) {
            nowmax = a[i] - minn;
            cnt = 1;
        }
    }

    ans = cnt;
    cout << ans << endl;

    return 0;
}