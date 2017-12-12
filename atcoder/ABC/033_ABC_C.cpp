#include<iostream>
#include<string>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

/* 2017/01/29 問題 ----- ABC033 C /Link http://abc033.contest.atcoder.jp/tasks/abc033_c */
/* -----解説等-----
問題: 次のような制約を満たす数式 S が与えられます。

演算子は + (加算) と * (乗算) のみからなる。乗算を優先して計算する。
括弧は存在しない。
それぞれの項は、 1 桁の整数である。
例えば、1+3*4*0 、 1+2+3+4+5 などの数式はこの条件を満たしますが、
12+3+5、4*6*7-3、(3+4)*5+2 のような数式は 条件を満たさないため、入力として与えられません。

あなたは、この数式のうち数字の部分をいくつか選んで 0 に書き換えることで、この式の値を 0 にしたいです。
式の値を 0 にするために 0 に書き換えなければならない数字の個数の最小値を求めてください。


状態を三つに分けることができる。
+...+のあいだに(...は数字や演算*) 0が存在しない
+...+のあいだに(...は数字や演算*) 0が存在する
+...+を見切った

ゼロを発見したら区間の中で０を追加しなくてもよく、なければついかをする。
最後の区間は+が登場しないので自分で加算をさせる。
もしくは +S+ としてもよい。

*/

string S;
int flag = 1;
int ans = 0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> S;
    FOR(i, 0, S.size()) {

        if (S[i] == '0')flag = 0;
        if (S[i] == '+') {
            ans += flag;
            flag = 1;
        }

    }
    ans += flag;

    cout << ans << endl;

    return 0;
}
