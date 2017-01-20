#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/20 問題 -----  ABC048 C /Link  */
/* -----解説等-----
問題: N 個の箱が横一列に並んでいます。 最初、左から i 番目の箱には ai 個のキャンディが入っています。

すぬけ君は次の操作を好きな回数だけ行うことができます。

キャンディが 1 個以上入っている箱をひとつ選び、その箱のキャンディを 1 個食べる。
すぬけ君の目標は次の通りです。

どの隣り合う 2 つの箱を見ても、それらの箱に入っているキャンディの個数の総和が x 以下である。
目標を達成するために必要な操作回数の最小値を求めてください。


取り出す要件として端から順にｘを超えてしまうものを削減していけばよい。
新しく見つけた要素に対して削減を常に行うようにすれば次回に削減しなくてもよい可能性が存在するので
この探し方が最小解を求める手段である。Ｏ(N)

*/

int N, x;
int a[100000];
ll ans = 0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> x;
    FOR(i, 0, N) {
        cin >> a[i];
    }
    FOR(i, 0, N - 1) {
        ll sum = a[i] + a[i + 1];
        if (sum <= x)continue;
        
        ll sub = sum - x;
        if (sub <= a[i + 1]) a[i + 1] -= sub;
        else {
            ll subsub = sub;
            subsub -= a[i + 1];
            a[i + 1] = 0;
            a[i] -= subsub;
        }
        ans += sub;
    }


    cout << ans << endl;

    return 0;
}