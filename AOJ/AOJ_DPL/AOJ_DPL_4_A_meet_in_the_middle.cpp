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
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;
ll N;

/* 2017/01/16 問題 AOJ_DPL_4_A  Name/Link http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_4_A */
/* -----解説等-----
問題:コインの組み合わせ
４つの袋Ａ, Ｂ, Ｃ, Ｄにそれぞれ N 枚, 合計 4N 枚のコインが入っています。
それぞれの袋に入っているコインの値段はai, bi, ci, di 円です。
D君は,各袋から1枚,合計4枚のコインを得たいと思っていて,値段の合計はちょうどV円にしたいと思っています。
このようなコインの選び方は何通りあるでしょうか? 
ただし, それぞれのコインは区別するものとします。

選び方の総数を 1 行に出力しなさい。

純粋総組み合わせは n^4 = 1000^4 =10^12 (Over)
半分全列挙を行えば時間計算量はＯ(n^2 log n) =10^6 log n となりＯＫ！
a,bの組み合わせを全列挙し、ソートする。
一方でc,dの組み合わせは V-c-d=a+bとなるようなものを発見すればよい。
検索はソート済み配列を用いているのであるからlower_bound/upper_boundを用いてlogとなる。


*/
#define MAX_N 1000
ll V;
ll a[MAX_N], b[MAX_N], c[MAX_N], d[MAX_N];
ll record[MAX_N*MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> N>>V;
    FOR(i, 0, N) {
        cin >> a[i];
    }
    FOR(i, 0, N) {
        cin >> b[i];
    }
    FOR(i, 0, N) {
        cin >> c[i];
    }
    FOR(i, 0, N) {
        cin >> d[i];
    }

    FOR(i, 0, N) {
        FOR(j, 0, N) {
            record[i*N + j] = a[i] + b[j];
        }
    }
    sort(record, record + N*N);
    ll ans = 0;
    FOR(i, 0, N) {
        FOR(j, 0, N) {
            ll part = V - (c[i] + d[j]);
            ans += upper_bound(record, record + N*N, part) - lower_bound(record, record + N*N, part);
        } //part そのものの値
    }


    cout << ans << endl;

    return 0;
}