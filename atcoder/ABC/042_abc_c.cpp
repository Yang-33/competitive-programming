#include<iostream>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/25 問題 ----- ABC042 C/Link http://abc042.contest.atcoder.jp/tasks/arc058_a */
/* -----解説等-----
問題: いろはちゃんはこだわりもので、嫌いな数字が K 個あり、それぞれ D1,D2,…,DK です。

いろはちゃんはお店でお買い物をしていて、 N 円の品物を買おうとしています。
もちろん、この品物は N 円以上のお金を支払えば買うことができます。
しかし、先ほど述べたようにいろはちゃんは強いこだわりがあるので、
自分がお店に支払う金額の 10 進表記にいろはちゃんの嫌いな数字が出現しないような最も少ない金額を支払おうとします。

いろはちゃんが支払う金額を求めてください。

全探索をする。
各文字について使用可能かをチェックし、ダメなら+1して再度チェックをかけていく
の動作を繰り返し行えばよい。


*/

int N, K;
bool d[10];
int ans = 0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    FOR(i, 0, K) {
        int s;
        cin >> s;
        d[s] = true;
    }
    int x = N;
    for (;;) {
        bool flag = true;
        int t = x;
        while (t) {
            if (d[t % 10])flag = false;
            t /= 10;
        }
        if (flag) {
            cout << x << endl;
            return 0;
        }
            x++;
    }


    return 0;
}